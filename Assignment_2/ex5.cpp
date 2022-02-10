/**Matias Merko
 * mmerko@jacobs-university.de
 * */
#include <iostream>
#include <set>
#include <time.h>
using namespace std;
//print function for set
void printset(set<int> myset)
{
    set<int>::iterator it;
    for (it = myset.begin(); it != myset.end(); it++)
    {
        cout << *it << ' ';
    }
}
int main()
{
    //generating random number using time
    srand(time(0));
    set<int> myset;
    int num;
    //adding 6 random numbers to the set
    while(1)
    {   
        num = rand() % 49 + 1;
        myset.insert(num);
        if(myset.size()==6){break;}
    }
    printset(myset);
    return 0;
}