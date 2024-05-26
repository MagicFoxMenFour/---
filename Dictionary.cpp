#include "Dictionary.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

Dictionary::Dictionary() {
    loadFromFile();
}

Dictionary::~Dictionary() {
    saveToFile();
}

void Dictionary::loadFromFile() {
    std::ifstream inFile;
    std::string key, value;

    inFile.open(engToRusFile);
    if (inFile.is_open()) {
        while (inFile >> key >> value) {
            engToRus[toLower(key)] = value;
        }
        inFile.close();
    }

    inFile.open(rusToEngFile);
    if (inFile.is_open()) {
        while (inFile >> key >> value) {
            rusToEng[toLower(key)] = value;
        }
        inFile.close();
    }
}

void Dictionary::saveToFile() {
    std::ofstream outFile;

    outFile.open(engToRusFile);
    if (outFile.is_open()) {
        for (const auto& pair : engToRus) {
            outFile << pair.first << " " << pair.second << "\n";
        }
        outFile.close();
    }

    outFile.open(rusToEngFile);
    if (outFile.is_open()) {
        for (const auto& pair : rusToEng) {
            outFile << pair.first << " " << pair.second << "\n";
        }
        outFile.close();
    }
}

std::string Dictionary::toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void Dictionary::addWord(const std::string& english, const std::string& russian) {
    std::string lowerEnglish = toLower(english);
    std::string lowerRussian = toLower(russian);
    engToRus[lowerEnglish] = russian;
    rusToEng[lowerRussian] = english;
}

void Dictionary::deleteWord(const std::string& english) {
    std::string lowerEnglish = toLower(english);
    auto it = engToRus.find(lowerEnglish);
    if (it != engToRus.end()) {
        rusToEng.erase(toLower(it->second));
        engToRus.erase(it);
    }
}

std::string Dictionary::translateToRussian(const std::string& english) {
    std::string lowerEnglish = toLower(english);
    auto it = engToRus.find(lowerEnglish);
    if (it != engToRus.end()) {
        return it->second;
    }
    else {
        return "Translation not found";
    }
}

std::string Dictionary::translateToEnglish(const std::string& russian) {
    std::string lowerRussian = toLower(russian);
    auto it = rusToEng.find(lowerRussian);
    if (it != rusToEng.end()) {
        return it->second;
    }
    else {
        return "Translation not found";
    }
}

std::vector<std::string> Dictionary::suggestWords(const std::string& prefix, bool englishToRussian) {
    std::vector<std::string> suggestions;
    std::string lowerPrefix = toLower(prefix);

    if (englishToRussian) {
        for (const auto& pair : engToRus) {
            if (pair.first.find(lowerPrefix) == 0) {
                suggestions.push_back(pair.first);
            }
        }
    }
    else {
        for (const auto& pair : rusToEng) {
            if (pair.first.find(lowerPrefix) == 0) {
                suggestions.push_back(pair.first);
            }
        }
    }

    return suggestions;
}
