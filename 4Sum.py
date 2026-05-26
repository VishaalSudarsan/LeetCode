class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        collected1= set()
        collected2 = set()
        collection = []
        nums = sorted(nums)
        n = len(nums)
        print(nums)
        for a in range(n):
            for b in range(a+1, n):
                for c in range(b+1, n):
                    d = bisect_left(nums, target - (nums[a] + nums[b] + nums[c]), c+1, n)
                    if d < n and nums[d] == target - (nums[a] + nums[b] + nums[c]) and tuple((a,b,c,d)) not in collected1 and tuple((nums[a],nums[b],nums[c],nums[d])) not in collected2:
                        collection.append([nums[a], nums[b], nums[c], nums[d]])
                        collected1.add(tuple((a,b,c,d)))
                        collected2.add(tuple((nums[a],nums[b],nums[c],nums[d])))
        return collection
