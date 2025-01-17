//Done by:Emmanuel Johnson
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <chrono>
#include "BinarySearchTree.h"
#include "AVL.h"
#include "HashTable.h"

bool find(const std::list<int> &myList, const int &value) {
    return std::find(myList.begin(), myList.end(), value) != myList.end();
}

int main() {
    std::list<int> list1;         // Creates a List using std::list
    std::fstream deleteFile;
    std::fstream randomFile;
    std::fstream searchFile;
    
    int number;
    int successfulSearches = 0, failedSearches = 0, successfulInserts = 0 , successfulDeletes = 0, failedDeletes = 0;
    int datasize;

    
        std::cout << "What data size would you like." << std::endl;
        std::cout << "1. 10k data size" << std::endl;
        std::cout << "2. 1M data size" << std::endl;
        std::cout << "3. 10M data size" << std::endl;
        std::cin >> datasize;

        switch (datasize) {
            case 1: {
                deleteFile.open("delete_values_10k.txt");
                randomFile.open("random_values_10k.txt");
                searchFile.open("search_values_10k.txt");

                if (!deleteFile.is_open() || !randomFile.is_open() || !searchFile.is_open()) {
                    std::cerr << "Error opening files for 10k data size." << std::endl;
                    return 1;
                }

                auto startLoad = std::chrono::high_resolution_clock::now();
                while (randomFile >> number) {
                    list1.push_back(number);
                    successfulInserts++;
                }
                auto endLoad = std::chrono::high_resolution_clock::now();
                auto loadDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endLoad - startLoad);
                std::cout << "Time taken to insert list: " << loadDuration.count() << " ms" << std::endl;
                std::cout << "The number of successful inserts are " << successfulInserts << std::endl;

                auto startSearch = std::chrono::high_resolution_clock::now();
                while (searchFile >> number) {
                    if (find(list1, number)) successfulSearches++;
                    else failedSearches++;
                }
                auto endSearch = std::chrono::high_resolution_clock::now();
                auto searchDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endSearch - startSearch);
                std::cout << "Time taken to search list: " << searchDuration.count() << " ms" << std::endl;
                std::cout << "Successful searches: " << successfulSearches << std::endl;
                std::cout << "Failed searches: " << failedSearches << std::endl;

                auto startDelete = std::chrono::high_resolution_clock::now();
                while (deleteFile >> number) {
                    
                list1.remove(number);
                        
            }

                auto endDelete = std::chrono::high_resolution_clock::now();
                auto deleteDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endDelete - startDelete);
                std::cout << "Time taken to delete numbers from list: " << deleteDuration.count() << " ms" << std::endl;
                
                break;
            }
            case 2: {
                deleteFile.open("delete_values_1m.txt");
                randomFile.open("random_values_1m.txt");
                searchFile.open("search_values_1m.txt");

                if (!deleteFile.is_open() || !randomFile.is_open() || !searchFile.is_open()) {
                    std::cerr << "Error opening files for 1M data size." << std::endl;
                    return 1;
                }

                auto startLoad = std::chrono::high_resolution_clock::now();
                while (randomFile >> number) {
                    list1.push_back(number);
                    successfulInserts++;
                }
                auto endLoad = std::chrono::high_resolution_clock::now();
                auto loadDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endLoad - startLoad);
                std::cout << "Time taken to insert list: " << loadDuration.count() << " ms" << std::endl;
                std::cout << "The number of successful inserts are " << successfulInserts << std::endl;


                auto startSearch = std::chrono::high_resolution_clock::now();
                while (searchFile >> number) {
                    if (find(list1, number)) successfulSearches++;
                    else failedSearches++;
                }
                auto endSearch = std::chrono::high_resolution_clock::now();
                auto searchDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endSearch - startSearch);
                std::cout << "Time taken to search list: " << searchDuration.count() << " ms" << std::endl;
                std::cout << "Successful searches: " << successfulSearches << std::endl;
                std::cout << "Failed searches: " << failedSearches << std::endl;

                auto startDelete = std::chrono::high_resolution_clock::now();
                while (deleteFile >> number) {
                    
                        list1.remove(number);
                      
            }
                auto endDelete = std::chrono::high_resolution_clock::now();
                auto deleteDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endDelete - startDelete);
                std::cout << "Time taken to delete numbers from list: " << deleteDuration.count() << " ms" << std::endl;
                
                break;
            }
            case 3: {
                deleteFile.open("delete_values_10m.txt");
                randomFile.open("random_values_10m.txt");
                searchFile.open("search_values_10m.txt");

                if (!deleteFile.is_open() || !randomFile.is_open() || !searchFile.is_open()) {
                    std::cerr << "Error opening files for 10M data size." << std::endl;
                    return 1;
                }

                auto startLoad = std::chrono::high_resolution_clock::now();
                while (randomFile >> number) {
                    list1.push_back(number);
                    successfulInserts++;
                }
                auto endLoad = std::chrono::high_resolution_clock::now();
                auto loadDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endLoad - startLoad);
                std::cout << "Time taken to insert list: " << loadDuration.count() << " ms" << std::endl;
                std::cout << "The number of successful inserts are " << successfulInserts << std::endl;


                auto startSearch = std::chrono::high_resolution_clock::now();
                while (searchFile >> number) {
                    if (find(list1, number)) successfulSearches++;
                    else failedSearches++;
                }
                auto endSearch = std::chrono::high_resolution_clock::now();
                auto searchDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endSearch - startSearch);
                std::cout << "Time taken to search list: " << searchDuration.count() << " ms" << std::endl;
                std::cout << "Successful searches: " << successfulSearches << std::endl;
                std::cout << "Failed searches: " << failedSearches << std::endl;
                
                auto startDelete = std::chrono::high_resolution_clock::now();
                while (deleteFile >> number) {
                   
                        list1.remove(number);
                }
                      
                auto endDelete = std::chrono::high_resolution_clock::now();
                auto deleteDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endDelete - startDelete);
                std::cout << "Time taken to delete numbers from list: " << deleteDuration.count() << " ms" << std::endl;
                break;
            }
            default:
                std::cerr << "Invalid data size option." << std::endl;
        }

    
       
     

    deleteFile.close();
    randomFile.close();
    searchFile.close();

    std::cout << "Done" << std::endl;
    return 0;
}
