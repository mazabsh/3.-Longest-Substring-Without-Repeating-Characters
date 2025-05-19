#include<iostream> 
#include<vector> 
#include<string> 
#include<unordered_map> 
#include<algorithm> 

using namespace std; 

class Solution{
public: 
      int lengthOfLongestSubstring(string s){
        int maxLen=0; 
        unordered_map<char, int> mp; 
        int left = 0; 
        for(int right=0; right<s.size(); ++right){
          char current = s[right]; 
          if(mp.find(current)!=mp.end() && mp[current]>=left) left = mp[current] +1; 
          mp[current] = right; 
          maxLen = max(maxLen, right-left+1); 
        }
        return maxLen; 
      }
};
int main(){
  string s = "abcabcbb"; 
  Solution sol; 
  int ans = sol.lengthOfLongestSubstring(s); 
  cout << "the longthest substring with unique character: " << ans << endl; 
  return 0; 
}
