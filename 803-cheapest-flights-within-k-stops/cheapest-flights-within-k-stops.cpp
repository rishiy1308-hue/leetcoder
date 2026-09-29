class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // {stops, {distance, node}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);

        dist[src] = 0;

        // {stops, {distance, node}}
        pq.push({0, {src, 0}});

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int stops = it.first;
            int node = it.second.first;
            int dis = it.second.second;

            // More than k stops means invalid
            if(stops > k)
                continue;

            for(auto edge : adj[node]) {

                int adjNode = edge.first;
                int edgeW = edge.second;

                if(dis + edgeW < dist[adjNode] && stops <= k) {

                    dist[adjNode] = dis + edgeW;

                    pq.push({
                        stops + 1,
                        {adjNode, dis + edgeW}
                    });
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};