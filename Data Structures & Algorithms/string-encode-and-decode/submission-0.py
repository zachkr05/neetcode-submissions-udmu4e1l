class Solution:

    def encode(self, strs: List[str]) -> str:
        finalSTR = ""
        
        for word in strs:
            wordLength = str(len(word))
            finalSTR += wordLength +"#"+ word

        return finalSTR

    def decode(self, s: str) -> List[str]:

        decodedList = []
        i=0
        while i < len(s):
            #find the delimiter
            j = s.index('#', i)
            #extract the length
            length = int(s[i:j])
            decodedList.append(s[j+1 : j+1+length])
            i= j+length+1

        return decodedList

