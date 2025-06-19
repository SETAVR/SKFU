#include "dictionary.h" // Подключаем наш заголовочный файл
#include <fstream>  // Для работы с файлами
#include <iostream> // Для ввода/вывода
#include <locale>   // Для поддержки русского языка

using namespace std; // Чтобы не писать std::

// Добавляет пару слов в оба словаря
void Dictionary::addPair(const string& eng, const string& rus) {
    addPairImpl(eng, rus); // Вызов protected-метода базового класса
}

// Загружает словарь из файла
bool Dictionary::loadFromFile(const string& filename) {
    // Очищаем старые данные
    engToRus.clear();
    rusToEng.clear();

    // Пытаемся открыть файл
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка: файл не найден!\n";
        return false;
    }

    // Читаем файл построчно
    string line;
    while (getline(file, line)) {
        // Ищем разделитель между словами
        size_t delimiter = line.find(':');
        if (delimiter != string::npos) {
            // Разделяем строку на английское и русское слово
            string eng = line.substr(0, delimiter);
            string rus = line.substr(delimiter + 1);

            // Добавляем пару в словарь
            addPair(eng, rus);
        }
    }

    file.close(); // Закрываем файл
    cout << "Словарь успешно загружен!\n";
    return true;
}

// Ищет перевод английского слова
vector<string> Dictionary::translateEng(const string& word) const {
    // Пытаемся найти слово в словаре
    auto it = engToRus.find(word);
    if (it == engToRus.end()) {
        cout << "Перевод не найден!\n";
        return {}; // Возвращаем пустой список
    }
    return it->second; // Возвращаем все варианты перевода
}

// Ищет перевод русского слова (работает аналогично)
vector<string> Dictionary::translateRus(const string& word) const {
    auto it = rusToEng.find(word);
    if (it == rusToEng.end()) {
        cout << "Перевод не найден!\n";
        return {};
    }
    return it->second;
}

// Показывает меню пользователю
void DictionaryUI::showMenu() const {
    cout << "\n=== Англо-русский словарь ===\n";
    cout << "1. Загрузить словарь\n";
    cout << "2. Англо-русский перевод\n";
    cout << "3. Русско-английский перевод\n";
    cout << "4. Выход\n";
    cout << "Выберите действие: ";
}

// Обрабатывает выбор пользователя
void DictionaryUI::processChoice(int choice) {
    switch (choice) {
    case 1: { // Загрузка словаря
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        dictionaryLoaded = dictionary.loadFromFile(filename);
        break;
    }
    case 2: { // Англо-русский перевод
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
    case 3: { // Русско-английский перевод (аналогично)
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
    case 4: // Выход
        exit(0); // Завершение программы
    default: // Неправильный ввод
        cout << "Неверный выбор!\n";
    }
}

// Главный цикл программы
void DictionaryUI::run() {
    // Настраиваем консоль для русского языка
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul"); // Устанавливаем кодировку

    // Бесконечный цикл работы программы
    while (true) {
        showMenu(); // Показываем меню
        int choice;
        cin >> choice; // Читаем выбор пользователя
        processChoice(choice); // Выполняем выбранное действие
    }
}

