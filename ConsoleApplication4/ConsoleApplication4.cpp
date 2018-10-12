// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

double dIntegral(double (*func)(double x), double from, double to, double step)
{
	double i, f0;
	double integral_summ_down, integral_summ_up, integral_summ;

	integral_summ = 0.;
	integral_summ_down = 0.;
	integral_summ_up = 0.;
	f0 = (*func)(from);
	step = (step > 1e-3) ? (1e-7) : step;

	for (i = from + step; i <= to; i += step)
	{
		integral_summ_up += (*func)(i);
		integral_summ_down += f0;
		f0 = (*func)(i);
	}
	integral_summ = .5*(integral_summ_down + integral_summ_up)*step;
	printf("calculation result:\t");
	return integral_summ;

}

int main()
{
	double a, b, delta;
	printf("please, enter the limits of integration:\t");
	scanf_s("%lf %lf", &a, &b);
	if (a > b)
	{
		delta = a;
		a = b;
		b = delta;
	}
	printf("please, enter the integration accuracy:\t");
	scanf_s("%lf", &delta);

	printf("computing, please, be patient :))\n");
	printf("%lf", dIntegral(log10,a,b,delta));
	
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
