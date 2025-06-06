class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> ns(n);
        ns[n-1] = s[n-1];
        for(int i=n-2; i>=0; i--)
            ns[i] = min(ns[i+1], s[i]);
        string ans = "";
        stack<char> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() <= ns[i]){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};