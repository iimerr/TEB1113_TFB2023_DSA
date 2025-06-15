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
    }
  }

  void display_list() {
    Node* currNode = head;
    while (currNode != nullptr) {
      cout << currNode->name << " -> ";
      currNode = currNode->next;
    }
    cout << "NULL" << endl;
  }

  void delete_value(string name) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->name != name) {
      previous = current;
      current = current->next;
    }

    if (current == nullptr) return;

    if (previous == nullptr) {
      head = current->next;
    } else {
      previous->next = current->next;
    }

    if (current == tail) {
      tail = previous;
    }

    delete current;
  }
};

int main() {
  Node* node1 = new Node("Abu");
  Node* node2 = new Node("Ahmad");
  Node* node3 = new Node("Azman");

  LinkedList std_list;

  std_list.add_item(node1);
  std_list.add_item(node2);
  std_list.add_item(node3);

  std_list.display_list();

  std_list.delete_value("Ahmad");

  std_list.display_list();

  return 0;
}
