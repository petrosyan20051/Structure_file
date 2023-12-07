#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

#define PATH1 "data/input.txt"
#define PATH2 "data/output.txt"

int main_t()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream file(PATH1);
	if (file.is_open())
		cout << "���� ��� ������ �������� ������ ������� ������!" << endl;
	else
	{
		cout << "���� ��� ������ �������� ������ �� ������!" << endl;
		return 1;
	}

	string inf = "";
	unsigned short int i = 0, k = 0;
	cout << "�������� ������ ���������� � �������� (������� '*' ��� ���������� �����)" << endl;
	do
	{
		if (i == 5)
		{
			file << '\n';
			i = 0;
			k++;
		}
		switch (i)
		{
		case 0:
			cout << "������� �������: ";
			break;
		case 1:
			cout << "������� ������������: ";
			break;
		case 2:
			cout << "������� ���������: ";
			break;
		case 3:
			cout << "������� ����������: ";
			break;
		case 4:
			cout << "������� ����: ";
			break;
		}
		cin >> inf;
		file << inf << ' ';
	} while (inf != "*");

	cout << "������ � ���� ������� ���������!" << endl;
	file.close();

	struct data_base
	{
		unsigned short int art;
		char name[20];
		unsigned long int cost;
		unsigned long int count;
		char date[8];
	}
	pr; // pr (product) - �����

	ifstream in(PATH1);
	if (in.is_open())
		cout << "���� ��� ������ �������� ������ ������� ������!" << endl;
	else
	{
		cout << "���� ��� ������ �������� ������ �� ������!" << endl;
		return 1;
	}

	ofstream out(PATH2);
	if (out.is_open())
		cout << "���� ��� ������ ����������� ������� ������!" << endl;
	else
	{
		cout << "���� ��� ������ ����������� �� ������!" << endl;
		return 1;
	}

	unsigned long int mnc, mxk;

	while (in.eof())
		for (int k = 0; k < 5; k++)
		{
			getline(in, inf, ' ');
			switch (i)
			{
			case 0:
				pr.art = stoi(inf);
				break;
			case 1:
				strcpy_s(pr.name, inf.c_str());
				break;
			case 2:
				pr.cost = stoi(inf);
				break;
			case 3:
				pr.count = stoi(inf);
				break;
			case 4:
				strcpy_s(pr.date, inf.c_str());
				break;
			}
		}

	return 0;
}