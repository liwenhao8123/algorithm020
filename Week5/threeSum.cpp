class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int cur = 0; cur < length-2; cur++){
            //判重需要先用过以后再判重，不能发现前后一样就直接用后面，会使后面的变量漏掉对元素的使用
            if (cur > 0 && nums[cur] == nums[cur - 1])
                continue;
            if (nums[cur] > 0)  //排序以后如果当前元素大于0，则终止循环
                break;
            int left = cur + 1, right = length - 1;
            while (left < right){
                if (nums[cur] + nums[left] + nums[right] < 0){
                    left++;
                }else if (nums[cur] + nums[left] + nums[right] > 0){
                    right--;
                }else{
                    result.push_back({nums[cur], nums[left], nums[right]});
                    while (nums[left] == nums[++left] && (left < right));
                    while (nums[right] == nums[--right] && (left < right));
                }
            }
            //while (nums[cur] == nums[++cur] && (cur + 1 < nums.size()));
        }
        return result;
    }
};