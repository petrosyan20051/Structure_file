#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;

#define PATH1 "data/input.txt"
#define PATH2 "data/output.txt"
#define N 100

int main_t()
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

	unsigned short int i = 0, count = 0;
	cout << "Начинаем запись информации об изделиях" << endl;
	for (count; count < N; count++)
	{
		unsigned short int t1; // выделяем память для локальных переменных ввода из консоли и дальнейшего переноса в текстовый файл для дальнейшего считывания
		char t2[25];

		if (i == 5)
		{
			file << '\n';
			i = 0;
			count++;
		}
		switch (i)
		{
		case 0:
			cout << "Введите Артикул: ";
			cin >> t2;
			file << t2;
			break;
		case 1:
			cout << "Введите Наименование: ";
			cin >> t2;
			file << t2;
			break;
		case 2:
			cout << "Введите Стоимость: ";
			cin >> t1;
			file << t1;
			break;
		case 3:
			cout << "Введите Количество: ";
			cin >> t1;
			file << t1;
			break;
		case 4:
			cout << "Введите Дату: ";
			cin >> t2;
			file << t2;
			break;
		}

	}

	cout << "Запись в файл успешна завершена!" << endl;
	file.close();

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
	out << setw(25) << "Артикул" << '\t|\t' << setw(25) << "Наименование" << '\t|\t' << setw(25) << "Стоимость" << '\t|\t' << setw(25) << "Количество" << '\t|\t' << setw(26) << "Дата производства";

	struct data_base
	{
		char art[25];
		char name[20];
		unsigned long int cost;
		unsigned long int count;
		char date[8];
	}
	pr; // pr (product) - товар

	unsigned long int mnc, mxk; // mnc (min cost) - наименьшая цена, mxk (max count) - наибольшее количество

	in >> pr.art >> pr.name >> pr.cost >> pr.count >> pr.date; // считываем первый товар и берём начальные значения цены и количества, с помощью которых будет сравнивать другие товары
	mnc = pr.cost;
	mxk = pr.count;
	out << setw(25) << pr.art << '\t|\t' << setw(25) << pr.name << '\t|\t' << setw(25) << pr.cost << '\t|\t' << setw(25) << pr.count << '\t|\t' << setw(25) << pr.date;

	while (in.eof())
	{
		in >> pr.art >> pr.name >> pr.cost >> pr.count >> pr.date;
		if (pr.cost < mnc && pr.count > mxk)
			out << setw(25) << pr.art << '\t|\t' << setw(25) << pr.name << '\t|\t' << setw(25) << pr.cost << '\t|\t' << setw(25) << pr.count << '\t|\t' << setw(25) << pr.date;

	}

	cout << "Работа с файлом успешно завершена!";
	in.close();
	out.close();

	_getch();
	return 0;
}