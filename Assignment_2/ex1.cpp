/**Matias Merko
 * mmerko@jacobs-university.de
 * */
#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
using namespace std;
int main()
{
    ofstream bfile;
    bfile.open("list_b.txt");
    if (!bfile.is_open())
    {
        exit(1);
    } //checking if file is good
    list<int> a, b;
    int inpval;
    //takin inputs
    while (inpval > 0)
    {
        cin >> inpval;
        if (inpval == 0 || inpval < 0)
        {
            break;
        }
        a.push_back(inpval);
        b.push_back(inpval);
    }
    //printing list a
    for (auto v : a)
    {
        cout << v << ' ';
    }
    //printing list b in bfile
    for (auto d : b)
    {
        bfile << d << ' ';
    }
    cout << endl;
    //moving first element to the end
    a.push_back(a.front());
    b.push_back(b.front());
    a.pop_front();
    b.pop_front();
    bfile.close();
    //printing lists seperated by comma
    unsigned int size = 0;
    list<int>::iterator it;
    for (it = a.begin(); it != a.end(); it++)
    {
        size++;
        if (size == a.size())
        {
            break;
        }
        cout << *it << ',';
    }
    cout << a.back() << endl;
    size = 0;
    list<int>::iterator itb;
    for (itb = b.begin(); itb != b.end(); itb++)
    {
        size++;
        if (size == b.size())
        {
            break;
        }
        cout << *itb << ',';
    }
    cout << b.back() << endl;
    //merging list B into list A
    list<int>::iterator itt;
    for (itt = b.begin(); itt != b.end(); itt++)
    {
        a.push_back(*itt);
    }
    a.sort();
    //printing sorted merged list
    for (auto z : a)
    {
        cout << z << ' ';
    }
    return 0;
}