#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
using namespace std;
const int MAX_TRAINS = 100;

struct Train {
    int trainNumber;
    char destination[50];
    char daysOfOperation[50];
    char arrivalTime[10];
    char departureTime[10];
};

void inputTrainData(Train& train) {
    cout << "Введите номер поезда: ";
    cin >> train.trainNumber;

    cout << "Введите пункт назначения: ";
    cin.ignore();  
    cin.getline(train.destination, sizeof(train.destination));

    cout << "Введите дни следования: ";
    cin.getline(train.daysOfOperation, sizeof(train.daysOfOperation));

    cout << "Введите время прибытия: ";
    cin >> train.arrivalTime;

    cout << "Введите время отправления: ";
    cin >> train.departureTime;
}

void displayTrainData(const Train& train) {
    cout << "Номер поезда: " << train.trainNumber << endl;
    cout << "Пункт назначения: " << train.destination << endl;
    cout << "Дни следования: " << train.daysOfOperation << endl;
    cout << "Время прибытия: " << train.arrivalTime << endl;
    cout << "Время отправления: " << train.departureTime << endl;
    cout << "------------------------" << endl;
}

void writeTrainToFile(const Train& train, const char* filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(&train), sizeof(train));
        file.close();
    }
    else {
        cerr << "Ошибка открытия файла для записи!" << endl;
    }
}

void readTrainsFromFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        Train train;
        while (file.read(reinterpret_cast<char*>(&train), sizeof(train))) {
            displayTrainData(train);
        }
        file.close();
    }
    else {
        cerr << "Ошибка открытия файла для чтения!" << endl;
    }
}

void searchByDestination(const char* filename, const char* destination) {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        Train train;
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&train), sizeof(train))) {
            if (strcmp(train.destination, destination) == 0) {
                displayTrainData(train);
                found = true;
            }
        }
        file.close();
        if (!found) {
            cout << "Поезда с пунктом назначения \"" << destination << "\" не найдены." << endl;
        }
    }
    else {
        cerr << "Ошибка открытия файла для чтения!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Train trains[MAX_TRAINS];
    int numberOfTrains;

    cout << "Введите количество поездов: ";
    cin >> numberOfTrains;

    for (int i = 0; i < numberOfTrains; ++i) {
        cout << "Введите данные для поезда #" << i + 1 << endl;
        inputTrainData(trains[i]);
        writeTrainToFile(trains[i], "trains.dat");
    }

    cout << "\nДанные о поездах:" << endl;
    readTrainsFromFile("trains.dat");

    char searchDestination[50];
    cout << "\nВведите пункт назначения для поиска: ";
    cin.ignore();
    cin.getline(searchDestination, sizeof(searchDestination));
    searchByDestination("trains.dat", searchDestination);

    return 0;
}
