class Solution(object):
    def maximumSubarraySum(self, nums, k):
        st = set()
        left = 0
        sum = 0
        maxi = 0
        for i in range(len(nums)):
            while(nums[i] in st):
                st.remove(nums[left])
                sum -= nums[left]
                left+=1
            
            st.add(nums[i])
            sum += nums[i]
            if(i - left +1 == k):
                maxi = max(maxi , sum)
                st.remove(nums[left])
                sum-= nums[left]
                left+=1
        
        return maxi


        