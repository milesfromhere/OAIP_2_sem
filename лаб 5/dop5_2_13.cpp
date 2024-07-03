#include <iostream>
#include <string>
using namespace std;

const int SIZE = 30;
int current_size = 0;

void addNew();
void display();
void search();


union forstruct {
	char str[50];
	long int numb;
	long float fnumb;
};

struct Notebook {
	forstruct name;
	forstruct capital;
	forstruct surname;
	forstruct population;
	forstruct area;
} governments[30];


int main()
{
	setlocale(LC_ALL, "rus");
	int choose;
	do
	{
		cout << "\nВведите:\n1 - Для ввода новой записи;\n2 - Для отображения информации;\n3 - Для поиска;\n4 - Выход.\n";
		cin >> choose;
		switch (choose) {
		case 1: addNew(); break;
		case 2: display(); break;
		case 3: search(); break;
		}
	} while (choose != 4);

}

void addNew() {
	cout << "Информация об государствах" << endl;
	cout << "Запись  " << current_size + 1 << endl;
	if (current_size < SIZE) {

		cin.get();
		cout << "Наименование: ";
		std::cin.getline(governments[current_size].name.str, 50);

		cin.get();
		cout << "Столица: ";
		std::cin.getline(governments[current_size].capital.str, 50);

		cout << "Численность населения: ";
		cin >> governments[current_size].population.fnumb;

		cout << "Площадб (в тыс кв км): ";
		cin >> governments[current_size].area.fnumb;

		cin.get();
		cout << "Фамилия президента: ";
		std::cin.getline(governments[current_size].surname.str, 50);

		current_size++;
	}
	else
		cout << "Больше никаких записей ввести невозможно" << endl;
}

void displayOneStructure(Notebook oneProduct) {
	cout << endl;
	cout << "Наименование: " << oneProduct.name.str << endl;
	cout << "столица: " << oneProduct.capital.str << endl;
	cout << "Численность населения: " << oneProduct.population.fnumb << endl;
	cout << "Площадб (в тыс кв км): " << oneProduct.area.fnumb << endl;
	cout << "Фамилия президента: " << oneProduct.surname.str << endl;

}


void display() {
	int ch, num;
	cout << "1 - для отображения одной записей" << endl;
	cout << "2 - для отображения всех записей" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Введите номер записи для отображения" << endl;
		cin >> num;
		if (num > current_size or num < 1)
			cout << "Неверный ввод";
		cout << endl;
		displayOneStructure(governments[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			displayOneStructure(governments[i]);
			cout << endl;
		}
	}
	else
		cout << "Неверный ввод";
}

void search() {
	string nedded_government_name;
	cout << "Введите название правительства для поиска: ";
	cin.get();
	getline(cin, nedded_government_name);
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (governments[i].name.str == nedded_government_name) {
			displayOneStructure(governments[i]);
		}
	}
}