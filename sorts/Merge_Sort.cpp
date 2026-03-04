#include <iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e){
    int temp[100];
    int i = s;
    int j = mid + 1;
    int k = s;
    while(i <= mid && j<= e){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    // copy remaining left part
    while(i <= mid)
        temp[k++] = arr[i++];

    // copy remaining right part
    while(j <= e)
        temp[k++] = arr[j++];

    // copy back to original array
    for(int x = s; x <= e; x++)
        arr[x] = temp[x];
}
void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}
int main(){
    int n;

    cout << "ENTER NUMBER OF ELEMENTS: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "ENTER THE " << i << "TH ELEMENT : ";
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}