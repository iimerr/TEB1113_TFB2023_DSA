/*
ID = 24003510
NAME = Emir Azimil Akbar Bin Mohd Fauzi
*/

#include <iostream>
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

class LinkedList {
  Node* head;
  Node* tail;

public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void add_item(Node* node) {
    if (head == nullptr) {
      head = tail = node;
    } else {
      tail->next = node;
      tail = node;
      tail->next = head;
    }
  }

  void display_list() {
    Node* currNode = head;
    do{
      cout << currNode->name << " -> ";
      currNode = currNode->next;
    }
    while (currNode!=head);
    
    cout << currNode->name << endl;
  }

};

int main() {
  Node* node1 = new Node("Abu");
  Node* node2 = new Node("Ahmad");
  Node* node3 = new Node("Azman");
  Node* node4 = new Node("Hamza");

  LinkedList std_list;

  std_list.add_item(node1);
  std_list.add_item(node2);
  std_list.add_item(node3);
  std_list.add_item(node4);

  std_list.display_list();


  return 0;
}