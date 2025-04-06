class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        for(int i=0; i < 32; i++) {
            int r = n >> 1;
            if(r*2 != n) {
                count++;
            }
            n = r;
        }
        return count;
    }
};
/*
10101 -> 21
1010 -> 10


10100 -> 20
1010 -> 10
*/