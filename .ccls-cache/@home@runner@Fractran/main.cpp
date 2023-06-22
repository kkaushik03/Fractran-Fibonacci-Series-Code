//g++ main.cpp -o main


#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
//to avoid errors

namespace mp = boost::multiprecision;
#include <iostream>  //input / op 
#include <vector>   // to create the list
#include <cmath>    // 
#include "Fraction.cpp"  //

using namespace std;
//int fractionLocation = 0; 
void uploadList();
void prlonglong();
mp::cpp_int  functionR(mp::cpp_int  num);
mp::cpp_int  hasVectorgcd(mp::cpp_int  num);
std::vector<Fraction> frc;

int main()
{
    uploadList();  //good
    //std::cout<< "List is uploaded"<<endl; //good
    prlonglong();  //good
     cout << "enter the number"<< endl;
    long  number=0; 
    cin >> number;
    long  x  = (long  )pow(5, number-1);
    number  = 78*x;
    cout <<"Transformed: " << number << endl;
   // mp::cpp_int  b= hasVectorgcd( number);
   mp::cpp_int  answer =  functionR( number);
   // while(hasVectorgcd(answer)!=answer)
   // {
   //     mp::cpp_int  answer =  functionR( number);
  //  }
  double ans= (double)(answer);
  double result = std::log2(ans);
  cout << "Answer: " << answer << " Log2: "<< result<< endl;  
  
    return 0;
}

mp::cpp_int  functionR(mp::cpp_int num)
{
    cout << "entered functionR"<< endl;
   // Fraction fr= frc.at(0);
    mp::cpp_int x = hasVectorgcd(num);
   // cout << "hasVectorgcd(num):   "<< x<<  endl;
    if(x!=num)  //why    5 should not have a gcd 5
    {
     cout << "gcd ";
    num = x;
    return functionR(num);
    }
    cout << "No gcd avaiblable" << endl;
    return num;
}


mp::cpp_int  hasVectorgcd(mp::cpp_int num)
{
   // Fraction fr= frc.at(0);
   cout <<"             "<< frc.size()<<endl;
   int  i = 0 ;
    while(i < frc.size())
     {

Fraction fr= frc.at(i);
        cout << "Tested:  " << fr.getDenominator() << endl;
        if (num % fr.getDenominator()==0) 
        {
            cout << "Divisible: "<< fr.getDenominator() <<endl;
            //fractionLocation=i;
           
            num =(num/fr.getDenominator()) * fr.getNumerator();
            
            cout <<"Number: " << num << endl;
            return num;
        }
        i++;



     }  
    // cout << "Num/den" << fr.getNumerator() << " / " << fr.getDenominator()<< endl;
    cout << "Updated:  " << num << endl;
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


