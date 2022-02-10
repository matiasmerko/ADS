#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#include <math.h>
#include <algorithm>
using namespace std;
/**
 * IMPORTANT NOTE :
 * This code only works for two large integers of size
 * 2^n.
 * */
void printvec(vector<int> a)
{
    for (unsigned int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }
    cout << endl;
}
vector<int> add(vector<int> vec1, vector<int> vec2)
{
	vector<int> temp1, temp2;
	if (vec1.size() > vec2.size())
	{
		for (unsigned int i = 0; i < vec1.size() - vec2.size(); i++)
		{
			temp1.push_back(0);
		}
		for (unsigned int j = 0; j < vec2.size(); j++)
		{
			temp1.push_back(vec2[j]);
		}
		temp2 = vec1;
	}
	else if (vec2.size() > vec1.size())
	{
		for (unsigned int i = 0; i < vec2.size() - vec1.size(); i++)
		{
			temp1.push_back(0);
		}
		for (unsigned int j = 0; j < vec1.size(); j++)
		{
			temp1.push_back(vec1[j]);
		}
		temp2 = vec2;
	}
	else
	{
		temp1 = vec1;
		temp2 = vec2;
	}
	vector<int> result(temp1.size() + 1, 0);
	reverse(temp1.begin(), temp1.end());
	reverse(temp2.begin(), temp2.end());
	for (unsigned int i = 0; i < temp1.size(); i++)
	{
		if (temp1[i] + temp2[i] > 9)
		{
			result[i] += (temp1[i] + temp2[i]) % 10;
			result[i + 1] += 1;
		}
		else
		{
			result[i] += temp1[i] + temp2[i];
		}
	}
	for(unsigned int i=0;i<result.size();i++){
        if(result[i]>9){
            result[i+1]+=1;
            result[i]-=10;
        }
    }
	if (result[result.size() - 1]==0)
	{
		result.pop_back();
	}
	reverse(result.begin(), result.end());
	return result;
}
vector<int> mult(vector<int> vec1, vector<int> vec2)
{
    vector<int> result;
    int product = vec1[0] * vec2[0];
    if (product < 10)
    {
        result.push_back(product);
    }
    else
    {
        result.push_back((product-(product%10))/10);
        result.push_back(product % 10);
    }
    return result;
}
vector<int> product(vector<int> a, vector<int> b)
{
    vector<int> temp, v;
    if (a.size() == 1 && b.size() == 1)
    {
        return mult(a, b);
    }
    else
    {
        vector<int> aL(a.begin(), a.begin() + a.size() / 2);
        vector<int> aR(a.begin() + a.size() / 2, a.end());
        vector<int> bL(b.begin(), b.begin() + b.size() / 2);
        vector<int> bR(b.begin() + b.size() / 2, b.end());
        vector<int> w, x, y, z;
        w = product(aL, bL);
        x = product(aL, bR);
        y = product(aR, bL);
        z = product(aR, bR);
        temp = add(x, y);
        for (unsigned int i = 0; i < a.size(); i++)
        {
            w.push_back(0);
            if (i < a.size() / 2)
            {
                temp.push_back(0);
            }
        }
        v = add(w, temp);
        return add(v, z);
    }
}
int main()
{
    vector<int> a;
    vector<int> b;
    string ainput, binput;
    cout << "Enter a: \n";
    cin >> ainput;
    for (unsigned int i = 0; i < ainput.size(); i++)
    {
        a.push_back(ainput[i] - '0');
    }
    cout << "Enter b: \n";
    cin >> binput;
    for (unsigned int i = 0; i < binput.size(); i++)
    {
        b.push_back(binput[i] - '0');
    }
    cout << "result: ";
    printvec(product(a, b));
    return 0;
}