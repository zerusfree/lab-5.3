#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double h(const double x);
int main()
{
	double qp, qk, w;
	int n;
	cout << "qp = "; cin >> qp;
	cout << "qk = "; cin >> qk;
	cout << "n = "; cin >> n;
	cout << fixed;
	cout << "----------------------" << endl;
	cout << "|" << setw(5) << "q" << "   |"
		<< setw(7) << "h" << "    |"
		<< endl;
	cout << "----------------------" << endl;
	double dq = (qk - qp) / n;
	double q = qp;
	while (q <= qk)
	{
		w = h(q + 1) + h(q * q + 1) + pow(h(q * q),2);
		cout << "|" << setw(7) << setprecision(2) << q << " |"
			<< setw(10) << setprecision(5) << w << " |"
			<< endl;
		q += dq;
	}
	return 0;
}
double h(const double x)
{
	if (abs(x) >= 1)
		return (cos(x) + 1)/(pow(cos(x),2) + 1);
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = pow(x,2*i) / ((2*i-5)*(2*i-4)*(2*i-3) * (2*i - 2) * (2*i - 1)* (2*i));
			a *= R;
			S += a;
		} while (i < 6);
		return S* 1 / cos(x);
	}
}