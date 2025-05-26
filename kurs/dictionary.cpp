#include "dictionary.h"
#include <fstream>
#include <iostream>
#include <locale>

using namespace std;

void Dictionary::addPair(const string& eng, const string& rus) {
    engToRus[eng].push_back(rus);
    rusToEng[rus].push_back(eng);
}

bool Dictionary::loadFromFile(const string& filename) {
    engToRus.clear();
    rusToEng.clear();

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка: файл не найден!\n";
        return false;
    }

    string line;
    while (getline(file, line)) {
        size_t delimiter = line.find(':');
        if (delimiter != string::npos) {
            string eng = line.substr(0, delimiter);
            string rus = line.substr(delimiter + 1);
            addPair(eng, rus);
        }
    }

    file.close();
    cout << "Словарь успешно загружен!\n";
    return true;
}

vector<string> Dictionary::translateEng(const string& word) const {
    auto it = engToRus.find(word);
    if (it == engToRus.end()) {
        cout << "Перевод не найден!\n";
        return {};
    }
    return it->second;
}

vector<string> Dictionary::translateRus(const string& word) const {
    auto it = rusToEng.find(word);
    if (it == rusToEng.end()) {
        cout << "Перевод не найден!\n";
        return {};
    }
    return it->second;
}

void DictionaryUI::showMenu() const {
    cout << "\n=== Англо-русский словарь ===\n";
    cout << "1. Загрузить словарь\n";
    cout << "2. Англо-русский перевод\n";
    cout << "3. Русско-английский перевод\n";
    cout << "4. Выход\n";
    cout << "Выберите действие: ";
}

void DictionaryUI::processChoice(int choice) {
    switch (choice) {
    case 1: {
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        dictionaryLoaded = dictionary.loadFromFile(filename);
        break;
    }
    case 2: {
        if (!dictionaryLoaded) {
            cout << "Сначала загрузите словарь!\n";
            break;
        }
        string word;
        cout << "Введите английское слово: ";
        cin >> word;
        auto translations = dictionary.translateEng(word);
        if (!translations.empty()) {
            cout << "Перевод: ";
            for (const auto& trans : translations) {
                cout << trans << " ";
            }
            cout << endl;
        }
        break;
    }
    case 3: {
        if (!dictionaryLoaded) {
            cout << "Сначала загрузите словарь!\n";
            break;
        }
        string word;
        cout << "Введите русское слово: ";
        cin >> word;
        auto translations = dictionary.translateRus(word);
        if (!translations.empty()) {
            cout << "Перевод: ";
            for (const auto& trans : translations) {
                cout << trans << " ";
            }
            cout << endl;
        }
        break;
    }
    case 4:
        exit(0);
    default:
        cout << "Неверный выбор!\n";
    }
}

void DictionaryUI::run() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");

    while (true) {
        showMenu();
        int choice;
        cin >> choice;
        processChoice(choice);
    }
}
