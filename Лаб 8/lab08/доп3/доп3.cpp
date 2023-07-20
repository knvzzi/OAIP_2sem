#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    string input_file = "input.txt";
    string output_file = "output.txt";
    ifstream fin(input_file);
    ofstream fout(output_file);

    if (!fin.is_open()) {
        cout << "Ошибка открытия входного файла" << endl;
        return 1;
    }
    if (!fout.is_open()) {
        cout << "Ошибка открытия выходного файла" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        queue<char> chars;
        queue<char> digits;

        for (char c : line) {
            if (isdigit(c)) {
                digits.push(c);
            }
            else {
                chars.push(c);
            }
        }

        while (!chars.empty()) {
            fout << chars.front();
            chars.pop();
        }
        while (!digits.empty()) {
            fout << digits.front();
            digits.pop();
        }
        fout << endl;
    }

    fin.close();
    fout.close();

    cout << "Программа завершила работу" << endl;
    return 0;
}
