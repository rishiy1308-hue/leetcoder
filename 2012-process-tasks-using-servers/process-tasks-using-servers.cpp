class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // Available servers: {weight, {index, 0}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > available;

        // Busy servers: {freeTime, {weight, index}}
        priority_queue<
            pair<long long, pair<int,int>>,
            vector<pair<long long, pair<int,int>>>,
            greater<pair<long long, pair<int,int>>>
        > busy;

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        // Initially, all servers are available
        for(int i = 0; i < n; i++) {
            available.push({servers[i], {i, 0}});
        }

        long long time = 0;

        for(int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            // Release all servers that have completed their tasks
            while(!busy.empty() && busy.top().first <= time) {

                auto p = busy.top();
                busy.pop();

                int weight = p.second.first;
                int index = p.second.second;

                available.push({weight, {index, 0}});
            }

            // If no server is available, wait
            if(available.empty()) {

                time = busy.top().first;

                // Release all servers that become free at this time
                while(!busy.empty() && busy.top().first <= time) {

                    auto p = busy.top();
                    busy.pop();

                    int weight = p.second.first;
                    int index = p.second.second;

                    available.push({weight, {index, 0}});
                }
            }

            // Choose the server with minimum weight and index
            auto p = available.top();
            available.pop();

            int weight = p.first;
            int index = p.second.first;

            ans[i] = index;

            // Mark this server as busy
            busy.push({time + tasks[i], {weight, index}});
        }

        return ans;
    }
};