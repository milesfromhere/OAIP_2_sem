#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    setlocale(LC_ALL, "Russian");
    using namespace std;
    // Ввести строку с клавиатуры
    cout << "Введите строку символов: ";
    string inputString;
    getline(std::cin, inputString);

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

        // Ввести k - порядковый номер символа (позиции)
        int k;
        cout << "Введите порядковый номер символа k: ";
        cin >> k;

        // Инициализировать переменные для подсчета слов и символов
        int wordCount = 0;
        int charCount = 0;
        int currentWord = 0;

        // Итерировать по символам и подсчитывать слова и символы
        for (char character : fileData) {
            if (character == ' ' && charCount != 0) {
                wordCount++;
                charCount = 0;
            }
            else {
                charCount++;
            }

            if (charCount == k) {
                std::cout << "Символ " << k << "-й позиции находится в слове номер " << wordCount + 1 << "\n";
                break;
            }
        }

        // Если в k-й позиции пробел, вывести номер предыдущего слова
        if (charCount == 0 && wordCount > 0) {
            cout << "Символ " << k << "-й позиции находится в слове номер " << wordCount << "\n";
        }
        else if (charCount != k) {
            cout << "Введенный порядковый номер символа превышает общее количество символов в строке.\n";
        }
    }
    else {
        cerr << "Не удалось открыть файл для чтения.\n";
        return 1;
    }

    return 0;
}
