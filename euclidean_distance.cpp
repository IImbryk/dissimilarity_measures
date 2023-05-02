#include <iostream>
#include <cmath>

float euclidean_distance(const float arr1[], const float arr2[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        float diff = arr1[i] - arr2[i];
        sum += diff * diff;
    }
    return std::sqrt(sum);
}
int main() {
    int n;
    std::cout << "Enter the size of the arrays: ";
    std::cin >> n;
    
    float arr1[n], arr2[n];
    std::cout << "Enter the elements of array 1: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr1[i];
    }
    
    std::cout << "Enter the elements of array 2: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr2[i];
    }

    // float arr1[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    // float arr2[] = {4, 5, 8, 6, 10, 4, 5, 8, 6, 10};
    // int size = sizeof(arr1) / sizeof(arr1[0]);
    
    float distance = euclidean_distance(arr1, arr2, n);
    
    std::cout << "Euclidean distance: " << distance << std::endl;
    
    return 0;
}
