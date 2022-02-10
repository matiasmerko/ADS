//Matias Merko
//mmerko@jacobs-university.de
#include <iostream>
using namespace std;
class Complex
{
private:
    float real, imag;

public:
    Complex();
    Complex(const float newreal, const float newimag);
    Complex(const Complex &obj); //copy constructor
    ~Complex();                  //destructor
    void setComplex(float newreal, float newimag);
    bool operator==(const Complex &);
    void display();
};
void Complex::setComplex(float newreal, float newimag)
{
    real = newreal;
    imag = newimag;
}
/**overloading the operator == in order to be able
 * to use it for complex numbers*/
bool Complex::operator==(const Complex &obj)
{
    if (real == obj.real && imag == obj.imag)
    {
        return 1;
    }
    return 0;
}
//default constructor
Complex::Complex()
{
    real = 0;
    imag = 0;
}
Complex::Complex(float newreal, float newimag)
{
    real = newreal;
    imag = newimag;
}
//copy constructor
Complex::Complex(const Complex &obj)
{
    real = obj.real;
    imag = obj.imag;
}
//destructor
Complex::~Complex() {}
//generic array_search using template.
template <typename T>
void array_search(T arr[], int size, T el)
{
    int i;
    //NOTE: determining the first occurrance of the element
    //remove "break;" in order to print the position of all occurrances
    for (i = 0; i < size; i++)
    {
        if (arr[i] == el)
        {
            cout << i << endl;
            break;
        }
    }
    if (i == size)
    {
        cout << "-1" << endl;
    }
}
//used to display the imaginary number
void Complex::display()
{
    if (imag < 0)
        if (imag == -1)
            cout << real << "-i" << endl;
        else
            cout << real << imag << "i" << endl;
    else if (imag == 1)
        cout << real << " + i" << endl;
    else
        cout << real << " + " << imag << "i" << endl;
}
int main()
{
    Complex Cparray[3];          //creating an array of complex numbers
    Complex b(7, 2);             //i will search this complex number from Cparray
    Cparray[0].setComplex(1, 2); //adding elements to Cparray
    Cparray[1].setComplex(3, 2);
    Cparray[2].setComplex(4, 2);
    int intarr[4] = {1, 2, 3, 4};     //making an integer array
    float flarr[3] = {1.2, 3.4, 1.4}; //making a float array
    cout << "Searching for complex" << endl;
    array_search<Complex>(Cparray, 3, b);
    cout << "Searching for int:" << endl;
    array_search<int>(intarr, 4, 2);
    cout << "Searching for float:" << endl;
    array_search<float>(flarr, 3, 1.2);
    cout << "Searching for char:" << endl;
    char arr[2] = {'a', 'b'};
    array_search<char>(arr, 2, 'b');
    return 0;
}