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

	unsigned long int s;
	cout << "Введите минимальную сумму s изготовления для вывода товара:";
	cin >> s;

	unsigned short int i = 0, count = 0;
	cout << "Начинаем запись информации об изделиях (введите '*' для завершения ввода)" << endl;
	for (count; count < N; i++)
	{
		unsigned long int t1; // выделяем память для локальных переменных ввода из консоли и дальнейшего переноса в текстовый файл для дальнейшего считывания
		char t2[50];

		if (i == 5)
		{
			i = 0;
			count++;
		}
		switch (i)
		{
		case 0:
			cout << "Введите Артикул: ";
			cin >> t2;
			file << t2 << '\n';
			break;
		case 1:
			cout << "Введите Наименование: ";
			cin >> t2;
			file << t2 << '\n';
			break;
		case 2:
			cout << "Введите Стоимость: ";
			cin >> t1;
			file << t1 << '\n';
			break;
		case 3:
			cout << "Введите Количество: ";
			cin >> t1;
			file << t1 << '\n';
			break;
		case 4:
			cout << "Введите Дату: ";
			cin >> t2;
			file << t2 << '\n';
			break;
		}
		if (t2[0] - '*' == 0)
			break;
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

	struct data_base
	{
		char art[15];
		char name[50];
		unsigned long int cost;
		unsigned long int count;
		char date[8];
	}
	pr; // pr (product) - товар

	out << "Выводим товары на сумму не меньше заданной\n" << setw(20) << "Артикул" << '\t' << '|' << '\t' << setw(20) << "Наименование" << '\t' << '|' << '\t' << setw(20) << "Стоимость" << '\t' << '|' << '\t' << setw(20) << "Количество" << '\t' << '|' << '\t' << setw(20) << "Дата производства" << endl;
	out << setw(20) << "Артикул" << '\t' << '|' << '\t' << setw(20) << "Наименование" << '\t' << '|' << '\t' << setw(20) << "Стоимость" << '\t' << '|' << '\t' << setw(20) << "Количество" << '\t' << '|' << '\t' << setw(20) << "Дата производства" << endl;
	while (in)
	{
		in >> pr.art >> pr.name >> pr.cost >> pr.count >> pr.date;
		if (pr.cost * pr.count > s)
			out << setw(20) << pr.art << '\t' << '|' << '\t' << setw(20) << pr.name << '\t' << '|' << '\t' << setw(20) << pr.cost << '\t' << '|' << '\t' << setw(20) << pr.count << '\t' << '|' << '\t' << setw(20) << pr.date << endl;
	}
	in.clear();
	in.seekg(0, ios::beg);

	unsigned long int mnc, mxk; // mnc (min cost) - наименьшая цена, mxk (max count) - наибольшее количество

	out << "Выводим отфильтрованные по цене и количеству производства товары\n" << setw(20) << "Артикул" << '\t' << '|' << '\t' << setw(20) << "Наименование" << '\t' << '|' << '\t' << setw(20) << "Стоимость" << '\t' << '|' << '\t' << setw(20) << "Количество" << '\t' << '|' << '\t' << setw(20) << "Дата производства" << endl;
	in >> pr.art >> pr.name >> pr.cost >> pr.count >> pr.date; // считываем первый товар и берём начальные значения цены и количества, с помощью которых будет сравнивать другие товары
	mnc = pr.cost;
	mxk = pr.count;
	out << setw(20) << pr.art << '\t' << '|' << '\t' << setw(20) << pr.name << '\t' << '|' << '\t' << setw(20) << pr.cost << '\t' << '|' << '\t' << setw(20) << pr.count << '\t' << '|' << '\t' << setw(20) << pr.date << endl;
	while (in)
	{
		in >> pr.art >> pr.name >> pr.cost >> pr.count >> pr.date;
		if (pr.cost < mnc && pr.count > mxk)
		{
			out << setw(20) << pr.art << '\t' << '|' << '\t' << setw(20) << pr.name << '\t' << '|' << '\t' << setw(20) << pr.cost << '\t' << '|' << '\t' << setw(20) << pr.count << '\t' << '|' << '\t' << setw(20) << pr.date << endl;
			mnc = pr.cost;
			mxk = pr.count;
		}
	}

	cout << "Работа с файлом успешно завершена!";
	in.close();
	out.close();

	_getch();
	return 0;
}