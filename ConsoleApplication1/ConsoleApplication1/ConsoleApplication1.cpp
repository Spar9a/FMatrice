// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
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
	if (method == 1)                   
	{
		cout << "Ты выбрал сложение матриц!" << endl; // Тут будет решение матриц
	}
	else if (method == 2)
	{
		cout << "Ты выбрал вычитание матриц!" << endl;
	}
	else if (method == 3)
	{
		cout << "Ты выбрал умножение матриц!" << endl;
	}
	else {
		cout << "Ты выбрал транспонирование матрицы!" << endl;
	}
	system("pause");
    return 0;
}

