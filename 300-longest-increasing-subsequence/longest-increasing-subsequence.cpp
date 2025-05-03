class Solution {
private:
    int binarySearch(const vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<int> res;

        // for (int n : nums) {
        //     if (res.empty() || res.back() < n) {
        //         res.push_back(n);
        //     } else {
        //         int idx = binarySearch(res, n);
        //         res[idx] = n;
        //     }
        //     for (int r : res) {
        //         cout << r << "\t";
        //     }
        //     cout << endl;
        // }

        // return res.size();
        vector<int> asc;
        for (int n : nums) {
            if (asc.empty() || asc.back() < n) {
                asc.push_back(n);
            } else {
                // replace the number in asc that is just bigger than n
                for(int i=0; i<asc.size(); i++) {
                    if(asc[i] >= n) {
                        asc[i] = n;
                        break;
                    }
                }
            }
            // for (int j = 0; j < asc.size(); j++) {
            //     cout << asc[j] << "\t";
            // }
            // cout << endl;
        }
        return asc.size();
    }
};
/*
0   1   2   3   4   5   6   7
10  9   2   5   3   7   101 18

*/