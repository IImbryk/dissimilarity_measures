#include <iostream>
#include <set>
#include <chrono>
#include <algorithm>
using namespace std::chrono;

double jaccard_similarity(const int arr1[], const int arr2[], int size) {
    std::set<int> set1(arr1, arr1 + size);
    std::set<int> set2(arr2, arr2 + size);
    
    std::set<int> intersection;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                            std::inserter(intersection, intersection.begin()));
    
    std::set<int> union_set;
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                    std::inserter(union_set, union_set.begin()));
    
    double jaccard_coefficient = static_cast<double>(intersection.size()) / union_set.size();
    return jaccard_coefficient;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    int arr2[] = {4, 5, 8, 6, 10, 4, 5, 8, 6, 10};

    int size = sizeof(arr1) / sizeof(arr1[0]);
    
    auto start = high_resolution_clock::now();
    double jaccard_coefficient = jaccard_similarity(arr1, arr2, size);
    auto stop = high_resolution_clock::now();
    
    std::cout << "Jaccard similarity coefficient: " << jaccard_coefficient << std::endl;
    
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    
    return 0;
}
