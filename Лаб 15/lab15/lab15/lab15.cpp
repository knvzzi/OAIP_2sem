#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <chrono>
#include <random>

using namespace std;

class hashTable {
public:
    struct hashNode {
        int year{};
        string name{};
        bool deleted = false;

        hashNode(int yr, string* nm)
            : year{ yr }, name{ *nm }
        {}

        hashNode* next{};
        friend hashTable;
    };

private:
    size_t m_length{};
    vector<hashNode*> m_data{};
    vector<int> primes = { 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 }; // Список простых чисел для универсального хэширования
    int primeIndex = 0; // Индекс для выбора простого числа для хэширования

    int hashIndex(int key) {
        int h = ((key * primes[primeIndex]) % m_length);
        primeIndex = (primeIndex + 1) % primes.size(); // Циклически перебирать простые числа
        return h;
    }

public:
    hashTable(size_t length) : m_length{ length } {
        m_data.resize(length);
    }

    void resize(size_t length) {
        m_length = length;
        m_data.resize(length);
    }

    void addhash(int year, string name) {
        int id = hashIndex(year);
        hashNode* p = m_data[id];
        if (!p) {
            m_data[id] = new hashNode{ year, &name };
            return;
        }

        while (p->next) p = p->next;
        p->next = new hashNode{ year, &name };
    }

    void deletehash(int year) {
        int id = hashIndex(year);
        hashNode* p = m_data[id];
        hashNode* prev = nullptr;

        while (p) {
            if (p->year == year && !p->deleted) {
                if (prev) {
                    prev->next = p->next;
                }
                else {
                    m_data[id] = p->next;
                }
                p->deleted = true;
                delete p;
                cout << "Deleted";
                return;
            }
            prev = p;
            p = p->next;
        }

        cout << "Error: not found.";
    }

    void searchhash(int year) {
        int id = hashIndex(year);
        hashNode* p = m_data[id];

        while (p) {
            if (p->year == year && !p->deleted) {
                cout << "Найден: " << p->name << " Хеш: " << id + 1 << endl;
                return;
            }
            p = p->next;
        }

        cout << "Error: not found.";
    }

    void outputtable() {
        int counter = 0;
        for (auto el : m_data) {
            counter++;
            if (!el)
                continue;

            cout << counter << " - " << el->year << " Название: " << el->name << endl;
            while ((el = el->next))
                cout << "<" << el->year << " Название: " << el->name << ">" << endl;
        }
    }
};

int menu() {
    int choice;
    cout << "\nПрайс-лист\n";
    cout << "1. Добавить элемент\n";
    cout << "2. Удалить элемент\n";
    cout << "3. Найти элемент\n";
    cout << "4. Вывести элементы\n";
    cout << "5. Выйти\n";
    cout << "Ваш выбор: ";
    cin >> choice;
    return choice;
}


int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "Выберите размер таблицы: 16 / 32 / 64 / 128 \n";
	size_t size;
	while (true) {
		cin >> size;
		if (size == 16 || size == 32 || size == 64 || size == 128)
			break;
		cout << "\nError: try again: ";
	}

	hashTable table = { size };

	for (;;) {
		int year;
		int choice = menu();

		if (choice < 0 || choice > 5) { cout << "error"; continue; }

		switch (choice) {
		case 1: {
			int year;
			cout << "\nЦена: ";
				cin >> year;
			
			cin.ignore();
			cout << "\nНавзание: ";
			string name;
			getline(cin, name);
			table.addhash(year, name);
			break;
		}
		case 2:
			cin >> year;
			table.deletehash(year);
			break;
        case 3: {
            cin >> year;
            auto start = chrono::high_resolution_clock::now();
            table.searchhash(year);
            auto end = chrono::high_resolution_clock::now();
            cout << "Время поиска: " << (chrono::duration_cast<chrono::nanoseconds>(end - start).count()) * 0.000000001 << " мс" << endl;
            break; }
		case 4:
			table.outputtable();
			break;
		case 5:
			return 0;
		}
	}
}