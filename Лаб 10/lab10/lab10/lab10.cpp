#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

// ============================ ВАРИАНТ 7 ============================

int i = 1;
double PI = 3.14;
double sum = 0;



void foo(int n, double x, double* sum)
{
	while (i <= n)
	{
		*sum += sin(x * i);
		++i;
		foo(n, x, sum);
	}
}




// ============================ ВАРИАНТ 5 ============================

int C(int m, int n)
{
	if (m > n || m < 0 || n < 0) 
		return 0;
	if (m == 0 || m == n || n == 0) 
		return 1;
	else
		return C(m, n - 1) + C(m - 1, n - 1);
}




// ============================ ДОП 1 ============================

void dop1(int size, int* arr, int tmp)
{

	ofstream file("data.txt", ios_base::app);
	for (int i = 0; i <= size; i++) {
		arr[tmp] = i;
		if (tmp == size - 1) {
			for (int j = 0; j < size; j++)
			{
				cout << arr[j];
				file << arr[j];
			}
			cout << " ";
			file << " ";
		}
		else
			dop1(size, arr, tmp + 1);
	}
}

// ============================ ДОП 2 ============================

char c[50] = {};
char tr[50] = {};
int count = 0;

void dop2(string s, int count)
{
	if (count == strlen(c))
	{
		cout << s << endl;
		return;
	}

	for (int i = 0; i < strlen(c); i++)
	{
		if (!tr[i])
		{
			count++;
			string save = s;
			s += c[i];
			tr[i] = 1;
			dop2(s, count);
			count--;
			s = save;
			tr[i] = 0;
		}
	}
}

// ============================ ДОП 3 ============================

static char dop3(char* arr, const int& n, int m) {
	if (m < 26) dop3(arr, n, m + 1);
	if (m == 26) return arr[n + m];
}




// ============================  MAIN  ============================

int main()
{
	setlocale(LC_ALL, "russian");

	double m, d;
	cout << "Введите m:";
	cin >> m;
	cout << endl;
	cout << "Введите n:";
	cin >> d;
	cout << endl;
	cout << "5 вариант: " << C(m, d) << endl;

	double x;
	int p;

	cout << "Enter n: ", cin >> p;
	cout << "\nEnter x: ", cin >> x;
	foo(p, x, &sum);

	cout << "7 вариант: " << sum << endl << endl;


	int A;
	cout << "Dop 1:\nEnter A: ";
	cin >> A;
	int* arr = new int[A];
	if (A == 1)
	{
		cout << 0 << " ";
		cout << 1 << '\n';

	}
	else
		for (int i = 1; i <= A; i++)
		{
			arr[0] = i;
			dop1(A, arr, 1);
		}


	
	
		cout << "\nDop 3:\nEnter number:\n";
		cin >> c;
		cout << "All reshuffles:\n";
		dop2("", 0);

		cout << "Dop 4:\n";
	int max = 26;
	constexpr int size = 52;
	char array[size];
	int n = 0;
	for (int i = 0; i < max; i++)
	{
		array[i] = 'a' + i;
		array[i + max] = 'a' + i;
	}
	do
	{
		cout << "Введите число n меньше 26 и больше нуля: ";
		cin >> n;
		for (int i = 0; i < max; i++) {
			cout << i + 1 << ". " << array[i] << endl;
		}
		cout << endl;
		cout << "Искомый символ: " << dop3(array, (n-1), 0) << endl;
	} while (n);

}