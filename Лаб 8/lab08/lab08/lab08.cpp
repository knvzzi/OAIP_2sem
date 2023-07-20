#include <iostream>
#include "Queue.h"

//Создать очередь для символов и функции для ввода, вывода и удаления элементов очереди.
//Ввести символы с клавиатуры в очередь. 
//После введеня 5-го символа в ответ на каждый вводимый удалять по одному элементу из очереди. 

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    int maxSize;
    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    Queue queue(maxSize);
    char operation;

    do {
        cout << "\nВыберите операцию:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Удалить элемент\n";
        cout << "3. Показать элементы в очереди\n";
        cout << "0. Выйти\n\n";

        cout << "Операция: ";
        cin >> operation;

        switch (operation) {
        case '1': {
            char item;
            cout << "Введите символ для добавления в очередь: ";
            cin >> item;
            queue.enqueue(item);
            if (queue.size() >= 5) {
                queue.dequeue();
                cout << "Первый элемент удален из очереди\n";
            }
            break;
        }
        case '2': {
            if (queue.isEmpty()) {
                cout << "Очередь пуста\n";
            }
            else {
                char item = queue.dequeue();
                cout << "Элемент " << item << " удален из очереди\n";
            }
            break;
        }
        case '3': {
            if (queue.isEmpty()) {
                cout << "Очередь пуста\n";
            }
            else {
                queue.display();
            }
            break;
        }
        case '0': {
            cout << "Программа завершена\n";
            break;
        }
        default: {
            cout << "Неверная операция\n";
            break;
        }
        }
    } while (operation != '0');

    return 0;
}
