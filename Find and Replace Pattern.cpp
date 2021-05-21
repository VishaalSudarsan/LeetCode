class Solution {
public:
    
    string getPattern(string& s)
    {
        unordered_map<char, int> charnum;
        int pattern = 0;
        string unified;
        
        for(char c : s)
        {
            pattern++;
            if(charnum.find(c) == charnum.end())
                charnum.insert(pair<char, int>(c, pattern));
            else
                pattern--;
        }
        
        for(char c : s)
            unified.push_back(charnum[c]);
        
        return unified;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string patternunified = getPattern(pattern), wordunified;
        vector<string> result;
        
        for(string word : words)
        {
            wordunified = getPattern(word);
            if(patternunified == wordunified)
                result.push_back(word);
        }
        
        return result;
    }
};
