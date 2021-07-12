class Solution {
public:
    double myPowPositive(double x, unsigned int n)
    {
        if(n == 0)
            return 1;
        else if(n == 1)
            return x;
        else if(n%2 == 0)
        {
            double y = myPow(x, n/2);
            return y*y;
        }
        else
        {
            double y = myPow(x, n/2);
            return x*y*y;
        }
    }
    double myPow(double x, int n) {
        if(n < 0)
        {
            unsigned int m = n+1;
            m = -m;
            m++;
            return myPowPositive(1/x, m);        
        }
        else
            return myPowPositive(x,n);
    }
};
