#### [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs)   

> Given a linked list, swap every two adjacent nodes and return its head.
>
> For example,
> Given `1->2->3->4`, you should return the list as `2->1->4->3`.
>
> Your algorithm should use only constant space. You may **not** modify the values in the list, only nodes itself can be changed.

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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode *res = new ListNode(0);
        res->next = head;
        head = res;
        ListNode *first,*second,*last;
        while(first=head->next){
            if(second=head->next->next){
                last=second->next;
                head->next = second;
                second->next = first;
                first->next = last;
                head = first;
            }else{
                return res->next;
            }
        }
        return res->next;
    }
};
```

#### [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group)   

> Given a linked list, reverse the nodes of a linked list *k* at a time and return its modified list.
>
> *k* is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of *k* then left-out nodes in the end should remain as it is.
>
> You may not alter the values in the nodes, only nodes itself may be changed.
>
> Only constant memory is allowed.
>
> For example,
> Given this linked list: `1->2->3->4->5`
>
> For *k* = 2, you should return: `2->1->4->3->5`
>
> For *k* = 3, you should return: `3->2->1->4->5`

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode *res=new ListNode(0);
        res->next = head;
        stack<ListNode*> nodes;
        ListNode *temp,*last=head;
        int count;
        head = res;
        while(temp=head->next){
            count=k;
            while(count--){
                nodes.push(temp);
                temp=temp->next;
                if(temp==NULL&&nodes.size()!=k) return res->next;
            }
            while(nodes.size()){
                head->next=nodes.top();
                head = head->next;
                nodes.pop();
            }
            head->next=temp;
        }               
        return res->next;
    }
};//36ms
```

```c++
//别人家的代码 18ms
    ListNode *reverseNextK(ListNode *head, int k) {
        if (head == NULL) {
            return NULL;
        }
        // Check if there is enough nodes to reverse
        ListNode *next = head;
        for (int i = 0; i < k; ++i) {
            if (next->next == NULL) {
                return next;
            }
            next = next->next;
        }
        // Reverse the next K nodes
        ListNode *n1 = head->next;
        ListNode *prev = NULL;
        ListNode *cur = n1;
        for (int i = 0; i < k; ++i) {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        n1->next = cur;
        head->next = prev;
        return n1;
    }
    /**
     * @param head a ListNode
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || k <= 1) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        while (head->next != NULL) {
            head = reverseNextK(head, k);
        }
        return dummy.next;
    }
```

#### [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array) 

> Given a sorted array, remove the duplicates in place such that each element appear only *once* and return the new length.
>
> Do not allocate extra space for another array, you must do this in place with constant memory.
>
> For example,
> Given input array *nums* = `[1,1,2]`,
>
> Your function should return length = `2`, with the first two elements of *nums* being `1` and `2` respectively. It doesn't matter what you leave beyond the new length.

```c++
class Solution {//需要修改原数据，前length个为无重复的
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int res=1;
        for(int i=1;i<nums.size();i++){
            if(nums[res-1]!=nums[i]){
                res++;
                nums[res-1] = nums[i];
            }
        }
        return res;
    }
};//36ms
```

```c++
//别人家代码 22ms
    int removeDuplicates(vector<int>& nums) {
        int temp=0, count=1;
        if(nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        count = i+1;
        /*temp = nums[0];
        for(int i=0; i<nums.size(); i++) {
            if(temp!=nums[i]) {
                count++;
                temp = nums[i];
            }
        }*/
        return count;
    }
```

#### [Remove Element](https://leetcode.com/problems/remove-element)   

> Given an array and a value, remove all instances of that value in place and return the new length.
>
> Do not allocate extra space for another array, you must do this in place with constant memory.
>
> The order of elements can be changed. It doesn't matter what you leave beyond the new length.
>
> **Example:**
> Given input array *nums* = `[3,2,2,3]`, *val* = `3`
>
> Your function should return length = 2, with the first two elements of *nums* being 2.

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()<1) return 0;
        int res=1;
        if(nums[0]==val) res=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=val){
                nums[res++]=nums[i];
            }
        }
        return res;
    }
};
```

```c++
    int removeElement(vector<int>& nums, int val) {
        
        int shift = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == val)
               ++shift;
            //else if (shift > 0)
            else
               nums[i - shift] = nums[i];
        }
        return nums.size() - shift;//可以考虑两个变量控制区间
        
    }//3ms tong
```



#### [Implement strStr()](https://leetcode.com/problems/implement-strstr)   

> Implement strStr().
>
> Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        else if(haystack=="") return -1;
        int i=0,j,step=haystack.length()-needle.length()+1;
        while(i<step){
            for(j=0;j<needle.length();j++){
                if(haystack[j+i]!=needle[j])
                    break;
            }
            if(j==needle.length()) return i;
            i++;
        }
        return -1;
    }
};//6ms
```

```c++
  //别人家的代码 3ms
  int strStr(string haystack, string needle) {
        if (haystack.empty() || needle.empty()) {
            if (needle.empty()) return 0;
            else return -1;
        }
        else if (haystack.size() < needle.size()) //这个判断可以有
            return -1;

        for (int n = 0; n <= haystack.size()-needle.size(); ++n) {
            if (haystack[n] != needle[0]) continue;

            int i = 0;
            while (i < needle.size()) {
                if (haystack[n+i] != needle[i]) break;
                ++i;
            }
            if (i == needle.size()) return n;
        }
        return -1;
    }
```

#### [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) 

> Divide two integers without using multiplication, division and mod operator.
>
> If it is overflow, return MAX_INT.

```c++
class Solution {
public:
    typedef struct{
        int step;
        int value;
    }steps;
    int divide(int dividend, int divisor) {
        if(divisor==0) return INT_MAX;
        if(divisor==1) return dividend;
        if(divisor==-1) return (dividend==INT_MIN)?INT_MAX:-dividend;
        if(dividend==0) return 0;
        int res=0,pos=-1;
        vector<steps> steps_v;
        bool sign=(dividend^divisor)<0;
        if(dividend>0) dividend=-dividend;
        if(divisor>0) divisor=-divisor;
        steps_v.push_back({1,divisor});
        while(dividend<=divisor){
            if(dividend<steps_v[steps_v.size()-1].value&&steps_v[steps_v.size()-1].value>-1000000000){
                    int stemp1= steps_v[steps_v.size()-1].step+steps_v[steps_v.size()-1].step;
                    int stemp2= steps_v[steps_v.size()-1].value+steps_v[steps_v.size()-1].value;
                    steps_v.push_back({stemp1,stemp2});
            }
            for(int i=(pos==-1)?steps_v.size()-1:pos;i>=0;i--){
                // if(pos!=-1) i=pos;
                if(dividend<=steps_v[i].value){
                    dividend-=steps_v[i].value;
                    res+=steps_v[i].step;
                    if(i<steps_v.size()-1)
                        pos=i;
                    break;
                }
            }
        }
        if(sign) return -res;
        else return res;
    }
};
```