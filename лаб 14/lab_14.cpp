#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <chrono> 

struct School {
    std::string directorLastName;
};

inline unsigned int universalHash(const std::string& key, int size) {

    unsigned int hash = 0;
    for (char c : key) {
        hash ^= c;
    }
    return hash;
   
}

inline unsigned int xorHash(const std::string& key, int size) {

    unsigned int hash = 0;
    for (char c : key) {
        hash ^= c;
    }
    return hash;
}

int main() {

    std::unordered_map<int, std::vector<School>> hashTable;

    auto start = std::chrono::steady_clock::now();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = end - start;

    std::cout << "Поиск информации в хеш-таблице занял: " << elapsedTime.count() << " секунд." << std::endl;

    return 0;
}