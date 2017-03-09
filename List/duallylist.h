#ifndef DUALLYLIST_H
#define DUALLYLIST_H

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <cstdlib>

class Node;

class DuallyList{

public:
    explicit DuallyList();
    ~DuallyList();

    size_t Capacity;

    void push_back(int value = 0);
    int popback();

    void push_front(int value = 0);
    int pop_front();

    size_t get_size(){return Size;}

    Node *getHead(){return Head;}
    void setHead(Node *_Head){Head = _Head;}

    Node *getTail(){return Tail;}
    void setTail(Node *_Tail){Tail = _Tail;}

    void show_list();

    bool isempty(){if(Size == 0) return true; return false;}

    Node* operator[](int index);

private:
    size_t Size;
    Node *Head;
    Node *Tail;

};

class Node{

public:
    explicit Node();
    explicit Node(int value = 0);

    int getData(){return Data;}
    void setData(int value){Data = value;}

    Node *getNext(){return Next;}
    void setNext(Node *_Next){Next = _Next;}

    Node *getPrev(){return Prev;}
    void setPrev(Node *_Prev){Prev = _Prev;}

    bool comp(Node *obj);       // True если this->data > obj->data
private:
    int Data;
    Node *Next;
    Node *Prev;
};

#endif // DUALLYLIST_H
