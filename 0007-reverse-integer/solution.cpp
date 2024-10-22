#include <bits/stdc++.h>
class Solution {
public:

    int reverse(long x) 
    {
        long rev = 0;
        bool xsign = (x > 0);
        if (xsign == true)
        {
            while (x > 0)
            {
            int l = x%10;
            rev = rev*10 + l;
            x = x/10;
            }
        }
         
       else if (xsign == false)
        {
            x = x*-1;
            while (x > 0)
            {
             int c = x%10;
            rev = rev*10 + c;
            x = x/10;
            }
            rev = rev*-1;
        }
        if(rev < INT_MAX && rev > INT_MIN)
        {
        return rev;
        }
        else
        {return 0;}
    }
};
