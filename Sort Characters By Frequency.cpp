class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> frequency_map;
        for(char c : s)
            if(frequency_map.find(c) == frequency_map.end())
                frequency_map[c] = 1;
            else
                frequency_map[c]++;
        
        vector<pair<char, int>> frequency_vec(frequency_map.begin(), frequency_map.end());
        auto comp = [&](pair<char,int> elem1, pair<char, int> elem2)-> bool {return elem1.second>elem2.second;};
        sort(frequency_vec.begin(), frequency_vec.end(), comp);
        
        string result = "";
        for(pair<char, int> elem : frequency_vec)
            result += string(elem.second, elem.first);
        return result;
    }
};
