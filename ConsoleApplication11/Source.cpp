#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

void zadacha_1(char a, int b, int c);
int zadacha_2(int p, int a);
double min1(double, double);
void largerOf(double*x,double *y);
double sred(int *mas,int);
char check(char);
void IncTime(int H, int M, int S, int T);
int  recur(int , int );
void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	rand();
	do
	{
		cout << "Какое задание вы хотите выбрать"<<endl;
		int x;
		cin >> x;
		if (x == 0)
			break;
		else if (x == 1)
		{
			char a;
			int b, c;
			cout << "Какой символ вы хотите видеть и сколько столбцов и строк должно быть" << endl;
			cin >> a >> b >> c;
			zadacha_1(a, b, c);
		}
		else if (x == 2)
		{
			int p, a, b, c;
			cout << "Введите числа которые вы хотите" << endl;
			cin >> p >> a >> b >> c;

			cout << zadacha_2(p, a)<<endl;
			cout << zadacha_2(p, b) << endl;
			cout << zadacha_2(p, c) << endl;
		}
		else if (x == 3)
		{
			cout << "введите значения X и Y\n";
			double x , y ;
			cin >> x >> y;
			min1(x, y);
		}
		else if (x == 5)
		{
			cout << "введите значения X и Y\n";
			double x, y;
			cin >> x >> y;
			largerOf(&x, &y);
			cout << x << "\t" << y << endl;
		}
		else if (x == 6)
		{
			int const m = 10;
			int mas[m];
			for (int i = 0;i < m;i++)
			{
				mas[i] = rand() % 10;
			}
			cout << sred(mas, m);
		   }
		else if (x == 7)
		{
			char simvol;
			while (true) {
				cin >> simvol;
				if (simvol == ';')
					break;
				else
					 cout<<check(simvol);
			}
		
		}
		else if (x == 8)
		{
			cout << "введите время h:m:s и прибавленное время в сек.\n";
			int H, M, S, T;cin >> H >> M >> S >> T;
			IncTime(H, M, S, T);

			
		}
		else if (x == 9)
		{
			cout << "введите число";
			int n;cin >> n;
			cout<<recur(n, 1);
			//9.	Написать рекурсивную функцию для вычисления факториала натурального числа n.
		}
	} while (true);
	

}
void zadacha_1(char a, int b, int c)
{
	cout << a << endl;
	for (int i = 0;i < b;i++)
	{
		//cout << a << endl;
		for (int j = 0;j < c;j++)
		{
			cout << a <<"\t";
		}
		cout << endl;
	}
}
int zadacha_2(int p, int a)
{
	if (a == 0||a<0)
		return 0;

	a = exp(p*log(a));
	return a;
}

double min1(double x, double y)
{
	return x < y ? x : y;
}
void largerOf(double*x, double *y)
{
	if (*x > *y)
		*y = *x;
	else
		*x =*y ;
}
double sred(int *mas,int m)
{
	double summ=0;
	for (int i = 0;i < m;i++)
		summ += mas[i];
	summ = summ / m;
	return summ;
}
char check(char simvol)
{
	if (simvol >= 65 && simvol <= 90)
		return (int)simvol - 64;
	else if (simvol >= 97 && simvol <= 122)
		return (int)simvol - 96;
	else
		return 0;
		
//	for (int i=0;i < 256;i++)
//	{
//		cout<< i <<" - " << (char)i << endl;
//}
	//return 0;
}
void IncTime(int H, int M, int S, int T)
{
	S += T;
	M = M + S / 60;
	H = H + M / 60;
	S=S % 60;
	M=M % 60;
	H=H % 24;
	cout << H << ":" << M << ":" << S << endl;
}
int  recur(int n, int schet)
{
	if (n < schet)
		return 1;
	return schet*recur(n,schet+1);
}