//g++ main.cpp -o main
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
#include <iostream>  //input / op 
#include <vector>   // to create the list
#include <cmath>    // 
#include "Fraction.cpp"  
using namespace std;
void uploadList();
void prlonglong();
mp::cpp_int  functionR(mp::cpp_int  num);
mp::cpp_int  hasVectorgcd(mp::cpp_int  num);
std::vector<Fraction> frc;

int main()
{
    long  number=0; 
    long x;
    long  ans;
    double result;
    long anscopy=0; 
    uploadList();  
    prlonglong();  
  
    cout << "Enter the Number: "<< endl;
    cin >> number;
    anscopy = number;
    x = (long)pow(5, number-1);
    number  = 78*x;
    mp::cpp_int  answer =  functionR( number);
   
    ans= (long )(answer);
    result = std::log2(ans);
    cout << "The fibonacci number at position " << anscopy << " is: "<< result << endl;  
  return 0;
}
                        //prepared number
mp::cpp_int  functionR(mp::cpp_int num)
{
    mp::cpp_int x = hasVectorgcd(num);  //hasVectorgcd(prepared number);
    if(x!=num) {
    num = x;
    return functionR(num); }
  return num;
}
/*
Assumptiom: num is always a whole number 
returning the updated whole number 
*/

mp::cpp_int  hasVectorgcd(mp::cpp_int num)  //hasVectorgcd(prepared number or updated);
{
   int  i = 0 ; 
    while(i < frc.size()) {
    Fraction fr= frc.at(i);
        if (num % fr.getDenominator()==0) {
            num =(num/fr.getDenominator()) * fr.getNumerator();
            return num; 
          }//return the updated  
        i=i+1; 
      }  
  return num;
}




























void uploadList()
{
    /*
     133/34, 17/19, 23/17, 2233/69, 23/29, 31/23, 74/341, 31/37, 
     41/31, 129/287, 41/43, 13/41, 1/13, 1/3.
    */
frc.push_back(Fraction(17, 65));
frc.push_back(Fraction(133, 34));
frc.push_back(Fraction(17, 19));
frc.push_back(Fraction(23, 17));
frc.push_back(Fraction(2233, 69));
frc.push_back(Fraction(23, 29));
frc.push_back(Fraction(31, 23));
frc.push_back(Fraction(74, 341));
frc.push_back(Fraction(31, 37));
frc.push_back(Fraction(41, 31));
frc.push_back(Fraction(129, 287));
frc.push_back(Fraction(41, 43));
frc.push_back(Fraction(13, 41));
frc.push_back(Fraction(1, 13));
frc.push_back(Fraction(1, 3));
cout <<frc.size()<<endl;
}

void prlonglong()
{  
for(int  i = 0 ; i <  frc.size(); i++)
{
    Fraction fr = frc.at(i);
    cout << fr.getNumerator() << "  /  " << fr.getDenominator() << endl;
}
}


