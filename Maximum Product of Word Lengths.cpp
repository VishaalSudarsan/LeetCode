class Solution {
public:
    
    bool noMatch(string& s1, string& s2)
    {
        for(char c : s1)
            if(s2.find(c) != std::string::npos)
                return false;
        return true;
    }
    
    int maxProduct(vector<string>& words) {
        int result = 0, prodlength, size = words.size();
        for(int i=0;i<size;i++)
            for(int j=i+1;j<size;j++)
                if(noMatch(words[i], words[j]))
                {
                    prodlength = words[i].size()*words[j].size();
                    if(prodlength>result)
                        result = prodlength;
                }
        return result;  
    }
};
