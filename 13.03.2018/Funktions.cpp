#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <stdarg.h>

using namespace std;

unsigned i, j;

#define colCount 5
enum type_number { positive, negative, all };

int happy(char* arr)
{
	int f, s;
	f = (int)arr[0] + (int)arr[1];
	s = (int)arr[2] + (int)arr[3];
	if (f == s)
		return 1;
	else return 0;
}

void sort_u(int*arr, int j)
{
	int prom;
	if (arr[j] > arr[j + 1])
	{
		prom = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = prom;
	}
}

void sort_d(int*arr, int j)
{
	int prom;
	if (arr[j] < arr[j + 1])
	{
		prom = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = prom;
	}
}

void sort(int*arr, int r, int n)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < r - 1; j++)
		{
			if (n == 1)
				sort_u(arr, j);
			else
				sort_d(arr, j);
		}
	}
}

int numb(type_number tn, int start, int end)
{
	switch (tn)
	{
	case positive:
		return start + rand() % end;
		break;
	case negative:
		return start*(-1) + rand() % end;
		break;
	case all:
		return rand();
		break;
	}
}
double numb(type_number tn, double start, int end)
{
	switch (tn)
	{
	case positive:
		return (start + rand() % end) / (start + rand() % end);
		break;
	case negative:
		return (start*(-1) + rand() % end) / (start*(-1) + rand() % end);
		break;
	case all:
		return rand();
		break;
	}
}

void creat(int*arr, int r, int start, int end, type_number tn)
{
	for (i = 0; i < r; i++)
	{
		arr[i] = numb(tn, start, end);
	}
}

void creatMatrix(int(*a)[colCount], int r, int start, int end, type_number tn)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < colCount; j++)
		{
			a[i][j] = numb(tn, start, end);
		}
	}
}

void creatMatrix(int*a, int coll, int row)
{
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < coll; j++)
		{
			*(a + i*coll + j) = 1 + rand() % 100;
		}
	}
}

void printMatrix(int*a, int coll, int row)
{
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < coll; j++)
		{
			printf("%d\t", *(a + i*coll + j));
		}
		printf("\n");
	}
}

void creatMatrix(double(*a)[colCount], int r, double start, int end, type_number tn)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < colCount; j++)
		{
			a[i][j] = round(numb(tn, start, end) * 100) / 100;
			/*round(a[i][j] = numb(tn, start, end));*/
		}
	}
}

void print_arr(int*arr, int r)
{
	for (i = 0; i < r; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void printMatrix(double(*a)[colCount], int r)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < colCount; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
void printMatrix(int(*a)[colCount], int r)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < colCount; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void arr_d(int*arr, int arr1[][4], int r)
{
	int m = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			//*(*(arr1+i)+j) = *(arr+m);
			arr1[i][j] = arr[m];
			m++;
		}
	}
}

int sum(int num, ...)
{
	int arr = 0;
	va_list r;
	va_start(r, num);
	for (; num; num--)
	{
		arr += va_arg(r, int);
	}
	va_end(r);
	return arr;
}
//2.	ќписать процедуру Smooth(A,N), замен€ющую каждый элемент вещественного 
//массива A размера N на его среднее арифметическое со своими сосед€ми
//("сглаживание массива"). ћассив A Ч входной и выходной параметр,
//N Ч входной параметр. — помощью этой процедуры выполнить п€тикратное 
//сглаживание данного массива A размера N, вывод€ на экран результаты каждого сглаживани€.

void Smooth(int *a, int r, const int *k)
{
	for (int l = 0; l < *k; l++)
	{
		a++; //увеличиваем кол-во бит
		for (j = 1; j < r - 1; j++)
		{
			/*a[j] = (a[j - 1] + a[j] + a[j + 1]) / 3;*/

			*a = (*(a - 1) + *a + *(a + 1)) / 3;
			a++;
		}
		a = a - 9;
		print_arr(a, r);
	}
}

int FindMax(int* arr, int arrSize, int currPos = 0)

{
	if (currPos >= arrSize)

		return 0;

	int temp = FindMax(arr, arrSize, currPos + 1);

	return(arr[temp] > arr[currPos] ? temp : currPos);
}

int sum_ind(int(*a)[4], int r, int &col, int &row, int &max) //функци€ возвращает более 1 значени€
{
	int s;
	max = *(*a);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				col = j;
				row = i;
				s = i + j;
			}
		}
	}
	return s;
}

double sr_arif(double(*a)[colCount], int r)
{
	float s = 0, sr;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			s += a[i][j];
			//s += *(*a);
			//a++;
		}
	}
	return round((s / (colCount * r)) * 100) / 100;
}

void TwoInOne(int(*a)[colCount], int r, int *b)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			b[j] += a[j][i];
		}
	}
}

enum typeRait
{
	letter, five, twelve, percent
};

char getRait(int *x, typeRait to)
{
	switch (to)
	{
	case letter:
	{
		if (*x >= 1 && *x <= 20)
			return 'F';
		else if (*x >= 21 && *x <= 40)
			return 'D';

		else if (*x >= 41 && *x <= 47)
			return 3;
		else if (*x >= 48 && *x <= 53)
			return 4;
		else if (*x >= 54 && *x <= 60)
			return 5;

		else if (*x >= 61 && *x <= 47)
			return 6;
		else if (*x >= 68 && *x <= 73)
			return 7;
		else if (*x >= 74 && *x <= 80)
			return 8;

		else if (*x >= 81 && *x <= 87)
			return 9;
		else if (*x >= 88 && *x <= 93)
			return 10;
		else if (*x >= 94 && *x <= 100)
			return 11;

		else
			return 0;
	}
	break;

	case five:
	{
		if (*x >= 1 && *x <= 20)
			return 1;
		else if (*x >= 21 && *x <= 40)
			return 2;
		else if (*x >= 41 && *x <= 60)
			return 3;
		else if (*x >= 61 && *x <= 80)
			return 4;
		else if (*x >= 81 && *x <= 100)
			return 5;
		else
			return 0;
	}
	break;

	case twelve:
		if (*x >= 1 && *x <= 20)
			return 1;
		else if (*x >= 21 && *x <= 40)
			return 3;
		else if (*x >= 41 && *x <= 60)
			return 6;
		else if (*x >= 61 && *x <= 80)
			return 9;
		else if (*x >= 81 && *x <= 100)
			return 12;
		else
			return 0;
		break;

	case percent:
	{
		return *x;
	}
	break;

	default:
		break;
	}


}

void Perevod(char *mas, int size, int maxB, typeRait to)
{
	int x;
	for (i = 0; i < size; i++)
	{
		x = (100 * (int)(*mas)) / maxB;

		*mas = getRait(&x, to);
		mas++;
	}
}

int copyS(char *mas1, char *mas2, int size)
{
	for (i = 0; i < size; i++)
	{
		*mas2 = *mas1;
		mas1++;
		mas2++;
	}
	*mas1 = '\0';
	return 0;
}

void replacestr(char *str, char *old, char *tonew)
{
	int count;
	for ( i = 0; i < strlen(str); i++)
	{
		if (str[i] == *old)
		{
			count++;
			old++;
			while (*old!='\0')
			{
				if (str[i] == *old)
				{
					old++;
				}
				i++;
			}		
		}
		else
		{
			count = 0;
		}
		if (count == strlen(old))
		{

		}
	}
}