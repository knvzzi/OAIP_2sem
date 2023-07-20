#include <iostream>
using namespace std;

/*e^x – 3 – 1 / x,
0,2 – x2
*/

double koren(double a, double b, double (*f)(double))
{
	setlocale(0, "rus");
	double x, e = 0.001;
	do
	{
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0)
			b = x;
		else a = x;
	}
	while (abs(a - b) > 2 * e);
	cout <<"\nКорень равен "<< x << endl;
	return x;
}

double f1(double x)
{
	double z = 0.2 - pow(x,2);
	return z;
}

double f2(double x)
{
	double z = exp(x) - 3 - (1 / x);
	return z;
}

int main()
{	
	setlocale(0, "rus");
	double A, B;

	cout << "Ведите А: " << endl;
	cin >> A;

	cout << "Введите В: " << endl;
	cin >> B;

	double* a = &A;
	double* b = &B;

	koren(*a, *b, f1);
	koren(*a, *b, f2); 
}