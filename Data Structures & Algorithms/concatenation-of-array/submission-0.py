class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans = [0]*(2*len(nums))
        for idx, num in enumerate(nums):
            ans[idx] = nums[idx]
            ans[idx+len(nums)] = nums[idx]
        return ans  