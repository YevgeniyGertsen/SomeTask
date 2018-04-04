#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

void feelArray(int *mas, int n);
void printArray(int *mas, int n);
int sumArray(int *mas, int n);
void second(int *mas, int n);
int ifotr(int *mas, int n);
void sort(int *mas, int n);
void masvmas(int *mas1, int *mas2, int n);
void fifth(int *mas, int n);
void sixth(int *mas, int n, int *pol, int *otr, int *nol);
int seventh(int *mas, int *mas1, int m, int n);
void seventh(int *mas, int *mas1, int *mas3, int m, int n);
int *ninth(int *mas, int n);

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	rand();
	int x;
	do
	{
		cout << "Введите номер задания" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			int mas[5];
			int n = 5;
			feelArray(mas, n);
			printArray(mas, n);
			cout << endl << sumArray(mas, n) << endl;
		}
		break;
		case 2:
		{
			int mas[5];
			int n = 5;
			feelArray(mas, n);
			printArray(mas, n);
			second(mas, n);
		}
		break;
		case 3:
		{
			int mas[10];
			int n = 10;
			feelArray(mas, n);
			printArray(mas, n);
			cout << endl;
			sort(mas, n);
			printArray(mas, n);
		}
		break;
		case 4:
		{
			int mas1[10];
			int mas2[10];
			int n = 10;
			feelArray(mas1, n);
			masvmas(mas1, mas2, n);
			printArray(mas1, n);
			cout << endl;
			printArray(mas2, n);

		}
		break;
		case 5:
		{
			int mas[10];
			int n = 10;
			feelArray(mas, n);
			printArray(mas, n);
			cout << endl;
			fifth(mas, n);

		}
		break;
		case 6:
		{
			int mas[10];
			int n = 10;
			int otr = 0, pol = 0, nol = 0;
			feelArray(mas, n);
			printArray(mas, n);
			sixth(mas, n, &otr, &pol, &nol);
			cout << endl
				<< "Отриц=" << otr
				<< " Полож=" << pol
				<< " NULL=" << nol << endl;

		}
		break;
		case 7:
		{
			int m, n, a = 0;
			cin >> m >> n;
			int *mas = new int[m];
			int *mas1 = new int[n];

			feelArray(mas, n);
			feelArray(mas1, m);

			a = seventh(mas, mas1, m, n);

			int *mas3 = new int[a];
			seventh(mas, mas1, mas3, m, n);

			cout << endl;
			printArray(mas, n);
			cout << endl;
			printArray(mas1, m);
			cout << endl;
			printArray(mas3, a);

		}
		break;

		case 8:
		{
			cout << "izi" << endl;
		}
		break;
		case 9:
		{
			int mas[10];
			int n = 10;
			feelArray(mas, n);
			printArray(mas, n);
			cout << endl;
			cout<<*ninth(mas, n);
			cout << endl;

		}
		break;
		}
	} while (x > 0);

}
void feelArray(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(mas + i) = -10 + rand() % 100;
	}
}

void printArray(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(mas + i) << "\t";
	}
}
int sumArray(int *mas, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += *(mas + i);
	}
	return sum;
}
void second(int *mas, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		cout << *(mas + i) << "\t";
	}
}
int ifotr(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (*(mas + i) < 0)
			return 1;
	}
	return 0;
}
void sort(int *mas, int n)
{
	if (ifotr(mas, n) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (*(mas + j) < *(mas + j - 1))
				{
					int x = *(mas + j);
					*(mas + j) = *(mas + j - 1);
					*(mas + j - 1) = x;

				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (*(mas + j) > *(mas + j - 1))
				{
					int x = *(mas + j);
					*(mas + j) = *(mas + j - 1);
					*(mas + j - 1) = x;

				}
			}
		}
	}
}
void masvmas(int *mas1, int *mas2, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(mas2 + i) = *(mas1 + i);
	}
}
void fifth(int *mas, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		cout << *(mas + i) << "\t";
	}
}
void sixth(int *mas, int n, int *pol, int *otr, int *nol)
{
	for (int i = 0; i < n; i++)
	{
		if (*(mas + i) < 0)
			*pol += 1;
		else if (*(mas + i) > 0)
			*otr += 1;
		else if (*(mas + i) = 0)
			*nol += 1;
	}
}
int seventh(int *mas, int *mas1, int m, int n)
{
	int a = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (*(mas + i) == *(mas1 + j))
				a++;
		}
	}
	return a;
}
void seventh(int *mas, int *mas1, int *mas3, int m, int n)
{
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (*(mas + i) == *(mas1 + j))
			{
				*(mas3 + k) = *(mas + i);
				k++;
			}
		}
	}
}
int *ninth(int *mas,int n)
{
	int max = *(mas), maxIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(mas + i) > max)
		{
			max = *(mas + i);
			maxIndex = i;
		}
	}
	return (mas+ maxIndex);
}



