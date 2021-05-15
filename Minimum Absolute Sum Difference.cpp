class Solution {
public:   
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int abs_sum = 0, elem;
        vector<int> difference, sorted_nums1 = nums1;
        vector<int>::iterator nearest_right, nearest_left, max_elem, replacement;
        sort(sorted_nums1.begin(), sorted_nums1.end());
        for (int i = 0; i < nums1.size(); i++)
        {
            elem = nums2[i];
            nearest_right = lower_bound(sorted_nums1.begin(), sorted_nums1.end(), elem);
            if (nearest_right == sorted_nums1.end())
                nearest_right--;
            nearest_left = nearest_right;
            if(nearest_left != sorted_nums1.begin())
                nearest_left--;
            if (abs(*nearest_left - elem) < abs(*nearest_right - elem))
                difference.push_back(abs(nums1[i] - nums2[i]) - abs(*nearest_left - elem));
            else
                difference.push_back(abs(nums1[i] - nums2[i]) - abs(*nearest_right - elem));
        }
        max_elem = max_element(difference.begin(), difference.end());
        elem = *(nums2.begin() + int(max_elem - difference.begin()));
        nearest_right = lower_bound(sorted_nums1.begin(), sorted_nums1.end(), elem);
        if (nearest_right == sorted_nums1.end())
            nearest_right--;
        nearest_left = nearest_right;
        if (nearest_left != sorted_nums1.begin())
            nearest_left--;
        if (abs(*nearest_left - elem) < abs(*nearest_right - elem))
            replacement = nearest_left;
        else
            replacement = nearest_right;
        *(nums1.begin() + int(max_elem - difference.begin())) = *replacement;
        for (int i = 0; i < nums1.size(); i++)
        {
            abs_sum += abs(nums1[i] - nums2[i]) % 1000000007;
            abs_sum = abs_sum % 1000000007;
        }
        return abs_sum;
    }
};
