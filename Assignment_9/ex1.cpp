#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <cstring>
using namespace std;
int size=-1,curr_size=-1;
template<typename T>
struct Node{
    T data;
    Node* next;
};
bool isEmpty(){
    if(curr_size==-1){return true;}
    return false;
}
bool isFull(){
    if(curr_size==size-1 && size!=-1){return true;}
    return false;
}
template <typename T>
Node<T>* push(Node<T>* top,int newel){
    if(isFull()){cout<<"Overflow"<<endl;exit(1);}
    Node<T>* temp;
    temp=new Node<T>;
    temp->data=newel;
    temp->next=top;
    curr_size++;
    return temp;
}
template <typename T>
T pop(Node<T>* &top){
    if(isEmpty()){cout<<"Underflow"<<endl;exit(1);}
    curr_size--;
    T deleted=top->data;
    Node<T> *temp=top;
    top=top->next;
    delete temp;
    return deleted;
}
template <typename T>
void printlist(Node<T>*top){
    Node<T>* currpos;
    for(currpos=top;currpos;currpos=currpos->next){
        cout<<currpos->data<<" ";
    }cout<<endl;
}
int main() 
{    
    Node<char>* top=NULL;
    size=3;
    top=push(top,'a');
    top=push(top,'b');
    printlist(top);
    cout<<"popped: "<<pop(top)<<endl;
    top=push(top,'c');
    top=push(top,'d');
    printlist(top);
    cout<<"popped: "<<pop(top)<<" "<<pop(top)<<" "<<pop(top)<<" "<<pop(top);
    printlist(top);
    return 0;
}