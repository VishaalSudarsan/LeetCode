class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0) return false;
        unsigned int number = x, reversed_number = 0, digit;
        while(x>0)
        {
            digit = x%10;
            x /= 10;
            reversed_number = reversed_number*10 + digit; 
        }
        
        return number == reversed_number;
    }
};
