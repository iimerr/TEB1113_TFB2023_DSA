/*
ID: 24003510
NAME: EMIR AZIMIL AKBAR BIN MOHD FAUZI
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // add new node at the end
    void enqueue(string name) {
        Node* new_node = new Node(name);

        if (front == nullptr) {
            front = new_node;
            rear = new_node;
            rear->next = front;
        } else {
            rear->next = new_node;
            rear = new_node;
            rear->next = front;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        if (front == rear) {
            // Only one node
            cout << "Dequeued: " << front->name << endl;
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;  // maintain circular link
            cout << "Dequeued: " << temp->name << endl;
            delete temp;
        }
    }

    void display_queue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        do {
            cout << current->name << " -> ";
            current = current->next;
        } while (current != front);
        cout << front->name << endl;
    }
};

int main() {
    cout << "Queue" << endl;
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alice");
    queue.enqueue("Abu");

    cout << "Queue: ";
    queue.display_queue();

    queue.dequeue();

    cout << "After dequeueing: " << endl;
    queue.display_queue();

    return 0;
}
