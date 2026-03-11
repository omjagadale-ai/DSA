#include <iostream>
using namespace std;

int hash1(int key, int table_size) {
    return key % table_size;
}
void showtable(int hash_table[], int table_size) {
    cout << "Hash Table: " << endl;
    for (int i = 0; i < table_size; i++) {
        if (hash_table[i] != -1) {
            cout << i << " --> " << hash_table[i] << endl;
        } else {
            cout << i << " --> " << "NULL" << endl;
        }
    }
}

int main() {
    int table_size;
    cout << "Enter the size of the hash table: ";
    cin >> table_size;
    int hash_table[table_size];
    for (int i = 0; i < table_size; i++) {
        hash_table[i] = -1;
    }
    showtable(hash_table, table_size);

    while(true) {
        int key;
        cout << "ENTER KEY : ";
        cin >> key;
        int original_index = hash1(key, table_size);
        int pos = original_index;
        while(hash_table[pos] != -1){
            pos = (pos + 1) % table_size;
            if(pos == original_index){
                cout << "HASH TABLE IS FULL." << endl;
                showtable(hash_table, table_size);
                return 0;
            }
        }
        if(hash_table[pos] == -1){
            hash_table[pos] = key;
        }
        showtable(hash_table, table_size);
    
        char op;
        cout << "do you want to continue(y/n) : ";
        cin >> op;
        if(op == 'n' || op == 'N'){
            break;
        }
        if(op != 'y' && op != 'Y'){
            cout << "Invalid input. Exiting." << endl;
            break;
        }
    }


    return 0;
}
