// Chima Onochie


#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <chrono>
#include "BinarySeachTree.h"
#include "AVL.h"
#include "HashTable.h"

int main() {
    HashTable hashTable(10);  // Initialize the hash table with a non-zero bucket count

    char continueTest;
    int number;
    int successfulSearches = 0, failedSearches = 0, successfulInserts = 0;
    int successfulDeletes = 0, failedDeletes = 0;

    std::fstream deleteFile;
    std::fstream randomFile;
    std::fstream searchFile;

    // ---- 10K Dataset ----
    std::cout << "Starting with HashTable using 10K dataset" << std::endl;

    deleteFile.open("delete_values_10k.txt");
    randomFile.open("random_values_10k.txt");
    searchFile.open("search_values_10k.txt");

    if (!deleteFile.is_open() || !randomFile.is_open() || !searchFile.is_open()) {
        std::cerr << "Error opening files for 10K data size." << std::endl;
        return 1;
    }

    // Insert operations
    auto startLoad = std::chrono::high_resolution_clock::now();
    while (randomFile >> number) {
        if (hashTable.insert(number)) {
            successfulInserts++;
        }
    }
    auto endLoad = std::chrono::high_resolution_clock::now();
    auto loadDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endLoad - startLoad);
    std::cout << "Time taken to insert into HashTable: " << loadDuration.count() << " ms" << std::endl;
    std::cout << "The number of successful inserts are " << successfulInserts << std::endl;

    // Search operations
    auto startSearch = std::chrono::high_resolution_clock::now();
    while (searchFile >> number) {
        if (hashTable.search(number)) {
            successfulSearches++;
        }
        else {
            failedSearches++;
        }
    }
    auto endSearch = std::chrono::high_resolution_clock::now();
    auto searchDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endSearch - startSearch);
    std::cout << "Time taken to search HashTable: " << searchDuration.count() << " ms" << std::endl;
    std::cout << "Successful searches: " << successfulSearches << std::endl;
    std::cout << "Failed searches: " << failedSearches << std::endl;

    // Delete operations
    auto startDelete = std::chrono::high_resolution_clock::now();
    while (deleteFile >> number) {
        if (hashTable.remove(number)) {
            successfulDeletes++;
        }
        else {
            failedDeletes++;
        }
    }
    auto endDelete = std::chrono::high_resolution_clock::now();
    auto deleteDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endDelete - startDelete);
    std::cout << "Time taken to delete from HashTable: " << deleteDuration.count() << " ms" << std::endl;
    std::cout << "Successfully deleted " << successfulDeletes << " values." << std::endl;
    std::cout << "Failed to delete " << failedDeletes << " values." << std::endl;

    // Close files for 10K dataset
    deleteFile.close();
    randomFile.close();
    searchFile.close();

    // ---- 1M Dataset ----
    std::cout << "\nWould you like to test the 1M dataset? (y/n): ";
    std::cin >> continueTest;
    if (continueTest == 'y' || continueTest == 'Y') {
        // Reset counters
        successfulSearches = 0;
        failedSearches = 0;
        successfulInserts = 0;
        successfulDeletes = 0;
        failedDeletes = 0;

        deleteFile.open("delete_values_1m.txt");
        randomFile.open("random_values_1m.txt");
        searchFile.open("search_values_1m.txt");

        if (!deleteFile.is_open() || !randomFile.is_open() || !searchFile.is_open()) {
            std::cerr << "Error opening files for 1M data size." << std::endl;
            return 1;
        }

        // Insert operations for 1M dataset
        startLoad = std::chrono::high_resolution_clock::now();
        while (randomFile >> number) {
            if (hashTable.insert(number)) {
                successfulInserts++;
            }
        }
        endLoad = std::chrono::high_resolution_clock::now();
        loadDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endLoad - startLoad);
        std::cout << "\n----- 1M Dataset Results -----" << std::endl;
        std::cout << "Time taken to insert into HashTable: " << loadDuration.count() << " ms" << std::endl;
        std::cout << "The number of successful inserts are " << successfulInserts << std::endl;

        // Search operations for 1M dataset
        startSearch = std::chrono::high_resolution_clock::now();
        while (searchFile >> number) {
            if (hashTable.search(number)) {
                successfulSearches++;
            }
            else {
                failedSearches++;
            }
        }
        endSearch = std::chrono::high_resolution_clock::now();
        searchDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endSearch - startSearch);
        std::cout << "Time taken to search HashTable: " << searchDuration.count() << " ms" << std::endl;
        std::cout << "Successful searches: " << successfulSearches << std::endl;
        std::cout << "Failed searches: " << failedSearches << std::endl;

        // Delete operations for 1M dataset
        startDelete = std::chrono::high_resolution_clock::now();
        while (deleteFile >> number) {
            if (hashTable.remove(number)) {
                successfulDeletes++;
            }
            else {
                failedDeletes++;
            }
        }
        endDelete = std::chrono::high_resolution_clock::now();
        deleteDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endDelete - startDelete);
        std::cout << "Time taken to delete from HashTable: " << deleteDuration.count() << " ms" << std::endl;
        std::cout << "Successfully deleted " << successfulDeletes << " values." << std::endl;
        std::cout << "Failed to delete " << failedDeletes << " values." << std::endl;

        // Close files for 1M dataset
        deleteFile.close();
        randomFile.close();
        searchFile.close();
    }

    // ---- 10M Dataset ----
    std::cout << "\nWould you like to test the 10M dataset? (y/n): ";
    std::cin >> continueTest;
    if (continueTest == 'y' || continueTest == 'Y') {
        // Reset counters
        successfulSearches = 0;
        failedSearches = 0;
        successfulInserts = 0;
        successfulDeletes = 0;
        failedDeletes = 0;

        deleteFile.open("delete_values_10m.txt");
        randomFile.open("random_values_10m.txt");
        searchFile.open("search_values_10m.txt");

        if (!deleteFile.is_open() || !randomFile.is_open() || !searchFile.is_open()) {
            std::cerr << "Error opening files for 10M data size." << std::endl;
            return 1;
        }

        // Insert operations for 10M dataset
        startLoad = std::chrono::high_resolution_clock::now();
        while (randomFile >> number) {
            if (hashTable.insert(number)) {
                successfulInserts++;
            }
        }
        endLoad = std::chrono::high_resolution_clock::now();
        loadDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endLoad - startLoad);
        std::cout << "\n----- 10M Dataset Results -----" << std::endl;
        std::cout << "Time taken to insert into HashTable: " << loadDuration.count() << " ms" << std::endl;
        std::cout << "The number of successful inserts are " << successfulInserts << std::endl;

        // Search operations for 10M dataset
        startSearch = std::chrono::high_resolution_clock::now();
        while (searchFile >> number) {
            if (hashTable.search(number)) {
                successfulSearches++; 
            }
            else {
                failedSearches++;
            }
        }
        endSearch = std::chrono::high_resolution_clock::now();
        searchDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endSearch - startSearch);
        std::cout << "Time taken to search HashTable: " << searchDuration.count() << " ms" << std::endl;
        std::cout << "Successful searches: " << successfulSearches << std::endl;
        std::cout << "Failed searches: " << failedSearches << std::endl;

        // Delete operations for 10M dataset
        startDelete = std::chrono::high_resolution_clock::now();
        while (deleteFile >> number) {
            if (hashTable.remove(number)) {
                successfulDeletes++;
            }
            else {
                failedDeletes++;
            }
        }
        endDelete = std::chrono::high_resolution_clock::now();
        deleteDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endDelete - startDelete);
        std::cout << "Time taken to delete from HashTable: " << deleteDuration.count() << " ms" << std::endl;
        std::cout << "Successfully deleted " << successfulDeletes << " values." << std::endl;
        std::cout << "Failed to delete " << failedDeletes << " values." << std::endl;

        // Close files for 10M dataset
        deleteFile.close();
        randomFile.close();
        searchFile.close();
    }

    std::cout << "\nProgram completed." << std::endl;
    return 0;
}
