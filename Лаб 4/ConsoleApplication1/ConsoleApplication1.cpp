// Ломбард. База хранимых товаров и недвижимости: фамилия клиента, наименование товара, оценочная стоимость;
//сумма, выданная под залог, дата сдачи, срок хранения. Выбор по наименованию товара. 

//В программу должны войти функции:
//	ввод элементов структуры с клавиатуры;
//  вывод элементов структуры в консольное окно;
//	удаление заданной структурированной переменной;
//	поиск информации;
//	запись информации в файл;
//	чтение данных из файла.

# include <iostream> 
#include <iostream>
#include <fstream>
#include <string>
# define str_len 30                               
# define size 30  
int choice;
using namespace std;

int current_year = 2023;
int current_y = 2023;
int current_m = 2;
int current_d = 14;

typedef struct Lombard
{
	char nameclient[str_len];
	char nametovar[40];
	float ocenka;
	float summa;
	int god;
	int hranenie;

} STUD;

int number; FILE* f; errno_t err;

struct Lombard lomb[size];
struct Lombard bad;

int current_size = 0;
void enter_new()
{
	cout << "\n======================================" << endl;
	cout << "\nВвод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Фамилия: " << endl;
		cin >> lomb[current_size].nameclient;
		cout << endl << "Название товара: " << endl;
		cin.get();
		cin.getline(lomb[current_size].nametovar, 50);
		cout << endl << "Оценочная стоимость: " << endl;
		cin >> lomb[current_size].ocenka;
		cout << endl << "Сумма, выданная под залог: " << endl;
		cin >> lomb[current_size].summa;
		int is_correct_inspection_date = 0;
		do {
			string temp_str_y;
			cout << endl << "Дата сдачи(ДДММГГГГ): " << endl;
			cin >> lomb[current_size].god;

			int day, month, year;
			year = lomb[current_size].god % 10000;
			month = (lomb[current_size].god % 1000000 - year) / 10000;
			day = lomb[current_size].god / 1000000;

			if (year == current_y)
				is_correct_inspection_date = 2;
			if (year < current_y)
				is_correct_inspection_date = 1;
			if (is_correct_inspection_date == 2) {
				if (month > current_m)
					is_correct_inspection_date = 0;
				else if (month == current_m)
					is_correct_inspection_date = 2;
				else if (month < current_m)
					is_correct_inspection_date = 1;
				else if (month > 12)
					is_correct_inspection_date = 0;
			}
			if (is_correct_inspection_date == 2) {
				if (day > current_d)
					is_correct_inspection_date = 0;
				else if (day <= current_d)
					is_correct_inspection_date = 1;
				else if (day > 31)
					is_correct_inspection_date = 0;
			}
			if (month > 12 or day > 31)
				is_correct_inspection_date = 0;
			if (is_correct_inspection_date == 0)
				cout << "Некорректные данные" << endl;
		} while (is_correct_inspection_date == 0);

		cout << endl << "Срок хранения(недели): " << endl;
		cin >> lomb[current_size].hranenie;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "\n======================================" << endl;
}
void ofile()
{
	int N = 10;

	ofstream file1("information.txt");
	for (int i = 0; i < current_size; i++) {
		file1 << "\tКлиент №" << i + 1 << '\n';

		file1 << "Фамилия клиента: ";
		file1 << lomb[i].nameclient << "\n";

		file1 << "Название товара: ";
		file1 << lomb[i].nametovar << "\n";

		file1 << "Оценочная стоимость: ";
		file1 << lomb[i].ocenka << "\n";

		file1 << "Сумма, выданная под золг: ";
		file1 << lomb[i].summa << endl;

		file1 << "Дата сдачи: ";
		file1 << lomb[i].god << endl;

		file1 << "Срок хранения(недели): ";
		file1 << lomb[i].hranenie << endl << endl << endl;
	}
	cout << "Данные запсианы в файл" << endl;
	cout << "\n======================================" << endl<<endl;

}
void ifile()
{
	string strInf;
	ifstream file1("information.txt");
	cout << "\n======================================" << endl;
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
	}
	cout << "\n======================================" << endl;
}
void del()
{
	int d;
	cout << "\n======================================" << endl;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			lomb[de1] = lomb[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			lomb[i] = bad;
	cout << "\n======================================" << endl;
}


void outputOneStructure(Lombard oneGorozhanin)
{
	cout << "Фамилия клиента: ";
	cout << oneGorozhanin.nameclient << endl;
	cout << "Название:  ";
	cout << oneGorozhanin.nametovar << endl;
	cout << "Оценочная стоимость: ";
	cout << oneGorozhanin.ocenka << endl;
	cout << "Сумма, выданная под залог: ";
	cout << oneGorozhanin.summa << endl;
	cout << "Дата выдачи(г.): ";
	cout << oneGorozhanin.god << endl;
	cout << "Срок хранения(недели): ";
	cout << oneGorozhanin.hranenie << endl;
}


void out()
{
	int sw, n;
	cout << "\n======================================" << endl;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		outputOneStructure(lomb[n - 1]);
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			outputOneStructure(lomb[i]);
		}
	}
	cout << "\n======================================" << endl;
}
void search()
{
	char year_for_search[50];
	cout << "\n======================================" << endl;
	cout << "Введите навание товара для поиска" << endl;
	cin.get();
	cin.getline(year_for_search, 50);
	cout << endl;;
	int amount = 0;

	printf("Результат:\n");
	for (int i = 0; i < size; i++)
	{

		if (strcmp(year_for_search, lomb[i].nametovar) == 0)
		{
			amount++;
			outputOneStructure(lomb[i]);
		}

	}
	printf("Всего найдено:%d\n\n", amount);

	cout << "\n======================================" << endl;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Данных нет" << endl;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для удаления записи" << endl;
		cout << "2-для ввода новой записи" << endl;
		cout << "3-для поиска по названию товара" << endl;
		cout << "4-для вывода записи(ей)" << endl;
		cout << "5-для ввода в файл" << endl;
		cout << "6-для вывода из файла" << endl;
		cout << "7-для выхода" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3: search(); break;
		case 4:  out();	break;
		case 5: ofile();	break;
		case 6: ifile();	break;
		}
	} while (choice != 7);
}