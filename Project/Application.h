#ifndef SENTENCEINDICTIONARY_APPLICATION_H
#define SENTENCEINDICTIONARY_APPLICATION_H

#include "SentenceInDictionary.h"

class Application {
    std::set<std::string> dictionaryWords;
    void loadDictionary();
    bool runAgain();
    void printSeparator(const std::string& paragraph);
public:
    Application();
    void run();
};

#endif