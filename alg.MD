### LEETCODE

#### [Two Sum](https://leetcode.com/problems/two-sum/) 

> Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.
>
> You may assume that each input would have **exactly** one solution, and you may not use the *same* element twice.
>
> **Example:**
>
> ```
> Given nums = [2, 7, 11, 15], target = 9,
>
> Because nums[0] + nums[1] = 2 + 7 = 9,
> return [0, 1].
> ```

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> res(2);
        bool isok = false;
        for (size_t i = 0; i < nums.size()-1; i++) {
   
            res[0] = i;
            for (size_t j = i+1; j < nums.size(); j++) {
      
              if(nums[i]+nums[j]==target){
                res[1] = j;
                isok = true;
                break;
              }
            }
            if(isok)
              break;
        }
        return res;
    }
};//126ms
```

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //std::vector<int> res(2);
        int t;
        for (size_t i = 0; i < nums.size()-1; i++) {
   
            //res[0] = i;
            t = target - nums[i];
            for (size_t j = i+1; j < nums.size(); j++) {
      
              if(nums[j]==t){
                //res[0] = i;
                //res[1] = j;
                //vector<int> res = {i,j};
                return {i,j};
              }
            }
        }
        return {0,0};
    }
};//86ms
```

```c++
//别人家的代码（hashmap）
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind] + 1);
			result.push_back(i + 1);			
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}
```

#### [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) 

> You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
>
> You may assume the two numbers do not contain any leading zero, except the number 0 itself.
>
> **Input:** (2 -> 4 -> 3) + (5 -> 6 -> 4)
> **Output:** 7 -> 0 -> 8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add,sign=0;
        add = l1->val+l2->val+sign;
        ListNode* res = new ListNode(add%10);
        sign = add/10;
        ListNode* todo = res;
        // l1 = l1->next;
        // l2 = l2->next;
        while(l1->next!=NULL&&l2->next!=NULL){
            l1 = l1->next;
            l2 = l2->next;
            add = l1->val+l2->val+sign;
            //ListNode *t = new ListNode(add%10+sign);
            todo->next = new ListNode(add%10);
            sign = add/10;
            //t->next=NULL;
            //todo->next = t;
            todo = todo->next;

        }
        while(l1->next!=NULL){
            l1 = l1->next;
            add = l1->val+sign;
            todo->next = new ListNode(add%10);
            todo = todo->next;
            sign=add/10;
        }
        while(l2->next!=NULL){
            l2 = l2->next;
            add = l2->val+sign;
            todo->next = new ListNode(add%10);
            todo = todo->next;
            sign=add/10;
        }
        if(sign){
            todo->next = new ListNode(sign);
            todo = todo->next;
        }
        todo->next=NULL;
        return res;
    }
};//92ms
```

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sign=0;
        ListNode* res = l1;
        l1->val = l1->val + l2->val + sign;
        sign = l1->val/10;
        l1->val = l1->val%10;
        while(l1->next!=NULL){
            if(l2->next!=NULL){
                l1=l1->next;
                l2=l2->next;
                l1->val = l1->val + l2->val +sign;
                sign = l1->val/10;
                l1->val = l1->val%10;
            }else{
                l1=l1->next;
                l1->val = l1->val + sign;
                sign = l1->val/10;
                l1->val=l1->val%10;
            }
        }
        if(l2->next!=NULL){
            l1->next = l2->next;
            while(l1->next!=NULL){
                l1=l1->next;
                l1->val = l1->val + sign;
                sign = l1->val/10;
                l1->val=l1->val%10;
            }
        }
        if(sign){
            l1->next = new ListNode(1);
        }
        return res;
        
    }
};//55ms
```
```c++
//别人家的代码
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}
```

#### [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters)  

> Given a string, find the length of the **longest substring** without repeating characters.
>
> **Examples:**
>
> Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.
>
> Given `"bbbbb"`, the answer is `"b"`, with the length of 1.
>
> Given `"pwwkew"`, the answer is `"wke"`, with the length of 3. Note that the answer must be a **substring**, `"pwke"` is a *subsequence* and not a substring.

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length(),max=0,index=0,i=0;
        set<char> cset;
        for(;i<length;i++){
            if(cset.insert(s[i]).second==false){
                if(max<i-index)
                    max = i-index;
              	index = s.rfind(s[i],i-1);//-20ms
                i = index;
                index++;
                cset.clear();
            }
        }
        if(i==length){
            if(max<i-index)
                max = i-index;
        }
        return max;
    }
};//329ms
```
```c++
//别人家的代码
int lengthOfLongestSubstring(string s) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
      if (dict[s[i]] > start)
        start = dict[s[i]];
      dict[s[i]] = i;
      maxLen = max(maxLen, i - start);
    }
    return maxLen;
}
```