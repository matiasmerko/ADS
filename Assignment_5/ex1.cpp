#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
using namespace std;
//NOTE: Check at the end for more of exercise 1
//Naive method
int Naive(int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return Naive(n - 1) + Naive(n - 2);
    }
}

//Bottom up approach
int Bottomup(int a)
{
    int x=0,y=1,z;
    if(a==0){
        return a;
    }
    for(int i=2;i<=a;i++){
        z=x+y;
        x=y;
        y=z;
    }
    return y;
}

//Closed form
stringstream closedform(int n){
    stringstream result;
    result<<round((1/sqrt(5))*(pow((1+sqrt(5))/2,n))-(pow((1-sqrt(5))/2,n)));
    return result;
}

//Matrix representation
void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + 
            F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + 
            F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + 
            F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + 
            F[1][1] * M[1][1];
     
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
void power(int F[2][2], int n)
{
    int i;
    int M[2][2] = { { 1, 1 }, { 1, 0 } };
     
    // n - 1 times multiply the 
    // matrix to {{1,0},{0,1}}
    for(i = 2; i <= n; i++)
        multiply(F, M);
}
int matrix(int n)
{
    int F[2][2] = { { 1, 1 }, { 1, 0 } };
     
    if (n == 0)
        return 0;
         
    power(F, n - 1);
     
    return F[0][0];
}
void printarr(int *a, int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    stringstream a=closedform(1000);
    //Naive method  
    cout<<"Naive method with input 9: "<<Naive(9)<<endl;

    //Bottom up approach
    cout<<"Bottom up with input 9: "<<Bottomup(9)<<endl;
    
    //Closed form
    cout<<"Closed form with input 9: "<<a.str()<<endl;
    
    //Matrix
    cout<<"Matrix representation with input 9: "<<matrix(9);
    return 0;
}

/**
 * Ex 5.1c: 
 *I believe that most of the time they will output the same number,
 but for very big numbers, the closed form might not be 100% correct 
 in its output, because it is basically rounding up its answer.
 * */
