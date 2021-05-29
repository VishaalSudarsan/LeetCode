class Solution {
public:
//gives the correct answer using O(m+n) algorithm
double confirmanswer(vector<int> nums1, vector<int> nums2)
{
    vector<int> mergednums;
    while (!nums1.empty() && !nums2.empty())
    {
        if (nums1.back() > nums2.back())
        {
            mergednums.push_back(nums1.back());
            nums1.pop_back();
        }
        else
        {
            mergednums.push_back(nums2.back());
            nums2.pop_back();
        }
    }

    while (!nums1.empty())
    {
        mergednums.push_back(nums1.back());
        nums1.pop_back();
    }

    while (!nums2.empty())
    {
        mergednums.push_back(nums2.back());
        nums2.pop_back();
    }

    int size = mergednums.size();
    int result = mergednums[size / 2];

    return result;
}

//tells if a number lies between both the medians or not
bool CheckRange(int x, int median1, int median2)
{
    if ((median1 <= x && x <= median2) || (median2 <= x && x <= median1))
        return true;
    return false;
}

//Does a Binary Search for location of insertion on a sorted array
int FindPos(int item, vector<int>& nums)
{
    int size = nums.size();
    int start = 0, end = size - 1, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (nums[mid] <= item )
            start = mid + 1;
        else if (nums[mid] > item)
            end = mid-1;
        else
            start = mid+1;
    }

    return start;
}
//Does a Binary Search for location of insertion on a sorted array
int FindPos2(int item, vector<int>& nums)
{
    int size = nums.size();
    int start = 0, end = size - 1, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (nums[mid] < item)
            start = mid + 1;
        else if (nums[mid] >= item)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return start;
}

int ForcePos(int pos, int pos2, int m, int mid)
{
    for (int i = pos2;i <= pos;i++)
        if (i + mid == m)
            return i;
    return pos;
}


//Searches for the median by iteratively calling FindPos 
pair<int, int> FindMedianPos(vector<int>& nums1, vector<int>& nums2, int m, int flag = 0)
{
    int size1 = nums1.size(), size2 = nums2.size();
    int start = 0, end = size1 - 1, pos, pos2, mid;
    //int median1 = nums1[size1 / 2], median2 = nums2[size2 / 2];

    pair<int, int> medianpair;
    while (start <= end)
    {
        mid = (start + end) / 2;
        pos = FindPos(nums1[mid], nums2);
        if (flag)
        {
            pos2 = FindPos2(nums1[mid], nums2);
            pos = ForcePos(pos, pos2, m, mid);
        }
        if (pos + mid  == m)
        {
            if (m != (size1 + size2) / 2)
                pos--;
            if (mid>0)
                if(nums1[mid]>= nums2[max(pos - 1, 0)])
                    medianpair = make_pair(nums1[mid], max(nums1[mid-1],nums2[max(pos-1,0)]));
                else
                    medianpair = make_pair(nums1[mid], nums1[mid - 1]);
            else
                medianpair = make_pair(nums1[mid], nums2[max(pos-1,0)]);
            return medianpair;
        }   
        else if (pos + mid > m)
            end = mid-1;
        else
            start = mid+1;
    }

    return make_pair(-123329, -123329);
}

double CalculateAnswer(pair<int, int> ans, int size)
{
    if (size % 2 == 0)
        return (float)(get<0>(ans) + get<1>(ans)) / 2;
    else
        return get<0>(ans);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int size1 = nums1.size(), size2 = nums2.size(), size = size1 + size2;
    //int median1 = nums1[size1 / 2], median2 = nums2[size2 / 2];
    pair<int, int> ans;
    if (!size1)
        return CalculateAnswer(make_pair(nums2[size2 / 2], nums2[max(size2 / 2 - 1, 0)]), size2);
    else if(!size2)
        return CalculateAnswer(make_pair(nums1[size1 / 2], nums1[max(size1 / 2 - 1, 0)]), size1);
    else
    {
        ans = FindMedianPos(nums1, nums2, size/2);
        if (get<0>(ans) == -123329)
            ans = FindMedianPos(nums2, nums1, size/2);
        if (get<0>(ans) == -123329)
            ans = FindMedianPos(nums2, nums1, size / 2, 1);
    }

    return CalculateAnswer(ans, size);
}
};    
