// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

void check()
{
	cin.clear();											//���� ��� �� ���, ������� ����
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//���������� ��� ������� �� ����� '\n'
	cout << "������������ ��������!" << endl << "���������� ������: ";   //������� ��������� ��� ����� �������� ������ � ��������� ����, ���� �� ������ ������ ������
}

int main()
{
	setlocale(LC_ALL, "Russian"); // add locale language
	cout << "����������, � ������ ��� ������ �������." << endl; // ������� ������� ������
	int method;
	cout << "�������� �������� ������� �� ������ ����������� � ��������." << endl << "������� ����� (1) ��� �������� ������, (2) ���������, (3) ���������, (4) ���������������." << endl;
	cin >> method;
	while (method < 1 || method > 4) // ���� ������� ���������� ������� ���� �� ������� 
	{
		cout << "������� ������������ ��������" << endl << "�������� ��� ���" << endl;
		cin >> method;
	}
	if (method == 1) {
		cout << "�� ������� �������� ������!" << endl; // ��� ����� ������� ������ //��������� 
		cout << "������� ����������� ������� A." << endl;
		int i, j, n, m;
		cout << "�������: ";
		//������ �������� �������� ��������
		while (!(cin >> n)) {										//��������� �������, ��� �������� ������� ������������ ���� n
			check();
		}
		//����� �������� �������� ��������
		cout << "������: ";
		while (!(cin >> m)) {
			check();
		}
		double **matrix1 = new double *[n];
		for (i = 0; i < n; i++)
			matrix1[i] = new double[m];
		// ��������� ���� �������
		cout << "������� �������� ������� A." << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� A:" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-10g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		double **matrix2 = new double *[n];
		for (i = 0; i < n; i++)
			matrix2[i] = new double[m];
		// ��������� ���� �������
		cout << "������� �������� ������� B." << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� B:" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-10g", matrix2[i][j]);
			cout << endl;
		}
		cout << "���������� ������� C:" << "C=A+B" << endl;
		double **matrix3 = new double *[n];
		for (i = 0; i < n; i++)
			matrix3[i] = new double[m];
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
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
		int i, j, n, m;
		cout << "�������: ";
		//������ �������� �������� ��������
		while (!(cin >> n)) {										//��������� �������, ��� �������� ������� ������������ ���� n
			check();
		}
		//����� �������� �������� ��������
		cout << "������: ";
		while (!(cin >> m)) {
			check();
		}
		double **matrix1 = new double *[n];
		for (i = 0; i < n; i++)
			matrix1[i] = new double[m];
		// ��������� ���� �������
		cout << "������� �������� ������� A." << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� A: " << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-10g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		double **matrix2 = new double *[n];
		for (i = 0; i < n; i++)
			matrix2[i] = new double[m];
		// ��������� ���� �������
		cout << "������� �������� ������� B." << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� B:" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-10g", matrix2
					[i][j]);
			cout << endl;
		}
		cout << "���������� ������� C: " << "C=A-B" << endl;
		double **matrix3 = new double *[n];
		for (i = 0; i < n; i++)
			matrix3[i] = new double[m];
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
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
		int i, j, n, m, c, v;
		cout << "�������: ";
		//������ �������� �������� ��������
		while (!(cin >> n)) {										//��������� �������, ��� �������� ������� ������������ ���� n
			check();
		}
		//����� �������� �������� ��������
		cout << "������: ";
		while (!(cin >> m)) {
			check();
		}
		double **matrix1 = new double *[n];
		for (i = 0; i < n; i++)
			matrix1[i] = new double[m];
		// ��������� ���� �������
		cout << "������� �������� ������� A." << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� A:" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-10g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		cout << "������� ����������� ������� B." << endl;
		cout << "�������: ";
		//������ �������� �������� ��������
		while (!(cin >> c)) {										//��������� �������, ��� �������� ������� ������������ ���� n
			check();
		}
		//����� �������� �������� ��������
		cout << "������: ";
		while (!(cin >> v)) {
			check();
		}
		double **matrix2 = new double *[c];
		for (i = 0; i < c; i++)
			matrix2[i] = new double[v];
		// ��������� ���� �������
		cout << "������� �������� ������� B." << endl;
		for (i = 0; i < c; i++)
		{
			for (j = 0; j < v; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix2[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� B:" << endl;
		for (i = 0; i < c; i++)
		{
			for (j = 0; j < v; j++)
				printf("%-10g", matrix2[i][j]);
			cout << endl;
		}
		cout << "���������� ������� C: " << "C=A*B" << endl;
		double **matrix3 = new double *[c];
		for (i = 0; i < c; i++)
			matrix3[i] = new double[m];
		i = c;
		j = m;
		for (i = 0; i < c; i++)
		{
			for (j = 0; j < m; j++)
			{
				matrix3[i][j] = 0;
				for (int k = 0; k < c; k++) 
					matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
				printf("%-10g", matrix3[i][j]);
			}
			cout << endl;
		}
	}
	else {
		cout << "�� ������� ���������������� �������!" << endl;
		cout << "������� ����������� ������� ." << endl;
		int i, j, n, m;
		cout << "�������: ";
		//������ �������� �������� ��������
		while (!(cin >> n)) {										//��������� �������, ��� �������� ������� ������������ ���� n
			check();
		}
		//����� �������� �������� ��������
		cout << "������: ";
		while (!(cin >> m)) {
			check();
		}
		double **matrix1 = new double *[n];
		for (i = 0; i < n; i++)
			matrix1[i] = new double[m];
		// ��������� ���� �������
		cout << "������� �������� ������� A." << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "������� " << '[' << i + 1 << ";" << j + 1 << "]: ";
				while (!(cin >> matrix1[i][j])) {
					check();
				}
			}

		}
		//������ �������
		cout << "������� A:" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-10g", matrix1[i][j]);
			cout << endl;
		}
		cout << "������� �������" << endl;
		//============================================================================================================
		
		double **matrix2 = new double *[n];
		for (i = 0; i < n; i++)
			matrix2[i] = new double[m];
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
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

