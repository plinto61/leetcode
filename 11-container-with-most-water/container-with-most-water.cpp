class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int maxVol = 0;
        while(i < j) {
            int vol;
            if(height[i] > height[j]) {
                vol = height[j]*(j-i);
            } else {
                vol = height[i]*(j-i);
            }
            if(vol > maxVol) {
                maxVol = vol;
            }
            if(j-i > 1) {
                if(height[i] > height[j]) {
                    j--;
                } else {
                    i++;
                }
            } else {
                break;
            }
        }
        return maxVol;
    }
};