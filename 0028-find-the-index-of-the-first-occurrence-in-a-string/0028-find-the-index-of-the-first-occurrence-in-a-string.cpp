// Brute-Force or Naive or Sliding-Window Method
class Solution {
public:
    int strStr(string haystack, string needle) {
//         int m = haystack.length();
//         int n = needle.length();
        
//         for(int i=0;i<=m-n;i++){
//             for(int j=0;j<n;j++){
//                 if(needle[j]!=haystack[i+j]){
//                     break;
//                 }
//                 if(j == (n-1)){
//                     return i;
//                 }
//             }
//         }
//         return -1;
        return haystack.find(needle);
    }
};