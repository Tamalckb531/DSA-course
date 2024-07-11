# Week 5 (class):

## Char Arrays & Strings 1:

**Important Note Of Character Array:**

1. cin input will stop taking input if we hit the space. It will still take input but it won't store the character after space as space is considered as terminator.
2. To take input with space : cin.getline(arr, size, delimiter) -> space is default delimiter in cin, but with getline we can give out custom delimiter.

**Important Note Of String:**

1. string is like vector of char.
2. .front() -> to get the first char of a string.
3. .back() -> to get the last char of a string.
4. .begin/end() -> to get the first/last memory location of a string.
5. .find() -> to find a specific word in a string.
6. .substr() -> to get a part of the string index wise. It takes two parameter. First is the "starting index", second is the "how much from starting index". If we don't give the second parameter, it will return us all the char till end form starting index.

## Char Arrays & Strings 2:

**LeetCode 1047. Remove All Adjacent Duplicates In String [problem](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)**

<i>Question :</i>

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Input: s = "abbaca"
Output: "ca"

<i>Intuition & Approach:</i>

1. We need to have a variable(ans string) to store the non-duplicate string.
2. Traverse through the input and get each character.
3. Insert it into the ans string if ans is empty. (first character).
4. If the the next character is not match with last character of ans(.back() for last character) then insert it also
5. If the the next character is matched with last character of ans(.back() for last character) then pop the last character of ans string (with .pop_back()).
6. Return the ans.

<i>TC and SC</i>

1. Linear Loop so TC : O(n)
2. Only one variable created so SC : O(1)

**LeetCode 680. Valid Palindrome II[problem](https://leetcode.com/problems/valid-palindrome-ii/)**

<i>Question :</i>

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

<i>Intuition & Approach (two pointer):</i>

1. First set two pointers, one on left(first index) and another on right (last index).
2. Traverse the whole string til left<=right.
3. If left and right index character are same then left++ and right--. (palindrome check logic)
4. If not than delete on char and again run the checkPalindrome logic.
   1. Now we can delete on character both from left(left+1) and right(right - 1).
   2. So we will delete char from both side and find out the different output, then return their XOR. As, if one output true than it will satisfy the question.

<i>TC and SC</i>

1. Linear Loop so TC : O(n)
2. Only one variable created so SC : O(1)
