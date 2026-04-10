class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        word1 = dict()
        word2 = dict()

        for n in s:
            if n in word1:
                word1[n]+=1
            else:
                word1[n]=1

        for i in t:
            if i in word2:
                word2[i]+=1
            else:
                word2[i]=1


        return word1 == word2
