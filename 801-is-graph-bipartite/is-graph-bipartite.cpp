class Solution {
public:
    bool isCheck(vector<vector<int>>& graph,vector<int>& color,int start,queue<int> q){
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
     int n = graph.size();
    vector<int> color(n,-1);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(isCheck(graph,color,i,q)==false) return false;
        }
    }
    return true;
    }
};