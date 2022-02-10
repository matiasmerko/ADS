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
#define Table_size 5
//In this example, there are no collisions happening
struct DoubleHash{
	int* htable;
	int currsize;
	DoubleHash(){
		currsize=0;
		htable=new int[Table_size];
		for(int i=0;i<Table_size;i++){
			htable[i]=-1;
		}
	}
	int hash1(int key){
	return key %5;
	}
	int hash2(int key){
		return 7*key%8;
	}
	void insert(int key){
		if(currsize==Table_size){
			return;
		}
		int index1=hash1(key);
		if(htable[index1]!=-1){
			int index2=hash2(key);
			int i=1;
			while(1){
				int FinalIndex=(index1+i*index2)%Table_size;
				if(htable[FinalIndex]==-1){
					htable[FinalIndex]=key;
					break;
				}
				i++;
			}
		}else{
			htable[index1]=key;
		}
		currsize++;
	}
	void printhash(){
		for(int i=0;i<Table_size;i++){
			if(htable[i]!=-1){
				cout<<i<<"-->"<<htable[i]<<endl;
			}else{
				cout<<i<<endl;
			}
		}
	}
};

int main() {
	int seq[4]={3,10,2,4};
	DoubleHash a;
	for(int i=0;i<4;i++){
		a.insert(seq[i]);
	}
	a.printhash();
	return 0;
}