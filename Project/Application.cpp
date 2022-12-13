#include "Application.h"

void Application::run() {
    SentenceInDictionary sentenceObject;
    sentenceObject.takeSentence(this->dictionaryWords);
    if(runAgain()) run();
}

void Application::loadDictionary() {
    std::string fileName, word;
    std::ifstream dictionaryFile(fileName + ".txt");
    while (fileName.empty() || !dictionaryFile.is_open()){
        std::cout << "Enter the file name of the dictionary words: ";
        std::cin >> fileName;
        dictionaryFile.open(fileName + ".txt");
    }
    while (dictionaryFile >> word){
        this->dictionaryWords.insert(word);
    }
}

Application::Application() {
    this->loadDictionary();
}

bool Application::runAgain() {
    std::string input;
    std::cout << "Do you want to enter more sentence? y(yes), n(no)\n";
    std::cin >> input;
    if(input == "y" || input == "yes") return true;
    else return false;
}
