#include <iostream> 
using namespace std;

int partition(int arr[], int s, int e){
    
    int pivot = arr[s];
    int cnt = 0;

    for(int i = s+1; i <= e; i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    int PivotIndex = s + cnt;
    swap(arr[PivotIndex],arr[s]);

    //left & right part
    int i = s, j = e;
    while(i<PivotIndex && j>PivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < PivotIndex && j > PivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return PivotIndex;

}

void quickSort(int arr[], int s, int e) {

    // base case
    if(s>=e){
        return ;
    }
    //partion
    int p = partition(arr, s, e);

    //left
    quickSort(arr, s, p-1);
    //right
    quickSort(arr, p+1, e);
}

int main() {
    int n;

    cout << "ENTER NUMBER OF ELEMENTS: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "ENTER THE " << i << "TH ELEMENT : ";
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}