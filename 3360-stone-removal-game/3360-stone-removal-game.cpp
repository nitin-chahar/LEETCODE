class Solution {
public:
    bool canAliceWin(int n) {
        bool alice_turn = true;
        int x = 10;
        while(x <= n){
            n -= x;
            x--;
            alice_turn = !alice_turn;
        }
        return !alice_turn;
    }
};