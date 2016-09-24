#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int i, j, string_x, column_y, string_n, column_m;

void check()
{
	cin.clear();											//если это не так, очищаем ввод
	cin.ignore();	//игнорируем все символы до знака '\string_x'
	cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";
}   
void inputA()
{
	cout << "Столбцы: ";
	while (!(cin >> string_x)) {
		cin.clear();											//если это не так, очищаем ввод
		cin.ignore();	//игнорируем все символы до знака '\string_x'
		cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";   //выводим сообщение что ввели неверный символ и повторяем цикл, пока не введут верный символ
	}
	while (string_x < 1 || string_x > 100) // Цикл заставляющий ввести значения не меньше 1 и не больше 100
	{
		cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl << "Кол-во столбцов" << endl;
		cin >> string_x;
	}
	//Конец проверки вводимых символов
	cout << "Строки: ";
	while (!(cin >> column_y)) {
		cin.clear();											
		cin.ignore();	
		cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";   
	}
	while (column_y < 1 || column_y > 100) // Цикл заставляющий ввести значения не меньше 1 и не больше 100
	{
		cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl;
		cout << "Кол-во строк" << endl;
		cin >> column_y;
	}
}
void inputB()
{
	cout << "Столбцы: ";
	while (!(cin >> string_n)) {
		cin.clear();											//если это не так, очищаем ввод
		cin.ignore();	//игнорируем все символы до знака '\string_x'
		cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";   //выводим сообщение что ввели неверный символ и повторяем цикл, пока не введут верный символ
	}
	while (string_n < 1 || string_n > 100) // Цикл заставляющий ввести значения не меньше 1 и не больше 100
	{
		cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl << "Кол-во столбцов" << endl;
		cin >> string_n;
	}
	//Конец проверки вводимых символов
	cout << "Строки: ";
	while (!(cin >> column_m)) {
		cin.clear();
		cin.ignore();
		cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";
	}
	while (column_m < 1 || column_m > 100) // Цикл заставляющий ввести значения не меньше 1 и не больше 100
	{
		cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl;
		cout << "Кол-во строк" << endl;
		cin >> column_m;
	}
}
double** matrix_input(double** matrix1, int i, int j)
{ 
	int n, m;
	for (n = 0; n < i; n++)
	{
		for (m = 0; m < j; m++)
		{
			cout << "Элемент " << '[' << n + 1 << ";" << m + 1 << "]: ";
			while (!(cin >> matrix1[n][m])) {
				check();
			}
		}
	}
	return matrix1;
}
double** getMatrix1() {
	double **matrix1 = new double *[string_x];
	for (i = 0; i < string_x; i++)
		matrix1[i] = new double[column_y];
	return matrix1;
}
double** getMatrix2() {
	double **matrix1 = new double *[string_n];
	for (i = 0; i < string_n; i++)
		matrix1[i] = new double[column_m];
	return matrix1;
}
void output(double** matrix1) {
	 for (i = 0; i < string_x; i++)
	 {
		 for (j = 0; j < column_y; j++)
			 printf("%-10g", matrix1[i][j]);
		 cout << endl;
	 }
 }
void sum(double** matrix1, double** matrix2, double** matrix3) {
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
void minys(double** matrix1, double** matrix2, double** matrix3) {
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
void multip(double** matrix1, double** matrix2, double** matrix3) {
	i = string_n;
	j = column_y;
	for (i = 0; i < string_n; i++)
	{
		for (j = 0; j < column_y; j++)
		{
			matrix3[i][j] = 0;
			for (int k = 0; k < string_n; k++)
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			printf("%-10g", matrix3[i][j]);
		}
		cout << endl;
	}
}
void transp(double** matrix1, double** matrix2) {
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
		//Начало проверки вводимых символов

		inputA();

		double** matrix1 = matrix_input(getMatrix1(), string_x, column_y);
		cout << "Матрица A:" << endl;
		output(matrix1);
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы B." << endl;

		//Выводи матрицу
		double** matrix2 = matrix_input(getMatrix1(), string_x, column_y);
		cout << "Матрица B:" << endl;
		output(matrix2);

		//============================================================================================================
		cout << "Полученна матрица C:" << "C=A+B" << endl;
		double** matrix3 = getMatrix1();
		sum(matrix1, matrix2, matrix3);
	}
	else if (method == 2)
	{
		cout << "Вы выбрали вычитание матриц!" << endl;
		cout << "Введите размерность матрицы A." << endl;
		//Начало проверки вводимых символов

		inputA();

		double** matrix1 = matrix_input(getMatrix1(), string_x, column_y);
		cout << "Матрица A:" << endl;
		output(matrix1);
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы B." << endl;

		//Выводи матрицу
		double** matrix2 = matrix_input(getMatrix1(), string_x, column_y);
		cout << "Матрица B:" << endl;
		output(matrix2);

		//============================================================================================================
		cout << "Полученна матрица C:" << "C=A+B" << endl;
		double** matrix3 = getMatrix1();
		minys(matrix1, matrix2, matrix3);
	}
	else if (method == 3)
	{
		cout << "Вы выбрали умножение матриц!" << endl;
		cout << "Введите размерность матрицы A." << endl;

		inputA();

		double** matrix1 = matrix_input(getMatrix1(), string_x, column_y);
		cout << "Матрица A:" << endl;
		output(matrix1);
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы B." << endl;
		inputB();
		//Выводи матрицу
		double** matrix2 = matrix_input(getMatrix2(), string_n, column_m);
		cout << "Матрица B:" << endl;
		output(matrix2);

		//============================================================================================================
		cout << "Полученна матрица C:" << "C=A+B" << endl;
		double** matrix3 = getMatrix1();
		multip(matrix1, matrix2, matrix3);
		
	}

	else {
		cout << "Вы выбрали транспонирование матрицы!" << endl;
		cout << "Введите размерность матрицы ." << endl;
		//Начало проверки вводимых символов
		inputA();

		double** matrix1 = matrix_input(getMatrix1(), string_x, column_y);
		cout << "Матрица A:" << endl;
		output(matrix1);
		// Заполняем нашу матрицу
		cout << "Введите элементы матрицы B." << endl;

		//Выводи матрицу
		
		double** matrix2 = getMatrix1();
		transp(matrix1, matrix2);
	}
	system("pause");
	return 0;
}

