#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    setlocale(LC_ALL, "Russian");
    using namespace std;
    // Открыть файл FILE1 для чтения
    ifstream inFile1("FILE1.txt");
    if (!inFile1.is_open()) {
        cerr << "Не удалось открыть FILE1.txt для чтения.\n";
        return 1;
    }

    // Открыть файл FILE2 для записи
    ofstream outFile2("FILE2.txt");
    if (!outFile2.is_open()) {
        cerr << "Не удалось открыть FILE2.txt для записи.\n";
        inFile1.close();
        return 1;
    }

    // Копировать строки с одним словом из FILE1 в FILE2
    string line;
    while (getline(inFile1, line)) {
        istringstream iss(line);
        string word;
        int wordCount = 0;

        // Подсчитать количество слов в строке
        while (iss >> word) {
            wordCount++;
        }

        // Если строка содержит только одно слово, скопировать ее в FILE2
        if (wordCount == 1) {
            outFile2 << line << endl;
        }
    }

    // Закрыть файлы
    inFile1.close();
    outFile2.close();

    // Открыть FILE2 для поиска слова из 5 символов
    ifstream inFile2("FILE2.txt");
    if (!inFile2.is_open()) {
        cerr << "Не удалось открыть FILE2.txt для чтения.\n";
        return 1;
    }

    // Найти слово из 5 символов в FILE2
    string wordToFind = "     "; // искомое слово из 5 символов
    while (inFile2 >> line) {
        if (line.length() == 5) {
            wordToFind = line;
            break;
        }
    }

    // Закрыть файл FILE2
    inFile2.close();

    // Вывести результат поиска
    if (wordToFind != "     ") {
        cout << "Найдено слово из 5 символов в FILE2: " << wordToFind << endl;
    }
    else {
        cout << "Слово из 5 символов не найдено в FILE2.\n";
    }

    return 0;
}
