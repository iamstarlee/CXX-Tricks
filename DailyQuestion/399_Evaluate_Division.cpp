// 带权并查集
class UnionFind{
    public:
        vector<int> parent;
        vector<double> weight;
        UnionFind(int val){
            parent.resize(val);
            weight.resize(val);
            iota(parent.begin(), parent.end(), 0);
            for(int i = 0; i < val; i++){
                weight[i] = 1.0;
            }
        }

        void unite(int index1, int index2, double val){
            int root1 = find(index1);
            int root2 = find(index2);
            if(root1 != root2){
                parent[root1] = root2;
                weight[root1] = weight[index2] * val / weight[index1];
            }
        }

        int find(int index){
            if(index != parent[index]){
                int origin = parent[index];
                parent[index] = find(parent[index]);
                weight[index] *= weight[origin];
            }
            return parent[index];
        }

        double isConnected(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY){
                return weight[x] / weight[y];
            }
            else{
                return -1.0;
            }
        }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int equationsSize = equations.size();
        UnionFind uf(2 * equationsSize);
        unordered_map<string, int> hm;

        int idx = 0;
        for(int i = 0; i < equationsSize; i++){
            vector<string> tmp = equations[i];
            string val1 = tmp[0];
            string val2 = tmp[1];

            if(hm.find(val1) == hm.end()){
                hm.emplace(val1, idx);
                idx++;
            }
            if(hm.find(val2) == hm.end()){
                hm.emplace(val2, idx);
                idx++;
            }
            uf.unite(hm[val1], hm[val2], values[i]);
        }

        int queriesSize = queries.size();
        vector<double> res(queriesSize);
        for(int i = 0; i < queriesSize; i++){
            vector<string> tmp = queries[i];
            string val1 = tmp[0];
            string val2 = tmp[1];

            
            if(hm.find(val1) != hm.end() && hm.find(val2) != hm.end()){
                res[i] = uf.isConnected(hm[val1], hm[val2]);
            }
            else{
                res[i] = -1;
            }
            // cout << "id1 is " << id1 << " and id2 is " << id2 << "\n";
           
        }
        return res;
    }
};
