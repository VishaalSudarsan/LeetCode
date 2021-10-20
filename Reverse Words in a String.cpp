class Solution {
public:
    
    //used to remove leading and ending spaces
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
    
    //a generic function to split a string using a character
    vector<string> strsplit(string &s, char c)
    {
        string temp="";
        vector<string> result;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != c)
                temp += s[i];//create the temp vector to be inserted into the vector, it should not be having the split character in it
            else
            {
                //this if condition ensures that continues appearances of the split character is taken care of
                //for example "hello     world" with  " " as the split character should return ["hello", "world"]
                if(i != s.size()-1 && s[i+1] != ' ')
                {
                    result.push_back(temp);
                    temp = "";//reset the temp variable so that the next word can be inserted into the vector
                }
            }
            if(i == s.size()-1)
                result.push_back(temp);//last word is not inserted in the vector in the above if-else therefore creating a case for that
            
        }
        return result;
    }
    
    string reverseWords(string s) 
    {
        //1.trim the string 
        //2.split it with space as the split character
        //3.reverse the splited vector
        //4.create a string using the reversed vector and return the newly created string
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
