#pragma execution_character_set("utf-8")

#include <iostream>
#include <mecab/mecab.h>
#include <fstream>
#include <cstring>

using std::ofstream;
#include <iostream>
#include <vector>
#include <set>
using std::cout;
using std::endl;
bool startsWith(const std::string& str, const std::string& prefix) {
    // Check if the string is long enough to contain the prefix
    if (str.length() < prefix.length()) {
        return false;
    }

    // Compare the substring of str with the prefix
    return str.compare(0, prefix.length(), prefix) == 0;
}
bool containsSubstring(const std::string& str, const std::string& substring) {
    return str.find(substring) != std::string::npos;
}
void prependToCharArray(char*& dest, const char* src) {
    // Calculate the length of the source and destination strings
    size_t srcLen = strlen(src);
    size_t destLen = strlen(dest);

    // Allocate memory for the new string (source + destination)
    char* newStr = new char[srcLen + destLen + 1];  // +1 for the null terminator

    // Copy the source string to the beginning of the new string
    strcpy(newStr, src);

    // Copy the destination string after the source string
    strcpy(newStr + srcLen, dest);

    // Deallocate memory for the old destination string
    delete[] dest;

    // Update the destination pointer to point to the new string
    dest = newStr;
}
struct SearchPair
{
    /* The deconjugated string */
    std::string deconj;

    /* The raw conjugated string */
    std::string surface;
};

/**
 * A special SearchPair that contains additional information needed by MeCab.
 */
struct MeCabPair : public SearchPair
{
    /* The surface string without whitespace */
    std::string surfaceClean;
};


void him(const char* result, std::string file)
{
    std::ofstream outFile(file, std::ios::out | std::ios::binary);
    if (!outFile) {
        std::cerr << "Failed to open the file for writing." << std::endl;
        return;
    }
    outFile << result;
    outFile.close();
}
char* substring(const char* str, size_t endIndex) {
    if (str == nullptr || endIndex < 0 || endIndex >= strlen(str)) {
        // Handle invalid input or out-of-bounds endIndex as needed.
        return nullptr;
    }

    // Allocate memory for the new substring.
    char* result = new char[endIndex + 1];  // Add 1 for the null terminator.

    // Copy characters from the original array to the new substring.
    strncpy(result, str, endIndex);
    result[endIndex] = '\0';  // Null-terminate the new substring.

    return result;
}
static inline const char* extractSurface(const MeCab::Node* node)
{
    const char* rawText = node->surface;
    rawText -= node->rlength - node->length;

    char* subStr = substring(rawText, node->length);


    return subStr;
}
static inline const char* extractCleanSurface(const MeCab::Node* node)
{
    char* subStr = substring(node->surface, node->length);
    return subStr;
}
#define WORD_INDEX 6

static inline const char* extractDeconjugation(const MeCab::Node* node)
{
    const char* input = node->feature;
    him(input, "soe.txt");
    cout << input << endl;
    std::vector<const char*> tokens;

    // Create a modifiable copy of the input
    char* inputCopy = _strdup(input);
    //cout << inputCopy << endl;
    // Tokenize the input string by comma
    char* token = strtok(inputCopy, ",");
    //cout << token;
    while (token != nullptr) {
        tokens.push_back(token);
        //cout << token;
        token = strtok(nullptr, ",");

    }
    // Free the dynamically allocated memory

    const char* deconj = tokens[WORD_INDEX];
    for (size_t i = 0; i < tokens.size(); i++)
    {
        const char* deconj = tokens[i];
        //cout << i << " " << deconj << endl;
    }
    //cout << endl;
    free(inputCopy);


    return deconj;
}
#undef WORD_INDEX


static std::vector<MeCabPair>* generateQueriesHelper(
//static QList<MeCabPair>* generateQueriesHelper(
    const MeCab::Node* node)
{
    std::vector<MeCabPair>* queries = new std::vector<MeCabPair>;
    while (node)
    {
        const char* deconj = extractDeconjugation(node);
        const char* surface = extractSurface(node);
        const char* surfaceClean = extractCleanSurface(node);
        //cout << deconj << endl;

        //him(deconj, "aether.txt");

        //cout << surface << endl;

        if (deconj != "*")
        {
            MeCabPair pair;
            pair.deconj = deconj;
            pair.surface = surface;
            pair.surfaceClean = surfaceClean;
            queries->push_back(pair);
        }
        

        if (node->next)
        {
            std::vector<MeCabPair>* subQueries = generateQueriesHelper(node->next);
            for (MeCabPair& p : *subQueries)
            {
                p.deconj.insert(0, surfaceClean);
                p.surface.insert(0, surface);
                p.surfaceClean.insert(0, surfaceClean);
                queries->push_back(p);
            }
            delete subQueries;
        }
        node = node->bnext;
    }
    return queries;
}

int main(int argc, char** argv)
{
    SetConsoleOutputCP(CP_UTF8);
    //const char* mate = u8"私は面倒くさい男が好きだ";
    const char* query = u8"太陽は明るく輝いていた";
    //std::cout << "Hello, World! こんにちは世界!" << std::endl;
    //std::string query;

    std::vector<SearchPair> queries;
    //if (query.isEmpty() || m_tagger == nullptr)
    //{
    //    return queries;
    //}



    MeCab::Tagger* zig = MeCab::createTagger("");
    MeCab::Lattice* lattice = MeCab::createLattice();

    lattice->set_sentence(query);

    if (!zig->parse(lattice))
    {
        delete lattice;
    }
    std::vector<MeCabPair>* unfiltered= generateQueriesHelper(lattice->bos_node()->next);
    
    std::set<std::string> duplicates;
    for (const MeCabPair& p : *unfiltered)
    {
        if (startsWith(query, p.deconj))
        {
            continue;
        }
        std::set<std::string>::iterator it = duplicates.find(p.deconj);
        bool found = (it != duplicates.end());

        queries.push_back(p);
        duplicates.insert(p.deconj);
    }
    delete unfiltered;
    delete lattice;
}
