#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int i, j, string_x, column_y, string_n, column_m;

void check()																									// ������ ������� ��������
{
	cin.clear();																								// ���� ��� �� ���, ������� ����
	cin.ignore();																								// ���������� ��� �������
	cout << "������������ ��������!" << endl << "���������� ������: ";
}   
void inputA()
{
	cout << "�������: ";
	while (!(cin >> string_x)) {
		cin.clear();																							//���� ��� �� ���, ������� ����
		cin.ignore();																							//���������� ��� ������� �� ����� '\string_x'
		cout << "������������ ��������!" << endl << "���������� ������: ";										//������� ��������� ��� ����� �������� ������ � ��������� ����, ���� �� ������ ������ ������
	}
	while (string_x < 1 || string_x > 100)																		// ���� ������������ ������ �������� �� ������ 1 � �� ������ 100
	{
		cout << "������������ ����������� �������, ������� ���� ��� ���" << endl << "���-�� ��������" << endl;
		cin >> string_x;
	}
																												//����� �������� �������� ��������
	cout << "������: ";
	while (!(cin >> column_y)) {
		cin.clear();											
		cin.ignore();	
		cout << "������������ ��������!" << endl << "���������� ������: ";   
	}
	while (column_y < 1 || column_y > 100)																		// ���� ������������ ������ �������� �� ������ 1 � �� ������ 100
	{
		cout << "������������ ����������� �������, ������� ���� ��� ���" << endl;
		cout << "���-�� �����" << endl;
		cin >> column_y;
	}
}
void inputB()
{
	cout << "�������: ";
	while (!(cin >> string_n)) {
		cin.clear();																							//���� ��� �� ���, ������� ����
		cin.ignore();																							//���������� ��� ������� �� ����� '\string_x'
		cout << "������������ ��������!" << endl << "���������� ������: ";										//������� ��������� ��� ����� �������� ������ � ��������� ����, ���� �� ������ ������ ������
	}
	while (string_n < 1 || string_n > 100)																		// ���� ������������ ������ �������� �� ������ 1 � �� ������ 100
	{
		cout << "������������ ����������� �������, ������� ���� ��� ���" << endl << "���-�� ��������" << endl;
		cin >> string_n;
	}
																												//����� �������� �������� ��������
	cout << "������: ";
	while (!(cin >> column_m)) {
		cin.clear();
		cin.ignore();
		cout << "������������ ��������!" << endl << "���������� ������: ";
	}
	while (column_m < 1 || column_m > 100)																		// ���� ������������ ������ �������� �� ������ 1 � �� ������ 100
	{
		cout << "������������ ����������� �������, ������� ���� ��� ���" << endl;
		cout << "���-�� �����" << endl;
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
			cout << "������� " << '[' << n + 1 << ";" << m + 1 << "]: ";
			while (!(cin >> matrix1[n][m])) {
				check();
			}
		}
	}
	return matrix1;
}
/*double** getMatrix1() {
	double **matrix1 = new double *[string_x];
	for (i = 0; i < string_x; i++)
		matrix1[i] = new double[column_y];
	return matrix1;
}
double** getMatrix2() {
	double **matrix1 = new double *[string_x];
	for (i = 0; i < string_x; i++)
		matrix1[i] = new double[column_m];
	return matrix1;
} */
double** getMatrix(int x, int y) {
	double **matrix = new double *[x];
	for (i = 0; i < x; i++)
		matrix[i] = new double[y];
	return matrix;
}

