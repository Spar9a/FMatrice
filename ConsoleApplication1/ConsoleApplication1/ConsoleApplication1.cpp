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
	cout << "������ ����� ������� �������. ����� ����� (1) ��� ������ ������, ����� (2) ��� �������." << endl;
	cin >> method;
	while (method != 1 && method != 2) // ���� ������� ���������� ������� ���� �� ������� 
	{
		cin >> method;
	}
	if (method == 1)                   
	{
		cout << "�� ������ ����� ������!" << endl; // ��� ����� ������� ������ �� ������ ������
	}
	else
	{
		cout << "�� ������ ������ �����!" << endl;
	}
	system("pause");
    return 0;
}

