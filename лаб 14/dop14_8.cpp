#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <chrono>

struct Flight {
    int flightNumber;
    std::string destinationAirport;
};

unsigned int universalHash(int key, int size) {
    return key % size;
}


int main() {
    std::unordered_map<int, Flight> flightHashTable;

    flightHashTable[101] = { 101, "London" };
    flightHashTable[202] = { 202, "New York" };

    auto start = std::chrono::steady_clock::now();

    int searchFlightNumber = 101;
    auto it = flightHashTable.find(searchFlightNumber);
    if (it != flightHashTable.end()) {
        std::cout << "Рейс №" << it->second.flightNumber << " направляется в аэропорт " << it->second.destinationAirport << std::endl;
    }
    else {
        std::cout << "Информация о рейсе №" << searchFlightNumber << " не найдена." << std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = end - start;

    std::cout << "Поиск информации в хеш-таблице занял: " << elapsedTime.count() << " секунд." << std::endl;

    return 0;
}
