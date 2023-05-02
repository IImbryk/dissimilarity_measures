#include <iostream>
#include <cmath>
#include <algorithm>

float euclidean_distance(float arr1[], float arr2[], int size) {
    std::sort(arr1, arr1 + size);
    std::sort(arr2, arr2 + size);

    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        float diff = arr1[i] - arr2[i];
        sum += diff * diff;
    }
    return std::sqrt(sum);
}

float cosine_distance(float arr1[], float arr2[], int size) {
    std::sort(arr1, arr1 + size);
    std::sort(arr2, arr2 + size);
    
    float dot_product = 0, norm1 = 0, norm2 = 0;
    
    for (int i = 0; i < size; i++) {
        dot_product += arr1[i] * arr2[i];
        norm1 += pow(arr1[i], 2);
        norm2 += pow(arr2[i], 2);
    }
    
    norm1 = sqrt(norm1);
    norm2 = sqrt(norm2);
    
    float cosine_similarity = dot_product / (norm1 * norm2);
    float cosine_distance = 1 - cosine_similarity;
    
    return cosine_distance;
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
    
    float distance_eucl = euclidean_distance(arr1, arr2, n);
    std::cout << "Euclidean distance: " << distance_eucl << std::endl;


    float distance_cos = cosine_distance(arr1, arr2, n);
    std::cout << "Cosine distance: " << distance_cos << std::endl;
    
    return 0;
}
