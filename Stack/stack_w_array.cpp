#include <iostream>
using namespace std;

class Stack{
    int *arr;
    int top;
    int size;

    public: 

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int x){
        if( top == size -1){
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop(){
        if (top == -1){
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }

    int peek(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    int sizee(){
        return top + 1;
    }

};


int main() {

    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6); // overflow

    cout << "Top element is: " << s.peek() << endl; 
    cout << "Stack size is: " << s.sizee() << endl; 

    s.pop();
    cout << "Top element is: " << s.peek() << endl; 
    cout << "Stack size is: " << s.sizee() << endl; 

    
    if (s.isEmpty()){
        cout << "Stack is Empty "<<endl;
    }
    else{
        cout << "Stack is not Empty" << endl;
    }


    return 0;
}