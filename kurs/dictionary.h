#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Dictionary {
private:
    map<string, vector<string>> engToRus;
    map<string, vector<string>> rusToEng;

    void addPair(const string& eng, const string& rus);

public:
    bool loadFromFile(const string& filename);
    vector<string> translateEng(const string& word) const;
    vector<string> translateRus(const string& word) const;
};

class DictionaryUI {
private:
    Dictionary dictionary;
    bool dictionaryLoaded = false;

    void showMenu() const;
    void processChoice(int choice);
    void translateFromEnglish() const;
    void translateFromRussian() const;

public:
    void run();
};

#endif
