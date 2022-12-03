
#include <stdio.h>
#include <math.h>

//Подключаем заголовочный файл math.h для вызова функций pow(), exp() и fabs(), напишем функцию fact(), возвращающую факториал. 
//Так как функция fact() определена только для целых чисел и возвращает целое число, то ее вызов никак не повлияет на погрешность результата.

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
    {
        return n * fact(n - 1);
    }
}

//Задаем машинный эпсилон для типа long double при помощи функции machine_epsilon(), которая делит переменную e на 2 пока (1 + e/2) > 1. Если (1 + e/2) = 1, то e будет равно машинному нулю;
//функция возвращает результат предыдущей итерации. Присваиваем его переменной e0.

//long double machine_epsilon(void)
//{
	//long double e = 1.0f;
	//while (1.0f + e / 2.0f > 1.0f)
		///e /= 2.0f;
	//return e;
//}


//Задаем ввод количества равных разбиений отрезка [a,b], n, если n > 1, то объявляем число d, равное b/n - единичный отрезок.

int main()
{
	double machine_epsilon;
while (1+machine_epsilon>1){
	machine_epsilon/=2;
}
	printf("Vvedite kolichestvo ravnykh razbiyeniy otrezka [a, b]: n = ");
	int n;
	scanf("%d", &n);
	if (n < 1) {
		printf("Vvedennoye znacheniye dolzhno byt' bol'she nulya!\n");
		return 0;
	}
	double e0 = machine_epsilon;
	double d = 1 / (double)n;
	printf("Mashinnoye epsilon dlya tipa long double: e = %21.19f\n", e0);
	printf("+-----------------------------------------------------------------------------------------------------+\n");
	printf("|            Tablitsa znacheniy ryada Teylora i standartnoy funktsii dlya f(x) = exp(pow(x, 2))       |\n");
	printf("+-------+-----------------------------------------+---------------------------------+-----------------+\n");
	printf("|   x   |chastichnaya summa ryada dlya exp(pow(x, 2))|  znacheniye funktsii f(x)    |chislo iteratsiy|\n");
	printf("+-------+-----------------------------------------+---------------------------------+-----------------+\n");

	//В цикле for проходим по всем точкам разбиений {0, n}, присваиваем аргументу значение d * i (произведение единичного отрезка на номер итерации)
	for (double x = 0; x <= 1.0; x += d) {
		double math_func = cos(x);
		double res = 1;
		int n1 = 1;
		double numerator = 1;
		double denominator = 1;
		double cur = 1;
		int p1 = 1;
		
			//Суммируем данный ряд Тейлора, объявляем переменные res - результат, n1 - количество итераций, определяющее точность значения f(x), numenator и denomenator - числитель и знаменатель члена ряда.
			
			//Первый член ряда Тейлора уже задан объявим cur - значение дроби, начиная со второго члена циклически умножаем числитель и знаменатель согласно условию, прибавляем к переменной res значение дроби. 
			//Условие на выход из цикла: если модуль значения члена ряда меньше e0.
		while(cur > e0 || -cur > e0 || n1 <= 100){
			numerator *= x * x;
			denominator = denominator * n1 * (n1+1);
			p1 *= -1;
			cur = p1 * (numerator / denominator);
			res += cur;
			n1++;
		}
		//printf("%d\n", n1);
		//В виде таблицы выводим переменные x, res, math_func, n1.
		printf("| %.3f\t|          %.19f          |      %.19f      |        %d        |\n", x, res, math_func, n1);
	}
	printf("+-------+-----------------------------------------+---------------------------------+-----------------+\n");
	return 0;
}