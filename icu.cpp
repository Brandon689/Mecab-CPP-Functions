//#include <fstream>
//#include <string>
//
//#include <unicode/unistr.h>
//#include <mecab/mecab.h>
//
//#define WORD_INDEX 6
//
//struct SearchPair
//{
//    /* The deconjugated string */
//    icu::UnicodeString deconj;
//
//    /* The raw conjugated string */
//    icu::UnicodeString surface;
//};
//
//
//static inline icu::UnicodeString extractDeconjugation(const MeCab::Node* node)
//{
//
//    //return icu::UnicodeString::fromUtf8(node->feature).split(',')[WORD_INDEX];
//    auto d = node->feature;
//    icu::UnicodeString tot(node->feature);
//
//    return icu::UnicodeString(node->feature);
//}
//
//
////void d()
////{
////    icu::UnicodeString ucs = icu::UnicodeString::fromUTF8(StringPiece(s.c_str()));
////}