//Matias Merko
//mmerko@jacobs-university.de
#include <iostream>
template <class T>
class Node
{
private:
    Node *prev;
    Node *next;
    T el;
    int size;

public:
    Node();
    ~Node();
    T firstel(Node *);
    T lastel(Node *);
    int elamount();
    Node *addfront(Node *head, T newel);
    Node *addback(Node *head, T newel);
    void print(Node *);
};
