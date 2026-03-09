#include <iostream>
using namespace std;

void printarr(int arr[],int n){
    cout<<"\nArray is [ ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]\n";
}

int firstocc(int arr[], int n, int key){
    int start=0, end=n-1, mid = start + (end-start)/2;
    int ans = -1;

    while(start<=end){
        if(arr[mid]==key){
            ans = mid;
            end = mid - 1;
        }
        if(arr[mid]<key){
            start=mid+1;
        }
        if(arr[mid]>key){
            end=mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int lastocc(int arr[], int n, int key){
    int start=0, end=n-1, mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(arr[mid]==key){
            ans = mid;
            start = mid + 1;
        }
        if(arr[mid]<key){
            start=mid+1;
        }
        if(arr[mid]>key){
            end=mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main() {
    int arr[100], n, key;
    cout<<"enter no. of elements : ";
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cout<<"Enter the "<<i<<"th element : ";
        cin>>arr[i-1];
    }
    
    cout<<"\nENTER KEY : ";
    cin>>key;
    
    printarr(arr,n);
    
    if ( (firstocc(arr,n,key) & lastocc(arr,n,key)) != -1){
        cout<<"\nFIRST OCCURRENCE IS AT INDEX : "<< firstocc(arr,n,key);
        cout<<"\nLAST OCCURRENCE IS AT INDEX : "<< lastocc(arr,n,key);
    }
    else{
        cout<<"\nKEY IS NOT PRESENT!";
    }
    
    cout<<"\n\nTOTAL OCCURRENCE : "<< (lastocc(arr,n,key) - firstocc(arr,n,key)) + 1;
    
    return 0;
}
