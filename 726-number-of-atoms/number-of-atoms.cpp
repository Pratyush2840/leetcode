class Solution {
public:
    string countOfAtoms(string formula) {
        map<string , int> mp;
        stack<pair<string,int>> st;
        stack<pair<string,int>> st2;
        int n = formula.size();
        int i =0;
        while(i<n)
        {
            string str = "";
            string count ="";
            //upppercase
            if(formula[i] >= 'A' && formula[i] < 'a'){
                str += formula[i];
                i++;
                //lowercase
                while(formula[i] >='a'){
                    str += formula[i];
                    i++;
                }
                //number
                while(formula[i] >= '0' && formula[i] <= '9'){
                    count += formula[i];
                    i++;
                }
            }
            //bracket
            else if(formula[i] == '('){
                st.push({"(" , 1});
                i++;
            }
            else if(formula[i] == ')'){
                string counts = "";
                i++;
                //number
                while(formula[i] >= '0' && formula[i] <= '9'){
                    counts += formula[i];
                    i++;
                }
                int cnt ;
                if(counts.size() == 0){
                    cnt = 1;
                }
                else{
                    cnt = stoi(counts);
                }
                //push to other stack
                while(!st.empty() && st.top().first != "("){
                    st2.push({st.top().first , (st.top().second * cnt)});
                    st.pop();
                }
                st.pop();
                while(!st2.empty()){
                    st.push({st2.top().first , st2.top().second});
                    st2.pop();
                }
            }
            int cnt;
            if(count.size() == 0){
                cnt = 1;
            }
            else{
                cnt = stoi(count);
            }
            st.push({str , cnt});
        }
        while(!st.empty()){
            mp[st.top().first]+= st.top().second;
            cout<<st.top().first<<" "<<st.top().second<<endl;
            st.pop();
        }
        string ans="";
        for(auto it : mp){
            if(it.first.size() != 0){
                ans+=it.first;
                if(it.second != 1)ans+=to_string(it.second);
            }
        }
        return ans;
    }
    
    
};