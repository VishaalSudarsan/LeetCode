class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        output = True
        inc = 1
        dec = 1
        for i in range(len(nums)-1):
            if inc == 1:
                inc = inc * (nums[i] <= nums[i+1])
            if dec == 1:
                dec = dec * (nums[i] >= nums[i+1])
            if dec == 0 and inc == 0:
                output = False
                break
        return output
