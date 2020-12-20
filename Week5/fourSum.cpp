class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 3; i++) {  //由于有剪枝的break continue操作，所以这里要i++
            if (i > 0 && nums[i] == nums[i - 1]) //判重需要先用过以后再判重，不能发现前后一样就直接用后面，会使后面的变量漏掉对元素的使用
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target)
                continue;
            for (int j = i + 1; j < len - 2; j++) {  //由于有剪枝的break continue操作，所以这里要j++
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) 
                    break;
                if (nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target)
                    continue;
                int left = j + 1, right = len - 1;
                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] < target){
                        left++;
                    }else if (nums[i] + nums[j] + nums[left] + nums[right] > target){
                        right--;
                    }else{
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (nums[left] == nums[++left] && left < right) ;
                        while (nums[right] == nums[--right] && left < right) ;
                    }
                }
                //while (nums[j] == nums[++j] && (j < len - 2)) ;  //这道题判重的操作不能像threeSum那样用while循环，在末尾也通过while去重
            }
            //while (nums[i] == nums[++i] && (i < len - 3));  //这道题判重的操作不能像threeSum那样用while循环，在末尾也通过while去重
        }
        return result;
    }
};