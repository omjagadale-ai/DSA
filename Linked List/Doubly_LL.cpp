#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
    ~Node(){
        cout << "Memory freed for node with data: " << this -> data << endl;
    }
};

void insert(Node* &head, Node* &tail, int pos , int d ){ 
    
    //inserting at head 
    if(pos == 1){
        Node* temp = new Node(d);
        temp -> next = head;
        temp -> prev = nullptr;
        head = temp;
        return;
    }
    Node* temp = new Node(d);
    int count = 1;
    Node* curr = head;
    while(count < pos - 1){
        curr = curr -> next;
        count++;
    }
    //inserting at tail
    if(curr -> next == nullptr){
        curr -> next = temp;
        temp -> prev = curr;
        tail = temp;
        return;
    } 
    //inserting at middle
    temp -> next = curr -> next;
    curr -> next -> prev = temp;
    curr -> next = temp;
    temp -> prev = curr;
}

void DeleteNode(Node* &head, Node* &tail, int pos){
    if(pos==1){
        Node* temp = head;
        head = temp->next;
        head->prev = nullptr;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* pre = nullptr;

        int cnt = 1;

        while(cnt < pos && curr != nullptr){
            pre = curr;
            curr = curr -> next;
            cnt++;            
        }
        //Out of range case
        if(curr == nullptr){
            cout << "Deleting Position is out of range\n";
            return;
        }
        if(curr->next == nullptr){   // deleting last node
            pre->next = nullptr;
            tail = pre;
        }
        //deleting midddle node
        else{
            pre->next = curr->next;
            curr->next->prev = pre;
        }

        delete curr;
    }
}

void printlist(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {

    Node* n1 = new Node(20);
    Node* n2 = new Node(30);
    Node* n3 = new Node(40);

    Node* head = n1;
    Node* tail = n1;
    n1->next = n2;
    n2->next = n3;
    n2 -> prev = n1;
    n3 -> prev = n2;

    insert(head, tail, 1, 10);
    insert(head, tail, 5, 50);
    insert(head, tail, 3, 25);
    DeleteNode(head,tail,1);
    DeleteNode(head,tail,3);
    printlist(head);
    DeleteNode(head,tail,4);
    printlist(head);

    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;

    return 0;
}