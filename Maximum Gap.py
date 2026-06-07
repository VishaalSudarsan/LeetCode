class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        
        size = len(nums)
        upperbound = max(nums)
        lowerbound = min(nums)
        if size < 2 or upperbound == lowerbound:
            return 0

        bucket = {index : {"maxVal" : None, "minVal" : None} for index in range(size)}
        
        index_calc = lambda x: int( (size - 1) * (x - lowerbound) / (upperbound - lowerbound ))

        for x in nums:
            x_index = index_calc(x)
            
            if bucket[x_index]["minVal"] is None:
                bucket[x_index]["minVal"] = x
            else:
                bucket[x_index]["minVal"] = min(bucket[x_index]["minVal"], x)
            
            if bucket[x_index]["maxVal"] is None:
                bucket[x_index]["maxVal"] = x
            else:
                bucket[x_index]["maxVal"] = max(bucket[x_index]["maxVal"], x)

        MaxGap = 0
        MaxPrevious = None
        for index in range(size):
            if bucket[index]["minVal"] is None or bucket[index]["maxVal"] is None:
                continue
            else:
                if MaxPrevious is None:
                    MaxPrevious = bucket[index]["minVal"] 
                MaxGap = max(bucket[index]["minVal"] - MaxPrevious, bucket[index]["maxVal"] - bucket[index]["minVal"], MaxGap)
                MaxPrevious = bucket[index]["maxVal"]

        return MaxGap
