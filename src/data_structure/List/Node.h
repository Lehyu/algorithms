//
// Created by lehyu on 17-3-28.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H

template <typename Object>
struct _list_node{
    Object value;
    _list_node* next;
    _list_node* prev;
    _list_node(const Object &v = Object{},  _list_node* p = nullptr,  _list_node* n = nullptr):value{v}, next{n}, prev{p}{}
};

#endif //SRC_NODE_H
