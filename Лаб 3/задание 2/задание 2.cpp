#include <iostream>
#include <string>
#include <fstream>

//Ввести с клавиатуры строку, состоящую из букв, цифр, запятых, точек, знаков + и , и записать ее в файл.
//Прочитать из файла данные и вывести подстроку, которая соответствует записи целого числа.

using namespace std;
char s[256];
int nm;
ofstream f2("F2.txt");

void writef(ofstream& f, char str[256])
{
	f.open("F1.txt");
	if (f.fail())  
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	f << str;
	f.close();
}
void readf(ifstream& ff)
{
	ff.open("F1.txt");
	if (!ff.is_open())
	{
		cout << "Ошибка открытия F1.txt" << endl;
	}
	ff.getline(s, 256);
}
void number(char str[256])
{
	char pstr[256], ch =' ';
	int i = 0, j = 0;
	while (str[i] != '\0')
	{
			
		if (str[i] >= '0' && str[i] <= '9')
		{
			pstr[j] = str[i];
			cout << pstr[j];
			f2 << pstr[j];
		}
		
		if (str[i + 1] == ' ')
		{
			cout << ch;
			f2 << ch;
		}
		i++;
	}
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	ofstream f;

	char str[256]; 
	cout << "Введите строку символов:\n";
	cin.getline(str, 256);

	writef(f, str);
	ifstream ff;
	readf(ff);
	nm = sizeof(s);

	cout << "\nПодстрока, которая соответствует записи целого числа:\n";
	number(str);

}