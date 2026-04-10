class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        

        frequency = {}
        #loop thru the array
        #map the number to their frequency
        for num in nums:
            if num not in frequency:
                frequency[num] = 1
            else:
                frequency[num] += 1


        sorted_keys = [key for key, value in sorted(frequency.items(), key=lambda item: item[1], reverse=True)]


        return list(sorted_keys)[:k]

        
        