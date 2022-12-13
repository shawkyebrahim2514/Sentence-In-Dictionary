#ifndef SENTENCEINDICTIONARY_SENTENCEINDICTIONARY_H
#define SENTENCEINDICTIONARY_SENTENCEINDICTIONARY_H

#include <iostream>
#include <fstream>
#include <set>
#include <vector>

class SentenceInDictionary {
    void printFormulatedSentence(std::vector<std::string>& separatedWords);
public:
    bool separateSentence(std::set<std::string>& dictionaryWords, std::string& sentence,
                          std::vector<std::string> separatedWords, std::string currentWord, int currentPosition);
    void takeSentence(std::set<std::string>& dictionaryWords);
};

#endif