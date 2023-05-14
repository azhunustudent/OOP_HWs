#include <iostream>
#include <time.h>
#define SIZE 10
using namespace std;


void randArr(int* arr, int size)
{
	int min = 1;
	int max = 20;

	for (int i = 0; i < size; i++)
	{
		*arr = rand() % (max - min + 1) + min;
		arr++;
	}
}

void randArr2(int* arr, int size)
{
	int negativeNum = -10;
	int positiveNum = 10;

	for (int i = 0; i < size; i++)
	{
		*arr = rand() % (positiveNum - negativeNum + 1) + negativeNum;
		arr++;
	}
}


void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *arr << " ";
		arr++;
	}
	cout << endl;
}


void randGardes(int* arr, int size)
{
	int min = 1;
	int max = 12;
	for (int i = 0; i < size; i++)
	{
		*arr = rand() % (max - min + 1) + min;
		arr++;
	}
}


void calcGrades(int* arr, int size)
{
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;

	for (int i = 0; i < size; i++)
	{
		if (*arr >= 1 && *arr <= 3)
		{
			count2++;
		}
		else if (*arr >= 4 && *arr <= 6)
		{
			count3++;
		}
		else if (*arr >= 7 && *arr <= 9)
		{
			count4++;
		}
		else if (*arr >= 10 && *arr <= 12)
		{
			count5++;
		}
		arr++;
	}

	cout << "Кол-во двоек (1-3):\t" << count2 << ", в процентах:\t" << (double)count2 / size * 100 << "%" << endl;
	cout << "Кол-во троек(4-6):\t" << count3 << ", в процентах:\t" << (double)count3 / size * 100 << "%" << endl;
	cout << "Кол-во четверок(7-9):\t" << count4 << ", в процентах:\t" << (double)count4 / size * 100 << "%" << endl;
	cout << "Кол-во пятерок(10-12):\t" << count5 << ", в процентах:\t" << (double)count5 / size * 100 << "%" << endl;
}


void moveFirstNegToEnd(int* arr, int size)
{
	int* firstNegative = nullptr;

	for (int i = 0; i < size; i++)
	{
		if (*arr < 0)
		{
			firstNegative = &arr[i];
			break;
		}
		arr++;
	}

	if (firstNegative != nullptr)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (i < firstNegative - arr)
			{
				continue;
			}
			swap(arr[i], arr[i + 1]);
		}
	}
}


void replaceWithZero(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (*arr < 0)
		{
			*arr = 0;
		}
		arr++;
	}
}


int main()
{
	system("chcp 1251 > nul");
	srand(time(0));

	// 1)** Создать массив из N целых чисел, N вводит пользователь.
	// Заполнить массив случайным образом в диапазоне от 1 до 12.
	// Каждое число это оценка по 12 бальной системе.
	// Пользуясь указателем на массив целых чисел, посчитать процент 
	// двоек, троек, четверок и пятерок.
	// Двойка от 1 до 3 включительно, тройка от 4 до 6, четверка от 7 до 9, 
	// пятерка от 10 до 12.
	cout << "Задание 1." << endl;
	int n;
	cout << "Введите кол-во оценок: ";
	cin >> n;

	int* grades = new int[n];
	cout << "Оценки:" << endl;
	randGardes(grades, n);
	printArr(grades, n);

	calcGrades(grades, n);
	delete[] grades;
	cout << endl;


	// 2)** Используя указатели, перенести в хвост одномерного массива 
	// первый отрицательный элемент.
	cout << "Задание 2." << endl;
	int arr2[SIZE];
	randArr2(arr2, SIZE);
	printArr(arr2, SIZE);
	moveFirstNegToEnd(arr2, SIZE);
	printArr(arr2, SIZE);
	cout << endl;


	// 3)** Написать программу, которая содержит функцию, принимающую 
	// в качестве аргумента, указатель на массив и размер массива, 
	// и заменяет отрицательные элементы на 0.
	cout << "Задание 3." << endl;
	int arr3[SIZE];
	randArr2(arr3, SIZE);
	printArr(arr3, SIZE);
	replaceWithZero(arr3, SIZE);
	printArr(arr3, SIZE);
	cout << endl;


	// 4)* Написать программу, которая вычисляет сумму четных элементов массива,
	// используя ДВА указателя на массив целых чисел.Первый указатель двигается с
	// начала массива, второй - с конца.
	cout << "Задание 4." << endl;
	int arr4[SIZE];
	int* aPtr = arr4;
	int* bPtr = arr4 + SIZE - 1;
	int sum = 0;
	randArr(arr4, SIZE);
	printArr(arr4, SIZE);

	while (aPtr < bPtr)
	{
		if (*aPtr % 2 == 0)
		{
			sum += *aPtr;
		}
		if (*bPtr % 2 == 0)
		{
			sum += *bPtr;
		}
		aPtr++;
		bPtr--;
	}
	cout << "Сумма четных элементов массива: " << sum << endl << endl;


	// 5)** Написать программу, которая вычисляет сумму элементов массива с номерами
	// кратными трем, используя ДВА указателя на массив целых чисел.Первый
	// указатель двигается с начала массива, второй - с конца.
	cout << "Задание 5." << endl;
	int arr5[SIZE];
	int* aPtr2 = arr5;
	int* bPtr2 = arr5 + SIZE - 1;
	int sum2 = 0;
	randArr(arr5, SIZE);
	printArr(arr5, SIZE);

	while (aPtr2 < bPtr2)
	{
		if (*aPtr2 % 3 == 0)
		{
			sum2 += *aPtr2;
		}
		if (*bPtr2 % 3 == 0)
		{
			sum2 += *bPtr2;
		}
		aPtr2++;
		bPtr2--;
	}
	cout << "Сумма элементов массива с номерами кратными трем: " << sum2 << endl;
}