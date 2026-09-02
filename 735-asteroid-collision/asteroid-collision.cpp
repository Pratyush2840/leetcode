class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int it : asteroids) {
            bool alive = true;

            while (alive && !st.empty() && st.top() > 0 && it < 0) {

                if (st.top() < -it) {
                    st.pop();
                }
                else if (st.top() == -it) {
                    st.pop();
                    alive = false;
                }
                else {
                    alive = false;
                }
            }

            if (alive)
                st.push(it);
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};