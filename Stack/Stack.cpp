#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Stack{
public:
    Node* top;

    Stack(){
        top = NULL;
    }

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }

    int pop(){
        if(top == NULL){
            cout << "stack is empty : ";
            return -1;
        }
        Node* temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    int peek(){
        if(top == NULL){
            cout << "empty: ";
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }
};

int main() {
    Stack s;

    s.push(5);
    cout << "top element is : " << s.peek() << endl;

    s.push(6);
    cout << "top element is : " << s.peek() << endl;

    cout << "pop data is : " << s.pop() << endl;
    cout << "pop data is : " << s.pop() << endl;

    cout << "top element is : " << s.peek() << endl;

    return 0;
}