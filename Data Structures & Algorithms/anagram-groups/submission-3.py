class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        if len(strs) == 1:
            return [strs]
        
        groups = defaultdict(list)

        for idx, word in enumerate(strs):
            count_char = [0] * 26
            for c in word:
                count_char[ord(c) - ord('a')] +=1
            groups[tuple(count_char)].append(word)

        return list(groups.values())

        
            



