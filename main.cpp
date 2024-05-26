#include <iostream>
#include "Dictionary.h"
#include <vector>

int main() {
    Dictionary dict;

    int choice;
    std::string word, translation;
    std::vector<std::string> suggestions;

    while (true) {
        std::cout << "1. Add word\n";
        std::cout << "2. Delete word\n";
        std::cout << "3. Translate English to Russian\n";
        std::cout << "4. Translate Russian to English\n";
        std::cout << "5. Suggest words (English)\n";
        std::cout << "6. Suggest words (Russian)\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter English word: ";
            std::cin >> word;
            std::cout << "Enter Russian translation: ";
            std::cin >> translation;
            dict.addWord(word, translation);
            break;
        case 2:
            std::cout << "Enter English word to delete: ";
            std::cin >> word;
            dict.deleteWord(word);
            break;
        case 3:
            std::cout << "Enter English word: ";
            std::cin >> word;
            std::cout << "Translation: " << dict.translateToRussian(word) << std::endl;
            break;
        case 4:
            std::cout << "Enter Russian word: ";
            std::cin >> word;
            std::cout << "Translation: " << dict.translateToEnglish(word) << std::endl;
            break;
        case 5:
            std::cout << "Enter English prefix: ";
            std::cin >> word;
            suggestions = dict.suggestWords(word, true);
            std::cout << "Suggestions: ";
            for (const auto& suggestion : suggestions) {
                std::cout << suggestion << " ";
            }
            std::cout << std::endl;
            break;
        case 6:
            std::cout << "Enter Russian prefix: ";
            std::cin >> word;
            suggestions = dict.suggestWords(word, false);
            std::cout << "Suggestions: ";
            for (const auto& suggestion : suggestions) {
                std::cout << suggestion << " ";
            }
            std::cout << std::endl;
            break;
        case 7:
            return 0;
        default:
            std::cout << "Invalid option. Try again." << std::endl;
        }
    }

    return 0;
}
