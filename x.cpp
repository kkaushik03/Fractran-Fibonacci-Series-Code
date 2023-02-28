#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    cout << "Enter a number: ";
    int number; 
    cin>>number;
    int i =1;
    while(number>1)
    {
        if(number%2==0)
        {
            number = number/2;
            cout << i << " even  "<<number<< endl;
        }   
        else  
        {
            number = (number * 3) + 1;
            cout << i << " odd   "<<number<<endl;
        }  
           i++;
    }
    return 0;
}
