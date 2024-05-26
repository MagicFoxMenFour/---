#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <map>
#include <vector>

class Dictionary {
private:
    std::map<std::string, std::string> engToRus;
    std::map<std::string, std::string> rusToEng;
    const std::string engToRusFile = "eng_to_rus.txt";
    const std::string rusToEngFile = "rus_to_eng.txt";

    void loadFromFile();
    void saveToFile();
    std::string toLower(const std::string& str);

public:
    Dictionary();
    ~Dictionary();
    void addWord(const std::string& english, const std::string& russian);
    void deleteWord(const std::string& english);
    std::string translateToRussian(const std::string& english);
    std::string translateToEnglish(const std::string& russian);
    std::vector<std::string> suggestWords(const std::string& prefix, bool englishToRussian);
};

#endif
