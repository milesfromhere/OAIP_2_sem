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

    unsigned long modular_hash(const std::string& key) {
        unsigned long hash_value = 0;
        for (char ch : key) {
            hash_value = (hash_value * 31 + ch) % CAPACITY;
        }
        return hash_value;
    }

    unsigned long linear_probing_hash(const std::string& key, int i) {
        unsigned long h_prime = modular_hash(key);
        return (h_prime + i) % CAPACITY;
    }

    void insert(const std::string& key, const std::string& value) {
        int i = 0;
        unsigned long index = linear_probing_hash(key, i);
        while (items[index] != nullptr) {
            ++i;
            index = linear_probing_hash(key, i);
        }
        items[index] = new Ht_item{ key, value };
        ++count;
    }

    std::string search(const std::string& key) {
        int i = 0;
        unsigned long index = linear_probing_hash(key, i);
        while (items[index] != nullptr) {
            if (items[index]->key == key) {
                return items[index]->value;
            }
            ++i;
            index = linear_probing_hash(key, i);
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
