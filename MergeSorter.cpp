#include<iostream>
#include<iomanip>
#include<array>
using namespace std;

template <typename T, size_t size>
void merge(array<T, size>& items, size_t left, size_t middle1, size_t middle2, size_t right) {
    size_t leftIndex = left; // index into left subarray
    size_t rightIndex = middle2; // index into right subarray
    size_t combinedIndex = left; // index into temporary working array
    array<T, size> combined; // working array
    // merge arrays until reaching end of either

    while (leftIndex <= middle1 && rightIndex <= right) {
        // place smaller of two current elements into result
        // and move to next space in array
        if (items[leftIndex] <= items[rightIndex]) {
            combined[combinedIndex++] = items[leftIndex++];
        } else {
            combined[combinedIndex++] = items[rightIndex++];
        }

    }
    if (leftIndex == middle2) { // if at end of left array
        while (rightIndex <= right) { // copy in rest of right array
            combined[combinedIndex++] = items[rightIndex++];
        }
    } else { // at end of right array
        while (leftIndex <= middle1) { // copy in rest of left array
            combined[combinedIndex++] = items[leftIndex++];
        }
    }

    // copy values back into original array
    for (size_t i = left; i <= right; ++i) {
    items[i] = combined[i];
    }
}


template <typename T, size_t size>
void mergeSort(array<T, size>& items, size_t low, size_t high) {
    // test base case; size of array equals 1
    if ((high - low) >= 1) { // if not base case
        int middle1 = (low + high) / 2; // calculate middle of array
        int middle2 = middle1 + 1; // calculate next element over
        // split array in half; sort each half (recursive calls)
        mergeSort(items, low, middle1); // first half of array
        mergeSort(items, middle2, high); // second half of array
        // merge two sorted arrays after split calls return
        merge(items, low, middle1, middle2, high);
    }
}




int main() {
    const size_t arraySize = 10; // size of array
    array<int, arraySize> data = {20, 60, 80, 100, 400, 70, 30, 500, 900, 10}; // create array
    cout << "Unsorted array:\n";
    // output original array
    for (size_t i=0; i < arraySize; ++i) {
        cout << setw(4) << data[i];
    }

    mergeSort(data, 0, data.size() - 1); // sort the array data
    cout << "\nSorted array:\n";
    // output sorted array
    for (size_t i=0; i < arraySize; ++i) {
        cout << setw(4) << data[i];
    }
    cout << endl;
}
