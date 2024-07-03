#include <iostream>
#include <algorithm> // Для использования функции std::max

int F(int m, int n) {
    if ((m + n) % 2 == 0) {
        return (n + m + 1) / 2 * F(m, n + 1) + (m + 1) / 2 * F(m + 1, n + 1);
    }
    else {
        return std::max(n, m);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int m, n;
    std::cout << "Введите целые неотрицательные числа m и n: ";
    std::cin >> m >> n;
    std::cout << "Значение F(" << m << ", " << n << "): " << F(m, n) << std::endl;
    return 0;
}