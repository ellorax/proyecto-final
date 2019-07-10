#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>
#include <QDataStream>
#include <QFile>
using namespace std;
template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(Node<T> *f,Node<T> *l);
    ~LinkedList();
    void insertAtFront(T &);
    void insertAtBack(T &);
    bool find(T &);
    Node<T> *findElemt(T &);
    bool deleteAtFront();
    bool deleteAtBack();
    bool deleteElemnt(T &);
    bool isEmpty();
    int getSize();
    Node<T> *getFirstPtr() const;
    void setFirstPtr(Node<T> *value);
    Node<T> *getLastPtr() const;
    void setLastPtr(Node<T> *value);
    //create iterator to linked list class
    struct iterator;
    iterator begin();
    iterator end();
    //overwrite << operator
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
    friend inline QDataStream &operator << (QDataStream &ds,const LinkedList<T> l)
    {
        ds <<l.firstPtr << l.lastPtr ;
    }
    friend inline QDataStream &operator>>(QDataStream &ds,LinkedList<T> l)
    {
        ds >> l.firstPtr << l.lastPtr ;
    }
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
