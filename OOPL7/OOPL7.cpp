#include <iostream>
using namespace std;

template <typename T>
void bubble_sort(T arr[], int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    // Example for integers
    int int_arr[] = {64, 34, 25, 12, 22, 11, 90};
    int int_size = sizeof(int_arr) / sizeof(int);
    bubble_sort(int_arr, int_size);
    cout << "Sorted integer array: ";
    for(int i = 0; i < int_size; i++) {
        cout << int_arr[i] << " ";
    }
    cout << endl;

    // Example for floats
    float float_arr[] = {3.14, 1.618, 2.718, 0.577, 1.414};
    int float_size = sizeof(float_arr) / sizeof(float);
    bubble_sort(float_arr, float_size);
    cout << "Sorted float array: ";
    for(int i = 0; i < float_size; i++) {
        cout << float_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
