/*5	Разработать функцию, которая формирует стек Stack, включив в него по одному разу элементы, которые входят в стек Stack1, но не входят в стек Stack2.*/
#include"stack.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int choice, newEl;

	STACK* stack = new STACK;
	stack->head = NULL;


	while (true)
	{
		cout << "1 - добавить элемент в стек\n";
		cout << "2 - извлечь элемент из стека\n";
		cout << "3 - вывод стека на экран\n";
		cout << "4 - запись в файл\n";
		cout << "5 - вывод из файла\n";
		cout << "6 - очистка стека\n";
		cout << "7 - формирование стека Stack, в который включены элементы, входящие в стек Stack1, но не входящие в стек Stack2.\n";
		cout << "0 - выход\n";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			cout << "\n";
			cout << "Значение > "; cin >> newEl;
			AddEl(newEl, stack);
			cout << "\n";
			break;
		}

		case 2: {
			cout << TakeFromStack(stack) << endl;
			break;
		}

		case 3: {
			PrintStack(stack);
			break;
		}

		case 7: {
			std::stack<int> Stack1, Stack2, Stack3;

			Stack1.push(5);
			Stack1.push(2);
			Stack1.push(3);

			Stack2.push(2);
			Stack2.push(3);
			Stack2.push(4);

			fillStack(Stack3, Stack1, Stack2);

			cout << "Stack1: ";
			while (!Stack1.empty()) {
				cout << Stack1.top() << ' ';
				Stack1.pop();
			}
			cout << '\n';

			cout << "Stack2: ";
			while (!Stack2.empty()) {
				cout << Stack2.top() << ' ';
				Stack2.pop();
			}
			cout << '\n';

			cout << "Stack3: ";

			while (!Stack3.empty()) {
				cout << Stack3.top() << ' ';
				Stack3.pop();
			}

			cout << endl;
			break;
		}

		case 4: {
			ToFile(stack);
			break;
		}

		case 5: {
			FromFile(stack);
			break;
		}

		case 6: {
			clear(stack);
			cout << "\n\nСтек очищен!\n\n";
			break;
		}

		case 0: {
			exit(0);
			break;
		}
		}
	}
}

