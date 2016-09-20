// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

void check()
{
	cin.clear();											//если это не так, очищаем ввод
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//игнорируем все символы до знака '\n'
	cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";   //выводим сообщение что ввели неверный символ и повторяем цикл, пока не введут верный символ
}

int main()
{
	setlocale(LC_ALL, "Russian"); // add locale language
	cout << "Здравствуй, я помогу тебе решить матрицу." << endl; // Добавил перенос строки
	int method;
	cout << "Выбери действие которое ты хочешь осуществить с матрицой." << endl << "Введи цифру (1) для сложения матриц, цифру (2) для вычитания, (3) умножение, (4) траспонирование." << endl;
	cin >> method;
	while (method < 1 || method > 4) // Цикл который заставляет выбрать один из методов 
	{
		cout << "Введено недопустимое значание" << endl << "Попробуй ещё раз" << endl;
		cin >> method;
	}
	if (method == 1){
		cout << "Вы выбрали сложение матриц!" << endl; // Тут будет решение матриц
		cout << "Введите размерность матрицы A. \n";
		int i, j, n, m;
		cout << "Столбцы: ";
		//Начало проверки вводимых символов
		while (!(cin >> n)) {										//Проверяем условие, что вводимые символы соотвествуют типу n
			check();
		}
		//Конец проверки вводимых символов
		cout << "Строки: ";
		while (!(cin >> m)) {
			check();
		}
		double **matrix1 = new double *[n];
		for (i = 0; i < n; i++)
			matrix1[i] = new double[m];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы A.";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица A: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-7g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		double **matrix2 = new double *[n];
		for (i = 0; i < n; i++)
			matrix2[i] = new double[m];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы B.";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица B: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-7g", matrix2
					[i][j]);
			cout << endl;
		}
		cout << "Полученная матрица C: \n" << "C=A+B\n";
		double **matrix3 = new double *[n];
		for (i = 0; i < n; i++)
			matrix3[i] = new double[m];
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				matrix3[i][j] = 0;
				matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
				printf("%10.g", matrix3[i][j]);
			}
			cout << "\n";
		}
	}
	else if (method == 2)
	{
		cout << "Вы выбрали вычитание матриц!" << endl;
		cout << "Введите размерность матрицы A. \n";
		int i, j, n, m;
		cout << "Столбцы: ";
		//Начало проверки вводимых символов
		while (!(cin >> n)) {										//Проверяем условие, что вводимые символы соотвествуют типу n
			check();
		}
		//Конец проверки вводимых символов
		cout << "Строки: ";
		while (!(cin >> m)) {
			check();
		}
		double **matrix1 = new double *[n];
		for (i = 0; i < n; i++)
			matrix1[i] = new double[m];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы A.";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица A: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-7g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		double **matrix2 = new double *[n];
		for (i = 0; i < n; i++)
			matrix2[i] = new double[m];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы B.";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица B: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-7g", matrix2
					[i][j]);
			cout << endl;
		}
		cout << "Полученная матрица C: \n" << "C=A-B\n";
		double **matrix3 = new double *[n];
		for (i = 0; i < n; i++)
			matrix3[i] = new double[m];
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				matrix3[i][j] = 0;
				matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
				printf("%10.g", matrix3[i][j]);
			}
			cout << "\n";
		}
	}
	else if (method == 3)
	{
		cout << "Ты выбрал умножение матриц!" << endl;
		cout << "Введите размерность матрицы A. \n";
		int i, j, n, m;
		cout << "Столбцы: ";
		//Начало проверки вводимых символов
		while (!(cin >> n)) {										//Проверяем условие, что вводимые символы соотвествуют типу n
			check();
		}
		//Конец проверки вводимых символов
		cout << "Строки: ";
		while (!(cin >> m)) {
			check();
		}
		double **matrix1 = new double *[n];
		for (i = 0; i < n; i++)
			matrix1[i] = new double[m];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы A.";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица A: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-7g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		cout << "Введите размерность матрицы B. \n";
		cout << "Столбцы: ";
		//Начало проверки вводимых символов
		while (!(cin >> n)) {										//Проверяем условие, что вводимые символы соотвествуют типу n
			check();
		}
		//Конец проверки вводимых символов
		cout << "Строки: ";
		while (!(cin >> m)) {
			check();
		}
		double **matrix2 = new double *[n];
		for (i = 0; i < n; i++)
			matrix2[i] = new double[m];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы B.";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица B: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-7g", matrix2
					[i][j]);
			cout << endl;
		}
		cout << "Полученная матрица C: \n" << "C=A*B\n";
		double **matrix3 = new double *[n];
		for (i = 0; i < n; i++)
			matrix3[i] = new double[m];
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				matrix3[i][j] = 0;
				for (int k = 0; k<n; k++) 
					matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
					cout << matrix3[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else {
		cout << "Ты выбрал транспонирование матрицы!" << endl;
	}
	system("pause");
    return 0;
}

