#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>

int main() {
    using namespace std;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    // Ввести строку с клавиатуры
    cout << "Введите строку слов, разделенных пробелами: ";
    string inputString;
    getline(cin, inputString);

    // Записать строку в файл
    ofstream outFile("data.txt");
    if (outFile.is_open()) {
        outFile << inputString;
        outFile.close();
        cout << "Данные успешно записаны в файл.\n";
    }
    else {
        cerr << "Не удалось открыть файл для записи.\n";
        return 1;
    }

    // Прочитать данные из файла
    ifstream inFile("data.txt");
    if (inFile.is_open()) {
        string fileData;
        getline(inFile, fileData);
        inFile.close();

        // Вывести данные из файла
        cout << "Данные из файла: " << fileData << "\n";

        // Разделить строку на слова
        istringstream iss(fileData);
        string word;

        cout << "Слова, содержащие букву 'х':\n";

        // Итерировать по словам и вывести те, которые содержат букву 'х'
        while (iss >> word) {
            if (word.find('х') != string::npos || word.find('Х') != string::npos) {
                cout << word << std::endl;
            }
        }
    }
    else {
        cerr << "Не удалось открыть файл для чтения.\n";
        return 1;
    }

    return 0;
}