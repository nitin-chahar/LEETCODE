class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> request_counts(k, 0);

        set<int> available;

        for(int i=0; i<k; i++){
            available.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;

        for(int i=0; i<arrival.size(); i++){
            int start_time = arrival[i];
            int duration = load[i];

            while(!busy.empty() && busy.top().first <= start_time){
                available.insert(busy.top().second);
                busy.pop();
            }

            if(available.empty()) continue;

            int preferred_id = i % k;
            auto it = available.lower_bound(preferred_id);

            if (it == available.end()) {
                it = available.begin();
            }

            int server_to_use = *it;
            available.erase(it);

            request_counts[server_to_use]++;
            busy.push({start_time + duration, server_to_use});
        }

        int max_requests = *max_element(request_counts.begin(), request_counts.end());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_counts[i] == max_requests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};