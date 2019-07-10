#include "linkedlist.h"
template <typename T>
LinkedList<T>::LinkedList()
    :firstPtr(nullptr),lastPtr(nullptr)
{

}

template<typename T>
LinkedList<T>::LinkedList(Node<T> *f, Node<T> *l)
    :firstPtr(f),lastPtr(l)
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{
    if(isEmpty())
    {
        Node<T> *tlastPtr;
        Node<T> *curPtr;
        while (curPtr) {
            lastPtr=curPtr;
            curPtr=curPtr->nextPtr;
            delete lastPtr;
        }
    }
}
template<typename T>
void LinkedList<T>::insertAtFront(T &val)
{
    Node<T> *newPtr=getNewNode(val);
    if(isEmpty())
    {
        firstPtr=lastPtr=newPtr;
    }
    else {
        newPtr->nextPtr=firstPtr;
        firstPtr->backPtr=newPtr;
        firstPtr=newPtr;
    }
}

template<typename T>
void LinkedList<T>::insertAtBack(T &val)
{
    Node<T> *newPtr=getNewNode(val);
    if(isEmpty())
        firstPtr=lastPtr=newPtr;
    else {
        lastPtr->nextPtr=newPtr;
        newPtr->backPtr=lastPtr;
        lastPtr=newPtr;
    }
}

template<typename T>
bool LinkedList<T>::find(T &d)
{
    if(lastPtr->getData()==d)
        return true;
    Node<T> *temPtr=firstPtr;
    while (temPtr->getData()!=d) {
        if(temPtr->nextPtr==lastPtr)
            return false;
        temPtr=temPtr->nextPtr;
    }
    return true;
}

template<typename T>
Node<T> *LinkedList<T>::findElemt(T &d)
{
    if(lastPtr->getData()==d)
        return lastPtr;
    Node<T> *temPtr=firstPtr;
    while (temPtr->getData()!=d) {
        temPtr=temPtr->nextPtr;
    }
    return temPtr;
}
template<typename T>
bool LinkedList<T>::deleteAtFront()
{
    if(isEmpty())
        return false;
    else {
        Node<T> *temPtr=firstPtr;
        if(lastPtr==firstPtr)
            firstPtr=lastPtr=nullptr;
        else{
            firstPtr=firstPtr->nextPtr;
            firstPtr->backPtr=nullptr;
        }
        delete temPtr;
    }
    return true;
}
template<typename T>
bool LinkedList<T>::deleteAtBack()
{
    if(isEmpty())
        return false;
    else {
        Node<T> *temPtr=lastPtr;
        if(lastPtr==firstPtr)
            firstPtr=lastPtr=nullptr;
        else{
            lastPtr=lastPtr->backPtr;
            lastPtr->nextPtr=nullptr;
        }
        delete temPtr;
    }
}
template<typename T>
bool LinkedList<T>::deleteElemnt(T &d)
{
    if(isEmpty())
        return false;
    else {
        if(firstPtr->getData()==d)
            deleteAtFront();
        else if (lastPtr->getData()==d) {
            deleteAtBack();
        }
        else {
            Node<T> *temPtr=firstPtr;
            Node<T> *previusPtr=temPtr;
            Node<T> *util;
            while (temPtr->getData()!=d) {
                if(temPtr->nextPtr==lastPtr)
                    return false;
                else {
                    previusPtr=temPtr;
                    temPtr=temPtr->nextPtr;
                }
            }
            previusPtr->nextPtr=temPtr->nextPtr;
            util=temPtr->nextPtr;
            util->backPtr=previusPtr;
            delete temPtr;
            return true;
        }
    }
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
    return this->firstPtr==nullptr;
}
template<typename T>
Node<T> *LinkedList<T>::getFirstPtr() const
{
    return firstPtr;
}
template<typename T>
void LinkedList<T>::setFirstPtr(Node<T> *value)
{
    firstPtr = value;
}
template<typename T>
Node<T> *LinkedList<T>::getLastPtr() const
{
    return lastPtr;
}
template<typename T>
void LinkedList<T>::setLastPtr(Node<T> *value)
{
    lastPtr = value;
}

template<typename T>
class LinkedList<T>::iterator LinkedList<T>::begin()
{
    return iterator(firstPtr);
}

template<typename T>
class LinkedList<T>::iterator LinkedList<T>::end()
{
    return iterator(lastPtr);
}
template<typename T>
struct LinkedList<T>::iterator
{
    Node<T> *temPtr;
    public:
    iterator(Node<T> * n = nullptr)
    {
        temPtr = n;
    }
    ~iterator() = default;
    T & operator *()
    {
        return temPtr->getData();
    }
    iterator & operator ++()
    {
        temPtr = temPtr->nextPtr;
        return *this;
    }
    iterator & operator --() //tarea completada
    {
        temPtr = temPtr->backPtr;
        return *this;
    }
    bool operator != (const iterator & it)
    {
        return temPtr!= it.temPtr;
    }
};


