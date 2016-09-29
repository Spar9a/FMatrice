#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
int i, j, string_x, column_y, string_n, column_m;

void check()												// Функция проверки на ввод
{
	cin.clear();
	cin.ignore();
	cout << "Недопустимое значение!" << endl << "Попробуйте заново: ";
}

void inputA()												// Функция задания размерности массива для первой матрицы
{
	cout << "Строки: ";
	while (!(cin >> string_x))
		check();
	while (string_x < 1)					// Цикл проверки значения размерности, чтобы она не была равна отрицательному значению
	{
		cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl << "Кол-во строк" << endl;
		cin >> string_x;
	}
	cout << "Столбцы: ";
	while (!(cin >> column_y))
		check();
	while (column_y < 1)
	{
		cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl;
		cout << "Кол-во столбцов" << endl;
		cin >> column_y;
	}
}

void inputB()												// Функция задания размерности массива для второй матрицы (используется в умножении)
{
	cout << "Строки: ";
	while (!(cin >> string_n))
		check();
	while (string_n < 1 || string_n > 100)
	{
		cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl << "Кол-во строк" << endl;
		cin >> string_n;
	}

	cout << "Столбцы: ";
	while (!(cin >> column_m))
		check();
	while (column_m < 1 || column_m > 100)
	{
		cout << "Недопустимая размерность матрицы, повтори ввод ещё раз" << endl;
		cout << "Кол-во столбцов" << endl;
		cin >> column_m;
		column_m++;
	}
}

double** matrix_input(double** matrix1, int i, int j)		// Функция заполнения ячеек матрицы значениями
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

double** getMatrix(int x, int y) {							// Функция инициализации матрицы по заданому размеру
	double **matrix = new double *[x];
	for (i = 0; i < x; i++)
		matrix[i] = new double[y];
	return matrix;
}

void output(double** matrix, int x, int y) {				// Функция вывода матрицы на экран
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
			printf("%-10g", matrix[i][j]);
		cout << endl;
	}
}
double Gause(double** matrix1) {
	double k;
	double** matrix3 = getMatrix(string_x, column_y);
	//цикл поиска значения равного единице
	for (i = 0; i < string_x; i++) {
		for (j = 1; j = matrix1[string_x][0]; j++) {
		 k = matrix1[i][0] == 1;
			
		}
		cout << k;
	}
	return k;
}

double** sum(double** matrix1, double** matrix2) {			// Функция сложения матриц
	double** matrix3 = getMatrix(string_x, column_y);		// Задаем количество строк и колонок для результата суммы матриц
	for (i = 0; i < string_x; i++)							// Цикл строк matrix1
		for (j = 0; j < column_y; j++)						// Цикл колонок matrix1
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];	// Складывание матриц
	return matrix3;											// Возвращение результата
}

double** minys(double** matrix1, double** matrix2) {		// Функция вычитания матриц
	double** matrix3 = getMatrix(string_x, column_y);		// Задаем количество строк и колонок для результата разниц матриц
	for (i = 0; i < string_x; i++)							// Цикл строк matrix1
		for (j = 0; j < column_y; j++)						// Цикл колонок matrix1
			matrix3[i][j] = matrix1[i][j] - matrix2[i][j];	// Вычитание матриц
	return matrix3;											// Возвращение результата
}

double** multip(double** matrix1, double** matrix2) {	// Функция умножения двух матриц, возвращает произведения двух матриц.
	double** matrix3 = getMatrix(string_x, column_m);	// Задаем количество строк и колонок для будущего произведения матриц.
	for (i = 0; i < string_x; i++)						// Цикл строк matrix1
	{
		for (j = 0; j < column_m; j++)					// Цикл колонок matrix2
		{
			matrix3[i][j] = 0;
			for (int k = 0; k < string_n; k++)			// Цикл последовательного умножения ячеек матриц	
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];	// Сумирование произведений ячеек матриц
		}
	}
	return matrix3;										// Возвращение результата
}

double** transp(double** matrix1) {	// Функция транспонировая матрицы. Меняет местами строки с колонками и возвращает результат
	double** matrix2 = getMatrix(column_y, string_x);
	for (i = 0; i < column_y; i++)
		for (j = 0; j < string_x; j++)
			matrix2[i][j] = matrix1[j][i];
	return matrix2;
}

