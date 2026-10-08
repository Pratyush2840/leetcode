class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        st = set()
        for it in nums:
            if it in st:
                return True
            else:
                st.add(it)
        return False