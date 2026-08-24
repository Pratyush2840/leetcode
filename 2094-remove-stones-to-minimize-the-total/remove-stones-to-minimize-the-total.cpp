class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i =0;i<piles.size() ; i++){
            pq.push(piles[i]);
        }
        while(k>0){
            int temp = pq.top();
            //cout<<temp<<" ";
            pq.pop();
            temp = (temp +1) /2;
            //cout<<temp<<endl;
            pq.push(temp);
            k--;
        }
        int ans =0;
        while(!pq.empty()){
            int z = pq.top(); pq.pop();
            //cout<<z<<endl;
            ans+=z;
        }
        return ans;
    }
};