#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <map>

using namespace std;

// Базовый класс (добавляем в начало файла)
class BaseDictionary {
protected:
    map<string, vector<string>> engToRus;
    map<string, vector<string>> rusToEng;

    virtual void addPairImpl(const string& eng, const string& rus) {
        engToRus[eng].push_back(rus);
        rusToEng[rus].push_back(eng);
    }

public:
    virtual ~BaseDictionary() = default;
    virtual bool loadFromFile(const string& filename) = 0;
    virtual vector<string> translateEng(const string& word) const = 0;
    virtual vector<string> translateRus(const string& word) const = 0;
};

// Меняем объявление Dictionary (старый класс становится наследником)
class Dictionary : public BaseDictionary {
private:
    void addPair(const string& eng, const string& rus);

public:
    bool loadFromFile(const string& filename) override;
    vector<string> translateEng(const string& word) const override;
    vector<string> translateRus(const string& word) const override;
};


class DictionaryUI {
private:
    Dictionary dictionary; // Основной словарь
    bool dictionaryLoaded = false; // Проверка загрузки словаря

    // Показывает меню пользователю
    void showMenu() const;

    // Обрабатывает выбор пользователя
    void processChoice(int choice);

    // Перевод с английского
    void translateFromEnglish() const;

    // Перевод с русского
    void translateFromRussian() const;

public:
    // Главная функция - запускает программу
    void run();
};

#endif // Конец защиты файла

