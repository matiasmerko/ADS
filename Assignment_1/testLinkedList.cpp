//Matias Merko
//mmerko@jacobs-university.de
#include "LinkedList.h"
using namespace std;
//default constructor
template <class T>
Node<T>::Node()
{
    size = 0;
    prev = NULL;
    next = NULL;
    el = 0;
}

//destructor
template <class T>
Node<T>::~Node() {}

//returns the first element
template <class T>
T Node<T>::firstel(Node *head)
{
    return head->el;
}
// returns the last element
template <class T>
T Node<T>::lastel(Node *head)
{
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    return tmp->el;
}
//adds an element to the front
template <class T>
Node<T> *Node<T>::addfront(Node *head, T newel)
{
    Node *newnode = new Node;
    if (newnode == NULL)
    {
        exit(1);
    }
    newnode->next = head;
    head = newnode;
    newnode->prev = NULL;
    newnode->el = newel;
    return head;
}
//adds and element to the back
template <class T>
Node<T> *Node<T>::addback(Node *head, T newel)
{
    Node *tmp = head;
    Node *newnode = new Node;
    if (newnode == NULL)
    {
        exit(0);
    }
    newnode->el = newel;
    if (head == NULL)
    {
        head = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newnode;
        newnode->next = NULL;
    }
    return head;
}
//print method
template <class T>
void Node<T>::print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->el;
        tmp = tmp->next;
    }
}
int main()
{
    Node<int> *head = NULL;
    head = head->addfront(head, 2);
    head->print(head);
    cout << endl;
    head = head->addback(head, 3);
    head = head->addfront(head, 1);
    head->print(head);
    cout << endl
         << "Last elenent: " << head->lastel(head)
         << "\nFirst element:" << head->firstel(head);
    return 0;
}