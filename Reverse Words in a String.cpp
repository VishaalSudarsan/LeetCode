class Solution {
public:
    
    void trim(string &s)
    {
        string result = "";
        int begin = 0, end = s.size()-1;
        while(s[begin] == ' ')
            begin++;
        while(s[end] == ' ')
            end--;
        while(begin <= end)
            result += s[begin++];
        
        s = result;
    }
    
    vector<string> strsplit(string &s, char c)
    {
        string temp="";
        vector<string> result;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != c)
                temp += s[i];
            else
            {
                if(i != s.size()-1 && s[i+1] != ' ')
                {
                    result.push_back(temp);
                    temp = "";
                }
            }
            if(i == s.size()-1)
                result.push_back(temp);
            
        }
        return result;
    }
    
    string reverseWords(string s) 
    {
        trim(s);
        char splitchar = ' ';
        vector<string> split_s = strsplit(s, splitchar ), result_vec;
        reverse(split_s.begin(), split_s.end());
        string result = "";
        for(int i=0;i<split_s.size();i++)
        {
            if( i != split_s.size()-1)
                result += split_s[i] + ' ';
            else
                result += split_s[i];
        }
        return result;
    }
};
