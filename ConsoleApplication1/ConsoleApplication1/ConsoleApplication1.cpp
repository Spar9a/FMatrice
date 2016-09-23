// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
int i, j, string_x, column_y, string_n, column_m;
void check_x() {
	while (string_x < 1 || string_x > 100) // Цикл заставляющий ввести значения не меньше 1 и не больше 100
	{
		cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl << "Кол-во столбцов" << endl;
		cin >> string_x;
	}
}
void check_y() {
	while (column_y < 1 || column_y > 100) // Цикл заставляющий ввести значения не меньше 1 и не больше 100
	{
		cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl;
		cout << "Кол-во строк" << endl;
		cin >> column_y;
	}
}
void check()
{
	cin.clear();											//если это не так, очищаем ввод
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//игнорируем все символы до знака '\string_x'
	cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";   //выводим сообщение что ввели неверный символ и повторяем цикл, пока не введут верный символ
}

int main()
{
	setlocale(LC_ALL, "Russian"); // add locale language
	cout << "Здравствуйте, я помогу вам решить матрицу." << endl; // Добавил перенос строки
	int method;
	cout << "Выберите действие которое вы хотите осуществить с матрицей." << endl << "Введите цифру (1) для сложения матриц, (2) вычитание, (3) умножение, (4) траспонирование." << endl;
	cin >> method;
	while (method < 1 || method > 4) // Цикл который заставляет выбрать один из методов 
	{
		cout << "Введено недопустимое значение" << endl << "Попробуйте ещё раз" << endl;
		cin >> method;
	}
	if (method == 1) {
		cout << "Вы выбрали сложение матриц!" << endl; // Тут будет решение матриц //выебуется 
		cout << "Введите размерность матрицы A." << endl;
		cout << "Столбцы: ";
		//Начало проверки вводимых символов
		while (!(cin >> string_x)) {										//Проверяем условие, что вводимые символы соотвествуют типу string_x
			check();
		}
		check_x();
		//Конец проверки вводимых символов
		cout << "Строки: ";
		while (!(cin >> column_y)) {
			check();
		}
		check_y();
		double **matrix1 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix1[i] = new double[column_y];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы A." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица A:" << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
				printf("%-10g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		double **matrix2 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix2[i] = new double[column_y];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы B." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица B:" << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
				printf("%-10g", matrix2[i][j]);
			cout << endl;
		}
		cout << "Полученна матрица C:" << "C=A+B" << endl;
		double **matrix3 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix3[i] = new double[column_y];
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				matrix3[i][j] = 0;
				matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
				printf("%-10g", matrix3[i][j]);
			}
			cout << endl;
		}
	}
	else if (method == 2)
	{
		cout << "Вы выбрали вычитание матриц!" << endl;
		cout << "Введите размерность матрицы A." << endl;
		cout << "Столбцы: ";
		//Начало проверки вводимых символов
		while (!(cin >> string_x)) {										//Проверяем условие, что вводимые символы соотвествуют типу string_x
			check();
		}
		check_x();
		//Конец проверки вводимых символов
		cout << "Строки: ";
		while (!(cin >> column_y)) {
			check();
		}
		check_y();
		double **matrix1 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix1[i] = new double[column_y];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы A." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица A: \n";
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
				printf("%-10g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		double **matrix2 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix2[i] = new double[column_y];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы B." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица B:" << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
				printf("%-10g", matrix2[i][j]);
			cout << endl;
		}
		cout << "Полученна матрица C: " << "C=A-B" << endl;
		double **matrix3 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix3[i] = new double[column_y];
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				matrix3[i][j] = 0;
				matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
				printf("%-10g", matrix3[i][j]);
			}
			cout << endl;
		}
	}
	else if (method == 3)
	{
		cout << "Вы выбрали умножение матриц!" << endl;
		cout << "Введите размерность матрицы A." << endl;
		cout << "Столбцы: ";
		//Начало проверки вводимых символов
		while (!(cin >> string_x)) {										//Проверяем условие, что вводимые символы соотвествуют типу string_x
			check();
		}
		check_x();
		//Конец проверки вводимых символов
		cout << "Строки: ";
		while (!(cin >> column_y)) {
			check();
		}
		check_y();
		double **matrix1 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix1[i] = new double[column_y];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы A." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица A:" << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
				printf("%-10g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		cout << "Введите размерность матрицы B." << endl;
		cout << "Столбцы: ";
		//Начало проверки вводимых символов
		while (!(cin >> string_n)) {										//Проверяем условие, что вводимые символы соотвествуют типу string_x
			check();
		}
		while (string_n < 1 || string_n > 100) // Цикл заставляющий ввести значения не меньше 1 и не больше 100
		{
			cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl << "Кол-во столбцов" << endl;
			cin >> string_n;
		}
		//Конец проверки вводимых символов
		cout << "Строки: ";
		while (!(cin >> column_m)) {
			check();
		}
		while (column_m < 1 || column_m > 100) // Цикл заставляющий ввести значения не меньше 1 и не больше 100
		{
			cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl << "Кол-во столбцов" << endl;
			cin >> column_m;
		}
		double **matrix2 = new double *[string_n];
		for (i = 0; i < string_n; i++)
			matrix2[i] = new double[column_m];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы B." << endl;
		for (i = 0; i < string_n; i++)
		{
			for (j = 0; j < column_m; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица B:" << endl;
		for (i = 0; i < string_n; i++)
		{
			for (j = 0; j < column_m; j++)
				printf("%-10g", matrix2[i][j]);
			cout << endl;
		}
		cout << "Полученна матрица C: " << "C=A*B" << endl;
		double **matrix3 = new double *[string_n];
		for (i = 0; i < string_n; i++)
			matrix3[i] = new double[column_y];
		i = string_n;
		j = column_y;
		for (i = 0; i < string_n; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				matrix3[i][j] = 0;
				for (int k = 0; k<string_n; k++)
					matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
				printf("%-10g", matrix3[i][j]);
			}
			cout << endl;
		}
	}
	else {
		cout << "Вы выбрали транспонирование матрицы!" << endl;
		cout << "Введите размерность матрицы ." << endl;
		cout << "Столбцы: ";
		//Начало проверки вводимых символов
		while (!(cin >> string_x)) {										//Проверяем условие, что вводимые символы соотвествуют типу string_x
			check();
		}
		//Конец проверки вводимых символов
		cout << "Строки: ";
		while (!(cin >> column_y)) {
			check();
		}
		double **matrix1 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix1[i] = new double[column_y];
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы A." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "Элемент " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//Выводи матрицу
		cout << "Матрица A:" << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
				printf("%-10g", matrix1[i][j]);
			cout << endl;
		}
		cout << "Выводим матрицу" << endl;
		//============================================================================================================

		double **matrix2 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix2[i] = new double[column_y];
		for (i = 0; i < column_y; i++)
		{
			for (j = 0; j < string_x; j++)
			{
				matrix2[i][j] = 0;
				matrix2[i][j] = matrix1[j][i];
				printf("%-10g", matrix2[i][j]);
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}

