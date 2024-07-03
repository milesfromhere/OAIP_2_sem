#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;
enum Gender { MALE, FEMALE };

struct Date {
    int day;
    int month;
    int year;
};

struct Citizen {
    string fullName;
    Date birthDate;
    string address;
    Gender gender;
};

vector<Citizen> citizens;

void printMenu() {
    cout << "1. Вывести всех горожан\n";
    cout << "2. Добавить горожанина\n";
    cout << "3. Удалить горожанина\n";
    cout << "4. Найти горожанина\n";
    cout << "5. Выборка по году рождения\n";
    cout << "0. Выход\n";
}

void printCitizen(const Citizen& citizen) {
    cout << "Ф.И.О.: " << citizen.fullName << endl;
    cout << "Дата рождения: " << citizen.birthDate.day << "." << citizen.birthDate.month << "." << citizen.birthDate.year << endl;
    cout << "Адрес: " << citizen.address << endl;
    cout << "Пол: " << (citizen.gender == MALE ? "М" : "Ж") << endl;
    cout << "------------------------\n";
}

void displayAllCitizens() {
    for (const auto& citizen : citizens) {
        printCitizen(citizen);
    }
}

void addCitizen() {
    Citizen newCitizen;

    cout << "Введите Ф.И.О.: ";
    getline(cin >> ws, newCitizen.fullName);

    cout << "Введите дату рождения (ДД ММ ГГГГ): ";
    cin >> newCitizen.birthDate.day >> newCitizen.birthDate.month >> newCitizen.birthDate.year;

    cout << "Введите адрес: ";
    getline(cin >> ws, newCitizen.address);

    cout << "Введите пол (М/Ж): ";
    char genderInput;
    cin >> genderInput;
    newCitizen.gender = (genderInput == 'М' || genderInput == 'м') ? MALE : FEMALE;

    citizens.push_back(newCitizen);
    cout << "Горожанин добавлен!\n";
}

void deleteCitizen() {
    string fullNameToDelete;
    cout << "Введите Ф.И.О. горожанина для удаления: ";
    getline(cin >> ws, fullNameToDelete);

    auto it = std::find_if(citizens.begin(), citizens.end(), [&fullNameToDelete](const Citizen& citizen) {
        return citizen.fullName == fullNameToDelete;
        });

    if (it != citizens.end()) {
        citizens.erase(it);
        cout << "Горожанин удален!\n";
    }
    else {
        cout << "Горожанин не найден!\n";
    }
}

void findCitizen() {
    string fullNameToFind;
    cout << "Введите Ф.И.О. горожанина для поиска: ";
    getline(cin >> ws, fullNameToFind);

    auto it = find_if(citizens.begin(), citizens.end(), [&fullNameToFind](const Citizen& citizen) {
        return citizen.fullName == fullNameToFind;
        });

    if (it != citizens.end()) {
        printCitizen(*it);
    }
    else {
        cout << "Горожанин не найден!\n";
    }
}

void filterByBirthYear() {
    int yearToFilter;
    cout << "Введите год рождения для выборки: ";
    cin >> yearToFilter;

    cout << "Горожане, родившиеся в " << yearToFilter << " году:\n";
    for (const auto& citizen : citizens) {
        if (citizen.birthDate.year == yearToFilter) {
            printCitizen(citizen);
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;

    do {
        printMenu();
        cout << "Выберите действие (введите число): ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayAllCitizens();
            break;
        case 2:
            addCitizen();
            break;
        case 3:
            deleteCitizen();
            break;
        case 4:
            findCitizen();
            break;
        case 5:
            filterByBirthYear();
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный ввод. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
