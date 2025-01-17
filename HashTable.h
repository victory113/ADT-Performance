#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    std::vector<std::list<int>> table;
    int bucketCount; // Number of buckets in the hash table

    // Hash function to calculate the index for a given key
    int hashFunction(int key) const {
        return key % bucketCount;
    }

public:
    // Default constructor with a default bucket count
    HashTable() : bucketCount(10) {  // Set a default bucket count if none is specified
        table.resize(bucketCount);
    }

    // Constructor with a specified size
    HashTable(int size) : bucketCount(size) {
        if (bucketCount <= 0) {
            throw std::invalid_argument("Bucket count must be greater than zero");
        }
        table.resize(bucketCount);
    }

    // Inserts a key into the hash table; returns false if key already exists
    bool insert(int key) {
        int index = hashFunction(key);
        for (int element : table[index]) {
            if (element == key) {
                return false; // Key already exists, insertion failed
            }
        }
        table[index].push_back(key);
        return true; // Insertion successful
    }

    // Searches for a key in the hash table; returns true if found
    bool search(int key) const {
        int index = hashFunction(key);
        for (int element : table[index]) {
            if (element == key) {
                return true; // Key found
            }
        }
        return false; // Key not found
    }

    // Removes a key from the hash table; returns true if deletion was successful
    bool remove(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        auto it = std::find(chain.begin(), chain.end(), key);
        if (it != chain.end()) {
            chain.erase(it);
            return true; // Deletion successful
        }
        return false; // Key not found, deletion failed
    }

    // Displays the contents of the hash table
    void display() const {
        for (int i = 0; i < bucketCount; i++) {
            std::cout << "Bucket " << i << ": ";
            for (int key : table[i]) {
                std::cout << key << " -> ";
            }
            std::cout << "nullptr" << std::endl;
        }
    }
};
