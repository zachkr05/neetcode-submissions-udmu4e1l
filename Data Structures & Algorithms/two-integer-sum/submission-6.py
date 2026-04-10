class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        target_to_num = defaultdict()

        for idx, num in enumerate(nums):
            temp_target = target-num
            if temp_target in target_to_num:
                return [target_to_num[temp_target], idx]
            target_to_num[num] = idx
