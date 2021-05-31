class Solution {
public:  
    int getCorrespondingIndex(vector<int>& nums1, vector<int>& nums2, int& pos)
    {
        int medianpos = (nums1.size() + nums2.size() - 1) / 2;
        int correspondingindex = medianpos - pos;
        return correspondingindex;
    }

    void binaryTraverse(vector<int>& nums1, vector<int>& nums2, int p, int q, int& lowermedianpos)
    {
        if (p > q) return;
        int mid = (p + q) / 2;
        int index = getCorrespondingIndex(nums1, nums2, mid);
        if (index < 0)
            binaryTraverse(nums1, nums2, p, mid - 1, lowermedianpos);
        else if (index > nums2.size() - 1)
            if (index == nums2.size() && nums1[mid] >= nums2[index-1])
            {
                lowermedianpos = mid;
                return;
            }
            else
                binaryTraverse(nums1, nums2, mid + 1, q, lowermedianpos);
        else if (nums1[mid] <= nums2[index])
            if (index == 0 || nums1[mid] >= nums2[index - 1])
            {
                lowermedianpos = mid;
                return;
            }
            else
                binaryTraverse(nums1, nums2, mid + 1, q, lowermedianpos);
        else
            binaryTraverse(nums1, nums2, p, mid - 1, lowermedianpos);

    }

    double getMedian(vector<int>& nums1, vector<int>& nums2, int lowermedianpos1)
    {
        if ((nums1.size() + nums2.size()) % 2 == 1)
            return nums1[lowermedianpos1];
        else
            if (lowermedianpos1 == nums1.size() - 1)
                return float(nums1[lowermedianpos1] + nums2[getCorrespondingIndex(nums1, nums2, lowermedianpos1)]) / 2;
            else
                if (getCorrespondingIndex(nums1, nums2, lowermedianpos1) < nums2.size() && getCorrespondingIndex(nums1, nums2, lowermedianpos1) >= 0)
                    return float(nums1[lowermedianpos1] + min(nums1[lowermedianpos1 + 1], nums2[getCorrespondingIndex(nums1, nums2, lowermedianpos1)])) / 2;
                else
                    return float(nums1[lowermedianpos1] + nums1[lowermedianpos1 + 1]) / 2;
    }

    double emptyMedian(vector<int>& nums)
    {
        if (nums.size() % 2 == 1)
            return nums[nums.size() / 2];
        else
            return float(nums[(nums.size()-1) / 2] + nums[((nums.size() -1) / 2) + 1]) / 2;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) return emptyMedian(nums2);
        if (nums2.size() == 0) return emptyMedian(nums1);

        int lowermedianpos1 = -1, lowermedianpos2 = -1;
        binaryTraverse(nums1, nums2, 0, nums1.size() - 1, lowermedianpos1);
        if (lowermedianpos1 == -1)
            binaryTraverse(nums2, nums1, 0, nums2.size() - 1, lowermedianpos2);

        if (lowermedianpos1 == -1)
            return getMedian(nums2, nums1, lowermedianpos2);
        else
            return getMedian(nums1, nums2, lowermedianpos1);
    }
};
