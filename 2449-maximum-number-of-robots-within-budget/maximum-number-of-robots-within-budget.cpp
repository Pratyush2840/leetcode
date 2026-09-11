class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes,vector<int>& runningCosts,long long budget) {
        int n = chargeTimes.size();
        vector<int> q(n);
        int front = 0;
        int back = 0;

        long long sum = 0;
        int left = 0;
        int ans = 0;

        for(int right = 0; right < n; right++) {

            sum += runningCosts[right];
            //cout<<sum<<" "<<endl;
            while(front < back &&
                  chargeTimes[q[back - 1]] <= chargeTimes[right]) {
                back--;
            }

            q[back++] = right;
            while(front < back &&chargeTimes[q[front]] +(right - left + 1) * sum > budget) {

                if(q[front] == left)
                    front++;

                sum -= runningCosts[left];
                left++;
            }

            ans = max(ans, right - left + 1);
            //cout<<ans<<" "<<endl;
        }

        return ans;
    }
};