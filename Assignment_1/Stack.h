//Matias Merko
//mmerko@jacobs-university.de
#include <iostream>
template <class T, int initialsize = 10>
class Stack
{
private:
    T *ptr;          //dynamic array
    int size;        //size
    int pos;         //position
    void extend();   //extend method
    int entries = 0; //number of entriess
public:
    void print();
    Stack();
    Stack(const Stack &);
    Stack(int nsize);
    bool push(T element);
    bool pop(T &out);
    T back(void);
    int getNumEntries();
    ~Stack();
};