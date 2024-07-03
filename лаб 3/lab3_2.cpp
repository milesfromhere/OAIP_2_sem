#include <iostream>
#include <fstream>
#include <string>

int main() {
    setlocale( LC_ALL, "Russian");
    using namespace std;

    cout << "Введите строку символов (группы цифр и нулей): ";
    string inputString;
    getline(cin, inputString);

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

    ifstream inFile("data.txt");
    if (inFile.is_open()) {
        string fileData;
        getline(inFile, fileData);
        inFile.close();

        cout << "Данные из файла: " << fileData << "\n";


        char currentDigit = '\0';
        int currentCount = 0;
        char shortestDigit = '\0';
        int shortestCount = INT_MAX;

        for (char digit : fileData) {
            if (isdigit(digit)) {
                if (digit == currentDigit) {
                    currentCount++;
                }
                else {
                    if (currentCount > 0 && currentCount < shortestCount) {
                        shortestCount = currentCount;
                        shortestDigit = currentDigit;
                    }

                    currentDigit = digit;
                    currentCount = 1;
                }
            }
            else if (digit == ' ') {
                continue;
            }
            else {
                currentCount = 0;
            }
        }

        if (currentCount < shortestCount) {
            shortestCount = currentCount;
            shortestDigit = currentDigit;
        }

        cout << "Самая короткая группа: " << shortestDigit << " (длина " << shortestCount << ")\n";
    }
    else {
        cerr << "Не удалось открыть файл для чтения.\n";
        return 1;
    }

    return 0;
}
