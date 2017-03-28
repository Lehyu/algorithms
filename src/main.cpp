#include <iostream>
#include <vector>
#include "data_structure/List/List.h"

using namespace std;
int main() {
    List<int> list ;
    for(int i = 0; i < 10; i++)
        list.push_back(i);
    for(auto &x: list)
        cout<<x<<" ";
    cout<<endl;
    for(auto it = list.begin(); it != list.end(); it++)
        cout<<(*it)<<" ";

    cout<<endl;
    return 0;
}