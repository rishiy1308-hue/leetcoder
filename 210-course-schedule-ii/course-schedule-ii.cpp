class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];
            adj[prerequisite].push_back(course);
        }
        vector<int> inDegree(numCourses);
        for(int i = 0;i<adj.size();i++){
            for(auto it: adj[i]){
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0;i<inDegree.size();i++){
            if(inDegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)q.push(it);
            }
        }
        if(topo.size() != numCourses) return {};
    
        return topo;
    }
};