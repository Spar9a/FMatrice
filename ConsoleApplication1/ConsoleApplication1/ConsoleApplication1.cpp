// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
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
	if (method == 1)                   
	{
		cout << "�� ������ �������� ������!" << endl; // ��� ����� ������� ������
	}
	else if (method == 2)
	{
		cout << "�� ������ ��������� ������!" << endl;
	}
	else if (method == 3)
	{
		cout << "�� ������ ��������� ������!" << endl;
	}
	else {
		cout << "�� ������ ���������������� �������!" << endl;
	}
	system("pause");
    return 0;
}

