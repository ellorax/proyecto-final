#include "bst.h"
template<class K, class D>
struct bst<K,D>::node
{
    K key;
    D dato;
    node * p_child[2];
    node(const K & k) : key(k)
    {
        p_child[0] = p_child[1] = nullptr;
    }
    node(const K & k,const D & d) : key (k), dato(d)
    {
        p_child[0] = p_child[1] = nullptr;
    }
    ~node() = default;
};
template<class K, class D>
bool bst<K,D>::insert(const K & k, const D & d)
{
    node **n;
    if(find(n,k)) return false;
    *n = new node(k,d);
    return true;
}
template<class K, class D>
bool bst<K,D>::find(const K & k)
{
    node **n;
    return (find (n,k));
}
template<class K, class D>
bool bst<K,D>::remove(const K & k)
{
    node **n;
    if(!find(n,k)) return false;
    //completar
    return true;
}
template<class K, class D>
D & bst<K,D>::operator[](const K & key)
{
    node ** n;
    if(!find(n,key))
        *n = new node (key);
    return (*n) -> dato;
}
