#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct HotelClient {
    string passportData;
    string arrivalDate;
    string departureDate;
    int roomNumber;
    string accommodationType;
};

const int MAX_CLIENTS = 100;
HotelClient clients[MAX_CLIENTS];
int numClients = 0;

void addClient() {
    if (numClients < MAX_CLIENTS) {
        cout << "Введите данные паспорта: ";
        cin >> clients[numClients].passportData;

        cout << "Введите дату приезда: ";
        cin >> clients[numClients].arrivalDate;

        cout << "Введите дату отъезда: ";
        cin >> clients[numClients].departureDate;

        cout << "Введите номер комнаты: ";
        cin >> clients[numClients].roomNumber;

        cout << "Введите тип размещения: ";
        cin >> clients[numClients].accommodationType;

        numClients++;
        cout << "Клиент успешно добавлен.\n";
    }
    else {
        cout << "Невозможно добавить больше клиентов. Массив полон.\n";
    }
}

void displayClients() {
    cout << "Список клиентов:\n";
    for (int i = 0; i < numClients; ++i) {
        cout << "Паспорт: " << clients[i].passportData
            << ", Приезд: " << clients[i].arrivalDate
            << ", Отъезд: " << clients[i].departureDate
            << ", Номер: " << clients[i].roomNumber
            << ", Размещение: " << clients[i].accommodationType << endl;
    }
}

void deleteClient() {
    string passportToDelete;
    cout << "Введите данные паспорта для удаления: ";
    cin >> passportToDelete;

    for (int i = 0; i < numClients; ++i) {
        if (clients[i].passportData == passportToDelete) {
            for (int j = i; j < numClients - 1; ++j) {
                clients[j] = clients[j + 1];
            }
            numClients--;
            cout << "Клиент успешно удален.\n";
            return;
        }
    }

    cout << "Клиент с данными паспорта " << passportToDelete << " не найден.\n";
}

void searchClient() {
    string lastName;
    cout << "Введите фамилию для поиска: ";
    cin >> lastName;

    for (int i = 0; i < numClients; ++i) {
        if (clients[i].passportData.find(lastName) != string::npos) {
            cout << "Клиент найден:\n";
            cout << "Паспорт: " << clients[i].passportData
                << ", Приезд: " << clients[i].arrivalDate
                << ", Отъезд: " << clients[i].departureDate
                << ", Номер: " << clients[i].roomNumber
                << ", Размещение: " << clients[i].accommodationType << endl;
            return;
        }
    }

    cout << "Клиент с фамилией " << lastName << " не найден.\n";
}

void writeToFile() {
    ofstream outputFile("hotel_clients.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < numClients; ++i) {
            outputFile << clients[i].passportData << " "
                << clients[i].arrivalDate << " "
                << clients[i].departureDate << " "
                << clients[i].roomNumber << " "
                << clients[i].accommodationType << endl;
        }
        outputFile.close();
        cout << "Данные успешно записаны в файл.\n";
    }
    else {
        cout << "Не удалось открыть файл.\n";
    }
}

void readFromFile() {
    ifstream inputFile("hotel_clients.txt");
    if (inputFile.is_open()) {
        numClients = 0;
        while (inputFile >> clients[numClients].passportData
            >> clients[numClients].arrivalDate
            >> clients[numClients].departureDate
            >> clients[numClients].roomNumber
            >> clients[numClients].accommodationType) {
            numClients++;
        }
        inputFile.close();
        cout << "Данные успешно считаны из файла.\n";
    }
    else {
        cout << "Не удалось открыть файл.\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");
    int choice;

    do {
        cout << "\nСистема управления клиентами гостиницы\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Показать клиентов\n";
        cout << "3. Удалить клиента\n";
        cout << "4. Поиск клиента\n";
        cout << "5. Запись в файл\n";
        cout << "6. Чтение из файла\n";
        cout << "0. Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addClient();
            break;
        case 2:
            displayClients();
            break;
        case 3:
            deleteClient();
            break;
        case 4:
            searchClient();
            break;
        case 5:
            writeToFile();
            break;
        case 6:
            readFromFile();
            break;
        case 0:
            cout << "Завершение программы.\n";
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, повторите попытку.\n";
        }
    } while (choice != 0);

    return 0;
}
