#ifndef BST_H
#define BST_H


#include<iostream>
using namespace std;

template<class K, class D>
class bst
{
    struct node;

    private:
    node * p_root;

    public:
    bst() : p_root(nullptr){}
    bool insert(const K & k, const D & d);

    bool find(const K & k);
    bool remove(const K & k);

    D & operator [] (const K & key);

    private :
    bool find(node **& n, const K & key)
    {
        n = & p_root;
        while(*n)
        {
            if(key == (*n)->key){return true;}
            n = &(*n)-> p_child[key > (*n) -> key];
        }
        return false;
    }
};
#include "bst.inl"
#endif // BST_H
