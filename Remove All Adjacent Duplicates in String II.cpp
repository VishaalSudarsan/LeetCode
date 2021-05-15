class Solution {
public:
    list<pair<string, int>> compressToList(string &s)
    {
        int count;
        string letter;
        list<pair<string, int>> compressed;
        for(int i=0;i<s.size();i++)
        {
            letter = s[i];
            count = 1;
            while(i != s.size()-1 && s[i] == s[i+1])
            {
                count++;
                i++;
            }
            compressed.push_back(pair<string, int>(letter, count));
        }
        
       
        return compressed;
    }
    
    string compressedToString(list<pair<string, int>>& compressed)
    {
        string s = "";
        for (auto elem : compressed)
            for (int i = 1; i <= elem.second; i++)
                s += elem.first;
        return s;
    }
    
    string removeDuplicates(string s, int k) {
        list<pair<string, int>> compressed;
        compressed = compressToList(s);
        list<pair<string, int>>::iterator point = compressed.begin(), pointplus, pointminus;
        while (point != --compressed.end())
        {
            pointplus = point;
            pointplus++;
            pointminus = point;
            if (point != compressed.begin())
                pointminus--;
            if(point->second / k >= 1)
                point->second -= (point->second / k)* k;
            if (point->second == 0)
            {

                if (point == compressed.begin())
                {
                    pointminus++;
                    compressed.erase(point);
                    point = pointminus;
                    continue;
                }
                else
                {
                    compressed.erase(point);
                    point = pointminus;
                }

            }
            if (point->first == pointplus->first)
            {
                point->second += pointplus->second;
                compressed.erase(pointplus);
                continue;
            }
            point++;
        }

        if(point->second /k >=1)
            point->second -= (point->second / k)* k;
        if (point->second == 0)
            compressed.erase(point);

        return compressedToString(compressed);
    }
};
