class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string temp = "";
            int count = 0, sum = 0;
            for(char c : s){
                count++;
                sum += (c - '0');
                if(count%k == 0){
                    count = 0;
                    temp += to_string(sum);
                    sum = 0;
                }
            }
            if(count) temp += to_string(sum);
            s = temp;            
        }        
        return s;
    }
};