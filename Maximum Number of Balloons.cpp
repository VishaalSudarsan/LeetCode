class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        unordered_map<char, int> balloon({{'b',0},{'a',0},{'l',0},{'o',0},{'n',0}});
        for(char c : text)
            if(balloon.find(c) != balloon.end())
                balloon[c]++;
        return min({balloon['b'], balloon['a'], balloon['l']/2, balloon['o']/2, balloon['n']});
    }
};
