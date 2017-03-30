//
// Created by lehyu on 17-3-29.
//

#ifndef L_STACK_H
#define L_STACK_H

#include <iostream>

template <class T, class Ref, class Ptr>
class __stack_iterator{
public:
    typedef __stack_iterator<T, T&, T*> iterator;
    typedef __stack_iterator<T, Ref, Ptr> self;

    typedef Ptr pointer;
    typedef Ref reference;

    __stack_iterator();
    __stack_iterator(T* p);
    __stack_iterator(const iterator &it);

    bool operator==(const self & other){ return current == other.current;}
    bool operator!=(const self & other){ return current != other.current;}

    reference operator*(){ return *current;}
    pointer operator->(){ return operator*();}

    self & operator++();
    self & operator++(int);
    self & operator--();
    self & operator--(int);
    self & operator+(int step);
    self &operator-(int step);

    T* current;
};

template <class T>
class Stack{
public:
    typedef __stack_iterator<T, T&, T*> iterator;

public:

    Stack();
    Stack(int maxsize);
    Stack(const Stack &other);
    ~Stack();

    iterator begin(){ return {data+_back+1};}
    iterator end(){ return {data+_top+1};}

    bool empty();

    T& top(){ return *--end();}
    void push(const T &x);
    T& pop();

    iterator insert(iterator it, const T & x);
    iterator erase(iterator it);


private:
    T* data;
    int _top;
    int _back;
    int maxsize;
    void init();
    void _extend_size();
};

template <class T, class Ref, class Ptr>
__stack_iterator<T, Ref, Ptr>::__stack_iterator(): current{nullptr} {}
template <class T, class Ref, class Ptr>
__stack_iterator<T, Ref, Ptr>::__stack_iterator(T* p): current{p} {}

template <class T, class Ref, class Ptr>
__stack_iterator<T, Ref, Ptr>::__stack_iterator(const iterator &it) {
    current = it.current;
}
template <class T, class Ref, class Ptr>
__stack_iterator<T, Ref, Ptr> & __stack_iterator<T, Ref, Ptr>::operator++() {
    current += 1;
    return *this;
}
template <class T, class Ref, class Ptr>
__stack_iterator<T, Ref, Ptr> & __stack_iterator<T, Ref, Ptr>::operator++(int) {
    iterator old = *this;
    ++(*this);
    return old;
}

template <class T, class Ref, class Ptr>
__stack_iterator<T, Ref, Ptr> & __stack_iterator<T, Ref, Ptr>::operator--() {
    current--;
    return *this;
}

template <class T, class Ref, class Ptr>
__stack_iterator<T, Ref, Ptr> & __stack_iterator<T, Ref, Ptr>::operator--(int) {
    iterator old = *this;
    --(*this);
    return old;
}


template <class T, class Ref, class Ptr>
__stack_iterator<T, Ref, Ptr> & __stack_iterator<T, Ref, Ptr>::operator+(int step) {
    current += step;
    return *this;
}

template <class T, class Ref, class Ptr>
__stack_iterator<T, Ref, Ptr> & __stack_iterator<T, Ref, Ptr>::operator-(int step) {
    current -= step;
    return *this;
}

/*----------------------------------------------------------------------------------
 *----------------------------------------Stack-------------------------------------
 * ----------------------------------------------------------------------------------
 */


template <class T>
void Stack<T>::init() {
    _top = _back = -1;
    data = new T[maxsize];
}
template <class T>
void Stack<T>::_extend_size() {
    int size = 0;
    if(_top == 3*maxsize/4){
        size = 2*maxsize;
    }else if(_top < maxsize/10){
        size = maxsize/2;
    }else{
        return;
    }
    T* temp = new T[size];
    for(int i = 0; i <= _top; i++){
        *(temp+i) = *(data+i);
    }
    data = new T[size];
    for(int i = 0; i <= _top; i++){
        *(data+i) = *(temp+i);
    }
    maxsize = size;
    free(temp);
}
template <class T>
Stack<T>::Stack(int maxsize) {
    this->maxsize = maxsize;
    init();
}

template <class T>
Stack<T>::Stack() {
    this->maxsize = 5;
    init();
}

template <class T>
Stack<T>::Stack(const Stack &other) {
    this->maxsize = 5;
    init();
    for(auto &x: other)
        push(x);
}
template <class T>
Stack<T>::~Stack() {
    while(!empty())
        pop();
    delete data;
}

template <class T>
bool Stack<T>::empty() {
    return _top == _back;
}
template <class T>
void Stack<T>::push(const T &x) {
    _extend_size();
    insert(end(), x);
}
template <class T>
T& Stack<T>::pop() {
    _extend_size();
    return *erase(--end());
}
template <class T>
typename Stack<T>::iterator Stack<T>::insert(iterator it, const T &x) {
    _top++;
    *(it.current++) = x;
    return {it.current};
}

template <class T>
typename Stack<T>::iterator Stack<T>::erase(iterator it) {
    _top--;
    return {it.current};
}


#endif //SRC_STACK_H
