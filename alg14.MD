#### [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) 

> Write a function to find the longest common prefix string amongst an array of strings.

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        if(strs.size()==1)
            return strs[0];
        int size = strs.size();
        int j=0;
        int length = strs[0].length();
        while(length--){
            for(int m=1;m<size;m++){
                if(strs[0][j]!=strs[m][j]){
                    return strs[0].substr(0,j);
                }
            }
            j++;
        }
        return strs[0].substr(0,j);
    }
};
```

#### [3Sum](https://leetcode.com/problems/3sum/) 

> Given an array *S* of *n* integers, are there elements *a*, *b*, *c* in *S* such that *a* + *b* + *c* = 0? Find all unique triplets in the array which gives the sum of zero.
>
> **Note:** The solution set must not contain duplicate triplets.
>
> ```
> For example, given array S = [-1, 0, 1, 2, -1, -4],
>
> A solution set is:
> [
>   [-1, 0, 1],
>   [-1, -1, 2]
> ]
> ```

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        int min,mid,max;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) return res;//快了近60ms
            if(i>0&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nums.size()-1;j++){
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                int target = -(nums[i]+nums[j]); 
                min = j+1;max=nums.size();
                while(min<max){
                    mid = (min+max)/2;
                    if(target == nums[mid]){
                        res.push_back({nums[i],nums[j],nums[mid]});
                        break;
                    }
                    else if(target>nums[mid]){
                        min = mid+1;
                    }else
                        max = mid;
                }
            }
        }
        return res;
    }
};//223ms
```
```c++
//别人家的代码
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) return res;
            if(i>0 && nums[i] == nums[i-1]) continue;
            int target = 0-nums[i];
            int k = i+1;
            int j = nums.size()-1;
            while( k < j){
                if(target == nums[k] + nums[j]){
                    res.push_back({nums[i],nums[k],nums[j]});
                    while(k < j && nums[k] == nums[k+1]) k++;
                    while(k < j && nums[j] == nums[j-1]) j--;
                    k++;
                    j--;
                }
                else if(target > nums[k] + nums[j])
                    k++;
                else
                    j--;
            }            
        }
        return res;
    }    
};
```

#### [3Sum Closest](https://leetcode.com/problems/3sum-closest/) 

> Given an array *S* of *n* integers, find three integers in *S* such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
>
> ```
>     For example, given array S = {-1 2 1 -4}, and target = 1.
>
>     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
> ```

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int bias=INT_MAX,res;
        int size = nums.size();
        sort(nums.begin(),nums.end());
        int j,k,temp,diff;
        for(int i=0;i<size-2;i++){
            if(i>0&&nums[i]>target) return res;
            j=i+1;
            k=size-1;
            while(j<k){
                temp = nums[i]+nums[j]+nums[k];
                if(temp==target)
                    return target;
                diff = abs(target-temp);//就因为多算一遍abs，125个例子，多了3ms
                if(diff<bias){
                    bias = diff;
                    res = temp;
                }
                if(temp>target)
                    k--;
                else
                    j++;
            }
        }
        return res;
    }
};//6ms
```