#ifndef NODE_H
#define NODE_H

template<typename T>class LinkedList;
template<typename T>
class Node
{
    friend class LinkedList<T>;
public:
    Node(T &val)
        :nextPtr(nullptr),backPtr(nullptr),data(val)
    {

    }
    T getData()
    {
        return this->data;
    }
    void setData(T d)
    {
        this->data=d;
    }
    Node<T> *getNextPtr()
    {
        return this->nextPtr;
    }
    void setNextPtr(Node<T> *ptr)
    {
        this->nextPtr=ptr;
    }
    Node<T> *getBackPtr()
    {
        return  this->backPtr;
    }
    void setBackPtr(Node<T> *ptr)
    {
        this->backPtr=ptr;
    }
private:
    T data;
    Node<T> *nextPtr;
    Node<T> *backPtr;
};
#endif // NODE_H
