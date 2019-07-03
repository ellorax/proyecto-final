#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>
using namespace std;
template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void insertAtFront(T &);
    void insertAtBack(T &);
    bool deleteAtFront();
    bool deleteAtBack();
    bool isEmpty();
    void print()
    {
        Node<T> *t=firstPtr;
        while (t) {
            cout << t->getData();
            t=t->nextPtr;
        }
    }
    friend std::ostream & operator << (std::ostream &out,LinkedList *l)
    {
        out<< "linked" ;
        Node<T> *temPtr=l->firstPtr;
        while (temPtr) {
            out<<"[]"<<temPtr->getData() << "----->";
            temPtr=temPtr->getNextPtr();
        }
        return out;
    }
    Node<T> *getFirstPtr() const;
    void setFirstPtr(Node<T> *value);

    Node<T> *getLastPtr() const;
    void setLastPtr(Node<T> *value);

private:
    //pointer to first node
    Node<T> *firstPtr;
    //pointer to last node
    Node<T> *lastPtr;
    Node<T> *getNewNode(T &val)
    {
        return new Node<T>(val);
    }
};

#endif // LINKEDLIST_H
