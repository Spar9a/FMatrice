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
	cout << "����������, � ������ ���� ������ �������." << endl; // ������� ������� ������
	int method;
	cout << "������ �������� ������� �� ������ ����������� � ��������." << endl << "����� ����� (1) ��� �������� ������, ����� (2) ��� ���������, (3) ���������, (4) ���������������." << endl;
	cin >> method;
	while (method < 1 || method > 4) // ���� ������� ���������� ������� ���� �� ������� 
	{
		cout << "������� ������������ ��������" << endl << "�������� ��� ���" << endl;
		cin >> method;
	}
	if (method == 1){
		cout << "�� ������� �������� ������!" << endl; // ��� ����� ������� ������
		cout << "������� ����������� ������� A. \n";
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
		cout << "������� �������� ������� A.";
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
		cout << "������� A: \n";
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
		// ��������� ���� �������
		cout << "������� �������� ������� B.";
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
		cout << "������� B: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-7g", matrix2
					[i][j]);
			cout << endl;
		}
		cout << "���������� ������� C: \n" << "C=A+B\n";
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
		cout << "�� ������� ��������� ������!" << endl;
		cout << "������� ����������� ������� A. \n";
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
		cout << "������� �������� ������� A.";
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
		cout << "������� A: \n";
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
		// ��������� ���� �������
		cout << "������� �������� ������� B.";
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
		cout << "������� B: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-7g", matrix2
					[i][j]);
			cout << endl;
		}
		cout << "���������� ������� C: \n" << "C=A-B\n";
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
		cout << "�� ������ ��������� ������!" << endl;
		cout << "������� ����������� ������� A. \n";
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
		cout << "������� �������� ������� A.";
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
		cout << "������� A: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-7g", matrix1[i][j]);
			cout << endl;
		}
		//============================================================================================================
		cout << "������� ����������� ������� B. \n";
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
		double **matrix2 = new double *[n];
		for (i = 0; i < n; i++)
			matrix2[i] = new double[m];
		// ��������� ���� �������
		cout << "������� �������� ������� B.";
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
		cout << "������� B: \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%-7g", matrix2
					[i][j]);
			cout << endl;
		}
		cout << "���������� ������� C: \n" << "C=A*B\n";
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
		cout << "�� ������ ���������������� �������!" << endl;
	}
	system("pause");
    return 0;
}

