#include <iostream>

using namespace std;
//var2

double sum(int n, ...);

double sum(int n, ...) {
	int res = 0;
	int* p = &n + 1;
	for (; n > 0; n--)
		res += *(p++) * (*(p + 1));
	return res;
}


float findX(float (*f)(float), float a, float b, float e) {

	float x;

	do
	{
		x = (a + b) / 2;

		if (f(x) * f(a) <= 0)
		{
			b = x;
		}
		else {
			a = x;
		}

	} while (abs(a - b) > 2 * e);

	return x;
}
//var2
float f1(float x) {
	return (pow(x, 3) - x + 3);
}

float f2(float x) {
	return (pow(cos(x), 3));
}
//var8
float f3(float x) {
	return (pow(x, 2) + 4 * x - 2);
}

float f4(float x) {
	return (sin(x) - 0.1);
}

//var15
float f5(float x) {
	return (pow(x, 3) + x - 2);
}

float f6(float x) {
	return (sin(x) + 0.3);
}
//var5
float f7(float x) {
	return (exp(x) - 3 - (1 / x));
}

float f8(float x) {
	return (0.2 - (x * x));
}

float all_funk() {
	float a, b, e;
	cout << "write a" << endl;
	cin >> a;
	cout << "write b" << endl;
	cin >> b;
	cout << "write e" << endl;
	cin >> e;
	//var2
	cout << "var 2" << endl;
	cout << "x1=" << findX(f1, a, b, e) << endl;
	cout << "x2=" << findX(f2, a, b, e) << endl << "\n";
	//var8
	cout << "var 8" << endl;
	cout << "x3=" << findX(f3, a, b, e) << endl;
	cout << "x4=" << findX(f4, a, b, e) << endl << "\n";
	//var15
	cout << "var 15" << endl;
	cout << "x5=" << findX(f5, a, b, e) << endl;
	cout << "x6=" << findX(f6, a, b, e) << endl << "\n";
	//var5
	cout << "var 5" << endl;
	cout << "x7=" << findX(f7, a, b, e) << endl;
	cout << "x8=" << findX(f8, a, b, e) << endl;



	return 0;
}

//var 8

int mn(int count, ...);


int mn(int count, ...) {
	int* p = &count;
	int min = 1000;
	for (int i = 0; i < count * 2; i += 2) {

		if (*(p + i) < min)
			min = *(p + i);
	}
	return min;
}
//var15

int DecToBin(int a, ...)
{
	char tA[100000];
	int A;
	int* pA = &a + 1;
	/*for (int i = 0; i < (a + 1) * 2; i += 2)
	{
	 _itoa_s(*(pA + i), tA, 2);
	 cout << tA << endl;
	}
	return 0;*/
	for (; a > 0; a--) {
		A = *pA;
		_itoa_s(*(pA++), tA, 2);
		cout << tA << endl;
	}
	return 0;
}

//var 5

int kvadr(int m, ...)

{

	int* p = &m + 1;

	int k = 0;

	int kor;

	for (int i = 0; i < m; i++)

	{

		kor = sqrt(*(p + i));

		if (kor * kor == *(p + i)) k++;


	}

	return k;

}
//var5
int var5() {
	setlocale(0, "rus");

	int n1, n2, n3, n4, n5, n6;

	cout << "Введите числа:\t ";

	cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;
	cout << "Количество точных квадратов: " << kvadr(6, n1, n2, n3, n4, n5, n6) << "\n";
	return 0;
}



int main() {
	cout << "var2" << "\n" << "sum =" << sum(4, 4, 3, 5, 6, 4) << endl;
	cout << "dih" << all_funk();
	cout << "var8" << "\n" << mn(6, 12, 2, 10, 4, 17, 5) << endl;
	cout << "var 15" << "\n" << DecToBin(7, 9, 245, 3, 4, 3, 4, 5);
	cout << "var5" << var5();

}