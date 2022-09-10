#include <iostream>
#include <complex>
#include <math.h>
using namespace std;

// x^n = |x|^n * e^i(n*phi) Muavra
complex<double> COMP_Muavra(int n, double real, double immag)
{
	double leng = pow(sqrt(pow(real, 2) + pow(immag, 2)), n);
	double angle = atan2(immag, real) * n;
	complex<double> rescomp(leng, angle);
	return rescomp;
}
//re^ia > x+iy
complex<double> COMP_fromTrig_toAlg(double leng, double angle) 
{
	double x = leng / sqrt(1 + pow(tan(angle), 2));
	double y = x * tan(angle);
	complex<double> complex(x, y);
	return complex;
}
// x + iy->re ^ ia
complex<double> COMP_fromAlg_toTriag(double x, double y) 
{
	double leng = sqrt(pow(x, 2) + pow(y, 2));
	double angle = atan2(y, x);
	complex<double> complex(leng, angle);
	return complex;
}
// x^(1/n) -> x1, x2, x3
int COMP_KOR(int n, double real, double immag) 
{
	double leng = sqrt(pow(real, 2) + pow(immag, 2));
	double angle = atan2(immag, real);
	for (int i = 0; i < n; i++) {
		double res_angle = (2 * 3.14 * i) + angle;
		cout << "result: " << i << " :leng: " << leng << " :angle: " << res_angle;
	}
	return 0;
}
//суммирование комплексных чисел
complex<double> COMP_Pluse(int n)
{
	double sumreal = 0; double sumimmag = 0;
	for (int i = 0; i < n; i++) {
		double real = 0; double immag = 0;
		printf("%s\n", "print nums (real and immag)");
		cin >> real; cin >> immag;
		sumreal += real; sumimmag += immag;
	}
	printf("%s\n", "done");
	complex<double> comp(sumreal, sumimmag);
	return comp;
}
//разность комплексных чисел
complex<double> COMP_Difference(int n)
{
	double sumreal = 0; double sumimmag = 0;
	for (int i = 0; i < n; i++) {
		double real = 0; double immag = 0;
		printf("%s\n", "print nums (real and immag)");
		cin >> real; cin >> immag;
		sumreal -= real; sumimmag -= immag;
	}
	printf("%s\n", "done");
	complex<double> comp(sumreal, sumimmag);
	return comp;
}
//умножение комплексных чисел
complex<double> COMP_Mnoj(int n)
{
	double all_angle = 0; double all_leng = 1; complex<double> resultcomp;
	for (int i = 0; i < n; i++) {
		double real = 0; double immag = 0; double angle = 0; double leng = 0;
		cin >> real; cin >> immag;
		angle = atan2(immag, real); leng = sqrt(pow(real, 2) + pow(immag, 2)); //тригонометричаская запись
		all_angle += angle;
		all_leng *= leng;
	}
	resultcomp = COMP_fromTrig_toAlg(all_leng, all_angle); printf("%s\n", "done");
	return resultcomp;
}
//деление комплексных чисел
complex<double> COMP_Div(int n)
{
	double all_angle = 0; double all_leng = 1; double all_pod_real = 1; double real = 0; double immag = 0;
	cin >> real; cin >> immag;
	double piece1 = atan2(immag, real); double piece2 = sqrt(pow(real, 2) + pow(immag, 2));
	for (int i = 0; i < n-1; i++) {
		double del_real = 0; double del_immag = 0; cin >> del_real; cin >> del_immag; del_immag *= -1; //тут очень замудренная формула, думайте сами
		double del_leng = sqrt(pow(del_real, 2) + pow(del_immag, 2)); double del_angle = atan2(del_immag, del_real);
		double pod_real = pow(del_real, 2) + pow(del_immag, 2);
		all_angle += del_angle; all_leng *= del_leng; all_pod_real *= pod_real;
	}
	all_leng *= piece2 / all_pod_real; all_angle += piece1;
	complex<double> rescomplex; rescomplex = COMP_fromTrig_toAlg(all_leng, all_angle);
	return rescomplex;
}
int main()
{
	printf("%s\n", "[Created by Moren]");
	printf("%s\n", "| 1 - sum of complex nums                                  |");
	printf("%s\n", "| 2 - difference of complex numbers                        |");
	printf("%s\n", "| 3 - multiplication of complex nums                       |");
	printf("%s\n", "| 4 - division of complex numbers                          |");
	printf("%s\n", "| 5 - getting roots 1/n from complex number                |");
	printf("%s\n", "| 6 - r*e^ia -> x+iy                                       |");
	printf("%s\n", "| 7 - x+iy -> r*e^ia                                       |");
	printf("%s\n", "| 8 - Muavra                                               |");
	printf("%s\n", "| contacts: Herman Garsky#2574                             |");
	printf("%s\n", "| URL Telegram group: https://t.me/morenskytm              |");
	printf("%s", "how many times will you access the functions?: "); int acc; cin >> acc;
	for (int i = 0; i < acc; i++) {
		int shoose_num = 0; int amount = 0; complex<double> complex; double leng; double angle;
		printf("%s", "print type your choose: "); cin >> shoose_num;
		switch (shoose_num)
		{
		case 1: //суммирование комплекс чисел
			printf("%s", "print your amount passages: "); cin >> amount;
			complex = COMP_Pluse(amount);
			cout << "result: " << real(complex) << "+i" << imag(complex);
			break;
		case 3: //умножение комплексных чисел
			printf("%s", "print your amount passages: "); cin >> amount; if (amount < 2) exit(1);
			complex = COMP_Mnoj(amount);
			cout << "result: " << real(complex) << "+i" << imag(complex);
			break;
		case 2: //разность комплексных чисел
			printf("%s", "print your amount passages: "); cin >> amount;
			complex = COMP_Difference(amount);
			cout << "result: " << real(complex) << "+i" << imag(complex);
			break;
		case 4: //деление комплексных чисел
			printf("%s", "print your amount passages: "); cin >> amount; if (amount < 2) exit(1);
			complex = COMP_Div(amount);
			cout << "result: " << real(complex) << "+i" << imag(complex);
			break;
		case 5: //получаем корни
			double reall; double immag;
			printf("%s", "how many roots do you need?: "); cin >> amount;
			printf("%s\n", "print complex num: "); cin >> reall; cin >> immag;
			cout << COMP_KOR(amount, reall, immag);
			break;
		case 6: // из тригонемтрии в алгебру
			printf("%s\n", "print complex leng & angle for r*e^ia: "); cin >> leng; cin >> angle;
			complex = COMP_fromTrig_toAlg(leng, angle);
			cout << "result: " << real(complex) << " + i" << imag(complex);
			break;
		case 7: // из алгебры в тригонометрим
			printf("%s\n", "print complex nums: "); cin >> reall; cin >> immag;
			complex = COMP_fromAlg_toTriag(reall, immag);
			cout << complex;
			break;
		case 8: //формула муавры
			printf("%s", "the degree of a complex number: "); cin >> amount;
			printf("%s\n", "print complex nums: "); cin >> reall; cin >> immag;
			complex = COMP_Muavra(amount, reall, immag);
			cout << complex;
			break;
		default:
			break;
		}
    }
	return 0;
}