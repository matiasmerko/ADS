#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <cstring>
using namespace std;
struct Activities{
	int start,end;
};
bool cmp(Activities a1,Activities a2){
	return a1.start>a2.start;
}
void maxActivity(Activities arr[],int size){
	sort(arr,arr+size,cmp);
	int j=0;
	cout<<"Activities: "<<endl<<"Activity: "<<1<<" Start: "<<arr[0].start<<" End: "<<arr[0].end<<endl;
	for(int i=1;i<size;i++){
		if(arr[i].end<=arr[j].start){
			cout<<"Activity: "<<i<<" Start: "<<arr[i].start<<" End: "<<arr[i].end<<endl;
			j=i;
		}
	}
}
int main() {
	Activities activities[]={{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
	int size=6;
	maxActivity(activities,size);
	return 0;
}
