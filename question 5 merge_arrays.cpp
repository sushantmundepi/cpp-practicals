#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        result[k++] = arr1[i++];
    }

    while (j < n2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;

    int arr1[n1];
    cout << "Enter elements of first array in ascending order: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;

    int arr2[n2];
    cout << "Enter elements of second array in ascending order: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    int result[n1+n2];
    mergeArrays(arr1, arr2, n1, n2, result);

    cout << "Merged array in ascending order: ";
    for (int i = 0; i < n1+n2; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
