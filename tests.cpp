#include <iostream>
#include <chrono>
#include <vector>
#include "BinarySearchTree.h"

size_t lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

double fillContainer(BinarySearchTree& tree, int size) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size; ++i) {
        tree.insert(lcg());
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    return duration.count();
}

double containsInContainer(BinarySearchTree& tree, int size) {
    double total_time = 0;

    for (int i = 0; i < size; ++i) {
        size_t key = lcg();

        auto start = std::chrono::high_resolution_clock::now();
        tree.contains(key);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;
        total_time += duration.count();
    }

    return total_time / size;
}

double insertAndEraseInContainer(BinarySearchTree& tree, int size) {
    double total_time = 0;

    for (int i = 0; i < size; ++i) {
        size_t key = lcg();

        auto start = std::chrono::high_resolution_clock::now();

        tree.insert(key);
        tree.erase(key);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;
        total_time += duration.count();
    }

    return total_time / size;
}

double fillVector(std::vector<int>& vec, int size) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size; ++i) {
        vec.push_back(lcg());
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    return duration.count();
}

double searchInVector(const std::vector<int>& vec, int size) {
    double total_time = 0;

    for (int i = 0; i < size; ++i) {
        size_t key = lcg();

        auto start = std::chrono::high_resolution_clock::now();

        std::find(vec.begin(), vec.end(), key);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;
        total_time += duration.count();
    }

    return total_time / size;
}

double insertAndEraseInVector(std::vector<int>& vec, int size) {
    double total_time = 0;

    for (int i = 0; i < size; ++i) {
        size_t key = lcg();

        auto start = std::chrono::high_resolution_clock::now();

        vec.push_back(key);
        vec.erase(std::remove(vec.begin(), vec.end(), key), vec.end());

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;
        total_time += duration.count();
    }

    return total_time / size;
}

//int main() {
//    int sizes[] = { 1000, 10000, 100000 };
//    int attempts = 1000;
//
//    for (int size : sizes) {
//        double bst_total_fill_time = 0;
//        double bst_total_search_time = 0;
//        double bst_total_insert_erase_time = 0;
//
//        double vector_total_fill_time = 0;
//        double vector_total_search_time = 0;
//        double vector_total_insert_erase_time = 0;
//
//        for (int i = 0; i < attempts; ++i) {
//            BinarySearchTree tree;
//            std::vector<int> vec;
//            bst_total_fill_time += fillContainer(tree, size);
//            bst_total_search_time += containsInContainer(tree, size);
//            bst_total_insert_erase_time += insertAndEraseInContainer(tree, size);
//            vector_total_fill_time += fillVector(vec, size);
//            vector_total_search_time += searchInVector(vec, size);
//            vector_total_insert_erase_time += insertAndEraseInVector(vec, size);
//        }
//
//        double bst_average_fill_time = bst_total_fill_time / attempts;
//        double bst_average_search_time = bst_total_search_time / attempts;
//        double bst_average_insert_erase_time = bst_total_insert_erase_time / attempts;
//
//        double vector_average_fill_time = vector_total_fill_time / attempts;
//        double vector_average_search_time = vector_total_search_time / attempts;
//        double vector_average_insert_erase_time = vector_total_insert_erase_time / attempts;
//
//        std::cout << "BST average search time for " << size << " elements: " << bst_average_search_time << " milliseconds" << std::endl;
//        std::cout << "BST average fill time for " << size << " elements: " << bst_average_fill_time << " milliseconds" << std::endl;
//        std::cout << "BST average insert and erase time for " << size << " elements: " << bst_average_insert_erase_time << " milliseconds" << std::endl;
//
//        std::cout << "Vector average fill time for " << size << " elements: " << vector_average_fill_time << " milliseconds" << std::endl;
//        std::cout << "Vector average search time for " << size << " elements: " << vector_average_search_time << " milliseconds" << std::endl;
//        std::cout << "Vector average insert and erase time for " << size << " elements: " << vector_average_insert_erase_time << " milliseconds" << std::endl;
//    }
//
//    return 0;
//}
