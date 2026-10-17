class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int ind = nums.size() -1;
        for(int i =1 ; i< nums.size() ; i+=2){
            nums[i] = arr[ind];
            ind--;
        }
        for(int i = 0 ; i <nums.size() ; i+=2){
            nums[i] = arr[ind];
            ind--;
        }
        
    }
};