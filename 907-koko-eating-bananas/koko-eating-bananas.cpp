class Solution {
private:
    bool getIsKValid(vector<int>& piles, int k, int h) {
        for(int i=0; i < piles.size(); i++) {
            h -= piles[i]/k;
            if(piles[i]%k > 0) {
                h--;
            }
            if(h < 0) {
                return false;
            }
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = piles[0];
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > max) {
                max = piles[i];
            }
        }

        if (h == piles.size()) {
            return max;
        }

        int low = 1, high = max, min_k = max;
        while (low <= high) {
            int k = low + (high-low)/2;
            int isKValid = getIsKValid(piles, k, h);
            cout << "low: " << low << "\tk: " << k << "\thigh: " << high << endl;
            if(isKValid) {
                high = k-1;
            } else {
                low = k+1;
            }
        }
        return low;
    }
};