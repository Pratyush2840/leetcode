class Solution:
    def isPalindrome(self, s: str) -> bool:
        ans = ""
        for c in s:
            ch = c.lower()
            if ('a' <= ch <= 'z') or ('0' <= ch <= '9'):
                ans += ch
        i = 0
        j = len(ans) - 1
        while i < j:
            if ans[i] != ans[j]:
                return False
            i += 1
            j -= 1
        return True