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
#### [*Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays)   

> There are two sorted arrays **nums1** and **nums2** of size m and n respectively.
>
> Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
>
> **Example 1:**
>
> ```
> nums1 = [1, 3]
> nums2 = [2]
>
> The median is 2.0
> ```
>
> **Example 2:**
>
> ```
> nums1 = [1, 2]
> nums2 = [3, 4]
>
> The median is (2 + 3)/2 = 2.5
> ```

```c++
//别人家代码
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        int l=0,h=2*n1,mid1,mid2;
        int a1,b1,a2,b2;
        while(l<=h){
            mid1 = (l+h)/2;
            mid2 = n1+n2-mid1;
            a1 = (mid1==0)?INT_MIN:nums1[(mid1-1)/2];
            b1 = (mid2==0)?INT_MIN:nums2[(mid2-1)/2];
            a2 = (mid1==2*n1)?INT_MAX:nums1[mid1/2];
            b2 = (mid2==2*n2)?INT_MAX:nums2[mid2/2];
            if(a1>b2)
                h = mid1-1;
            else if(a2<b1)
                l = mid1+1;
            else
                break;
        }
        return (double)(max(a1,b1)+min(a2,b2))/2;
    }
};//52ms
```


#### [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) 

> Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.
>
> **Example:**
>
> ```
> Input: "babad"
>
> Output: "bab"
>
> Note: "aba" is also a valid answer.
>
> ```
>
> **Example:**
>
> ```
> Input: "cbbd"
>
> Output: "bb"
> ```

```c++
string longestPalindrome(string s) {
    int i,j,index,longest=0;
    string res;
    index=s.length()-1;
    for(;index>=0;index--){
      j=index;
      i=index-1;
      while(i>=0&&s[i]==s[j]&&j<s.length()){
        i--;
        j++;
      }
      if(longest<j-i-1){
        longest = j-i-1;
        res = s.substr(i+1,longest);
      }
      // longest = longest>=(j-i-1)?longest:(j-i-1);
      i=index-1;
      j=index+1;
      while(i>=0&&j<s.length()&&s[i]==s[j]){
        i--;
        j++;
      }
      if(longest<j-i-1){
        longest = j-i-1;
        res = s.substr(i+1,longest); 
      }
      // longest = longest>=(j-i-1)?longest:(j-i-1);
    }
    return res;
}//12ms
```

```c++
//别人家的代码
string longestPalindrome(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}
```



#### [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/) 

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R

```

And then read line by line: `"PAHNAPLSIIGYIR"` 

Write the code that will take a string and make this conversion given a number of rows:

```
string convert(string text, int nRows);
```

`convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"` 

```c++
class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows == 1)
    		return s;
        char res[s.length()+1];
    	int j = 0, step,sp;
    	for (int i = 1;i <= numRows;i++) {
    		int index = i;
    		step = 2 * numRows - 2;
    		sp = step-2*i+2;
    		while (index <= s.length()) {
    			res[j++] = s[index - 1];
    			//cout << s[index - 1] << endl;
    			if(i==1||i==numRows)
                    index+=step;
                else{
                    index += sp;
                    sp = step -sp;
                }
    		}
    	}
    	res[s.length()] = '\0';
    	return res;
    }
};//16ms
```

```c++
//别人家的代码
string convert(string s, int nRows) {
    
    if (nRows <= 1)
        return s;

    const int len = (int)s.length();
    string *str = new string[nRows];

    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]);

        if (row == 0)
            step = 1;
        else if (row == nRows - 1)
            step = -1;

        row += step;
    }

    s.clear();
    for (int j = 0; j < nRows; ++j)
    {
        s.append(str[j]);
    }

    delete[] str;
    return s;
}
```



#### [Reverse Integer](https://leetcode.com/problems/reverse-integer/) 

