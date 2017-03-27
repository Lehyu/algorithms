//
// Created by lehyu on 17-3-27.
//
#include <iostream>
#include "DList.h"

int main(){
    DList<double> list;
    for(int i = 0; i < 10; i++)
        list.push_front(i);
    for(auto it = list.begin(); it != list.end(); it++)
        std::cout<<(*it)<<" ";
    return 0;
}