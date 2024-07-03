#include <iostream>
#include <string>
using namespace std;

const int SIZE = 30;
int current_size = 0;
int current_y = 2023;
int current_m = 3;
int current_d = 14;

enum Faculties {
	FIT = 1,
	TOV,
	HTIT,
	PIM
};

struct EnterTime {
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 11;
};

struct Students {
	string surname;
	string name;
	string middlename;
	EnterTime enter_time;
	string specialty;
	unsigned group : 5;
	Faculties faculty;
	float average;
} students[SIZE];
struct Students empty_student;

void addNew();
void displayOneStructure(Students onePupil);
void display();
void deleteRecord();
void search();

void main()
{
	setlocale(LC_ALL, "rus");
	short choose;
	do
	{
		cout << "\nВведите:\n1 - для ввода новой записи;\n2 - для отображения информации;\n3 - для удаления записи;\n4 - для поиска\n5 - выход.\n";
		cin >> choose;
		switch (choose) {
		case 1: addNew(); break;
		case 2: display(); break;
		case 3: deleteRecord(); break;
		case 4: search(); break;
		}
	} while (choose != 5);

}

void addNew() {
	cout << "Ввод информации" << endl;
	cout << "Запись " << current_size + 1 << endl;

	if (current_size < SIZE) {
		cout << "Фамилия: ";
		cin.ignore();
		getline(cin, students[current_size].surname);

		cout << "Имя: ";
		cin.ignore();
		getline(cin, students[current_size].name);

		cout << "Отчество: ";
		cin.ignore();
		getline(cin, students[current_size].middlename);

		int is_correct_arriving_time = 0;
		do {
			int day;
			int month;
			int year;
			cout << "Введите дату: " << endl;

			cout << "День: ";
			cin >> day;
			students[current_size].enter_time.day = day;
			cout << "Месяц: ";
			cin >> month;
			students[current_size].enter_time.month = month;
			cout << "Год: ";
			cin >> year;
			students[current_size].enter_time.year = year;

			if (year == current_y)
				is_correct_arriving_time = 2;
			if (year < current_y)
				is_correct_arriving_time = 1;
			if (is_correct_arriving_time == 2) {
				if (month > current_m)
					is_correct_arriving_time = 0;
				else if (month == current_m)
					is_correct_arriving_time = 2;
				else if (month < current_m)
					is_correct_arriving_time = 1;
				else if (month > 12)
					is_correct_arriving_time = 0;
			}
			if (is_correct_arriving_time == 2) {
				if (day > current_d)
					is_correct_arriving_time = 0;
				else if (day <= current_d)
					is_correct_arriving_time = 1;
				else if (day > 31)
					is_correct_arriving_time = 0;
			}
			if (month > 12 or day > 31)
				is_correct_arriving_time = 0;
			if (is_correct_arriving_time == 0)
				cout << "Неверный ввод" << endl;
		} while (is_correct_arriving_time == 0);



		cout << "Специальность: ";
		cin.get();
		getline(cin, students[current_size].specialty);

		int gr;
		cout << "Группа: ";
		cin >> gr;
		students[current_size].group = gr;

		cout << "Факультет(1 - FIT, 2 - TOV, 3 - HTIT, 4 - PIM): ";
		int fac;
		do {
			cin >> fac;
			if (fac < 1 or fac > 4)
				cout << "Неверный ввод";
		} while (fac < 1 or fac > 4);
		if (fac == 1)
			students[current_size].faculty = FIT;
		if (fac == 2)
			students[current_size].faculty = TOV;
		if (fac == 3)
			students[current_size].faculty = HTIT;
		if (fac == 4)
			students[current_size].faculty = PIM;

		cout << "Средний балл: ";
		cin >> students[current_size].average;
		if (students[current_size].average > 10.0000000)
		{
			cout << "данные введены некорректно" << endl;
			do {
				cout << "повторите ввод: " << endl;
				cin >> students[current_size].average;
			} while (students[current_size].average < 0 || students[current_size].average > 10.0000000);

		}
		current_size++;
	}
	else
		cout << "Больше никаких записей ввести невозможно" << endl;
}


void displayOneStructure(Students onePupil) {
	cout << endl;
	cout << "Фамилия: " << onePupil.surname << endl;
	cout << "Имя: " << onePupil.name << endl;
	cout << "Отчество: " << onePupil.middlename << endl;
	cout << "Время ввода: " << endl;
	cout << "День: " << onePupil.enter_time.day << endl;
	cout << "Месяц: " << onePupil.enter_time.month << endl;
	cout << "Год: " << onePupil.enter_time.year << endl;
	cout << "Специальность: " << onePupil.specialty << endl;
	cout << "Группа: " << onePupil.group << endl;
	cout << "Факультет:";
	if (onePupil.faculty == FIT)
		cout << "FIT" << endl;
	if (onePupil.faculty == TOV)
		cout << "TOV" << endl;
	if (onePupil.faculty == HTIT)
		cout << "HTIT" << endl;
	if (onePupil.faculty == PIM)
		cout << "PIM" << endl;
	cout << "Средний балл: " << onePupil.average << endl;
}

void display() {
	int ch, num;
	cout << "1 - для отображения одной записи" << endl;
	cout << "2 -для отображения всех записей" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Введите номер записи для отображения" << endl;
		cin >> num;
		if (num > current_size or num < 1)
			cout << "Неверный ввод";
		cout << endl;
		displayOneStructure(students[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			displayOneStructure(students[i]);
			cout << endl;
		}
	}
	else
		cout << "Неверный ввод";
}

void deleteRecord() {
	int rec_number;
	cout << "Введите номер записи для удаления" << endl;
	cin >> rec_number;
	if (rec_number != 0) {
		for (int de = (rec_number - 1); de < current_size - 1; de++)
			students[de] = students[de + 1];
		current_size -= 1;
	}
	if (rec_number == 0)
		for (int i = 0; i < SIZE; i++)
			students[i] = empty_student;
}

void search() {
	float nedded_average;
	cout << "Введите средний балл для поиска: ";
	cin >> nedded_average;
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (students[i].average == nedded_average)
			displayOneStructure(students[i]);
	}
}

