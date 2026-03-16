#include<iostream>
#include<string>
using namespace std;

class Song{
    public: 
    int id;
    string name;
    string artist;
    int duration;
    Song* next;
    
    Song(int id,string name, string artist,int duration){
        this -> id = id;
        this -> name = name;
        this -> artist = artist;
        this -> duration = duration;
        this -> next = nullptr;
    }
};

class playlist{
    public:
    Song * head = nullptr;
    Song * tail = nullptr;

    void addsong(int id,string name, string artist,int duration){
        Song* newsong = new Song(id, name, artist, duration);
        Song* temp = head;   
        if(head == nullptr){
            head = newsong;
            tail = newsong;
            return;
        }

        tail->next = newsong;
        tail = newsong;
    }
    void printPlaylist(){
        if(head == nullptr){
            cout << "Playlist is empty.\n";
            return;
        }

        Song* temp = head;

        while(temp != nullptr){
            cout << "\nID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Artist: " << temp->artist << endl;
            cout << "Duration: " << temp->duration << " sec\n";
            cout << "----------------------\n";

            temp = temp->next;
        }
    }
    void deleteSong(int id){
        if(head == nullptr){
            cout << "Playlist is empty.\n";
            return;
        }

        // If first song 
        if(head->id == id){
            Song* temp = head;
            head = head->next;

            if(head == nullptr){   // if only one song 
                tail = nullptr;
            }

            delete temp;
            cout << "Song deleted successfully.\n";
            return;
        }

        // Search for song
        Song* curr = head;
        Song* prev = nullptr;

        while(curr != nullptr && curr->id != id){
            prev = curr;
            curr = curr->next;
        }

        // If not found
        if(curr == nullptr){
            cout << "Song not found.\n";
            return;
        }

        // Remove node
        prev->next = curr->next;

        // If deleting last song
        if(curr->next == nullptr){
            tail = prev;
        }

        delete curr;
        cout << "Song deleted successfully.\n";
    }

};
int main(){

    playlist p;
    int choice;
    int id;
    string name;
    string artist;
    int duration;
    
    p.addsong(1, "Believer", "Imagine Dragons", 210);
    p.addsong(2, "Shape of You", "Ed Sheeran", 240);
    
    while (true){
        cout<< "\n1.Add Song To Playlist."<<endl;
        cout<< "2. Print playlist."<<endl;
        cout<< "3. Delete song."<<endl;
        cout<<"Enter choice : ";
        cin>> choice;
        switch (choice){
            case 1:
                cout<< "Enter Id , Name , Artist , duration : ";
                cin>> id>>  name>> artist>>  duration;
                p.addsong(id, name, artist, duration);
                break;
            case 2:
                p.printPlaylist();
                break;
            case 3: 
                cout<< "Enter The Id Of Song You Want To Delete : ";
                cin >> id;
                p.deleteSong(id);
                break;
        }
    } 
    return 0;
}