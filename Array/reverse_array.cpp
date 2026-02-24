#include <iostream>
using namespace std;

void printingarr(int arr[], int n) {
    cout << "\nYOUR ARRAY IS : [ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

void rev(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        swap(arr[start], arr[end]); 
        start++;
        end--;
    }
    printingarr(arr, n);
}

int main() {
    int arr[100], n;

    cout << "ENTER NUMBER OF ELEMENTS: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "ENTER THE " << i << "TH ELEMENT : ";
        cin >> arr[i];
    }

    cout << "\nOriginal Array:";
    printingarr(arr, n);

    cout << "\nReversed Array:";
    rev(arr, n);

    return 0;
}