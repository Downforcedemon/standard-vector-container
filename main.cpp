#include <iostream>
#include "CustomVector.h"

int main() {
    // Create a CustomVector of integers
    CustomVector<int> vec;

    // Test push_back()
    std::cout << "Testing push_back():" << std::endl;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    std::cout << "Elements after push_back: " << vec[0] << ", " << vec[1] << ", " << vec[2] << std::endl;

    // Test front() and back()
    std::cout << "\nTesting front() and back():" << std::endl;
    std::cout << "First element (front): " << vec.front() << std::endl;
    std::cout << "Last element (back): " << vec.back() << std::endl;

    // Test size() and capacity()
    std::cout << "\nTesting size() and capacity():" << std::endl;
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    // Test pop_back()
    std::cout << "\nTesting pop_back():" << std::endl;
    vec.pop_back();
    std::cout << "Elements after pop_back: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\nSize after pop_back: " << vec.size() << std::endl;

    // Test operator[] and at()
    std::cout << "\nTesting operator[] and at():" << std::endl;
    vec[0] = 100;  // Modify element at index 0
    std::cout << "Element at index 0 using operator[]: " << vec[0] << std::endl;
    try {
        std::cout << "Element at index 1 using at(): " << vec.at(1) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test empty() and clear()
    std::cout << "\nTesting empty() and clear():" << std::endl;
    std::cout << "Is vector empty? " << (vec.empty() ? "Yes" : "No") << std::endl;
    vec.clear();
    std::cout << "Is vector empty after clear()? " << (vec.empty() ? "Yes" : "No") << std::endl;

    // Test resize()
    std::cout << "\nTesting resize():" << std::endl;
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);
    std::cout << "Size before resize: " << vec.size() << ", Capacity before resize: " << vec.capacity() << std::endl;
    vec.resize(10);
    std::cout << "Size after resize: " << vec.size() << ", Capacity after resize: " << vec.capacity() << std::endl;

    // Re-test push_back() after resize
    std::cout << "\nTesting push_back() after resize:" << std::endl;
    vec.push_back(70);
    vec.push_back(80);
    std::cout << "Elements after adding more: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
