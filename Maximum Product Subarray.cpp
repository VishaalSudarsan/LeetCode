//Method 1
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> maxarray(size, 1), minarray(size, 1);
        maxarray[0] = nums[0];
        minarray[0] = nums[0];
        for(int i=1;i<size;i++)
        {
            if(nums[i]>0)
            {   
                maxarray[i] = max(nums[i], nums[i]*maxarray[i-1]);
                minarray[i] = min(nums[i], nums[i]*minarray[i-1]);
            }
            else
            {
                maxarray[i] = max(nums[i], nums[i]*minarray[i-1]);
                minarray[i] = min(nums[i], nums[i]*maxarray[i-1]);
            }    
        }
        return max(*max_element(maxarray.begin(), maxarray.end()), *max_element(minarray.begin(), minarray.end()));
    }
};

//Method 2
class Solution {
public:
    
    int maxProductInner(vector<int>& nums)
    {
        if(nums.size()==1) return nums[0];
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int negatives = count_if(nums.begin(), nums.end(), [](int x){ return x < 0;});
        int result;
        if(negatives%2 == 0)
            result = accumulate(nums.begin(), nums.end(), 1, std::multiplies<>());
        else
        {
            int product_till_first_negative=1, product_after_last_negative=1;
            int first_negative_pos, last_negative_pos;
            int i=0;
            while(i < nums.size()-1 && nums[i]>0)
            {
                product_till_first_negative *= nums[i];
                i++;
            }
            first_negative_pos = i;
            i=nums.size()-1;
            while(i>=0 && nums[i]>0)
            {
                product_after_last_negative *= nums[i];
                i--;
            }
            last_negative_pos = i;
            cout<<product_till_first_negative<<" "<<product_after_last_negative<<endl;
            cout<<first_negative_pos<<" "<<last_negative_pos<<endl;
            if(product_till_first_negative*abs(nums[first_negative_pos]) > product_after_last_negative*abs(nums[last_negative_pos]))
                result = accumulate(nums.begin(), nums.begin()+last_negative_pos, 1, std::multiplies<int>());
            else
                result = accumulate(nums.begin()+first_negative_pos+1, nums.end(), 1, std::multiplies<int>());
        }
        return result;        
    }
    
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int result;
        vector<int> zeros, inner_prods;
        nums.insert(nums.begin(),0);
        nums.push_back(0);
        for(int i=0;i<nums.size();i++)
            if(nums[i] == 0)
                zeros.push_back(i);
        
        if(zeros.size() - nums.size() == 0) return 0;

        for(int i=0;i<zeros.size()-1;i++)
        {
            if(zeros[i]+1 != zeros[i+1])
            {
                vector<int> inner_nums(nums.begin()+zeros[i]+1, nums.begin()+zeros[i+1]);
                inner_prods.push_back(maxProductInner(inner_nums));
            }
        }

        result = *max_element(inner_prods.begin(), inner_prods.end());
        if(zeros.size()>2 && result < 0) result = 0;
        return result;
    }
};
