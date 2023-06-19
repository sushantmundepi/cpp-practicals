#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearchRecursive(arr, low, mid - 1, x);
        }

        return binarySearchRecursive(arr, mid + 1, high, x);
    }

    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 7, 8, 10, 15, 18, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;

    // Binary search with recursion
    int result1 = binarySearchRecursive(arr, 0, n - 1, x);
    if (result1 == -1) {
        cout << "Element is not present in array" << endl;
    } else {
        cout << "Element is present at index " << result1 << endl;
    }

    // Binary search without recursion
    int result2 = binarySearch(arr, n, x);
    if (result2 == -1) {
        cout << "Element is not present in array" << endl;
    } else {
        cout << "Element is present at index " << result2 << endl;
    }

    return 0;
}
