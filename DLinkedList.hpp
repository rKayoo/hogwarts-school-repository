#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <string>
using namespace std;

typedef enum {GRYFFINDOR, RAVENCLAW, HUFFLEPUFF, SLYTHERIN};

class Node {
    public:
        Node(string first, string last, int house, int a);
    private:
        Node* next;
        Node* prev;
        string firstName;
        string lastName;
        int houseType;
        int age;
        friend class DLinkedList;
};

class DLinkedList {
    public:
        DLinkedList(); // constructor
        ~DLinkedList(); // destructor
        bool empty() const; // is list empty?
        const Node& front() const; // get front element
        const Node& back() const; // get back element
        void addFront(const Node& n); // add to front of list
        void addBack(const Node& n); // add to back of list
        void removeFront(); // remove from front
        void removeBack(); // remove from back
    private: // local type definitions
        Node* header; // list sentinels
        Node* trailer;
    protected: // local utilities
        void add(Node* v, const Node& n); //insert new node before v
        void remove(Node* v); // remove node v
};


#endif