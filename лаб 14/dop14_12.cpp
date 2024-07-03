#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <chrono> 

struct Tenant {
    int apartmentNumber;
    std::string tenants;
};

unsigned int universalHash(int key, int size) {
}

int main() {
    std::unordered_map<int, Tenant> tenantHashTable;

    tenantHashTable[101] = { 101, "John, Alice" };
    tenantHashTable[202] = { 202, "Bob, Carol" };

    auto start = std::chrono::steady_clock::now();

    int searchApartmentNumber = 101;
    auto it = tenantHashTable.find(searchApartmentNumber);
    if (it != tenantHashTable.end()) {
        std::cout << "Жильцы квартиры №" << it->second.apartmentNumber << ": " << it->second.tenants << std::endl;
    }
    else {
        std::cout << "Информация о квартире №" << searchApartmentNumber << " не найдена." << std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = end - start;

    std::cout << "Поиск информации в хеш-таблице занял: " << elapsedTime.count() << " секунд." << std::endl;

    return 0;
}
