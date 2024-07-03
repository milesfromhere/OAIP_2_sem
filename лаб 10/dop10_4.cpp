#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

void generateNumbers(int A, std::ofstream& outputFile, std::vector<int>& digits, int numDigits) {
    if (numDigits == 0) {
        for (int digit : digits) {
            outputFile << digit;
        }
        outputFile << std::endl;
        return;
    }

    for (int i = 1; i <= A; ++i) {
        digits.push_back(i);
        generateNumbers(A, outputFile, digits, numDigits - 1);
        digits.pop_back();
    }
}

void printPermutations(std::vector<int>& numbers) {
    std::cout << "Все перестановки:" << std::endl;
    do {
        for (int number : numbers) {
            std::cout << number << ' ';
        }
        std::cout << std::endl;
    } while (std::next_permutation(numbers.begin(), numbers.end()));
}

int numseq(int a, int b) {
    if (b == 0) {
        return 0;
    }
    else {
        return std::floor(a / b) + numseq(a / b + a % b, b);
    }
}

int main() {
    int choice;
    std::cout << "Выберите задачу (1, 2 или 3): ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        int A;
        std::cout << "Введите число A: ";
        std::cin >> A;

        std::ofstream outputFile("output.txt");
        if (!outputFile) {
            std::cerr << "Не удалось открыть файл для записи." << std::endl;
            return 1;
        }

        std::vector<int> digits;
        generateNumbers(A, outputFile, digits, A);

        std::cout << "Числа успешно записаны в файл 'output.txt'." << std::endl;

        break;
    }
    case 2: {
        // Ваше решение задачи 2
        break;
    }
    case 3: {
        std::vector<int> numbers = { 1, 2, 3, 4, 5 }; // Исходные числа

        printPermutations(numbers);

        break;
    }
    default:
        std::cerr << "Некорректный выбор." << std::endl;
        return 1;
    }

    return 0;
}
