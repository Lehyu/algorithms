#include <iostream>
#include <vector>
#include "data_structure/List/DList.h"
using namespace std;
int main() {
    DList<int> list;
    for(int i = 0; i < 10; i++){
        list.push_back(i);
    }
    for(auto it = list.begin(); it != list.end(); it++)
        std::cout<<*it<<" ";
    return 0;
}