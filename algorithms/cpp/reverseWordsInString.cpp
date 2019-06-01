class Solution {
public:
    string reverseWords(string s) {
        
        std::vector<std::string> strs;
        auto pos = s.begin();
        auto wordStart = pos;
        auto wordEnd = pos;
        
        while(wordStart != s.end())
        {
            while(*wordStart == ' ')
                wordStart++;
        
            if(wordStart == s.end())
                break;
            
            wordEnd = wordStart;

            while(wordEnd != s.end() && *wordEnd != ' ')
                wordEnd++;

            strs.push_back(s.substr(wordStart-s.begin(),wordEnd-wordStart));
            
            wordStart = wordEnd;
        }
        
        std::string res;
              
        for(int i = strs.size()-1 ; i != -1;i--)
        {
           res += strs[i];
           if(i != 0)
               res += ' ';
        }
        
        return res;
    }
};
