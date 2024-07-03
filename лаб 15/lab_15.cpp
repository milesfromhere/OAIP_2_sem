#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

// Генерация случайных чисел в диапазоне от min до max
int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Вывод массива на экран
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Сортировка слиянием
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Быстрая сортировка (сортировка Хоара)
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL));

    std::vector<int> sizes = { 1000, 2000, 3000, 4000, 5000 };
    for (int size : sizes) {
        std::vector<int> arr(size);

        for (int i = 0; i < size; i++) {
            arr[i] = random(1, 10000);
        }

        auto start = std::chrono::steady_clock::now();
        mergeSort(arr, 0, size - 1);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Merge Sort for size " << size << " took " << elapsed_seconds.count() << " seconds." << std::endl;

        start = std::chrono::steady_clock::now();
        quickSort(arr, 0, size - 1);
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Quick Sort for size " << size << " took " << elapsed_seconds.count() << " seconds." << std::endl;
    }

    return 0;
}
