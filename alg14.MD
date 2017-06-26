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
#### [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) 

> Given a digit string, return all possible letter combinations that the number could represent.
>
> A mapping of digit to letters (just like on the telephone buttons) is given below.
>
> ![img](http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)
>
> ```
> Input:Digit string "23"
> Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
>
> ```
>
> **Note:**
> Although the above answer is in lexicographical order, your answer could be in any order you want.

```c++
class Solution {
public:
    void combineLetters(string s,string &dig,int n,int len,vector<string> &res){
        string temp;
        switch(dig[n]){
            case '2':temp="abc";break;
            case '3':temp="def";break;
            case '4':temp="ghi";break;
            case '5':temp="jkl";break;
            case '6':temp="mno";break;
            case '7':temp="pqrs";break;
            case '8':temp="tuv";break;
            case '9':temp="wxyz";break;
            default:temp="   ";break;
        }
        for(int i=0;i<temp.length();i++){
            s[n]=temp[i];
            if(len==n+1) res.push_back(s);
            else combineLetters(s,dig,n+1,len,res);
        }        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int len = digits.length();
        if(len==0) return res;
        string st(len,' ');
        combineLetters(st,digits,0,len,res);
        return res;
    }
};//3ms
```

#### [4Sum](https://leetcode.com/problems/4sum/) 

Given an array *S* of *n* integers, are there elements *a*, *b*, *c*, and *d* in *S* such that *a* + *b* + *c* + *d* = target? Find all unique quadruplets in the array which gives the sum of target.

**Note:** The solution set must not contain duplicate quadruplets.

```
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int m=j+1,n=nums.size()-1,tar=target-nums[i]-nums[j];
                while(m<n){
                    if(tar==nums[m]+nums[n]){
                        res.push_back({nums[i],nums[j],nums[m],nums[n]});
                        do m++; while (nums[m] == nums[m - 1] && m < n);
					    do n--; while (nums[n] == nums[n + 1] && m < n);
                    }else{
                        if(tar>nums[m]+nums[n]) m++;
                        else n--;
                    }
                }
            }
        }
        return res;
    }
};//23ms
```

```c++
//别人家代码，多了判断情况>target和<target，居然快了这么多！
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector<pair<int,int>>> twosums;
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 3; i++) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (nums[i] + 3 * nums[n - 1] < target) continue;
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            for(int j = i + 1; j < n - 2; j++) {
                int sum = nums[i] + nums[j];
                if (sum + nums[j + 1] + nums[j + 2] > target) break;
                if (sum + nums[n - 2] +nums[n - 1] < target) continue;
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                int l = j + 1, r = n - 1;
                while(l < r) {
                    int foursum = nums[l] + nums[r] + sum;
                    if (foursum < target)
                        l++;
                    else if (foursum > target)
                        r--;
                    else {
                        res.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                        while(nums[l - 1] == nums[l]) l++;
                        while(nums[r + 1] == nums[r]) r--;
                    }
                }
            }
        }
        return res;
    }
};//9ms
```

#### [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) 

> Given a linked list, remove the *n*th node from the end of list and return its head.
>
> For example,
>
> ```
>    Given linked list: 1->2->3->4->5, and n = 2.
>
>    After removing the second node from the end, the linked list becomes 1->2->3->5.
>
> ```
>
> **Note:**
> Given *n* will always be valid.
> Try to do this in one pass.

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode *first=head,*second;
        // int i=0;
        while(--n){
            first = first->next;
            // i++;
        }
        if(first->next!=NULL){
            first = first->next;
            second = head;
            // i++;
        }else{
            second = head->next;
            delete head;
            return second;
        }
        while(first->next!=NULL){
            first=first->next;
            second=second->next;
            // i++;
        }
        // ListNode *temp = second->next;
        second->next = second->next->next;
        // delete temp;
        return head;
    }
};//9ms
```

```c++
//别人家的代码,通过在head前加入新节点来排除特殊情况    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* fast = new ListNode(0);
        fast->next = head;
        head = fast;
        ListNode* slow = head;
        
        for(int i = 0; i < n; i++){
            if(head==NULL)
                return NULL;
            head = head->next;    
        }
        
        while(head!= NULL &&head->next != NULL ){
            slow = slow->next;
            head = head->next;
        }
  
        
        slow->next = slow->next->next;
        
        return fast->next;
    }//3ms
