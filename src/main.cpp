#include <iostream>
#include <vector>
#include "data_structure/List/LinkedList.h"
#include "data_structure/Stack/Stack.h"
#include "data_structure/Queue/Queue.h"

using namespace std;
void test_stack(){
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
}
void test_list(){
    LinkedList<int> list ;
    for(int i = 0; i < 10; i++)
        list.push_back(i);
    for(auto &x: list)
        cout<<x<<" ";
    cout<<endl;
    for(auto it = list.begin(); it != list.end(); it++)
        cout<<(*it)<<" ";

    cout<<endl;
}

void test_queue(){
    Queue<int> queue={10};
    for(int i = 0; i < 5; i++){
        queue.enqueue(i);
        cout<<"front: "<<queue.front()<<" ; back: "<<queue.back()<<endl;
    }
    cout<<queue.empty()<<endl;
    for(int i = 0; i < 5; i++){
        int x = queue.dequeue();
        cout<<"front: "<<queue.front()<<" ; back: "<<queue.back()<<"; dequeue: "<<x<<endl;
    }
    cout<<queue.empty()<<endl;
    queue.dequeue();
}
int main() {
    test_queue();
    return 0;
}