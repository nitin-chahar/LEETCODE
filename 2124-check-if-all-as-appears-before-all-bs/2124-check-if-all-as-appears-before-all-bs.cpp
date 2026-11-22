class Solution {
public:
    bool checkString(string s) {
        bool found_b = false;
        for(char c : s){
            if(c == 'b') found_b = true;
            else{
                if(found_b) return false;
            }
        }
        return true;
    }
};