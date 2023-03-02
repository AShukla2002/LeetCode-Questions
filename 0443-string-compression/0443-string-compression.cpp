// ln->length of group.
// st->used for string representation of 'ln'.

class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,res=0;
        while(i<chars.size()){
            int ln = 1;
            while(i+ln<chars.size() && chars[i+ln]==chars[i])
                ln++;
            chars[res++] = chars[i];
            if(ln>1){
                for(char c:to_string(ln)){
                    chars[res++] = c;
                }
            }
            i+=ln;
        }
        return res;
    }
};