```
#### [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) 

> Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.
>
> The brackets must close in the correct order, `"()"` and `"()[]{}"` are all valid but `"(]"` and `"([)]"` are not.

```c++
class Solution {
public:
    bool isValid(string s) {
        int i=0,size=s.length();
        if(size%2!=0) return false;
        //vector<char> str = {'(',')','{','}','[',']'};
        stack<char> schar;
        while(i<size){
            switch(s[i]){
                case '(':
                    schar.push('(');
                    i++;
                    break;
                case ')':
                    i++;
                    if(!schar.empty()&&schar.top()=='(') schar.pop();
                    else return false;
                    break;
                case '{':
                    schar.push('{');
                    i++;
                    break;
                case '}':
                    i++;
                    if(!schar.empty()&&schar.top()=='{') schar.pop();
                    else return false;
                    break;
                case '[':
                    schar.push('[');
                    i++;
                    break;
                case ']':
                    i++;
                    if(!schar.empty()&&schar.top()=='[') schar.pop();
                    else return false;
                    break;
                default: return false;
            }
        }
        return schar.empty();
    }
};//3ms
```

#### [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists)   

> Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *res = new ListNode(0);
        ListNode *head=res;
        while(l1&&l2){
            if(l1->val<l2->val){
                head->next = new ListNode(l1->val);
                l1=l1->next;
            }else{
                head->next = new ListNode(l2->val);
                l2=l2->next;
            }
            head = head->next;
        }
        if(l1){
            // head->next = new ListNode(l1->val);//居然慢了。。。
            // l1=l1->next;
            // head = head->next;
            head->next = l1;
        }
        if(l2){
            // head->next = new ListNode(l2->val);
            // l2=l2->next;
            // head = head->next;
            head->next = l2;
        }
        return res->next;
        
    }
};//13ms
```
#### [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) 

> Given *n* pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
>
> For example, given *n* = 3, a solution set is:
>
> ```
> [
>   "((()))",
>   "(()())",
>   "(())()",
>   "()(())",
>   "()()()"
> ]
> ```

```c++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0) return res;

        string curr(2*n, ' ');
        generateParenthesis(n, res, curr, 0, 0);

        return res;
    }

    void generateParenthesis(int n, vector<string>& res, string& curr, int left, int right) {
        if (left + right >= 2 * n) {
            res.push_back(curr);
            return;
        }

        if (left < n) {
            curr[left+right] = '(';
            generateParenthesis(n, res, curr, left+1, right);
        }

        if (left > right) {
            curr[left+right] = ')';
            generateParenthesis(n, res, curr, left, right+1);
        }
    }
};
```

```c++
//别人家的代码
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0) return res;

        string curr(2*n, ' ');
        generateParenthesis(n, res, curr, 0, 0);

        return res;
    }

    void generateParenthesis(int n, vector<string>& res, string& curr, int left, int right) {
        if (left + right >= 2 * n) {
            res.push_back(curr);
            return;
        }

        if (left < n) {
            curr[left+right] = '(';
            generateParenthesis(n, res, curr, left+1, right);
        }

        if (left > right) {
            curr[left+right] = ')';
            generateParenthesis(n, res, curr, left, right+1);
        }
    }
};
```

#### [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) 

> Merge *k* sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = new ListNode(0);
        int size = lists.size();
        vector<int> nums;
        for(int i=0;i<size;i++){
            while(lists[i]!=NULL){
                nums.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        sort(nums.begin(),nums.end());
        ListNode *head = res;
        for(int i=0;i<nums.size();i++){
            head->next=new ListNode(nums[i]);
            head = head->next;
        }
        return res->next;
    }
};//29ms
```

```c++
//别人家的代码
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergeKLists(lists, 0, lists.size());
    }
private:
    ListNode *mergeKLists(vector<ListNode *> &lists, int beg, int end){
        if(end - beg == 1) return lists[beg];   //only one list
        int mid = beg + (end - beg)/2;
        ListNode *l1 = mergeKLists(lists, beg, mid);    //merge list among[beg, mid)
        ListNode *l2 = mergeKLists(lists, mid, end);    //merge list among[mid, end)
        ListNode prehead(0), *pre = &prehead;
        while(l1 && l2){
            if(l1->val <= l2->val){
                pre->next = l1;
                l1 = l1->next;
            }
            else{
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        pre->next = (l1)? l1: l2;
        return prehead.next;
    }
};//23ms
```