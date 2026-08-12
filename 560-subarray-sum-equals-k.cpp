class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevOccurCntMap;
        prevOccurCntMap[0] = 1;
        int n = nums.size(), curSum = 0, lngstCnt = 0;
        for(int i = 0; i < n; i++) {
            curSum += nums[i];
            int rem = curSum - k;
            if(prevOccurCntMap.find(rem) != prevOccurCntMap.end()) {
                lngstCnt += prevOccurCntMap[rem];
            }
            prevOccurCntMap[curSum]++;
        }
        return lngstCnt;
    }
};