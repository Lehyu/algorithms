#include <iostream>
#include <vector>
#include "data_structure/List/LinkedList.h"
#include "data_structure/Stack/Stack.h"

using namespace std;
int main() {
    Stack<int> stack;
    for(int i = 0; i < 10; i++)
        stack.push(i);
    cout<<stack.top()<<endl;
    for(auto &x: stack)
        cout<<x<<" ";
    cout<<endl;
    for(int i = 0; i < 5; i++)
        cout<<stack.pop()<<" ";
    cout<<endl;

    /* test LinkedList
    LinkedList<int> list ;
    for(int i = 0; i < 10; i++)
        list.push_back(i);
    for(auto &x: list)
        cout<<x<<" ";
    cout<<endl;
    for(auto it = list.begin(); it != list.end(); it++)
        cout<<(*it)<<" ";

    cout<<endl;
     */
    return 0;
}