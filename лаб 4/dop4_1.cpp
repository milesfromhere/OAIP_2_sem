#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

struct ExamResult {
    string fullName;
    int numberOfExams;
    int* grades;
};

void processStudent(ExamResult& student) {
    // Пример обработки: проверка, сданы ли все экзамены на 4 и 5
    bool allPassed = true;
    for (int i = 0; i < student.numberOfExams; ++i) {
        if (student.grades[i] < 4) {
            allPassed = false;
            break;
        }
    }

    if (allPassed) {
        cout << student.fullName << " сдал все экзамены на 4 и 5.\n";
    }
    else {
        cout << student.fullName << " не сдал все экзамены на 4 и 5.\n";
    }
}

void processArrayOfStudents(ExamResult students[], int numStudents) {
    int passedCount = 0;

    for (int i = 0; i < numStudents; ++i) {
        processStudent(students[i]);

        // Пример учета студентов, сдавших на 4 и 5
        bool allPassed = true;
        for (int j = 0; j < students[i].numberOfExams; ++j) {
            if (students[i].grades[j] < 4) {
                allPassed = false;
                break;
            }
        }

        if (allPassed) {
            passedCount++;
        }
    }

    // Вычисление характеристики успеваемости в процентах
    float successRate = (static_cast<float>(passedCount) / numStudents) * 100;
    cout << "Характеристика успеваемости студентов: " << successRate << "%.\n";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");
    const int MAX_EXAMS = 5;
    const int MAX_STUDENTS = 3;

    ExamResult students[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; ++i) {
        cout << "Введите ФИО студента: ";
        getline(cin, students[i].fullName);

        cout << "Введите количество экзаменов: ";
        cin >> students[i].numberOfExams;

        students[i].grades = new int[MAX_EXAMS];

        cout << "Введите оценки по экзаменам: ";
        for (int j = 0; j < students[i].numberOfExams; ++j) {
            cin >> students[i].grades[j];
        }

        cin.ignore();  // Очистка буфера после ввода чисел
    }

    processArrayOfStudents(students, MAX_STUDENTS);

    // Освобождение памяти
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        delete[] students[i].grades;
    }

    return 0;
}
