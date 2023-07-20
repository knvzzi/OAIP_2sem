#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Скопировать из файла FILE1 в файл FILE2 строки, начиная с четвертой по порядку.
//Подсчитать количе-ство символов в последнем слове FILE2.

int main()
{
	setlocale(0, "rus");

	char buff1[50];
	int n, numb=0;

	cout << "Введите колличество строк: ";
	cin >> n;

	ofstream FILE1("FILE1.txt");

	char str[50];

	cin.ignore();

	for (int i = 1; i <= n; i++)
	{
		cout << "Строка " << i << "\n";
		
		cin.getline(str, 50, '\n');
		FILE1 << str;
		FILE1 << "\n";
		
	}

	FILE1.close();

	cout << "\n==============================\n";

	ofstream FILE2("FILE2.txt");   
	ifstream FILE11("FILE1.txt");

	if (!FILE11.is_open())
		cout << "Файл не может быть открыт!\n\n";
	else
	{
		for (int i = 0; i < 3; i++)
		{
			FILE11.getline(buff1, 50, '\n');
		}
		for (int i = 3; i < n-1; i++)
		{
			FILE11.getline(buff1, 50, '\n');
			FILE2 << buff1;
			FILE2 << "\n";
			cout << buff1 << "\n\n";
		}
		for (int i = n - 1; i < n; i++)
		{

			FILE11.getline(buff1, 50);
			int k = strlen(buff1);

			while (buff1[k-1] != ' ' && k != 0)
			{
				numb++;
				k--;
			}
			FILE2 << buff1;
			cout << buff1 << "\n\n";

			cout << "Количество символов в последней строке равно " << numb;
		}
	}
	FILE1.close();
	FILE2.close();

	return 0;
}