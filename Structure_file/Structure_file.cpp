#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

#define PATH1 "data/input.txt"
#define PATH2 "data/output.txt"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream file(PATH1);
	if (file.is_open())
		cout << "Файл для записи исходных данных успешно открыт!" << endl;
	else
	{
		cout << "Файл для записи исходных данных не открыт!" << endl;
		return 1;
	}

	string inf = "";
	unsigned short int i = 0, k = 0;
	cout << "Начинаем запись информации о изделиях (Нажмите '*' для завершения ввода)" << endl;
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
			cout << "Введите Артикул: ";
			break;
		case 1:
			cout << "Введите Наименование: ";
			break;
		case 2:
			cout << "Введите Стоимость: ";
			break;
		case 3:
			cout << "Введите Количество: ";
			break;
		case 4:
			cout << "Введите Дату: ";
			break;
		}
		cin >> inf;
		file << inf << ' ';
	} 
	while (inf != "*");
	
	cout << "Запись в файл успешна завершена!" << endl;
	file.close();

	struct data_base
	{
		unsigned short int art;
		char name[20];
		unsigned long int cost;
		unsigned long int count;
		char date[8];
	}
	pr; // pr (product) - товар

	ifstream in(PATH1);
	if (in.is_open())
		cout << "Файл для чтения исходных данных успешно открыт!" << endl;
	else
	{
		cout << "Файл для чтения исходных данных не открыт!" << endl;
		return 1;
	}
	
	ofstream out(PATH2);
	if (out.is_open())
		cout << "Файл для записи результатов успешно открыт!" << endl;
	else
	{
		cout << "Файл для записи результатов не открыт!" << endl;
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
				pr.art = dynamic_cast<unsigned short int>(inf);
				break;
			case 1:
				cout << "Введите Наименование: ";
				break;
			case 2:
				cout << "Введите Стоимость: ";
				break;
			case 3:
				cout << "Введите Количество: ";
				break;
			case 4:
				cout << "Введите Дату: ";
				break;
			}
		}

	return 0;
}