#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int i, j, string_x, column_y, string_n, column_m;

void check()																									// Начало функции проверки
{
	cin.clear();																								// если это не так, очищаем ввод
	cin.ignore();																								// игнорируем все символы
	cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";
}   
void inputA()
{
	cout << "Столбцы: ";
	while (!(cin >> string_x)) {
		cin.clear();																							//если это не так, очищаем ввод
		cin.ignore();																							//игнорируем все символы до знака '\string_x'
		cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";										//выводим сообщение что ввели неверный символ и повторяем цикл, пока не введут верный символ
	}
	while (string_x < 1 || string_x > 100)																		// Цикл заставляющий ввести значения не меньше 1 и не больше 100
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
	while (column_y < 1 || column_y > 100)																		// Цикл заставляющий ввести значения не меньше 1 и не больше 100
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
		cin.clear();																							//если это не так, очищаем ввод
		cin.ignore();																							//игнорируем все символы до знака '\string_x'
		cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";										//выводим сообщение что ввели неверный символ и повторяем цикл, пока не введут верный символ
	}
	while (string_n < 1 || string_n > 100)																		// Цикл заставляющий ввести значения не меньше 1 и не больше 100
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
	while (column_m < 1 || column_m > 100)																		// Цикл заставляющий ввести значения не меньше 1 и не больше 100
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
		matrix1[i] = new double[column_y];
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
void transp(double** matrix1, double** matrix2) {																// Начало функции транспонирования
	for (i = 0; i < column_y; i++)																				// Цикл столбцов
	{
		for (j = 0; j < string_x; j++)																			// Цикл строк
		{
			matrix2[i][j] = matrix1[j][i];																		// Перезапись ячеек matrix2, ячейками matrix1
			printf("%-10g", matrix2[i][j]);																		// Вывод результата 
		}
		cout << endl;
	}
}																												// Конец функции транспонирования
int main()
{
	setlocale(LC_ALL, "Russian");																				// Изменение языка ввывода на русский
	cout << "Здравствуйте, я помогу вам решить матрицу." << endl;												// Начало выбора выполняемой операции
	int method;																									
	cout << "Выберите действие которое вы хотите осуществить с матрицей." << endl << "Введите цифру (1) для сложения матриц, (2) вычитание, (3) умножение, (4) траспонирование." << endl;// Доступные операции
	cin >> method;																								// Ввод номера операции
	while (method < 1 || method > 4)																			// Цикл который заставляет выбрать одну из операций
	{
		cout << "Введено недопустимое значение" << endl << "Попробуйте ещё раз" << endl;
		cin >> method;
	}
	if (method == 1) {																							// Начало операции сложения
		cout << "Вы выбрали сложение матриц!" << endl;
		cout << "Введите размерность матрицы A." << endl;														
		inputA();																								// Ввод размерности матрицы A, так же он используется и для матрицы B, так как при сложении матрицы должны быть одинаковыми.
		double** matrix1 = matrix_input(getMatrix1(), string_x, column_y);										// Передача функции gerMatrix1() в которой уже инициализирован массив в функцию matrix_input. Результат matrix_input приравнивается к заданной переменной matrix1.
		cout << "Матрица A:" << endl;
		output(matrix1);																						// Вывод массива ввиде таблицы
																												
		cout << "Введите элементы матрицы B." << endl;
		double** matrix2 = matrix_input(getMatrix1(), string_x, column_y);
		cout << "Матрица B:" << endl;
		output(matrix2);

		cout << "Полученна матрица C:" << "C=A+B" << endl;
		double** matrix3 = getMatrix1();																		// Инициализация новой массива matrix3
		sum(matrix1, matrix2, matrix3);																			// Сложение матриц и вывод результата
	}
	else if (method == 2)																						// Начало операции вычитания
	{
		cout << "Вы выбрали вычитание матриц!" << endl;
		cout << "Введите размерность матрицы A." << endl;
		inputA();																								// Ввод размерности матрицы A, так же он используется и для матрицы B, так как при сложении матрицы должны быть одинаковыми.
		double** matrix1 = matrix_input(getMatrix1(), string_x, column_y);										// Передача функции gerMatrix1() в которой уже инициализирован массив в функцию matrix_input. Результат matrix_input приравнивается к заданной переменной matrix1.
		cout << "Матрица A:" << endl;
		output(matrix1);																						// Вывод массива ввиде таблицы

		cout << "Введите элементы матрицы B." << endl;
		double** matrix2 = matrix_input(getMatrix1(), string_x, column_y);
		cout << "Матрица B:" << endl;
		output(matrix2);

		cout << "Полученна матрица C:" << "C=A+B" << endl;
		double** matrix3 = getMatrix1();																		// Инициализация новой массива matrix3
		minys(matrix1, matrix2, matrix3);																		// Вычитание матриц и вывод результата
	}
	else if (method == 3)																						// Начало операции умножения
	{
		cout << "Вы выбрали умножение матриц!" << endl;
		cout << "Введите размерность матрицы A." << endl;
		inputA();																								// Ввод размерности матрицы A
		double** matrix1 = matrix_input(getMatrix1(), string_x, column_y);										// Передача функции gerMatrix1() в которой уже инициализирован массив в функцию matrix_input. Результат matrix_input приравнивается к заданной переменной matrix1.
		cout << "Матрица A:" << endl;
		output(matrix1);																						// Вывод массива ввиде таблицы

		cout << "Введите элементы матрицы B." << endl;
		inputB();																								// Ввод размерности матрицы B
		double** matrix2 = matrix_input(getMatrix2(), string_n, column_m);										// Передача функции gerMatrix2() в которой уже инициализирован массив в функцию matrix_input. Результат matrix_input приравнивается к заданной переменной matrix2.
		cout << "Матрица B:" << endl;
		output(matrix2);																						// Вывод массива ввиде таблицы

		cout << "Полученна матрица C:" << "C=A+B" << endl;
		double** matrix3 = getMatrix2();																		// Инициализация новой массива matrix3
		multip(matrix1, matrix2, matrix3);																		// Умножение матриц и вывод результата
		
	}

	else {																										// Начало операции транспонирования
		cout << "Вы выбрали транспонирование матрицы!" << endl;													
		cout << "Введите размерность матрицы A." << endl;
		inputA();																								// Ввод размерности матрицы
		double** matrix1 = matrix_input(getMatrix1(), string_x, column_y);										// Передача функции gerMatrix1() в которой уже инициализирован массив в функцию matrix_input. Результат matrix_input приравнивается к заданной переменной matrix1.
		cout << "Матрица A:" << endl;
		output(matrix1);																						// Вывод массива ввиде таблицы

		cout << "Транспонированная матрица A." << endl;
		double** matrix2 = getMatrix1();																		// Инициализация новой массива matrix2
		transp(matrix1, matrix2);																				// Транспонирование матрицы и вывод результата
	}
	system("pause");
	return 0;
}

