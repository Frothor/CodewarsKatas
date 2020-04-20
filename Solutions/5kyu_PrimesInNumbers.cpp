/*
5kyu Primes in numbers

Given a positive number n > 1 find the prime factor decomposition of n. The result will be a string with the following form :

 "(p1**n1)(p2**n2)...(pk**nk)"
with the p(i) in increasing order and n(i) empty if n(i) is 1.

Example: n = 86240 should return "(2**5)(5)(7**2)(11)"
*/

//better solution
#include <sstream>
#include <string>

class PrimeDecomp
{
public:
    static std::string factors(int lst);
};


std::string PrimeDecomp::factors(int n) {
  std::ostringstream res;
  for (int i = 2; n > 1; i++) {
    int k = 0;
    while (n % i == 0) {
      n /= i;
      k++;
    }
    if (k == 1)
      res << '(' << i << ')';
    else if (k > 1)
      res << '(' << i << "**" << k << ')';
  }
  return res.str();
}


//first thought
/*
#include <math.h> 
class PrimeDecomp
{
public:
    static std::string factors(int lst) {
       int n = lst;
       std::map<int, int> m;
       while (n % 2 == 0)  
      {  
        m[2]++;
        n = n/2;  
      }  
  
      for (int i = 3; i <= std::sqrt(n); i = i + 2)  
      {  
          while (n % i == 0)  
          {  
            m[i]++;
            n = n/i;  
          }  
      }  
  
      if (n > 2)  
         m[n] = 1;
         
      std::string res = "";
      
      for(auto e: m){
        if(e.second > 1)
          res += '(' + std::to_string(e.first) + "**" + std::to_string(e.second) + ')';
        else
          res += '(' + std::to_string(e.first) + ')';
      }
      
      return res;
    }
};
*/