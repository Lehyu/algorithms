//
// Created by lehyu on 17-3-28.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename Object>
struct _list_node{
    Object value;
    _list_node* next;
    _list_node* prev;
    _list_node(const Object &v = Object{},  _list_node* p = nullptr,  _list_node* n = nullptr):value{v}, next{n}, prev{p}{}
};

template <class T, class Ref, class Ptr>
class __list_iterator{
public:
    typedef __list_iterator<T, T&, T*> iterator;
    typedef __list_iterator<T, Ref, Ptr> self;

    typedef Ptr pointer;
    typedef Ref reference;

    __list_iterator(_list_node<T>* p);
    __list_iterator();
    __list_iterator(const iterator &it);

    bool operator==(const self & other){ return current == other.current;}
    bool operator!=(const self & other){ return current != other.current;}

    reference operator*(){ return current->value;}
    pointer operator->(){ return &(operator*());}

    self & operator++();
    self & operator++(int);
    self & operator--();
    self & operator--(int);
    self & operator+(int step);
    self &operator-(int step);

    _list_node<T>* current;
};

template <class T>
class LinkedList {
public:
    typedef __list_iterator<T, T&, T*> iterator;

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    ~LinkedList();
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
    current = current->prev;
    return *this;
}
template <class T, class Ref, class Ptr>
__list_iterator<T, Ref, Ptr>& __list_iterator<T, Ref, Ptr>::operator+(int step) {
    for(int i = 0; i < step; i++)
       current = current->next;
    return *this;
}

template <class T, class Ref, class Ptr>
__list_iterator<T, Ref, Ptr>& __list_iterator<T, Ref, Ptr>::operator-(int step) {

    for(int i = 0; i < step; i++)
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
 * ---------------------implementation of LinkedList---------------------------------
 * ----------------------------------------------------------------------------
 * */
template <class T>
void LinkedList<T>::init() {
    theSize = 0;
    head = new _list_node<T>;
    tail = new _list_node<T>;
    head->next = tail;
    tail->prev = head;
}
template <class T>
LinkedList<T>::LinkedList() {
    init();
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList &other) {
    init();
    for(auto &x: other)
        push_back(x);
}
template <class T>
LinkedList<T>::~LinkedList() {
    clear();
    delete head;
    delete tail;
}
template <class T>
void LinkedList<T>::clear() {
    while (!empty())
        pop_back();
}
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::insert(iterator it, const T &x) {
    _list_node<T>* p = it.current;
    theSize++;
    return {p->prev = p->prev->next=new _list_node<T>{x, p->prev,p}};
}
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::erase(iterator it) {
    _list_node<T>* p = it.current;
    iterator retval{p->next};
    p->prev->next = p->next;
    p->next->prev = p->prev;
    theSize--;
    return retval;
}
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::erase(iterator from, iterator to) {
    for(iterator it = from; it != to;)
        it = erase(it);
    return to;
}

#endif //SRC_DLIST_H
