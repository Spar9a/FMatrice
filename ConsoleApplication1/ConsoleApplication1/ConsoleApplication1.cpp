// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
int i, j, string_x, column_y, string_n, column_m;
void check_x() {
	while (string_x < 1 || string_x > 100) // ���� ������������ ������ �������� �� ������ 1 � �� ������ 100
	{
		cout << "������������ ����������� �������, ������� ���� ��� ���" << endl << "���-�� ��������" << endl;
		cin >> string_x;
	}
}
void check_y() {
	while (column_y < 1 || column_y > 100) // ���� ������������ ������ �������� �� ������ 1 � �� ������ 100
	{
		cout << "������������ ����������� �������, ������� ���� ��� ���" << endl;
		cout << "���-�� �����" << endl;
		cin >> column_y;
	}
}
void check()
{
	cin.clear();											//���� ��� �� ���, ������� ����
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//���������� ��� ������� �� ����� '\string_x'
	cout << "������������ ��������!" << endl << "���������� ������: ";   //������� ��������� ��� ����� �������� ������ � ��������� ����, ���� �� ������ ������ ������
}

int main()
{
	setlocale(LC_ALL, "Russian"); // add locale language
	cout << "������������, � ������ ��� ������ �������." << endl; // ������� ������� ������
	int method;
	cout << "�������� �������� ������� �� ������ ����������� � ��������." << endl << "������� ����� (1) ��� �������� ������, (2) ���������, (3) ���������, (4) ���������������." << endl;
	cin >> method;
	while (method < 1 || method > 4) // ���� ������� ���������� ������� ���� �� ������� 
	{
		cout << "������� ������������ ��������" << endl << "���������� ��� ���" << endl;
		cin >> method;
	}
	if (method == 1) {
		cout << "�� ������� �������� ������!" << endl; // ��� ����� ������� ������ //��������� 
		cout << "������� ����������� ������� A." << endl;
		cout << "�������: ";
		//������ �������� �������� ��������
		while (!(cin >> string_x)) {										//��������� �������, ��� �������� ������� ������������ ���� string_x
			check();
		}
		check_x();
		//����� �������� �������� ��������
		cout << "������: ";
		while (!(cin >> column_y)) {
			check();
		}
		check_y();
		double **matrix1 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix1[i] = new double[column_y];
		// ��������� ���� �������
		cout << "������� �������� ������� A." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� A:" << endl;
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
		// ��������� ���� �������
		cout << "������� �������� ������� B." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� B:" << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
				printf("%-10g", matrix2[i][j]);
			cout << endl;
		}
		cout << "��������� ������� C:" << "C=A+B" << endl;
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
		cout << "�� ������� ��������� ������!" << endl;
		cout << "������� ����������� ������� A." << endl;
		cout << "�������: ";
		//������ �������� �������� ��������
		while (!(cin >> string_x)) {										//��������� �������, ��� �������� ������� ������������ ���� string_x
			check();
		}
		check_x();
		//����� �������� �������� ��������
		cout << "������: ";
		while (!(cin >> column_y)) {
			check();
		}
		check_y();
		double **matrix1 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix1[i] = new double[column_y];
		// ��������� ���� �������
		cout << "������� �������� ������� A." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� A: \n";
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
		// ��������� ���� �������
		cout << "������� �������� ������� B." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� B:" << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
				printf("%-10g", matrix2[i][j]);
			cout << endl;
		}
		cout << "��������� ������� C: " << "C=A-B" << endl;
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
		cout << "�� ������� ��������� ������!" << endl;
		cout << "������� ����������� ������� A." << endl;
		cout << "�������: ";
		//������ �������� �������� ��������
		while (!(cin >> string_x)) {										//��������� �������, ��� �������� ������� ������������ ���� string_x
			check();
		}
		check_x();
		//����� �������� �������� ��������
		cout << "������: ";
		while (!(cin >> column_y)) {
			check();
		}
		check_y();
		double **matrix1 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix1[i] = new double[column_y];
		// ��������� ���� �������
		cout << "������� �������� ������� A." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� A:" << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
				printf("%-10g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		cout << "������� ����������� ������� B." << endl;
		cout << "�������: ";
		//������ �������� �������� ��������
		while (!(cin >> string_n)) {										//��������� �������, ��� �������� ������� ������������ ���� string_x
			check();
		}
		while (string_n < 1 || string_n > 100) // ���� ������������ ������ �������� �� ������ 1 � �� ������ 100
		{
			cout << "������������ ����������� �������, ������� ���� ��� ���" << endl << "���-�� ��������" << endl;
			cin >> string_n;
		}
		//����� �������� �������� ��������
		cout << "������: ";
		while (!(cin >> column_m)) {
			check();
		}
		while (column_m < 1 || column_m > 100) // ���� ������������ ������ �������� �� ������ 1 � �� ������ 100
		{
			cout << "������������ ����������� �������, ������� ���� ��� ���" << endl << "���-�� ��������" << endl;
			cin >> column_m;
		}
		double **matrix2 = new double *[string_n];
		for (i = 0; i < string_n; i++)
			matrix2[i] = new double[column_m];
		// ��������� ���� �������
		cout << "������� �������� ������� B." << endl;
		for (i = 0; i < string_n; i++)
		{
			for (j = 0; j < column_m; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� B:" << endl;
		for (i = 0; i < string_n; i++)
		{
			for (j = 0; j < column_m; j++)
				printf("%-10g", matrix2[i][j]);
			cout << endl;
		}
		cout << "��������� ������� C: " << "C=A*B" << endl;
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
		cout << "�� ������� ���������������� �������!" << endl;
		cout << "������� ����������� ������� ." << endl;
		cout << "�������: ";
		//������ �������� �������� ��������
		while (!(cin >> string_x)) {										//��������� �������, ��� �������� ������� ������������ ���� string_x
			check();
		}
		//����� �������� �������� ��������
		cout << "������: ";
		while (!(cin >> column_y)) {
			check();
		}
		double **matrix1 = new double *[string_x];
		for (i = 0; i < string_x; i++)
			matrix1[i] = new double[column_y];
		// ��������� ���� �������
		cout << "������� �������� ������� A." << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� A:" << endl;
		for (i = 0; i < string_x; i++)
		{
			for (j = 0; j < column_y; j++)
				printf("%-10g", matrix1[i][j]);
			cout << endl;
		}
		cout << "������� �������" << endl;
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

