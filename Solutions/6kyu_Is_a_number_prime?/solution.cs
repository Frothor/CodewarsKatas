using System;

public static class Kata
{
  public static bool IsPrime(int n)
  {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    var boundary = (int)Math.Floor(Math.Sqrt(n));

    for (int i = 3; i <= boundary; i+=2)
        if (n % i == 0)
            return false;

    return true;     
  }
}

/*
Another solutions:
using System;

public static class Kata
{
  public static bool IsPrime(int n)
  {
    if (n <= 2 || n % 2 == 0) return n == 2;
    for (int i = 3; i <= Math.Sqrt(n); i += 2) if (n % i == 0) return false;
    return true;
  }
}


public static class Kata
{
  public static bool IsPrime(int n)
  {
    if (n <= 1)
      return false;
      
    for (int i = 2; i*i <= n; i++)
    {
      if (n % i == 0)
        return false;
    }  
        
    return true;
  }
}


*/