double** multip_number(double** matrix1, double q) {			// Функция сложения матриц
	double** matrix3 = getMatrix(string_x, column_y);		// Задаем количество строк и колонок для результата суммы матриц
	for (i = 0; i < string_x; i++)							// Цикл строк matrix1
		for (j = 0; j < column_y; j++)						// Цикл колонок matrix1
			matrix3[i][j] = matrix1[i][j] * q;	// Складывание матриц
	return matrix3;											// Возвращение результата
}

int main()
{
	setlocale(LC_ALL, "Russian");	// Смена текущей локали
	cout << "Здравствуйте, я помогу вам решить матрицу." << endl;	// Выбор операции с матрицами
	int method;
	cout << "Выберите действие которое вы хотите осуществить с матрицей." << endl << "Введите цифру (1) для сложения матриц, (2) вычитание, (3) умножение, (4) траспонирование, (5) умножение на число, (6)Метод Гауса (ALPHA)." << endl;
	while (!(cin >> method))
		check();
	while (method < 1 || method > 6)	// Проверка выбора операции
	{
		cout << "Введено недопустимое значение" << endl << "Попробуйте ещё раз" << endl;
		cin >> method;
	}
	if (method == 1) {	// Операция сложения
		cout << "Вы выбрали сложение матриц!" << endl;
		cout << "Введите размерность матрицы A." << endl;
		inputA();
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "Матрица A:" << endl;
		output(matrix1, string_x, column_y);

		cout << "Введите элементы матрицы B." << endl;
		double** matrix2 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "Матрица B:" << endl;
		output(matrix2, string_x, column_y);

		cout << "Полученна матрица C:" << "C=A+B" << endl;
		double** matrix3 = sum(matrix1, matrix2);
		output(matrix3, string_x, column_y);
	}
	else if (method == 2)	// Операция вычитания
	{
		cout << "Вы выбрали вычитание матриц!" << endl;
		cout << "Введите размерность матрицы A." << endl;
		inputA();
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "Матрица A:" << endl;
		output(matrix1, string_x, column_y);

		cout << "Введите элементы матрицы B." << endl;
		double** matrix2 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "Матрица B:" << endl;
		output(matrix2, string_x, column_y);

		cout << "Полученна матрица C:" << "C=A-B" << endl;
		double** matrix3 = minys(matrix1, matrix2);
		output(matrix3, string_x, column_y);
	}
	else if (method == 3)	// Операция умножения
	{
		cout << "Вы выбрали умножение матриц!" << endl;
		cout << "Введите размерность матрицы A." << endl;
		inputA();
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "Матрица A:" << endl;
		output(matrix1, string_x, column_y);

		cout << "Введите элементы матрицы B." << endl;
		inputB();
		double** matrix2 = matrix_input(getMatrix(string_n, column_m), string_n, column_m);
		cout << "Матрица B:" << endl;
		output(matrix2, string_n, column_m);

		cout << "Полученна матрица C:" << "C=A*B" << endl;

		double** matrix3 = multip(matrix1, matrix2);
		output(matrix3, string_x, column_m);

	}
	else if (method == 4) {	// Операция транспонирования
		cout << "Вы выбрали транспонирование матрицы!" << endl;
		cout << "Введите размерность матрицы A." << endl;
		inputA();
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "Матрица A:" << endl;
		output(matrix1, string_x, column_y);

		cout << "Транспонированная матрица A." << endl;
		double** matrix2 = transp(matrix1);
		output(matrix2, column_y, string_x);
	}
	else if ( method==5) {	// Операция сложения
		double q;
		cout << "Вы выбрали умножение матрицы на число!" << endl;
		cout << "Введите размерность матрицы A." << endl;
		inputA();
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "Матрица A:" << endl;
		output(matrix1, string_x, column_y);

		cout << "Введите число на которые будет происходить умножение" << endl;
		cin >> q;

		cout << "Полученна матрица C:" << "C=A*B" << endl;
		double** matrix3 = multip_number(matrix1, q);
		output(matrix3, string_x, column_y);
	}
	else {	// Метод Гауса
		cout << "Вы выбрали метод Гауса" << endl;
		cout << "Введите размерность матрицы." << endl;
		inputA();
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "Матрица A:" << endl;
		output(matrix1, string_x, column_y);
		
	}
	system("pause");
	return 0;
}