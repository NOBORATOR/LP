#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Deterministic QuickSort
void deterministicQuickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);

// Randomized QuickSort
void randomizedQuickSort(vector<int>& arr, int low, int high);
int randomizedPartition(vector<int>& arr, int low, int high);

// Utility functions
void swap(int& a, int& b);
vector<int> generateRandomArray(int size, int range);

int main() {
    int size = 10000; // Size of the array
    int range = 10000; // Range of random numbers

    // Generate random array for deterministic QuickSort
    vector<int> arr1 = generateRandomArray(size, range);
    clock_t startTime = clock();
    deterministicQuickSort(arr1, 0, arr1.size() - 1);
    clock_t endTime = clock();
    cout << "Deterministic QuickSort time: " << (endTime - startTime) * 1000.0 / CLOCKS_PER_SEC << " ms" << endl;

    // Generate random array for randomized QuickSort
    vector<int> arr2 = generateRandomArray(size, range);
    startTime = clock();
    randomizedQuickSort(arr2, 0, arr2.size() - 1);
    endTime = clock();
    cout << "Randomized QuickSort time: " << (endTime - startTime) * 1000.0 / CLOCKS_PER_SEC << " ms" << endl;

    return 0;
}

// Deterministic QuickSort function
void deterministicQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}

// Partition function for deterministic QuickSort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized QuickSort function
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Randomized partition function
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

// Swap utility function
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Generate a random array
vector<int> generateRandomArray(int size, int range) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }
    return arr;
}
