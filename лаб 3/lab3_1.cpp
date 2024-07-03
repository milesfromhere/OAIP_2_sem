#include <iostream>
#include <fstream>
#include <sstream>

void copyLinesStartingWithA(const std::string& inputFileName, const std::string& outputFileName, int& wordCount) {
    using namespace std;
    setlocale(LC_ALL, "Russian");
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile || !outputFile) {
        cerr << "Ошибка с открытием файла." << endl;
        return;
    }

    string line;
    wordCount = 0;

    while (getline(inputFile, line)) {
        if (!line.empty() && line.front() == 'A') {
            outputFile << line << '\n';

            istringstream iss(line);
            string word;
            while (iss >> word) {
                ++wordCount;
            }
        }
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    int wordCount = 0;

    copyLinesStartingWithA("FILE1.txt", "FILE2.txt", wordCount);

    std::cout << "Колличество скопированных слов из FILE1 в FILE2: " << wordCount << std::endl;

    return 0;
}
