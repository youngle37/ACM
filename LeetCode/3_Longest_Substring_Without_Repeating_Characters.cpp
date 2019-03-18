class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> hash;
        int start = 0;
        int ans = 0;
        
        for(int i=0; i<s.size(); i++){
            if(hash.find(s[i]) != hash.end()){
                start = max(hash.find(s.at(i))->second, start);
            }
            ans = max(ans, i-start+1);
            hash[s[i]] = i+1;
        }

        return ans;
    }
};
