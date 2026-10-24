class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto helper = [&](string date){
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = day;
            for(int i=1; i<month; i++){
                totalDays += daysInMonth[i];
            }
            return totalDays;
        };

        int aliceStart = helper(arriveAlice);
        int aliceEnd = helper(leaveAlice);
        int bobStart = helper(arriveBob);
        int bobEnd = helper(leaveBob);

        int overlap_start = max(aliceStart, bobStart);
        int overlap_end = min(aliceEnd, bobEnd);

        return max(0, overlap_end - overlap_start + 1);
    }
};