#include<iostream>
using namespace std;

void getset(int set[], int &n){
    cout<<"enter no of element in set: ";
    cin>>n;
    cout<<"enter elements: ";
    for (int i = 0; i < n; i++){
        cin>>set[i];
    }
    
}

bool isexist(int A[],int n,int elem){
     for(int i=0 ;i<n;i++){
        if(A[i]==elem) return true;
    }
    return false;

}

void display(int set[],int n){
    cout<<"{";
    for(int i=0;i<n;i++){
        cout<<set[i];
        if(!set[n-1]){
            cout<<",";
        }
    }
    cout<<"}";
}

int setunion(int A[],int n1,int B[],int n2,int U[]){
    int k=0;
    for(int i=0;i<n1;i++){
        U[k++]=A[i];
    }
    for (int i = 0; i <n2; i++){
        if(!isexist(A,n1,B[i])){
            U[k++]=B[i];
        }
    }
    return k; 
    
}
int setinsersection(int A[],int n1,int B[],int n2,int I[]){
    int k=0;
    for(int i =0;i<n1;i++){
        if(isexist(B,n2,A[i])){
            I[k++]=A[i];
        }
    }
    return k;
}

int difference(int A[],int n1,int B[],int n2,int D[]){
    int k=0;
    for (int i = 0; i <n1; i++){
        if(!isexist(B,n2,A[i])){
            D[k++]=A[i];
        }

    }
    return k;
}

int symmetricdiff(int A[],int n1,int B[],int n2,int SD[]){
    int temp1[50],temp2[50];

    int ntemp1=difference(A,n1,B,n2,temp1);
    int ntemp2=difference(B,n2,A,n1,temp2);

    int k = setunion(temp1,ntemp1,temp2,ntemp2,SD);
    return k;
}


int main(){
    int A[50], B[50];
    int n1, n2;

    cout<<"enter set A: ";
    getset(A,n1);
    cout<<"enter set B: ";
    getset(B,n2);
}
