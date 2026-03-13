#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
     
    // constructor
    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
    //destructor
    ~Node() {
        int value = this->data;
        cout << "Memory freed for node with data: " << value << endl;
    }
};        

void insertAtHead(Node* &head, int d){
    // creating new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d); 

    tail -> next = temp;
    tail = temp;
    
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d){

    //head conditon
    if(pos == 1){
        insertAtHead(head,d);
        return;
    }

    
    Node* temp = head;
    int count = 1;

    while(count < pos-1 && temp != nullptr){
        temp = temp -> next;
        count ++;
    }
    //Out of range case
    if(temp == nullptr){
        cout << "Inserting Position is out of range\n";
        return;
    }

    // tail condition
    if(temp->next == nullptr){
        insertAtTail(tail,d);
        return;
    }

    // postion pe insert
    Node* NodeToInsert = new Node(d);

    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;
}

void printlist(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void DeleteNode(Node* &head,Node* &tail, int pos){
    // head
    if(pos==1){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    //middle & end
    else{
        Node* curr = head;
        Node* prev = nullptr;

        int cnt = 1;

        while(cnt < pos && curr != nullptr){
            prev = curr;
            curr = curr -> next;
            cnt++;            
        }
        //Out of range case
        if(curr == nullptr){
            cout << "Deleting Position is out of range\n";
            return;
        }
        prev->next = curr->next;
        // if deleting last node
        if(curr->next == nullptr ){  
            tail = prev;
        }
        delete curr;

    }
}

int main(){

    Node* node1 = new Node(10);  

    Node* head = node1;
    Node* tail = node1;
    
    insertAtHead(head,5);
    
    insertAtTail(tail,15);

    insertAtPosition(head, tail, 1, 2);

    insertAtPosition(head, tail, 3, 127);
    
    insertAtPosition(head, tail, 6, 227);

    DeleteNode(head, tail, 3);
    
    printlist(head);

    cout<<endl;
    
    return 0;
}