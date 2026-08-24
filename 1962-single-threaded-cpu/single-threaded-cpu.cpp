class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();
        vector<int> index(n);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> time;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> job;

        for(int i = 0; i < n; i++) {
            index[i] = i;
            time.push({tasks[i][0], tasks[i][1], i});
        }
        vector<int> ans;
        auto temp = time.top();
        time.pop();
        long long samay = get<0>(temp) + get<1>(temp);
        ans.push_back(get<2>(temp));
        while(!time.empty() || !job.empty()) {
            while(!time.empty() && get<0>(time.top()) <= samay) {

                auto task = time.top();
                time.pop();

                job.push({get<1>(task), get<2>(task)});
            }
            if(job.empty()) {

                auto task = time.top();
                time.pop();

                ans.push_back(get<2>(task));

                samay = get<0>(task) + get<1>(task);
            }
            else {
                auto task = job.top();
                job.pop();

                ans.push_back(task.second);

                samay += task.first;
            }
        }

        return ans;
    }
};