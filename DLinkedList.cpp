#include "DLinkedList.hpp"

Node:: Node() {
    this->firstName = nullptr;
    this->lastName = nullptr;
    this->houseType = -1;
    this->age = -1;
}

Node:: Node(string first, string last, int house, int a) {
    this->firstName = first;
    this->lastName = last;
    this->houseType = house;
    this->age = a;
};

DLinkedList:: DLinkedList() {
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList:: ~DLinkedList() {
    while(!empty()) 
        removeFront();
    delete header;
    delete trailer;
};

bool DLinkedList:: empty() const {
    return (header->next == trailer);
};

const Node* DLinkedList:: front() const {
    return header->next;
};

const Node* DLinkedList:: back() const {
    return trailer->prev;
};

void DLinkedList:: add(Node* v, const Node& n) {
    Node* a = new Node;
    a->firstName = v->firstName;
    a->lastName = v->lastName;
    a->houseType = v->houseType;
    a->age = v->age;
    a->next = v;
    a->prev = v->prev;
    v->prev->next= a;
};

void DLinkedList:: addFront(const Node& n) {
    add(header->next, n);
};

void DLinkedList:: addBack(const Node& n) {
    add(trailer, n);
};