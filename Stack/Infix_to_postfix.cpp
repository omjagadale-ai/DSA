#include<iostream>
#include<cctype>
using namespace std;

class Node{
public:
    char val;
    Node* next;

    Node(char val){
        this->val = val;
        this->next = NULL;
    }
};

class Stack{
public:
    Node* top;

    Stack(){
        top = NULL;
    }

    void push(char val){
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    char pop(){
        if(top == NULL){
            return -1;
        }
        Node* temp = top;
        char value = temp->val;
        top = top->next;
        delete temp;
        return value;
    }

    char peek(){
        if(top == NULL){
            return -1;
        }
        return top->val;
    }

    bool empty(){
        return top == NULL;
    }
};

int priority(char ch){
    if(ch == '(') return 0;
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    return 3;
}

void infixtopostfix(char infix[20], char postfix[20]){
    Stack s;
    int i, j = 0;
    char token;

    for(i = 0; infix[i] != '\0'; i++){
        token = infix[i];

        if(isalnum(token)){
            postfix[j++] = token;
        }

        else if(token == '('){
            s.push(token);
        }

        else if(token == ')'){
            while(!s.empty() && s.peek() != '('){
                postfix[j++] = s.pop();
            }
            s.pop(); 
        }

        else{
            while(!s.empty() && priority(token) <= priority(s.peek())){
                postfix[j++] = s.pop();
            }
            s.push(token);
        }
    }

    while(!s.empty()){
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0';
}

int main(){
    char infix[20], postfix[20];

    cout << "Enter the expression: ";
    cin >> infix;

    infixtopostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}