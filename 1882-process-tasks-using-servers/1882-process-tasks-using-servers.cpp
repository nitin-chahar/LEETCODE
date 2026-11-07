class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        long long curr_time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available_servers;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_servers;

        for(int i=0; i<servers.size(); i++){
            available_servers.push({servers[i], i});
        }

        vector<int> result(tasks.size());

        for(int i=0; i<tasks.size(); i++){
            curr_time = max(curr_time, (long long)i);
            while(!busy_servers.empty() && busy_servers.top().first <= curr_time){
                available_servers.push({servers[busy_servers.top().second], busy_servers.top().second});
                busy_servers.pop();
            }

            if(available_servers.empty()){
                curr_time = busy_servers.top().first;
                while(!busy_servers.empty() && busy_servers.top().first == curr_time){
                    available_servers.push({servers[busy_servers.top().second], busy_servers.top().second});
                    busy_servers.pop();
                }
            }

            auto best_server = available_servers.top();
            available_servers.pop();

            result[i] = best_server.second;
            busy_servers.push({curr_time + tasks[i], best_server.second});
        }
        return result;
    }
}; 