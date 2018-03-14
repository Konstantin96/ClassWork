#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <time.h>
#include "Protorip.h"

using namespace std;
unsigned short int nz;

int i, j;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, ".1251");

	while (true)
	{
		cout << "Введите номер задания (0 - что бы выйти) : ";
		cin >> nz;
		cin.get();

		if (nz == 0)
		{
			break;
			system("exit");
		}

		if (nz == 1)
		{
			system("cls");
			/* Ввести вещественные числа. Создать из них массив. Определить индекс второго положительного элемента массива */
			int *mas = NULL;
			int coll, ele = 0;
			printf("Vvedite razmer massiva:");
			scanf("%d", &coll);
			mas = (int*)calloc(coll, sizeof(int));
			for (i = 0; i < coll; i++)
			{
				*mas = -100 + rand() % 200;
				printf("%d\t", *mas);
				mas++;
				if (*mas > 0)
				{
					ele++;
					if (ele == 2)
					{
						printf("%d", mas);
						break;
					}
				}
			}
		}

		else if (nz == 2)
		{
			system("cls");
			/*Ввести вещественные числа. Создать из них массив. Переставить элементы массива в обратном порядке */
			int* mas = NULL;
			int n = 0, temp = 0;
			cout << "Vvedite razmer massiva:";
			cin >> n;
			mas = (int*)calloc(n, sizeof(int));
			cout << "Massiv" << endl;
			for (int i = 0; i < n; i++)
			{
				mas[i] = rand() % 100;
				printf("%d\t", mas[i]);
			}
			printf("\n");
			for (int i = 0; i < n / 2; i++)
			{
				temp = mas[i];
				mas[i] = mas[n - i - 1];
				mas[n - i - 1] = temp;
			}
			for (int i = 0; i < n; i++)
			{
				cout << mas[i] << "\t";
			}
			cout << endl;
		}

		else if (nz == 3)
		{
			system("cls");
			/*Ввести целое число N и массив из N целых чисел. Определить среднее арифметическое элементов массива, не кратных 3*/
			int* mas = NULL;
			int n = 0, sr = 0, sum = 0;
			cout << "Vvedite razmer massiva:";
			cin >> n;
			mas = (int*)calloc(n, sizeof(int));
			cout << "Massiv" << endl;

			for (int i = 0; i < n; i++)
			{
				*mas = rand() % 100;
				printf("%d\t", *mas);
				mas++;
			}
			printf("\n");
			mas = mas - n;
			for (int i = 0; i < n; i++)
			{
				sum += *mas;
				mas++;
			}
			printf("%d\n", sum);
			sr = sum / n;
			printf("%d\n", sr);
		}

		else if (nz == 4)
		{
			system("cls");
			/*Ввести целые числа. Создать массив из нечётных чисел. Вычислить произведение положительных элементов массива.*/
			int* mas = NULL;
			int n = 0;
			cout << "Vvedite razmer massiva:";
			cin >> n;
			mas = (int*)calloc(n, sizeof(int));
			cout << "Massiv" << endl;
			for (int i = 0; i < n; i++)
			{
				*mas = rand() % 100;
				printf("%d\t", *mas);
				mas++;
			}
			mas = mas - n;
			printf("\n");
			int Rez = 1;
			for (int i = 0; i < n; i++)
			{
				if (*mas % 2 != 0)
				{
					Rez *= *mas;
				}
				mas++;
			}
			printf("%d", Rez);

		}

		else if (nz == 5)
		{
			system("cls");
			/*Ввести целые числа. Создать из них массив. Вычислить произведение элементов из промежутка (2, 8)*/
			int* mas = NULL;
			int n = 0;
			cout << "Vvedite razmer massiva:";
			cin >> n;
			mas = (int*)calloc(n, sizeof(int));
			cout << "Massiv" << endl;
			for (int i = 0; i < n; i++)
			{
				*mas = rand() % 100;
				printf("%d\t", *mas);
				mas++;
			}
			mas = mas - n;
			printf("\n");
			int Rez = 1;
			for (int i = 2; i < 8; i++)
			{
				Rez *= *mas;
				mas++;
			}
			printf("%d", Rez);
		}

		else if (nz == 6)
		{
			/*Функция strncpy(s1, s2,n) копирует ровно n символов из строки s2 в строку s1, усекая при необходимости строку s2 или заполняя избыточные символы дополнительными 
			нулевыми символами. Целевая строка может не с одержать завершающего нулевого символа, если длина строки s2 равна или больше n. Функция возвращает строку s1. 
			Напишите собственную версию этой функции. Протестируйте эту функцию в рамках завершенной программы, которая ис¬пользует цикл для передачи входных значений рассматриваемой функции.*/
			char s2[] = "Функция strncpy(s1, s2,n) копирует ровно n символов из строки s2 в строку s1, усекая при необходимости строку s2";
			char* s1 = NULL;
			int r;
			printf("Vvedite kol-vo simvolov dlya kopirovaniya: ");
			cin >> r;
			s1 = (char*)calloc(r + 1, sizeof(char));
			copyS(s2, s1, r);
			printf("%s\n", s1);
		}
		//test
		else
		{
			printf("Такого задания нет!");
			exit(EXIT_FAILURE);
		}
	}
}
