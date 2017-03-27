//
// Created by lehyu on 17-3-27.
//

#ifndef SRC_NODE_H
#define SRC_NODE_H

template <typename Object>
struct DNode {
    Object value;
    DNode * next;
    DNode * prev;
    DNode(const Object &d = Object{}, DNode *n = nullptr, DNode *p = nullptr): value{d}, next{n}, prev{p}{}
};

#endif //SRC_NODE_H