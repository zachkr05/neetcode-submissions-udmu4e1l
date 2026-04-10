class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #O(n)
        frequency = {}
        topElements = [None]*k
        #produce frequency list
        for num in nums:
            if num not in frequency:
                frequency[num] = 1
            else:
                frequency[num] += 1

        for i in range(k):
            topElements[i] = (max(frequency, key=frequency.get))
            frequency.pop(max(frequency, key=frequency.get))
        return topElements

        

        
        