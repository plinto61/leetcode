class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, double>> spt(n);
        for(int i=0; i<n; i++) {
            double time = double(target - position[i])/speed[i];
            spt[i] = {position[i], time};
        }
        sort(spt.rbegin(), spt.rend());

        double currentFleetTime = spt[0].second;
        int fleetCount = 1;
        // cout << spt[0].first << "\t" << spt[0].second << "\t" << currentFleetTime << "\t" << fleetCount << endl;
        for(int i=1; i<n; i++) {
            double currectCarTime = spt[i].second;
            if(currectCarTime > currentFleetTime) {
                ++fleetCount;
                currentFleetTime = currectCarTime;
            }
            // cout << spt[i].first << "\t" << spt[i].second << "\t" << currentFleetTime << "\t" << fleetCount << endl;
        }
        return fleetCount;
    }
};