class Solution {
public:
    //We use Dynamic Programming so solve this problem.
    //Recall that a binary tree is a tree with a root having it's left child and right child as binary trees
    //therefore solution for k-node binary tree is the sum of solutions of k-node binary tree with, 0 left child k-1 right child, 
    //1 left child k-2 right child, 2 left child k-3 right child,....k-1 left child 0 right child.
    //since it involves solution of smaller k's we will store these solutions to avoid recomputation
    int numTreesInner(int n, vector<int>& dp)
    {
        if(dp[n] != -1)//if already computed return the answer else compute it
            return dp[n];
        else
        {
            int sum=0;
            for(int i=0;i<n;i++)
                sum += numTreesInner(i, dp) * numTreesInner(n-i-1, dp);//solution for k-node binary tree with i-node left binary tree and k-i-1-node right binary tree
            dp[n]=sum;                                                //is the product of solutions for i-node binary tree and k-i-1 binary tree via multiplication rule     
        }                                                             //in combinatorics.      
        return 0;
    }
    int numTrees(int n) 
    {
        vector<int> dp(n+1,-1);//initialize dp array
        dp[0]=1;//although the answer maybe 0 for this one we need this to be 1 for the product sum defined above
        dp[1]=1;//for 1 node there is only 1 possibility
        for(int i=0;i<=n;i++)
            numTreesInner(i, dp);//iterate from 1 to n and store the solutions
        
        return dp[n];//return the answer which is the last element in the dp array.
    }
};
