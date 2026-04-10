class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        frequency = defaultdict(int)
        numbers = [[] for _ in range(len(nums) + 1)]
        for num in nums:
            frequency[num] += 1

        for num, count in frequency.items():
            numbers[count].append(num)

        if k == 1:
            return [max(frequency, key=frequency.get)]

        res = []
        for i in range(len(numbers)-1,0,-1):
            for num in numbers[i]:
                res.append(num)
                if len(res) == k:
                    return res
        