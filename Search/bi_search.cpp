#include <iostream>
using namespace std;

void printarr(int arr[],int n){
    cout<<"\nArray is [ ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]\n";
}

int binarysearch(int arr[], int n, int key){
    int start=0, end=n-1, mid = start + (end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            start=mid+1;
        }
        if(arr[mid]>key){
            end=mid-1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main() {
    int arr[1000], n, key;
    cout<<"enter no. of elements : ";
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cout<<"Enter the "<<i<<"th element : ";
        cin>>arr[i-1];
    }
    
    cout<<"\nENTER KEY : ";
    cin>>key;
    
    printarr(arr,n);
    
    int result = binarysearch(arr, n, key);
    
    if (result != -1)
        cout << "\nKEY FOUND AT INDEX " << result << endl;
    else
        cout << "\nKEY NOT FOUND!!";
    
    return 0; 
}