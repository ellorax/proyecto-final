#ifndef NODE_H
#define NODE_H

template<typename T>class LinkedList;
template<typename T>
class Node
{
    friend class LinkedList<T>;
public:
    Node(T &val)
        :nextPtr(nullptr),data(val)
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
private:
    T data;
    Node<T> *nextPtr;
};

#endif // NODE_H
