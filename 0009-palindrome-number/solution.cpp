class Solution {
public:
    bool isPalindrome(int x) {
        int dup = x;
          long rev = 0;
        bool xsign = (x >= 0);
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
            return false;
        }
        if (dup == rev)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
};
