class Solution:

    def encode(self, strs: List[str]) -> str:

        #for all strings in the list
        words =''
        for s in strs:
            word = str(len(s)) + '#' + s
            words+= word
        return words



    def decode(self, s: str) -> List[str]:
        decodedStrs = []
        i = 0
        #continue till we reach the end of the string 
        #10neet8code
        while i < len(s):
            j = i
            while s[j] != '#':
                j += 1
            length = int(s[i:j])
            decodedStrs.append(s[j+1:j+1+length])
            i=j+1+length
        return decodedStrs


