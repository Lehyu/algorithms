//
// Created by lehyu on 17-3-30.
//

#ifndef L_QUEUE_H
#define L_QUEUE_H
#include <assert.h>
#include <iostream>

template <class T>
class Queue{
public:
    Queue(const int maxsize);
    ~Queue();

    int size() const;
    bool empty() const;
    T& front() const;
    T& back() const;

    void enqueue(const T& x);
    T& dequeue();

private:
    int theCapacity;
    int theSize;
    int _front;
    int _back;
    T* data;
    void init(const int maxsize);
};

template <class T>
void Queue<T>::init(const int maxsize) {
    theCapacity = maxsize;
    theSize = 0;
    data = new T[theCapacity];
    _front = 0;
    _back = 0;
}

template <class T>
Queue<T>::Queue(const int maxsize) {
    init(maxsize);
}

template <class T>
Queue<T>::~Queue() {
    delete data;
}

template <class T>
int Queue<T>::size() const {
    return theSize;
}

template <class T>
bool Queue<T>::empty() const {
    return size() == 0;
}

template <class T>
T& Queue<T>::front() const {
    //std::cout<<"_front: "<<_front;
    return *(data+_front);

}

template <class T>
T& Queue<T>::back() const {
    //std::cout<<"_back: "<<_back;
    return *(data+(_back-1)%theCapacity);
}
template <class T>
void Queue<T>::enqueue(const T &x) {
    assert(theSize <= theCapacity);
    *(data+_back) = x;
    _back = (_back+1)%theCapacity;
    theSize++;
}

template <class T>
T& Queue<T>::dequeue() {
    assert(theSize > 0 );
    T& x = *(data+_front);
    _front = (_front+1)%theCapacity;
    theSize--;
    return x;
}
#endif //SRC_QUEUE_H