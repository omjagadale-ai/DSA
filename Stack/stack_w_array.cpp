#include <iostream>
using namespace std;

class Stack{
    int *arr;
    int top;
    int capacity;
public:
    Stack(int size){
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int x){
        if(top == capacity - 1){
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop(){
        if(top == -1){
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    
    int size(){
        return top + 1;
    }
};

int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6); // overflow

    cout << "Top element is: " << s.peek() << endl; 
    cout << "Stack size is: " << s.size() << endl; 

    cout << "Popped element is: " << s.pop() << endl;
    cout << "Top element is: " << s.peek() << endl; 
    cout << "Stack size is: " << s.size() << endl; 

    return 0;
}