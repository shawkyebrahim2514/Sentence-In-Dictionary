#include "Application.h"

void Application::run() {
    SentenceInDictionary sentenceObject;
    printSeparator("");
    sentenceObject.takeSentence(this->dictionaryWords);
    printSeparator("");
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

void Application::printSeparator(const std::string &paragraph) {
    int width = 155;
    int part = width/2 - paragraph.size()/2;
    std::cout << std::string(part, '-') << paragraph << std::string(part, '-') << '\n';
}
