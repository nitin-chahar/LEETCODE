class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int queriesSize = queries.size(), logsSize = logs.size();

        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        vector<pair<int, int>> sortedQueries(queriesSize);
        for(int i=0; i<queriesSize; i++){
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size(), 0);
        unordered_map<int, int> activeServers;
        int left=0, right=0;

        for(int i=0; i<queriesSize; i++){
            int qTime = sortedQueries[i].first;
            int index = sortedQueries[i].second;

            int winStart = qTime-x;
            int winEnd = qTime;
            
            while(right < logsSize && logs[right][1] <= winEnd){
                activeServers[logs[right][0]]++;
                right++;
            }

            while(left < logsSize && logs[left][1] < winStart){
                activeServers[logs[left][0]]--;
                if(activeServers[logs[left][0]] == 0){
                    activeServers.erase(logs[left][0]);
                }
                left++;
            }

            result[index] = n - activeServers.size();
        }

        return result;
    }
};