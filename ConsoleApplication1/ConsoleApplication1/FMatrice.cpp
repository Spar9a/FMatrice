#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
int i, j, string_x, column_y, string_n, column_m;

void check()												// ������� �������� �� ����
{
	cin.clear();
	cin.ignore();
	cout << "������������ ��������!" << endl << "���������� ������: ";
}

void inputA()												// ������� ������� ����������� ������� ��� ������ �������
{
	cout << "������: ";
	while (!(cin >> string_x))
		check();
	while (string_x < 1)					// ���� �������� �������� �����������, ����� ��� �� ���� ����� �������������� ��������
	{
		cout << "������������ ����������� �������, ������� ���� ��� ���" << endl << "���-�� �����" << endl;
		cin >> string_x;
	}
	cout << "�������: ";
	while (!(cin >> column_y)) 
		check();
	while (column_y < 1)
	{
		cout << "������������ ����������� �������, ������� ���� ��� ���" << endl;
		cout << "���-�� ��������" << endl;
		cin >> column_y;
	}
}

void inputB()												// ������� ������� ����������� ������� ��� ������ ������� (������������ � ���������)
{
	cout << "������: ";
	while (!(cin >> string_n))
		check();
	while (string_n < 1 || string_n > 100)
	{
		cout << "������������ ����������� �������, ������� ���� ��� ���" << endl << "���-�� �����" << endl;
		cin >> string_n;
	}

	cout << "�������: ";
	while (!(cin >> column_m)) 
		check();
	while (column_m < 1 || column_m > 100)
	{
		cout << "������������ ����������� �������, ������� ���� ��� ���" << endl;
		cout << "���-�� ��������" << endl;
		cin >> column_m;
	}
}

double** matrix_input(double** matrix1, int i, int j)		// ������� ���������� ����� ������� ����������
{
	int n, m;
	for (n = 0; n < i; n++)
	{
		for (m = 0; m < j; m++)
		{
			cout << "������� " << '[' << n + 1 << ";" << m + 1 << "]: ";
			while (!(cin >> matrix1[n][m])) {
				check();
			}
		}
	}
	return matrix1;
}

double** getMatrix(int x, int y) {							// ������� ������������� ������� �� �������� �������
	double **matrix = new double *[x];
	for (i = 0; i < x; i++)
		matrix[i] = new double[y];
	return matrix;
}

void output(double** matrix, int x, int y) {				// ������� ������ ������� �� �����
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
			printf("%-10g", matrix[i][j]);
		cout << endl;
	}
}

double** sum(double** matrix1, double** matrix2) {			// ������� �������� ������
	double** matrix3 = getMatrix(string_x, column_y);		// ������ ���������� ����� � ������� ��� ���������� ����� ������
	for (i = 0; i < string_x; i++)							// ���� ����� matrix1
		for (j = 0; j < column_y; j++)						// ���� ������� matrix1
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];	// ����������� ������
	return matrix3;											// ����������� ����������
}

double** minys(double** matrix1, double** matrix2) {		// ������� ��������� ������
	double** matrix3 = getMatrix(string_x, column_y);		// ������ ���������� ����� � ������� ��� ���������� ������ ������
	for (i = 0; i < string_x; i++)							// ���� ����� matrix1
		for (j = 0; j < column_y; j++)						// ���� ������� matrix1
			matrix3[i][j] = matrix1[i][j] - matrix2[i][j];	// ��������� ������
	return matrix3;											// ����������� ����������
}

double** multip(double** matrix1, double** matrix2) {	// ������� ��������� ���� ������, ���������� ������������ ���� ������.
	double** matrix3 = getMatrix(string_x, column_m);	// ������ ���������� ����� � ������� ��� �������� ������������ ������.
	for (i = 0; i < string_x; i++)						// ���� ����� matrix1
	{
		for (j = 0; j < column_m; j++)					// ���� ������� matrix2
		{
			matrix3[i][j] = 0;
			for (int k = 0; k < string_n; k++)			// ���� ����������������� ��������� ����� ������	
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];	// ����������� ������������ ����� ������
		}
	}
	return matrix3;										// ����������� ����������
}

double** transp(double** matrix1) {	// ������� �������������� �������. ������ ������� ������ � ��������� � ���������� ���������
	double** matrix2 = getMatrix(string_x, column_y);
	for (i = 0; i < column_y; i++)
		for (j = 0; j < string_x; j++)
			matrix2[i][j] = matrix1[j][i];
	return matrix2;	
}

int main()
{
	setlocale(LC_ALL, "Russian");	// ����� ������� ������
	cout << "������������, � ������ ��� ������ �������." << endl;	// ����� �������� � ���������
	int method;
	cout << "�������� �������� ������� �� ������ ����������� � ��������." << endl << "������� ����� (1) ��� �������� ������, (2) ���������, (3) ���������, (4) ���������������." << endl;
	while (!(cin >> method))
		check();
	while (method < 1 || method > 4)	// �������� ������ ��������
	{
		cout << "������� ������������ ��������" << endl << "���������� ��� ���" << endl;
		cin >> method;
	}
	if (method == 1) {	// �������� ��������
		cout << "�� ������� �������� ������!" << endl;
		cout << "������� ����������� ������� A." << endl;
		inputA();
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "������� A:" << endl;
		output(matrix1, string_x, column_y);

		cout << "������� �������� ������� B." << endl;
		double** matrix2 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "������� B:" << endl;
		output(matrix2, string_x, column_y);

		cout << "��������� ������� C:" << "C=A+B" << endl;
		double** matrix3 = sum(matrix1, matrix2);
		output(matrix3, string_x, column_y);
	}
	else if (method == 2)	// �������� ���������
	{
		cout << "�� ������� ��������� ������!" << endl;
		cout << "������� ����������� ������� A." << endl;
		inputA();
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "������� A:" << endl;
		output(matrix1, string_x, column_y);

		cout << "������� �������� ������� B." << endl;
		double** matrix2 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "������� B:" << endl;
		output(matrix2, string_x, column_y);

		cout << "��������� ������� C:" << "C=A-B" << endl;
		double** matrix3 = minys(matrix1, matrix2);
		output(matrix3, string_x, column_y);
	}
	else if (method == 3)	// �������� ���������
	{
		cout << "�� ������� ��������� ������!" << endl;
		cout << "������� ����������� ������� A." << endl;
		inputA();
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "������� A:" << endl;
		output(matrix1, string_x, column_y);

		cout << "������� �������� ������� B." << endl;
		inputB();
		double** matrix2 = matrix_input(getMatrix(string_n, column_m), string_n, column_m);
		cout << "������� B:" << endl;
		output(matrix2, string_n, column_m);

		cout << "��������� ������� C:" << "C=A*B" << endl;

		double** matrix3 = multip(matrix1, matrix2);
		output(matrix3, string_x, column_m);

	}
	else {	// �������� ����������������
		cout << "�� ������� ���������������� �������!" << endl;
		cout << "������� ����������� ������� A." << endl;
		inputA();
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "������� A:" << endl;
		output(matrix1, string_x, column_y);

		cout << "����������������� ������� A." << endl;
		double** matrix2 = transp(matrix1);
		output(matrix2, string_x, column_y);
	}
	system("pause");
	return 0;
}