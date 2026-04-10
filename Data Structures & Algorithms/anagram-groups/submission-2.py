class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #find frequency of each letter in each word
        #find the matching frequency in the map 
        #append the word to the key list

        anagrams = {}

        for w in strs:
            count = [0] * 26
            for l in w:
                count[ord(l)-ord('a')] += 1
            count = tuple(count)
            if count not in anagrams:
                anagrams[count] = [w]
            else:
                anagrams[count].append(w)

        return list(anagrams.values())