int greater_value(int x, int y) {
	if (x > y) {
		return x;
	}
	else return y;
	return x;
}
void output(double** matrix) {
	 for (i = 0; i < string_x; i++)
	 {
		 for (j = 0; j < column_y; j++)
			 printf("%-10g", matrix[i][j]);
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
	for (i = 0; i < string_x; i++)
	{
		for (j = 0; j < column_m; j++)
		{
			matrix3[i][j] = 0;
			for (int k = 0; k < string_x; k++)
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			printf("%-10g", matrix3[i][j]);
		}
		cout << endl;
	}
}
void transp(double** matrix1, double** matrix2) {																// ������ ������� ����������������
	for (i = 0; i < column_y; i++)																				// ���� ��������
	{
		for (j = 0; j < string_x; j++)																			// ���� �����
		{
			matrix2[i][j] = matrix1[j][i];																		// ���������� ����� matrix2, �������� matrix1
			printf("%-10g", matrix2[i][j]);																		// ����� ���������� 
		}
		cout << endl;
	}
}																												// ����� ������� ����������������

int main()
{
	setlocale(LC_ALL, "Russian");																				// ��������� ����� ������� �� �������
	cout << "������������, � ������ ��� ������ �������." << endl;												// ������ ������ ����������� ��������
	int method;																									
	cout << "�������� �������� ������� �� ������ ����������� � ��������." << endl << "������� ����� (1) ��� �������� ������, (2) ���������, (3) ���������, (4) ���������������." << endl;// ��������� ��������
	cin >> method;																								// ���� ������ ��������
	while (method < 1 || method > 4)																			// ���� ������� ���������� ������� ���� �� ��������
	{
		cout << "������� ������������ ��������" << endl << "���������� ��� ���" << endl;
		cin >> method;
	}
	if (method == 1) {																							// ������ �������� ��������
		cout << "�� ������� �������� ������!" << endl;
		cout << "������� ����������� ������� A." << endl;														
		inputA();																								// ���� ����������� ������� A, ��� �� �� ������������ � ��� ������� B, ��� ��� ��� �������� ������� ������ ���� �����������.
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);						// �������� ������� gerMatrix1() � ������� ��� ��������������� ������ � ������� matrix_input. ��������� matrix_input �������������� � �������� ���������� matrix1.
		cout << "������� A:" << endl;
		output(matrix1);																						// ����� ������� ����� �������
																												
		cout << "������� �������� ������� B." << endl;
		double** matrix2 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "������� B:" << endl;
		output(matrix2);

		cout << "��������� ������� C:" << "C=A+B" << endl;
		double** matrix3 = getMatrix(string_x, column_y);														// ������������� ����� ������� matrix3
		sum(matrix1, matrix2, matrix3);																			// �������� ������ � ����� ����������
	}
	else if (method == 2)																						// ������ �������� ���������
	{
		cout << "�� ������� ��������� ������!" << endl;
		cout << "������� ����������� ������� A." << endl;
		inputA();																								// ���� ����������� ������� A, ��� �� �� ������������ � ��� ������� B, ��� ��� ��� �������� ������� ������ ���� �����������.
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);						// �������� ������� gerMatrix1() � ������� ��� ��������������� ������ � ������� matrix_input. ��������� matrix_input �������������� � �������� ���������� matrix1.
		cout << "������� A:" << endl;
		output(matrix1);																						// ����� ������� ����� �������

		cout << "������� �������� ������� B." << endl;
		double** matrix2 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);
		cout << "������� B:" << endl;
		output(matrix2);

		cout << "��������� ������� C:" << "C=A+B" << endl;
		double** matrix3 = getMatrix(string_x, column_y);														// ������������� ����� ������� matrix3
		minys(matrix1, matrix2, matrix3);																		// ��������� ������ � ����� ����������
	}
	else if (method == 3)																						// ������ �������� ���������
	{
		cout << "�� ������� ��������� ������!" << endl;
		cout << "������� ����������� ������� A." << endl;
		inputA();																								// ���� ����������� ������� A
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);						// �������� ������� gerMatrix1() � ������� ��� ��������������� ������ � ������� matrix_input. ��������� matrix_input �������������� � �������� ���������� matrix1.
		cout << "������� A:" << endl;
		output(matrix1);																						// ����� ������� ����� �������

		cout << "������� �������� ������� B." << endl;
		inputB();																								// ���� ����������� ������� B
		double** matrix2 = matrix_input(getMatrix(string_n, column_m), string_n, column_m);						// �������� ������� gerMatrix2() � ������� ��� ��������������� ������ � ������� matrix_input. ��������� matrix_input �������������� � �������� ���������� matrix2.
		cout << "������� B:" << endl;
		output(matrix2);																						// ����� ������� ����� �������

		cout << "��������� ������� C:" << "C=A+B" << endl;
		double** matrix3 = getMatrix(greater_value(string_x, string_n), greater_value(column_m, column_y));														// ������������� ����� ������� matrix3
		multip(matrix1, matrix2, matrix3);																		// ��������� ������ � ����� ����������
		
	}

	else {																										// ������ �������� ����������������
		cout << "�� ������� ���������������� �������!" << endl;													
		cout << "������� ����������� ������� A." << endl;
		inputA();																								// ���� ����������� �������
		double** matrix1 = matrix_input(getMatrix(string_x, column_y), string_x, column_y);						// �������� ������� gerMatrix1() � ������� ��� ��������������� ������ � ������� matrix_input. ��������� matrix_input �������������� � �������� ���������� matrix1.
		cout << "������� A:" << endl;
		output(matrix1);																						// ����� ������� ����� �������

		cout << "����������������� ������� A." << endl;
		double** matrix2 = getMatrix(string_x, column_y);														// ������������� ����� ������� matrix2
		transp(matrix1, matrix2);																				// ���������������� ������� � ����� ����������
	}
	system("pause");
	return 0;
}

