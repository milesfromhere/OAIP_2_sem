#include <iostream>
#include <string>

struct Ht_item {
    std::string key;
    std::string value;
};

class HashTable {
private:
    static const int CAPACITY = 128; 
    Ht_item* items[CAPACITY];
    int count;

public:
    HashTable() {
        for (int i = 0; i < CAPACITY; ++i) {
            items[i] = nullptr;
        }
        count = 0;
    }

    unsigned long universal_hash(const std::string& key) {
        unsigned long hash_value = 0;
        const unsigned long A = 2654435769; 
        for (char ch : key) {
            hash_value = (hash_value * A) + ch;
        }
        return hash_value % CAPACITY;
    }

    void insert(const std::string& key, const std::string& value) {
        unsigned long index = universal_hash(key);
        while (items[index] != nullptr) {
            index = (index + 1) % CAPACITY; 
        }
        items[index] = new Ht_item{ key, value };
        ++count;
    }

    std::string search(const std::string& key) {
        unsigned long index = universal_hash(key);
        while (items[index] != nullptr) {
            if (items[index]->key == key) {
                return items[index]->value;
            }
            index = (index + 1) % CAPACITY; 
        }
        return "Not found";
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    HashTable ht;
    ht.insert("яблоко", "фрукт");
    ht.insert("банан", "фрукт");
    ht.insert("морковка", "овощь");

    std::cout << "банан - это " << ht.search("банан") << std::endl;
    std::cout << "виноград - это " << ht.search("виноград") << std::endl;
}
