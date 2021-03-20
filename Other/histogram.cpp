//Largest Rectangle in Histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int ans = -1;
        stack<int> s;
        v.push_back(-1);    //ponto de partida
        for(int i = 0; i < v.size(); i++){
            while(!s.empty() && v[i] < v[s.top()]){
                int top = s.top();
                s.pop();
                if(s.empty()) {
                    ans = max(ans, i*v[top]);
                }
                else ans = max(ans, v[top]*(i-1-s.top()));
            }
            s.push(i);
        }
        return ans;
    }
};
