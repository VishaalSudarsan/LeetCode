class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, size = cardPoints.size(), tempsum;
        for(int i=0;i<k;i++)
            sum += cardPoints[i];
        tempsum=sum;
        for(int i=size-1,j=k-1;i>size-k-1;i--,j--)
        {
            tempsum = tempsum - cardPoints[j] + cardPoints[i];
            sum = max(sum, tempsum);
        }
        
        return sum;
    }
};
