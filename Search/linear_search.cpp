#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter element to search: ";
    cin >> target;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        cout << "Element found in the array.\n";
    }
    else
    {
        cout << "Element not found in the array.\n";
    }
}