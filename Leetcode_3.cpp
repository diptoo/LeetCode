class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int cnt=0, maxy=0;
        map<int,int>mp;
        for(int i=0;i<len;i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                cnt = i - mp[s[i]];
            }
            else
            {
                cnt++;
            }
            if(cnt>maxy)
            {
                maxy = cnt;
            }
            mp[s[i]] = i;
        }
        return maxy;
    }
};