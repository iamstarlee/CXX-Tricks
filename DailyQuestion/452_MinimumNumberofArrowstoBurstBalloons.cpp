// 对sort函数排序cmp的重写
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()){
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v){return u[1] < v[1];});
        int pos = points[0][1];
        int ans = 1;
        for(const vector<int>& ballon : points){
            if(ballon[0] > pos){
                ans++;
                pos = ballon[1];
            }
        }
        return ans;
    }
};
