#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

#define PATH1 "data/input.txt"
#define PATH2 "data/output.txt"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct data_base
	{
		unsigned short int art;
		char name[20];
		unsigned short int cost;
		unsigned long int count;
		char date[8];
	}
	pr; // pr (product) - товар

	ofstream out(PATH1);
	if (out.is_open())
		cout << "Файл для записи успешно открыт!" << endl;
	else
	{
		cout << "Файл для записи не открыт!" << endl;
		return 1;
	}

	string inf = "";
	unsigned short int i = 0;
	cout << "Начинаем запись информации о изделиях (Нажмите '*' для завершения ввода)" << endl;
	do
	{
		if (i == 5)
		{
			out << endl;
			i = 0;
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
		out << inf << ' ';
		i++;
	} 
	while (inf != "*");
		

	return 0;
}