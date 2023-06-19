#include <iostream>
#include <set>

using namespace std;

int main() {
    int arr[100];
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> s(arr, arr + n);

    int i = 0;
    for(int x : s) {
        arr[i] = x; //copy set elements to array
        i++;
    }
    
    n = s.size(); //update the size of the array

    cout << "Array after deleting duplicates: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
