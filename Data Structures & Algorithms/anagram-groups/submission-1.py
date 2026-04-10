class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        #map each word to their alphabetically sorted arrangement
        #compare their alphabetically sorted arrangement 

        sortedWords = {}
        for word in strs:
            key = ''.join(sorted(word))
            if not key in sortedWords:
                sortedWords[key] =[word]
            else:
                sortedWords[key].append(word)
        result = list(sortedWords.values())
        return result
