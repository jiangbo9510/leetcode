//from https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/submissions/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int start = 0, end = 0;
        int maxLength = 1;
        for(int i = 1;i != s.length();++i)
        {
            int repetitionFlag = false;
            
            for(int j = start;j <= end;j++)
            {
                if(s[j] == s[i])
                {
                    int length = end - start + 1;
                    maxLength = (maxLength < length?length:maxLength);
                    start = j + 1;
                    repetitionFlag = true;
                    break;
                }
            }

            end = i;
            //if compare the last char,and is not repetition. judge the max lengrth again
            if(i == s.length()-1 && repetitionFlag == false)
            {
                    int length = end - start + 1;
                    maxLength = (maxLength < length?length:maxLength);      
            }
            
        }
        
        return maxLength;
    }
};
