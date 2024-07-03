#include <iostream>
#include <iomanip>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct TRAIN {
    string destination;
    int trainNumber;
    string departureTime;
};

const int NUM_TRAINS = 8;

bool compareByDestination(const TRAIN& train1, const TRAIN& train2) {
    return train1.destination < train2.destination;
}

void inputTrains(TRAIN trains[]) {
    cout << "Введите информацию о поездах:\n";

    for (int i = 0; i < NUM_TRAINS; ++i) {
        cout << "Поезд #" << i + 1 << ":\n";
        cout << "Название пункта назначения: ";
        cin >> trains[i].destination;

        cout << "Номер поезда: ";
        cin >> trains[i].trainNumber;

        cout << "Время отправления (в формате HH:MM): ";
        cin >> trains[i].departureTime;

        cout << endl;
    }

    sort(trains, trains + NUM_TRAINS, compareByDestination);
}

void displayTrains(const TRAIN trains[], const string& inputTime) {
    cout << "\nИнформация о поездах:\n";
    cout << setw(20) << "Пункт назначения" << setw(15) << "Номер поезда" << setw(20) << "Время отправления" << endl;

    bool foundTrain = false;

    for (int i = 0; i < NUM_TRAINS; ++i) {
        if (trains[i].departureTime > inputTime) {
            foundTrain = true;
            cout << setw(20) << trains[i].destination << setw(15) << trains[i].trainNumber << setw(20) << trains[i].departureTime << endl;
        }
    }

    if (!foundTrain) {
        cout << "Поездов после указанного времени не найдено.\n";
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    TRAIN trains[NUM_TRAINS];
    string inputTime;

    inputTrains(trains);

    cout << "Введите время для поиска поездов (в формате HH:MM): ";
    cin >> inputTime;

    displayTrains(trains, inputTime);

    return 0;
}
