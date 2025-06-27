/*
ID = 24003510
NAME = Emir Azimil Akbar Bin Mohd Fauzi
*/

#include <iostream>
using namespace std;

// Node class
class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

// Stack class using Linked List
class Stack {
public:
    Node* top;

    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push operation
void push(string name) {
    Node* new_node = new Node(name);

    if (top == nullptr) {
        top = new_node;
    } else {
        new_node->next = top;  // connect to previous top
        top = new_node;        // now new node is the top
    }
}

void peek() {
  if (top == nullptr){
    cout << "is empty"<< endl;
      }else{
        Node* curr = top;
        cout << curr->name;
      }
}

void pop() {
  if (top == nullptr){
    cout << "is empty"<< endl;
      }else{
        Node* curr = top;
        top = top->next;
        cout << curr->name;
      }
      cout << endl ;
}
    // Display the stack
    void display_stack() {
        Node* currNode = top;
        while (currNode != nullptr) {
            cout << currNode->name << " -> ";
            currNode = currNode->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack std_stack;

    std_stack.push("Abu");
    std_stack.push("Ahmad");
    std_stack.push("Azman");

    std_stack.display_stack();
    std_stack.pop();
    std_stack.pop();
    std_stack.pop();
    std_stack.display_stack();

    return 0;
}
