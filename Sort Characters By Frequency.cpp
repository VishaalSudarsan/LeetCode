class Solution {
public:
    string frequencySort(string s) 
    {
        //create a frequency table between the characters and the number of times
        //it appears in the string
        unordered_map<char, int> frequency_map;
        for(char c : s)
            if(frequency_map.find(c) == frequency_map.end())
                frequency_map[c] = 1;
            else
                frequency_map[c]++;
        
        //store the frequency map as a vector so that it can be sorted
        vector<pair<char, int>> frequency_vec(frequency_map.begin(), frequency_map.end());
        auto comp = [&](pair<char,int> elem1, pair<char, int> elem2)-> bool {return elem1.second>elem2.second;}; //use a custom comparator to sort it by the frequency
        sort(frequency_vec.begin(), frequency_vec.end(), comp);
        
        //create a sorted string by iterating through the sorted vector
        string result = "";
        for(pair<char, int> elem : frequency_vec)
            result += string(elem.second, elem.first);//use the string constructor to create a string of repeated character
        return result;
    }
};
