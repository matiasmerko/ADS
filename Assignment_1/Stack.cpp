//Matias Merko
//mmerko@jacobs-university.de
#include "Stack.h"
using namespace std;
//default constructor
template <class T, int initialsize>
Stack<T, initialsize>::Stack()
{
    ptr = new T[initialsize];
    size = initialsize;
    pos = -1;
}
//destructor
template <class T, int initialsize>
Stack<T, initialsize>::~Stack()
{
    delete[] ptr;
}
//copy constructor
template <class T, int initialsize>
Stack<T, initialsize>::Stack(const Stack &obj)
{
    size = obj.size;
    ptr = new T[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = obj.ptr[i];
    }
}
//constructor setting the isze to a given size
template <class T, int initialsize>
Stack<T, initialsize>::Stack(int nsize)
{
    pos = -1;
    size = nsize;
    ptr = new T[nsize];
    entries = 0;
}
//extend method which doubles the size
//of the stack
template <class T, int initialsize>
void Stack<T, initialsize>::extend()
{
    T *nptr = new T[2 * size];
    for (int i = 0; i < size; i++)
    {
        nptr[i] = ptr[i];
    }
    delete[] ptr;
    ptr = nptr;
    size = size * 2;
}
//push method which adds an element on top of the stack
template <class T, int initialsize>
bool Stack<T, initialsize>::push(T element)
{
    if (pos + 1 == size)
    {
        extend(); //since I have an extend method,the push will always return 1
    }
    ptr[pos + 1] = element;
    pos++;
    entries++;
    return 1;
}
//pop method
template <class T, int initialsize>
bool Stack<T, initialsize>::pop(T &out)
{
    if (pos == -1)
    {
        return false;
    }
    else
    {
        out = ptr[pos];
        pos--;
        return true;
    }
}
//this method returns the top of the stack
template <class T, int initialsize>
T Stack<T, initialsize>::back()
{
    return ptr[pos];
}
//method which returns number of entries
template <class T, int initialsize>
int Stack<T, initialsize>::getNumEntries()
{
    return entries;
}
//printing method
template <class T, int initialsize>
void Stack<T, initialsize>::print()
{
    for (int i = 0; i < pos + 1; ++i)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Stack<int> intStack; //creating a stack
    int c;
    for (int i = 0; i < 20; i++)
    {
        cout << intStack.push(i); //returns 20 1's,because of extend method
    }
    cout << endl;
    intStack.print();
    cout << intStack.pop(c) << endl; //returns 1 if pop was succesful
    intStack.print();
    cout << intStack.getNumEntries() << endl; //returns number of entries
    cout << intStack.back();                  //returns the element on top of the stack
    return 0;
}