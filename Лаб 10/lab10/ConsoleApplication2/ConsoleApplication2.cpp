#include <iostream>
using namespace std;

char getCharAtIndex(int n, string str) {
    // Проверяем, что n не выходит за пределы длины строки
    if (n >= str.length()) {
        cout << "Ошибка: индекс выходит за пределы строки!" << endl;
        return '\0';
    }

    // Получаем символ на n-ом месте в строке
    char symbol = str[n];

    // Применяем шаг 26: заменяем каждый символ на следующий в алфавите
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'z') {
            str[i] = 'a';
        }
        else {
            str[i]++;
        }
    }

    // Возвращаем символ на n-ом месте
    return symbol;
}

int main() {
    setlocale(LC_CTYPE, "rus");
    string str = "abcdefghijklmnopqrstuvwxyz"; // исходная строка
    int n;
    cout << "Введите номер символа: ";
    cin >> n;

    char symbol = getCharAtIndex(n, str);

    cout << "Символ на " << n << "-м месте: " << symbol << endl;

    return 0;
}
