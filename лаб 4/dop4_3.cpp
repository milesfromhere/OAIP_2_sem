#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

struct Sanatorium {
    string name;
    string location;
    string healingProfile;
    int availableVouchers;
};

bool compareByHealingProfile(const Sanatorium& san1, const Sanatorium& san2) {
    return san1.healingProfile < san2.healingProfile;
}

void displayTable(const vector<Sanatorium>& sanatoriums) {
    cout << setw(25) << "Название санатория" << setw(20) << "Место расположения" << setw(20) << "Лечебный профиль" << setw(25) << "Количество путевок" << endl;

    for (const Sanatorium& san : sanatoriums) {
        cout << setw(25) << san.name << setw(20) << san.location << setw(20) << san.healingProfile << setw(25) << san.availableVouchers << endl;
    }
}

void displayGroupedTable(const vector<Sanatorium>& sanatoriums) {
    vector<string> uniqueProfiles;
    for (const Sanatorium& san : sanatoriums) {
        if (find(uniqueProfiles.begin(), uniqueProfiles.end(), san.healingProfile) == uniqueProfiles.end()) {
            uniqueProfiles.push_back(san.healingProfile);
        }
    }

    sort(uniqueProfiles.begin(), uniqueProfiles.end());

    cout << "\nГруппировка по лечебным профилям:\n";
    for (const string& profile : uniqueProfiles) {
        cout << "\nЛечебный профиль: " << profile << "\n";
        cout << setw(25) << "Название санатория" << setw(20) << "Место расположения" << setw(25) << "Количество путевок" << endl;

        for (const Sanatorium& san : sanatoriums) {
            if (san.healingProfile == profile) {
                cout << setw(25) << san.name << setw(20) << san.location << setw(25) << san.availableVouchers << endl;
            }
        }
    }
}

void searchSanatoriums(const vector<Sanatorium>& sanatoriums, const string& searchProfile) {
    cout << "\nПоиск санаториев по лечебному профилю: " << searchProfile << "\n";
    cout << setw(25) << "Название санатория" << setw(20) << "Место расположения" << setw(25) << "Количество путевок" << endl;

    bool foundSanatorium = false;

    for (const Sanatorium& san : sanatoriums) {
        if (san.healingProfile == searchProfile) {
            foundSanatorium = true;
            cout << setw(25) << san.name << setw(20) << san.location << setw(25) << san.availableVouchers << endl;
        }
    }

    if (!foundSanatorium) {
        cout << "Санатории с указанным лечебным профилем не найдены.\n";
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<Sanatorium> sanatoriums;

    // Ввод данных о санаториях (можно использовать цикл для ввода)
    Sanatorium san1 = { "Санаторий 1", "Место1", "Профиль1", 20 };
    Sanatorium san2 = { "Санаторий 2", "Место2", "Профиль2", 15 };
    Sanatorium san3 = { "Санаторий 3", "Место3", "Профиль1", 30 };

    sanatoriums.push_back(san1);
    sanatoriums.push_back(san2);
    sanatoriums.push_back(san3);

    // Сортировка по лечебным профилям и названиям санаториев
    sort(sanatoriums.begin(), sanatoriums.end(), compareByHealingProfile);

    // Вывод данных в виде таблицы
    displayTable(sanatoriums);

    // Вывод данных в виде таблицы, сгруппированных по лечебным профилям
    displayGroupedTable(sanatoriums);

    // Поиск санаториев по лечебному профилю
    string searchProfile;
    cout << "\nВведите лечебный профиль для поиска санаториев: ";
    cin >> searchProfile;
    searchSanatoriums(sanatoriums, searchProfile);

    return 0;
}