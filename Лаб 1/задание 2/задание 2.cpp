﻿#include <iostream>
using namespace std;

int kvadr(int m, ...) //функция, считающая количество точных квадратов

{

	int* p = &m+1; // настраиваем указатель на параметр m

	int k = 0; //счетчик количества квадратов

	int kor; //переменная для хранения корня

	for (int i = 0; i < m; i++)

	{

		kor = sqrt(*(p+i)); //извлекаем корень из числа, записываем его без дробной части

		if (kor * kor == *(p+i)) k++; //возводим корень в квадрат, проверяем


	}

	return k;

}

int main()

{
	setlocale(0, "rus");

	int n1, n2, n3, n4, n5, n6;

	int N;
	cout << "Введите колличество повторений программы: ";
	cin >> N;
	cout << "\n============================================\n\n";

	int ch;
 
	do
	{
		cout << "Хотите выполнить программу? (1 - да, 2 - нет)\n";

		cin >> ch; //переменная для хранения кода выбора

		switch (ch)
		{
		case 1:
		{
			cout << "Введите числа:\t ";

			cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;

			cout << "Количество точных квадратов: " << kvadr(6, n1, n2, n3, n4, n5, n6)<<"\n";
			cout << "\n============================================\n\n";

			break;
		}

		case 2: break;
		default: cout << "Некорректный вариант"; break;
		}
		N--;
	} 
	while (N != 0);
}
