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
#### [Next Permutation](https://leetcode.com/problems/next-permutation/) 

> Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
>
> If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
>
> The replacement must be in-place, do not allocate extra memory.
>
> Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
> `1,2,3` → `1,3,2`
> `3,2,1` → `1,2,3`
> `1,1,5` → `1,5,1`

```c++
class Solution {
public:
    static bool bigger(int l,int r){
        return (l<r);
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2) return;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                int temp,index;
                for(int j=i;j<nums.size();j++){
                    if(nums[j]>nums[i-1]) index=j;
                    else break;
                }
                temp = nums[i-1];
                nums[i-1]=nums[index];
                nums[index]=temp;
                sort(nums.begin()+i,nums.end(),bigger);
                return;
            }
        }
        sort(nums.begin(),nums.end());//完全逆序，reverse效率因此高得多
    }
};//25ms
```

```c++
//别人家的代码
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        vector<int>::reverse_iterator i = is_sorted_until(nums.rbegin(), nums.rend()); 
        if(i != nums.rend()) swap(*i, *upper_bound(nums.rbegin(), i, *i)); // Important! 
        reverse(nums.rbegin(), i);
    }
};//9ms
```
#### [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) 

> Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
>
> (i.e., `0 1 2 4 5 6 7` might become `4 5 6 7 0 1 2`).
>
> You are given a target value to search. If found in the array return its index, otherwise return -1.
>
> You may assume no duplicate exists in the array.

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        //if(nums.size()==1) return (nums[0]==target)?0:-1;
        int left=0,right=nums.size()-1,mid,pivot=0;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]>=nums[0]) left=mid+1;
            else{
                if(mid>0&&nums[mid-1]>=nums[0]){
                    pivot=mid;
                    break;
                }
                right=mid-1;
            }
        }
        left=0;right=nums.size()-1;
        //cout<<pivot<<endl;
        if(pivot!=0){
            if(nums[nums.size()-1]>=target) left = pivot;
            else right = pivot-1;
        }
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};//6ms
```

```c++
//别人家的代码,不进行pivot的查找，直接针对target
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h = nums.size();
        int l = 0;
        while(h>l){
            int mid = (h+l)/2;
                //     double num = (nums[mid] < nums[0]) == (target < nums[0])
                //   ? nums[mid]
                //   : target < nums[0] ? -INFINITY : INFINITY;

            double num = ((nums[0]<=nums[mid]) == (nums[0]<=target))? nums[mid]: target<nums[0]? -INFINITY:INFINITY;
            if(target<num){
                h = mid;
            }
            else if(target>num){
                l = mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
        
    }
};//3ms
```

#### [Search for a Range](https://leetcode.com/problems/search-for-a-range/) 

> Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
>
> Your algorithm's runtime complexity must be in the order of *O*(log *n*).
>
> If the target is not found in the array, return `[-1, -1]`.
>
> For example,
> Given `[5, 7, 7, 8, 8, 10]` and target value 8,
> return `[3, 4]`.

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        //if(nums.empty()) return res;
        int left=0,right=nums.size()-1,mid;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target){
                //cout<<"ok"<<endl;
                left=right=mid;
                while(left>=0&&nums[left]==target) left--;
                while(right<nums.size()&&nums[right]==target) right++;
                //cout<<left<<" "<<right<<endl;
                //for(int i=left+1;i<right;i++) res.push_back(i);
                return {left+1,right-1};
            }else if(nums[mid]>target) right=mid-1;
            else left = mid+1;
        }
        return {-1,-1};
    }
};//9ms
```

#### [Search Insert Position](https://leetcode.com/problems/search-insert-position/) 

> Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
>
> You may assume no duplicates in the array.
>
> Here are few examples.
> [1,3,5,6], 5 → 2
> [1,3,5,6], 2 → 1
> [1,3,5,6], 7 → 4
> [1,3,5,6], 0 → 0
>

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        if(nums[0]>=target) return 0;
        int left=0,right=nums.size()-1,mid;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]<target) left=mid+1;
            else if(nums[mid]>target) right = mid-1;
            else return mid;
        }
        return (nums[mid]>target)?mid:mid+1;
    }
  /*
         int low = 0;
         int high = nums.size()-1;
         
         while(low<=high)
         {
           int mid = low+ (high-low)/2;
           if(nums[mid]<target) low= mid+1;
           else high = mid-1; 
         }        
        return low;
  */
};//6ms
```

#### [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) 

> Determine if a Sudoku is valid, according to: [Sudoku Puzzles - The Rules](http://sudoku.com.au/TheRules.aspx).
>
> The Sudoku board could be partially filled, where empty cells are filled with the character `'.'`.
>
> ![img](http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
>
> A partially filled sudoku which is valid.
>
> **Note:**
> A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int tr,tc;
        
        for(int i=0;i<9;i++){
            vector<int> judgerow(10,0);
            vector<int> judgecol(10,0);
            for(int j=0;j<9;j++){
                tr=board[i][j]-'0';
                tc=board[j][i]-'0';
                if(tr>0){
                    if(judgerow[tr]==0) judgerow[tr]++;
                    else return false;
                }
                if(tc>0){
                    if(judgecol[tc]==0) judgecol[tc]++;
                    else return false;                    
                }                
            }
        }
        
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<int> judgers(10,0);
                for(int m=i;m<i+3;m++){
                    for(int n=j;n<j+3;n++){
                        tr=board[m][n]-'0';
                        if(tr>0){
                            if(judgers[tr]==0) judgers[tr]++;
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};//19ms
```

```c++
//别人家的代码 6ms bool型
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // validate Row
        for (int i = 0; i < board.size(); i++) {
            if (!validateRow(board[i])) {
                return false;
            }
        }
        
        // validate col
        for (int i = 0; i < board[0].size(); i++) {
            if (!validateCol(board, i)) {
                return false;
            }
        }
        
        // validate square
        for (int i = 0; i < board.size(); i+=3) {
			for (int j = 0; j < board[0].size(); j+=3) {
                if (!validateSquare(board, i, j)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool validateRow(vector<char>& row) {
        bool used[9] = {false};
        
        for (auto c : row) {
			if (c != '.' && used[c - '1']) {
                return false;
            } else if (c != '.') {
                used[c - '1'] = true;
            }
        }
        
        return true;
    }
    
    bool validateCol(vector<vector<char>>& board, int col) {
        bool used[9] = {false};
        
        for (int i = 0; i < 9; i++) {
			if (board[i][col] != '.' && used[board[i][col] - '1']) {
                return false;
            } else if (board[i][col] != '.') {
                used[board[i][col] - '1'] = true;
            }
        }
        
        return true;
    }
    
    bool validateSquare(vector<vector<char>>& board, int row, int col) {
        bool used[9] = {false};
        
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] != '.' && used[board[i][j] - '1']) {
                    return false;
                } else if (board[i][j] != '.') {
                    used[board[i][j] - '1'] = true;
                }
        	}
        }
        
        return true;
    }
};
```