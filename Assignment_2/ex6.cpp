/**Matias Merko
 * mmerko@jacobs-university.de
 * */
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
struct Birthday
{
    string fn; //first name
    string sn; //surname
    string d;  //date
};
int main()
{
    ifstream myfile("data.txt", ifstream::in);
    map<string, string> mymap;
    Birthday bday;
    while (myfile.good())
    {
        myfile >> bday.fn;
        myfile >> bday.sn;
        myfile >> bday.d;
        //adding the pair to ma[]
        mymap.insert(pair<string, string>(bday.fn + " " + bday.sn, bday.d));
    }
    unsigned int count = 0;
    string name;
    cout << "Enter name:";
    getline(cin, name);
    map<string, string>::iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++)
    {
        count++;
        if (name == it->first)
        {
            cout << it->second;
            break;
        }
        if (count == mymap.size())
        {
            cout << "Name not found";
        }
    }
    return 0;
}