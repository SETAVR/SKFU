#include "dictionary.h"
#include <locale.h>  // Добавляем для setlocale
#include <stdlib.h>  // Добавляем для system

int main() {
    // Настройка локали и кодовой страницы
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");

    DictionaryUI ui;
    ui.run();
    return 0;
}
