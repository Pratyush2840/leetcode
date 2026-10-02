class Solution(object):
    def twoSum(self, numbers, target):
        i = 0
        j = int(len(numbers)-1)
        while i <= j:
            sum = int(numbers[i] + numbers[j])
            if(sum > target):
                j-=1
            elif(sum < target):
                i+=1
            else:
                return [i+1,j+1]
        return [-1,-1]

        