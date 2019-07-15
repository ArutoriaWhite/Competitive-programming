#define _CRT_SECURE_NO_WARNINGS
#define _for(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define N 4
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

int _main() {
	double a, b; char opr; string result;
	cin >> a >> opr >> b;
	
	if (opr == '*')	cout << fixed << setprecision(N) << a << " * " << b << " = " << a * b;
	if (opr == '+')	cout <<fixed<< setprecision(N) << a << " +" << b << " = " << a + b;
	if (opr == '-')	cout <<fixed<< setprecision(N) << a << " - " << b << " = " << a - b;
	if (opr == '/') {
		if (b != 0)
			cout <<fixed<< setprecision(N) << a << " / " << b << " = " << a / b;
		else
			printf("%s", "ERROR");
	}
	//if (opr == '*')	printf("%.4f * %.4f = %.4f", a, b, a*b);
	//if (opr == '+')	printf("%.4f + %.4f = %.4f", a, b, a + b);
	//if (opr == '-')	printf("%.4f - %.4f = %.4f", a, b, a - b);
	//if (opr == '/') {
	//	if (b != 0)
	//		printf("%.4f / %.4f = %.4f", a, b, a / b);
	//	else
	//		printf("%s", "ERROR");
	//}
	cout << endl;
	return 0;

}
