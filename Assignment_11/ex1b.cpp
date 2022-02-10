#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <set>
#include <cstring>
using namespace std;
void printsett(set<int> s){
	cout<<"here"<<endl;
	for(int a:s){
		cout<<a<<" ";
	}
}
int main() {
	set <int> s;
	s.insert(40);
	s.insert(30);
	s.insert(60);
	printsett(s);
	return 0;
}