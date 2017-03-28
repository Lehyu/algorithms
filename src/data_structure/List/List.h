//
// Created by lehyu on 17-3-28.
//

#ifndef SRC_DLIST_H
#define SRC_DLIST_H

#include <glob.h>
#include "Node.h"

template <class T, class Ref, class Ptr>
class __list_iterator{
public:
    typedef __list_iterator<T, T&, T*> iterator;
    typedef __list_iterator<T, const T&, const T*> const_iterator;
    typedef __list_iterator<T, Ref, Ptr> self;

    typedef T value_type;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef size_t size_type;

    __list_iterator(_list_node<T>* p);
    __list_iterator();
    __list_iterator(const iterator &it);

    bool operator==(const self & other){ return current == other.current;}
    bool operator!=(const self & other){ return current != other.current;}

    reference operator*(){ return current->value;}
    pointer operator->(){ return &(operator*());}

    self & operator++();
    self & operator++(int);
    self &operator--();
    self &operator--(int);

    _list_node<T>* current;
};

template <class T>
class List {
public:
    typedef __list_iterator<T, T&, T*> iterator;

public:
    List();
    List(const List& other);
    ~List();
    iterator begin() { return {head->next};};
    iterator end() { return {tail};};

    int size() const { return theSize;}
    bool empty() const { return theSize == 0;}
    void clear();

    T &front(){ return * begin(); }
    T &back() { return * --end();}

    void push_back(const T &x){insert(end(), x);}
    void push_front(const T &x){insert(begin(), x);}

    void pop_back(){erase(end());}
    void pop_front(){erase(begin());}

    iterator insert(iterator it, const T &x);
    iterator erase(iterator it);

    iterator erase(iterator from, iterator to);


private:
    _list_node<T>* head;
    _list_node<T>* tail;
    int theSize;
    void init();
};

template <class T, class Ref, class Ptr>
__list_iterator<T, Ref, Ptr> & __list_iterator<T, Ref, Ptr>::operator++() {
    if(current->next != nullptr)
        current = current->next;
    return *this;
}
template <class T, class Ref, class Ptr>
__list_iterator<T, Ref, Ptr> & __list_iterator<T, Ref, Ptr>::operator++(int) {
    iterator old = *this;
    ++(*this);
    return old;
}

template <class T, class Ref, class Ptr>
__list_iterator<T, Ref, Ptr> & __list_iterator<T, Ref, Ptr>::operator--(int) {
    iterator old = *this;
    --(*this);
    return old;
}

template <class T, class Ref, class Ptr>
__list_iterator<T, Ref, Ptr> & __list_iterator<T, Ref, Ptr>::operator--() {
    if(current->prev != nullptr)
        current = current->prev;
    return *this;
}

template <class T, class Ref, class Ptr>
__list_iterator<T, Ref, Ptr>::__list_iterator(_list_node<T>* p): current{p} {}

template <class T, class Ref, class Ptr>
__list_iterator<T, Ref, Ptr>::__list_iterator(const iterator &it) {
    current = it.current;
}

template <class T, class Ref, class Ptr>
__list_iterator<T, Ref, Ptr>::__list_iterator():current{nullptr} {}


/* ----------------------------------------------------------------------------
 * ---------------------implementation of List---------------------------------
 * ----------------------------------------------------------------------------
 * */
template <class T>
void List<T>::init() {
    theSize = 0;
    head = new _list_node<T>;
    tail = new _list_node<T>;
    head->next = tail;
    tail->prev = head;
}
template <class T>
List<T>::List() {
    init();
}
template <class T>
List<T>::List(const List &other) {
    init();
    for(auto &x: other)
        push_back(x);
}
template <class T>
List<T>::~List() {
    clear();
    delete head;
    delete tail;
}
template <class T>
void List<T>::clear() {
    while (!empty())
        pop_back();
}
template <class T>
typename List<T>::iterator List<T>::insert(iterator it, const T &x) {
    _list_node<T>* p = it.current;
    return {p->prev = p->prev->next=new _list_node<T>{x, p->prev,p}};
}
template <class T>
typename List<T>::iterator List<T>::erase(iterator it) {
    _list_node<T>* p = it.current;
    iterator retval{p->next};
    p->prev->next = p->next;
    p->next->prev = p->prev;
    return retval;
}
template <class T>
typename List<T>::iterator List<T>::erase(iterator from, iterator to) {
    for(iterator it = from; it != to;)
        it = erase(it);
    return to;
}

#endif //SRC_DLIST_H
