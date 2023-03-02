#ln->length of group.
#st->used for string representation of 'ln'.

class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)
        i,res = 0,0
        while i < n:
            ln = 1
            while (i+ln<len(chars) and chars[i+ln]==chars[i]):
                ln += 1
            chars[res] = chars[i]
            res+=1
            if(ln>1):
                st = str(ln)
                chars[res:res+len(st)] = list(st)
                res+=len(st)
            i+=ln
        return res