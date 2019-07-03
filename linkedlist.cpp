#include "linkedlist.h"
template <typename T>
LinkedList<T>::LinkedList()
    :firstPtr(nullptr),lastPtr(nullptr)
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
        lastPtr=newPtr;
    }
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
        else
            firstPtr=firstPtr->nextPtr;
        delete temPtr;
    }
}

template<typename T>
bool LinkedList<T>::deleteAtBack()
{
    if(isEmpty())
        return false;
    else {
        Node<T> *temPtr=firstPtr;
        if(lastPtr==firstPtr)
            firstPtr=lastPtr=nullptr;
        else{
            Node<T>*temL=lastPtr;
            while (temPtr->nextPtr==lastPtr) {
                temPtr=temPtr->nextPtr;
            }
            lastPtr=temPtr;
            lastPtr->nextPtr=nullptr;
            delete temL;
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

