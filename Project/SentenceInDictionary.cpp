#include "SentenceInDictionary.h"

bool SentenceInDictionary::separateSentence(std::set<std::string> &dictionaryWords, std::string &sentence,
                                            std::vector<std::string> separatedWords, std::string currentWord,
                                            int currentPosition) {
    if (currentPosition >= sentence.size()) {
        if (dictionaryWords.count(currentWord)) {
            separatedWords.push_back(currentWord);
            this->printFormulatedSentence(separatedWords);
            return true;
        } else return false;
    }
    bool result = false;
    if (dictionaryWords.count(currentWord)) {
        separatedWords.push_back(currentWord);
        result |= separateSentence(dictionaryWords, sentence, separatedWords, "", currentPosition);
        separatedWords.pop_back();
    }
    currentWord.push_back(sentence[currentPosition]);
    result |= separateSentence(dictionaryWords, sentence, separatedWords, currentWord,
                               currentPosition + 1);
    return result;
}

void SentenceInDictionary::takeSentence(std::set<std::string> &dictionaryWords) {
    std::cout << "Enter sentence: ";
    std::string sentence;
    std::cin >> sentence;
    std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
    bool isSentenceValid = separateSentence(dictionaryWords, sentence, {}, "",
                                            0);
    if (!isSentenceValid) {
        std::cout << "This sentence cannot be formed from words that are in the dictionary\n";
    }
}

void SentenceInDictionary::printFormulatedSentence(std::vector<std::string> &separatedWords) {
    for (auto &word: separatedWords) std::cout << word << ' ';
    std::cout << '\n';
}
