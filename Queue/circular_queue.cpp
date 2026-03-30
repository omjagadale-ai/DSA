#include <iostream>
using namespace std;

#define n 10

class circular_queue
{
public:
    int front, rear, size;
    int q[n];
    circular_queue()
    {
        size = 0;
        rear = -1;
        front = 0;
    }
    void enqueue(int x)
    {
        if (size == n)
        {
            cout << "Queue is Full\n";
            return;
        }

        rear = (rear + 1) % n;
        q[rear] = x;
        size++;

        cout << x << " inserted\n";
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << q[front] << " removed\n";
        front = (front + 1) % n;
        size--;
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";
        int i = front;

        for (int count = 0; count < size; count++)
        {
            cout << q[i] << " ";
            i = (i + 1) % n;
        }
        cout << endl;
    }
};

int main()
{
    int choice, value;

    circular_queue q1;

    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;
            q1.enqueue(value);
        }
        else if (choice == 2)
        {
            q1.dequeue();
        }
        else if (choice == 3)
        {
            q1.display();
        }
        else if (choice == 4)
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}  