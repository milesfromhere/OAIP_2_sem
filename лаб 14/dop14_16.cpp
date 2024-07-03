#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <chrono>

struct Car {
    int number;
    std::string owner;
    std::string brand;
};

inline unsigned int xorHash(int key, int size) {
    return key; 
}

int main() {
    std::unordered_map<int, Car> carHashTable;

    carHashTable[12345] = { 12345, "John", "Toyota" };
    carHashTable[67890] = { 67890, "Alice", "Ford" };

    auto start = std::chrono::steady_clock::now();

    int searchNumber = 12345;
    auto it = carHashTable.find(searchNumber);
    if (it != carHashTable.end()) {
        std::cout << "Найдена машина с номером " << it->second.number << ", владелец: " << it->second.owner << ", марка: " << it->second.brand << std::endl;
    }
    else {
        std::cout << "Машина с номером " << searchNumber << " не найдена." << std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = end - start;

    std::cout << "Поиск информации в хеш-таблице занял: " << elapsedTime.count() << " секунд." << std::endl;

    return 0;
}
