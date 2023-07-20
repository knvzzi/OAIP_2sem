#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void printList() {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertNode() {
    int value;
    cout << "Введите значение элемента: ";
    cin >> value;
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void deleteNode() {
    int value;
    cout << "Введите значение элемента: ";
    cin >> value;
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            delete current;
            cout << "Элемент удален." << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Элемент не найден." << endl;
}

void searchNode() {
    int value;
    cout << "Введите значение элемента: ";
    cin >> value;
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            cout << "Элемент найден." << endl;
            cout << value << endl;
            return;
        }
        current = current->next;
    }
    cout << "Элемент не найден." << endl;
}

void saveList() {
    ofstream outFile("list.txt");
    Node* current = head;
    while (current != NULL) {
        outFile << current->data << endl;
        current = current->next;
    }
    outFile.close();
    cout << "Список сохранен в файле." << endl;
}

void loadList() {
    ifstream inFile("list.txt");
    int value;
    while (inFile >> value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << ' ';
    }
    cout << endl;
    inFile.close();
    cout << "Список загружен из файла." << endl;
}

void sumTwoDigitPositive() {
    int sum = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data > 9 && current->data < 100 && current->data > 0) {
            sum += current->data;
        }
        current = current->next;
    }
    if (sum > 0) {
        cout << "Сумма положительных двузначных элементов: " << sum << endl;
    }
    else {
        cout << "Нет положительных двузначных элементов." << endl;
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");
    int choice;
    do {
        cout << "1. Добавить элемент" << endl;
        cout << "2. Найти элемент" << endl;
        cout << "3. Найти сумму положительных двузначных элементов" << endl;
        cout << "4. Удалить элемент" << endl;
        cout << "5. Вывести список" << endl;
        cout << "6. Сохранить список в файл  " << endl;
        cout << "7. Считать список из файла" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1:
            insertNode();
            break;
        case 2:
            searchNode();
            break;
        case 3:
            sumTwoDigitPositive();
            break;
        case 4:
            deleteNode();
            break;
        case 5:
            printList();
            break;
        case 6:
            saveList();
            break;
        case 7:
            loadList();
            break;
        case 0:
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
    } while (choice != 0);

    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;

    return 0;
}
