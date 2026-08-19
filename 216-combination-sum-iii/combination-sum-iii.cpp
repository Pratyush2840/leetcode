class Solution {
public:
    vector<vector<int>> ans;
    void f(int ind , int step ,int target ,vector<int>temp){
        if(step==0 && target == 0){
            ans.push_back(temp);
            cout<<"dfdf"<<endl;
            return;
        }
        if(ind <= 0) return;
        f(ind-1 , step , target , temp);
        temp.push_back(ind);
        //cout<<temp.back()<<" ";
        f(ind-1 , step-1 ,target-ind ,temp);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> dp;
        vector<int>temp;
        f(9 , k,n,temp);
        return ans;
    }
};