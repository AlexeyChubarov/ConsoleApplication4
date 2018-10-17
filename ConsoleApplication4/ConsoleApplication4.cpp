// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

double dIntegral(double (*func)(double x), double from, double to, double step)
{
	int n,id_sign;
	double integral_summ,change;

	integral_summ = 0.;
	
	if (from > to)
	{
		id_sign = -1;
		change = to;
		to = from;
		from = change;
	} 
	else id_sign = 1;

	n = (int)(abs(to - from) / step);

	for (int i=1 ; i < n; i ++)
	{
		integral_summ += (*func)(from+i*step);
	}
	integral_summ =id_sign*(integral_summ+((*func)(from)+(*func)(to))/2.)*step;
	printf("calculation result:\t");
	return integral_summ;

}

int main()
{
	double a, b, delta;
	printf("please, enter the limits of integration:\t");
	scanf_s("%lf %lf", &a, &b);
	
	printf("please, enter the integration accuracy:\t");
	scanf_s("%lf", &delta);

	printf("computing, please, be patient :))\n");

	printf("calculation result :\t %lf \n", dIntegral(log10,a,b,delta));
	
	system("pause");
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
