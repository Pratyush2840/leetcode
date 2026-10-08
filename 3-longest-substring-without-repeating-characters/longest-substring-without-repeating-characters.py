class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq = {}
        ans = 0
        left = 0

        for i in range(len(s)):
            idx = s[i]

            while freq.get(idx,0) ==1:
                freq[s[left]] = 0
                left += 1

            freq[idx] = 1
            ans = max(ans, i - left + 1)

        return ans