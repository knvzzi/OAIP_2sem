#include <iostream>
#include "stack.h"

using namespace std;

void printMenu() {
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Top" << endl;
    cout << "4. Is empty" << endl;
    cout << "5. Clear" << endl;
    cout << "6. Save to file" << endl;
    cout << "7. Read from file" << endl;
    cout << "8. Form new stack" << endl;
    cout << "0. Exit" << endl;
}

int main() {
    Stack stack;
    Stack stack1;
    Stack stack2;

    int choice = -1;
    while (choice != 0) {
        printMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        }
        case 2: {
            int value = stack.pop();
            if (value != -1) {
                cout << "Popped value: " << value << endl;
            }
            break;
        }
        case 3: {
            int value = stack.top();
            if (value != -1) {
                cout << "Top value: " << value << endl;
            }
            break;
        }
        case 4: {
            if (stack.isEmpty()) {
                cout << "Stack is empty." << endl;
            }
            else {
                cout << "Stack is not empty." << endl;
            }
            break;
        }
        case 5: {
            stack.clear();
            cout << "Stack cleared." << endl;
            break;
        }
        case 6: {
            string filename;
            cout << "Enter filename to save to: ";
            cin >> filename;
            stack.saveToFile(filename);
            break;
        }
        case 7: {
            string filename;
            cout << "Enter filename to read from: ";
            cin >> filename;
            stack.readFromFile(filename);
            cout << "Stack read from file." << endl;
            break;
        }
        case 8: {
            while (!stack1.isEmpty()) {
                int value = stack1.pop();
                if (!stack2.isEmpty() && stack2.top() == value) {
                    stack2.pop();
                }
                else {
                    stack.push(value);
                }
            }
            while (!stack2.isEmpty()) {
                int value = stack2.pop();
                stack.push(value);
            }
            cout << "New stack formed." << endl;
            break;
        }
        case 0: {
            cout << "Exiting..." << endl;
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
            break;
        }
        }
    }
    return 0;
}