> Reverse digits of an integer.
>
> **Example1:** x = 123, return 321
> **Example2:** x = -123, return -321
>
> [click to show spoilers.](https://leetcode.com/problems/reverse-integer/#)
>
> **Note:**
> The input is assumed to be a 32-bit signed integer. Your function should **return 0 when the reversed integer overflows**.

```c++
class Solution {
public:
    int reverse(int x) {
        bool sign = false;
        if(x<0){
            x=-x;
            sign = true;
        }
        int max = INT_MAX/10;
        int max_t = INT_MAX%10;
        if(sign)
            max_t = -(INT_MIN%10);
        int res=0;

        while(x>0){
            if(res>max||(res==max&&x>max_t))
                return 0;
            res = 10*res+x%10;
            x/=10;
        }
        if(sign)
            res = -res;
        return res;
    }
};//12ms
```

```java
//别人家的代码
public int reverse(int x)
{
    int result = 0;

    while (x != 0)
    {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        if ((newResult - tail) / 10 != result)
        { return 0; }
        result = newResult;
        x = x / 10;
    }

    return result;
}
```



#### [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) 

> Implement atoi to convert a string to an integer.
>
> **Hint:** Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
>
> **Notes:** It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
>
> **Update (2015-02-10):**
> The signature of the `C++` function had been updated. If you still see your function signature accepts a `const char *` argument, please click the reload button  to reset your code definition.
>
> **Requirements for atoi:**The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

```c++
class Solution {
public:
    int myAtoi(string str) {
        if(str=="")
            return 0;
        int i=0;
        long long res=0;
        int sign = 0;
        while(str[i]==' '){
            i++;
        };
        if(str[i]=='+'||str[i]=='-'){
            if(str[i]=='+'){
                sign = 1;
            }else
                sign = 2;
            i++;
        }
        char c;
        do{
            c = str[i++];
            if('0'<=c&&c<='9'){
                res = res * 10 + (c-'0');
                if(res>2147483647){
                    if(sign==2)
                        return -2147483648;
                    else
                        return 2147483647;
                }
            }else
                break;
        }while(true);
        if(sign==2)
            res = -res;
        return res;
    }
};//19ms
```

```c++
//别人家的代码
int atoi(const char *str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i++] == '-'); 
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}
```



#### [Palindrome Number](https://leetcode.com/problems/palindrome-number/) 

> Determine whether an integer is a palindrome. Do this without extra space.
>
> [click to show spoilers.](https://leetcode.com/problems/palindrome-number/#)
>
> **Some hints:**Could negative integers be palindromes? (ie, -1)If you are thinking of converting the integer to string, note the restriction of using extra space.You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?There is a more generic way of solving this problem.

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int count=0,temp;
        temp =x;
        while(temp){
            temp/=10;
            count++;
        }
        int tenc=1,tent=1;
        for(int i=0;i<count-1;i++) tenc*=10;
        while(temp<count/2){
            if((x/tent)%10!=(x/(tenc/tent))%10)
                return false;
            temp++;
            tent*=10;
        }
        return true;
    }
};//205ms
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int count=1,temp=x/10;
        int tenc=1,tent=1;
        // temp =x;
        while(temp){
            temp/=10;
            count++;
            tenc*=10;
        }
        // for(int i=0;i<count-1;i++) tenc*=10;
        count=count>>1;
        while(temp++<count){
            if((x/tent)%10!=(x/(tenc/tent))%10)
                return false;
            // temp++;
            tent*=10;
        }
        return true;
    }
};//69ms
```

```c++
//别人家的代码
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};
```

#### [*Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching) 

> Implement regular expression matching with support for `'.'` and `'*'`.
>
> ```
> '.' Matches any single character.
> '*' Matches zero or more of the preceding element.
>
> The matching should cover the entire input string (not partial).
>
> The function prototype should be:
> bool isMatch(const char *s, const char *p)
>
> Some examples:
> isMatch("aa","a") → false
> isMatch("aa","aa") → true
> isMatch("aaa","aa") → false
> isMatch("aa", "a*") → true
> isMatch("aa", ".*") → true
> isMatch("ab", ".*") → true
> isMatch("aab", "c*a*b") → true
> ```

```c++

```

#### [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) 

> Given *n* non-negative integers *a1*, *a2*, ..., *an*, where each represents a point at coordinate (*i*, *ai*). *n* vertical lines are drawn such that the two endpoints of line *i* is at (*i*, *ai*) and (*i*, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
>
> Note: You may not slant the container and *n* is at least 2.

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {//递归超时，加入hmaxi和hmaxj后大大提升速度（300ms）
        int m = 0,length=height.size(),temp,hmaxi=0,hmaxj;
        for(int i=0;i<length-1;i++){
            if(hmaxi<height[i])
                hmaxi = height[i];
            else
                continue;
            hmaxj=0;
            for(int j=length-1;j>i;j--){
                if(height[j]<height[i]){
                    if(height[j]>hmaxj){
                        hmaxj = height[j];
                        temp = hmaxj*(j-i);
                        if(temp>m)
                            m=temp;
                    }
                }else{
                    temp = height[i]*(j-i);
                    if(temp>m)
                        m=temp;
                        break;
                }
            }
        }
        return m;
    }
};//16ms
```



#### [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) 

> Given an integer, convert it to a roman numeral.
>
> Input is guaranteed to be within the range from 1 to 3999.

```c++
class Solution {
public:
    string intToRoman(int num) {
        string rm[]={
            "","I","II","III","IV","V","VI","VII","VIII","IX",
            "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
            "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
            "","M","MM","MMM"};
        string res="";
        res.append(rm[30+num/1000%10]);
        res.append(rm[20+num/100%10]);
        res.append(rm[10+num/10%10]);
        res.append(rm[num%10]);
        return res;
    }
};//82ms
```