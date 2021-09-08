class Solution {
public:
    
    char shiftChar(char c, int n)
    {
        n = n%26;
        return int(c) + n > 122 ? int(c) + n - 26 : int(c) + n;
    }
    
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        int size = shifts.size();
        
        for(int i=size-2;i>=0;i--)
            shifts[i] = (shifts[i]%26 + shifts[i+1]%26)%26;

        for(int i=0;i<size;i++)
            s[i] = shiftChar(s[i], shifts[i]);
        
        return s;
    }
};
