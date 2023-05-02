#include <iostream>
#include <algorithm>
#include <set>
#include <chrono>
using namespace std::chrono;


using namespace std;
 
double array_similarity(int arr1[], int arr2[], int n) {

    // sort(arr1, arr1 + n);
    // sort(arr2, arr2 + n);
    
    set <int> set1(arr1, arr1 + n);
    set <int> set2(arr2, arr2 + n);
    int intersection_size = 0;
    for (int x : set1) {
        if (set2.count(x)) {
            intersection_size++;
        }
    }
    int union_size = set1.size() + set2.size() - intersection_size;
    return (double)intersection_size / union_size;
}
 
int main() {
    int arr1[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    int arr2[] = {4, 5, 8, 6, 10, 4, 5, 8, 6, 10};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    
    auto start = high_resolution_clock::now();
    double similarity = array_similarity(arr1, arr2, size);
    auto stop = high_resolution_clock::now();
    cout << "The similarity coefficient is " << similarity << endl;
    
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
