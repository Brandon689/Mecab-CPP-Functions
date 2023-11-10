//// Run following command to build this file.
//// $ g++ `mecab-config --cflags` `mecab-config --libs` -Os mecab.cpp
//
//#include <iostream>
//#include <mecab/mecab.h>
//
//#include "croc.cpp";
//
//static void generateQueriesHelper(
//    const MeCab::Node* node)
//{
//
//
//    //QList<MeCabPair>* queries = new QList<MeCabPair>;
//    while (node)
//    {
//        auto deconj = extractDeconjugation(node);
//        /*QString surface = extractSurface(node);
//        QString surfaceClean = extractCleanSurface(node);
//        if (deconj != "*")
//        {
//            MeCabPair pair;
//            pair.deconj = deconj;
//            pair.surface = surface;
//            pair.surfaceClean = surfaceClean;
//            queries->append(pair);
//        }
//
//        if (node->next)
//        {
//            QList<MeCabPair>* subQueries = generateQueriesHelper(node->next);
//            for (MeCabPair& p : *subQueries)
//            {
//                p.deconj.prepend(surfaceClean);
//                p.surface.prepend(surface);
//                p.surfaceClean.prepend(surfaceClean);
//                queries->append(p);
//            }
//            delete subQueries;
//        }
//
//        node = node->bnext;*/
//    }
//    //return queries;
//
//}
//
//int main(int argc, char** argv) {
//
//
//
//    const MeCab::Node* node = MeCab::createTagger("")->parseToNode("隣の客はよく柿食う客だ。");
//    for (; node; node = node->next) {
//
//
//            auto k = node->feature;
//            int f = 0;
//
//    }
//
//    auto m_tagger = MeCab::createTagger("");
//
//    icu::UnicodeString mega = "隣の客はよく柿食う客だ";
//
//    auto k = u8"隣の客はよく柿食う客だ";
//
//    //byte hello[10] = "隣の客はよく柿食う客";
//
//    //hello = "隣の客はよく柿食う客";
//
//    /* Lemmatize the query */
//    MeCab::Lattice* lattice = MeCab::createLattice();
//    const char* queryArr = "hello";
//    //const char* queryArr = "隣の客はよく柿食う客だ";
//    lattice->set_sentence(queryArr);
//    if (!m_tagger->parse(lattice))
//    {
//        std::cout << "Cannot access MeCab";
//    }
//
//    generateQueriesHelper(lattice->bos_node()->next);
//
//    
//
//    /* Generate queries */
//    //QList<MeCabPair>* unfiltered =
//    //    generateQueriesHelper(lattice->bos_node()->next);
//    //QSet<QString> duplicates;
//    //for (const MeCabPair& p : *unfiltered)
//    //{
//    //    if (query.startsWith(p.deconj) || duplicates.contains(p.deconj))
//    //    {
//    //        continue;
//    //    }
//    //    queries << p;
//    //    duplicates << p.deconj;
//    //}
//
//
//
//
//
//
//
//
//
//
//    //const MeCab::Node* node = MeCab::createTagger("")->parseToNode("隣の客はよく柿食う客だ。");
//    //for (; node; node = node->next) {
//    //    switch (node->stat) {
//    //    case MECAB_BOS_NODE:
//    //    case MECAB_EOS_NODE:
//    //        continue;
//
//    //    default:
//    //        std::cout
//    //            << node->feature
//    //            //        << ' ' << (int)(node->surface - input)
//    //            //        << ' ' << (int)(node->surface - input + node->length)
//    //            //        << ' ' << node->rcAttr
//    //            //        << ' ' << node->lcAttr
//    //            //        << ' ' << node->posid
//    //            //        << ' ' << (int)node->char_type
//    //            //        << ' ' << (int)node->stat
//    //            //        << ' ' << (int)node->isbest
//    //            //        << ' ' << node->alpha
//    //            //        << ' ' << node->beta
//    //            //        << ' ' << node->prob
//    //            //        << ' ' << node->cost
//    //            << std::endl;
//    //    }
//    //}
//    return 0;
//}