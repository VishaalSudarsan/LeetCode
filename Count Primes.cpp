class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        bool insert = true;
        int num;
        vector<int> primenumbers;
        primenumbers.push_back(2);
        for(int i=3;i<n;i++)
        {
            num = sqrt(i);
            insert = true;
            for(int primenumber : primenumbers)
            {
                if(i%primenumber == 0)
                {
                    insert = false;
                    break;
                }
                if(primenumber>num) break;
                    
            }
            if(insert)
            {
                primenumbers.push_back(i);
            }
        }
        
        return primenumbers.size();
    }
};
