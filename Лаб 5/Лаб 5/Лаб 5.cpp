#include <iostream>
#include <string>
using namespace std;
// ==========================================  ОСНОВА 1  ==========================================

#define len 30 
#define records 30
# define size 30

int main();
void add31();
void del31();
void show31();
void search31();

int decision31;
int current_year = 2023;


enum origin {
	purchase = 1, theft, gift
} orig;

struct library {
	unsigned int year : 12;
	string author;
	string title;
	string press;
	string rasdel;
	string availability;
	origin orig;
	
} Book[records], zeroo;

int codow31 = 0;

void dop31() {
	setlocale(LC_CTYPE, "Russian");
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision31;
	do {
		switch (decision31) {
		case 1: add31(); break;
		case 2: del31(); break;
		case 3: show31(); break;
		case 4: search31(); break;
		case 5: main(); break;
		}
	} while (decision31 != 5);
}

void add31() {
	setlocale(LC_CTYPE, "Russian");
	int o, t;
	orig = purchase;
	if (codow31 < records) {
		cout << "Автор - ";
		cin.get();
		getline(cin, Book[codow31].author);
		cout << "Название - ";
		cin.get();
		getline(cin, Book[codow31].title);
		cout << "Издательство: ";
		cin.get();
		getline(cin, Book[codow31].press);
		do {
			cout << "Раздел библиотеки (специальная литература - 1, хобби - 2, домашнее хозяйство - 3, беллетристика - 4) - ";
			cin >> Book[codow31].rasdel;
		} while (Book[codow31].rasdel != "1" && Book[codow31].rasdel != "2" && Book[codow31].rasdel != "3" && Book[codow31].rasdel != "4");
		cout << "Наличие - ";
		cin.get();
		getline(cin, Book[codow31].availability);
		do {
			cout << "Происхождение (Покупка - 1, кража - 2, подарок - 3) - ";
			cin >> o;
		} while (o != 1 && o != 2 && o != 3);
		t = (int)orig - o;
		if (t == 0) {
			Book[codow31].orig = purchase;
		}
		else if (t == 1) {
			Book[codow31].orig = theft;
		}
		else {
			Book[codow31].orig = gift;
		}

		bool is_correct_year = false;
		do {
			cout << "Введите год издательства: ";
			int year;
			cin >> year;
			Book[codow31].year = year;
			if (Book[codow31].year <= current_year)
				is_correct_year = true;
			else
				cout << "Incorrect input" << endl;
		} while (is_correct_year == false);


		codow31++;
	}
	else {
		cout << "Вы ввели максимальное количество записей";
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision31;
	cout << endl;
}

void del31()
{
	int purge = 1;
	setlocale(LC_CTYPE, "Russian");
	for (int de = (purge - 1); de < codow31; de++)
		Book[de] = Book[de + 1];
	codow31 = codow31 - 1;
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision31;
	cout <<"Строка удалена" << endl;
}

void show31() {
	setlocale(LC_CTYPE, "Russian");
	for (int i = 0; i < codow31; i++)
	{
		cout << "Автор - ";
		cout << Book[i].author << endl;
		cout << "Название - ";
		cout << Book[i].title << endl;
		cout << "Издательство - ";
		cout << Book[i].press << endl;
		cout << "Раздел библиотеки - ";
		if (Book[i].rasdel == "1") cout << "специальная литература\n";
		if (Book[i].rasdel == "2") cout << "хобби\n";
		if (Book[i].rasdel == "3") cout << "домашнее хозяйство\n";
		if (Book[i].rasdel == "4") cout << "беллетристика\n";
		cout << "Наличие - ";
		cout << Book[i].availability << endl;
		cout << "Происхождение - ";
		if (Book[i].orig == purchase) cout << "покупка\n";
		else if (Book[i].orig == theft) cout << "кража\n";
		else if (Book[i].orig == gift) cout << "подарок\n";
		cout << "Год издательства: ";
		cout << Book[i].year << endl;
		cout << "\n====================================================\n";
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision31;
	cout << endl;
}

void search31() {
	setlocale(LC_CTYPE, "Russian");
	int yo;
	cout << "Введите год, по которому следует осуществить поиск - ";
	cin >> yo;
	for (int i = 0; i < codow31; i++) {
		if (yo == Book[i].year) {
			cout << "Автор - ";
			cout << Book[i].author << endl;
			cout << "Название - ";
			cout << Book[i].title << endl;
			cout << "Издательство - ";
			cout << Book[i].press << endl;
			cout << "Раздел библиотеки - ";
			if (Book[i].rasdel == "1") cout << "специальная литература\n";
			if (Book[i].rasdel == "2") cout << "хобби\n";
			if (Book[i].rasdel == "3") cout << "домашнее хозяйство\n";
			if (Book[i].rasdel == "4") cout << "беллетристика\n";
			cout << "Наличие - ";
			cout << Book[i].availability << endl;
			cout << "Происхождение - ";
			if (Book[i].orig == purchase) cout << "покупка\n";
			else if (Book[i].orig == theft) cout << "кража\n";
			else if (Book[i].orig == gift) cout << "подарок\n";
			cout << "Год издательства: ";
			cout << Book[i].year << endl;
		}
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision31;
	cout << endl;
}




// ==========================================  ОСНОВА 2  ==========================================

void add32();
void del32();
void show32();
void search32();

int decision32;


enum origin32 {
	purchase32 = 1, theft32, gift32
} orig32;

struct library32 {
	string author;
	string title;
	string press;
	string rasdel;
	string availability;
	origin orig;
	int year;
} book[records], zero32;

struct library32 bad;

union un_library {
	char author[len];
	char title[len];
	char press[len];
	char rasdel[len];
	char availability[len];
	origin orig[len];
	int year;
} un_book;

int codow32 = 0;

void dop32() {
	setlocale(LC_ALL, "russian");
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по автору;\n5 — выход.\n";
	cin >> decision32;
	do {
		switch (decision32) {
		case 1: add32(); break;
		case 2: del32(); break;
		case 3: show32(); break;
		case 4: search32(); break;
		case 5: main(); break;
		}
	} while (decision32 != 5);
}

void add32() {
	setlocale(LC_ALL, "russian");
	int o, t;
	orig32 = purchase32;
	if (codow32 < records) {
		cout << "Автор - ";
		cin.get();
		cin.getline(un_book.author, len);
		book[codow32].author = un_book.author;
		cout << "Название - ";
		cin.get();
		cin.getline(un_book.title, len);
		book[codow32].title = un_book.title;
		cout << "Издательство: ";
		cin.get();
		cin.getline(un_book.press, len);
		book[codow32].press = un_book.press;
		do {
			cout << "Раздел библиотеки (специальная литература - 1, хобби - 2, домашнее хозяйство - 3, беллетристика - 4) - ";
			cin >> un_book.rasdel;
			book[codow32].rasdel = un_book.rasdel;
		} while (book[codow32].rasdel != "1" && book[codow32].rasdel != "2" && book[codow32].rasdel != "3" && book[codow32].rasdel != "4");
		cout << "Наличие: ";
		cin.get();
		cin.getline(un_book.availability, len);
		book[codow32].availability = un_book.availability;
		do {
			cout << "Происхождение (покупка - 1, кража - 2, подарок - 3): ";
			cin >> o;
		} while (o != 1 && o != 2 && o != 3);
		t = (int)orig - o;
		if (t == 0) {
			book[codow32].orig = purchase;
		}
		else if (t == 1) {
			book[codow32].orig = theft;
		}
		else {
			book[codow32].orig = gift;
		}

		bool is_correct_year = false;
		do {
			cout << "Год издательства: ";
			cin >> un_book.year;
			book[codow32].year = un_book.year;
			if (book[codow32].year <= current_year)
				is_correct_year = true;
			else
				cout << "Incorrect input" << endl;
		} while (is_correct_year == false);

		codow32++;
	}
	else {
		cout << "Вы ввели максимальное количество записей";
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск автору;\n5 — выход.\n";
	cin >> decision32;
	cout << endl;
}

void del32()
{
	setlocale(LC_ALL, "russian");
	int purge = 1;
	for (int de = (purge - 1); de < codow32; de++)
		book[de] = book[de + 1];
	codow32 = codow32 - 1;
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск по году издательства;\n5 — выход.\n";
	cin >> decision32;
	cout << endl;
}


void outputOneStructure(library32 oneGorozhanin)
{
	cout << "Автор - ";
	cout << oneGorozhanin.author << endl;
	cout << "Название - ";
	cout << oneGorozhanin.title << endl;
	cout << "Издательство - ";
	cout << oneGorozhanin.press << endl;
	cout << "Раздел бибилиотеки - ";
	if (oneGorozhanin.rasdel == "1") cout << "специальная литература\n";
	else if (oneGorozhanin.rasdel == "2") cout << "хобби\n";
	else if (oneGorozhanin.rasdel == "3") cout << "домашнее хозяйство\n";
	else if (oneGorozhanin.rasdel == "4") cout << "беллетристика\n";
	cout << "Наличие - ";
	cout << oneGorozhanin.availability << endl;
	cout << "Происхождение - ";
	if (oneGorozhanin.orig == purchase) cout << "покупка\n";
	else if (oneGorozhanin.orig == theft) cout << "кража\n";
	else if (oneGorozhanin.orig == gift) cout << "подарок\n";
	cout << "Год издательства: ";
	cout << oneGorozhanin.year << endl;
}

void show32() {
	setlocale(LC_ALL, "russian");
	for (int i = 0; i < codow32; i++)
	{
		cout << "Автор - ";
		cout << book[i].author << endl;
		cout << "Название - ";
		cout << book[i].title << endl;
		cout << "Издательство - ";
		cout << book[i].press << endl;
		cout << "Раздел бибилиотеки - ";
		if (book[i].rasdel == "1") cout << "специальная литература\n";
		else if (book[i].rasdel == "2") cout << "хобби\n";
		else if (book[i].rasdel == "3") cout << "домашнее хозяйство\n";
		else if (book[i].rasdel == "4") cout << "беллетристика\n";
		cout << "Наличие - ";
		cout << book[i].availability << endl;
		cout << "Происхождение - ";
		if (book[i].orig == purchase) cout << "покупка\n";
		else if (book[i].orig == theft) cout << "кража\n";
		else if (book[i].orig == gift) cout << "подарок\n";
		cout << "Год издательства: ";
		cout << book[i].year << endl;
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск автору;\n5 — выход.\n";
	cin >> decision32;
	cout << endl;
}

void search32() {
	setlocale(LC_ALL, "russian");
	string yo;
	cout << "Введите автора, по которому нужно искать: ";
	cin >> yo;
	for (int i = 0; i < codow32; i++) 
	{
		if (yo.compare(book[i].author) == 0) {
			outputOneStructure(book[i]);
		}
	}
	cout << "\nВыберите, что сделать:\n1 — ввод информации;\n2 — удаление информации;\n3 — вывод информации;\n4 — поиск автору;\n5 — выход.\n";
	cin >> decision32;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	short choose;
	do {
		cout << "Выберите задание лабораторной:\n1 — Основа 1;\n2 — Основа 2;\n3 — завершение работы.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: dop31(); break;
		case 2: dop32(); break;
		case 3: cout << "---работа завершена---\n"; exit(0); break;
		}
	} while (choose != 3);
}


