//
// Created by lehyu on 17-3-27.
//

#ifndef SRC_LIST_H
#define SRC_LIST_H

#include "DNode.h"
template <typename Object>
class DList {
public:
    class const_iterator{
    public:
        const_iterator():current{nullptr}{}
        const Object & operator*() const{ return retrieve();}
        const_iterator &operator++ (){
            current = current->next;
            return *this;
        }
        bool operator==(const const_iterator &rhs) const{
            return current == rhs.current;
        }
        bool operator!=(const const_iterator &rhs) const{
            return !(*this==rhs);
        }

    protected:
        DNode<Object> *current;
        Object & retrieve() const { return current->value; }
        const_iterator(DNode<Object>* p):current{p}{}
        friend class DList<Object>;
    };

    class iterator:public const_iterator{
    public:
        iterator(){}
        Object &operator*(){ return const_iterator::retrieve(); }
        iterator &operator++(){
            this->current = this->current->next;
            return *this;
        }
        iterator operator++(int){
            iterator old = *this;
            ++(*this);
            return old;
        }
        iterator &operator--(){
            this->current = this->current->prev;
            return *this;
        }
        iterator &operator--(int){
            iterator old = *this;
            --(*this);
            return old;
        }
    protected:
        iterator(DNode<Object> *p):const_iterator{p}{}
        friend class DList<Object>;
    };
public:
    DList(){init();}
    DList(const DList &rhs){
        init();
        for(auto &x: rhs)
            push_back(x);
    }

    ~DList(){
        clear();
        delete head;
        delete tail;
    }
    DList &operator = (const DList &rhs){
        DList copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    void clear(){
        while(!empty())
            pop_back();
    }
    iterator insert(iterator it, const Object &x){
        DNode<Object> *p = it.current;
        theSize++;
        return {p->prev = p->prev->next = new DNode<Object>{std::move(x), p, p->prev}};
    }
    iterator erase(iterator it){
        DNode<Object> *p = it.current;
        iterator retval{p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;
        return retval;
    }
    iterator erase(iterator from, iterator to){
        for(iterator it = from; it != to;)
            erase(it);
        return to;
    }

    iterator begin(){ return {head->next};};
    const_iterator begin() const { return {head->next};}
    iterator end(){ return {tail};}
    const_iterator end() const { return {tail};}

    int size() const { return theSize;}
    bool empty() const{ return size() == 0;}

    Object &front(){ return *begin();}
    Object &back(){ return *--end();}
    void push_front(const Object &x){insert(begin(), x);}
    void push_back(const Object &x){insert(end(), x);}

    void pop_front(){erase(begin());}
    void pop_back(){erase(--end());}



private:
    DNode<Object> *head;
    DNode<Object> *tail;
    int theSize;
    void init(){
        theSize = 0;
        head = new DNode<Object>;
        tail = new DNode<Object>;
        head->next = tail;
        tail->prev = head;
    }
};


#endif //SRC_LIST_H