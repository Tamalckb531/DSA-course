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

**LeetCode 647. Palindromic Substrings[problem](https://leetcode.com/problems/palindromic-substrings/)**

<i>Question :</i>

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

<i>Intuition :</i>

1. If we place two pointer in one index of the string, start traversing the string(1, 2, 3, 4 etc) and start expand one to left and one to right, we can actually get all the odd sequence substring possible of the string.
2. But if we place one pointer ahead of other start traversing the string(1-2 , 2-3 , 3-4 , 4-5 etc) and start expand one to left and one to right, we can actually get all the even sequence substring possible of the string.
3. Now we can check all selected substrings are palindrome. If so then count them in.

<i>Approach (two pointer) :</i>

1. First traverse the string with the name center as index from 0th index to end index.
2. Point both pointer in center index. Count the oddCount with expandAroundCenter logic.
   1. expandAroundCenter has a count variable.
   2. When the left index and right index is in bound and both index pointed character are same (If two character from equal distance from the middle point are same then it's palindrome) then it increase the count and also expand the left and right index.
3. Vice versa with evenCount where the right index will be 1 ahead of the left one.
4. Add both count in totalCount for each traversal and return the totalCount.

<i>TC and SC</i>

1. Both loop can do whole traversal so TC : O(n^2)
2. SC : O(1)

## Char Arrays & Strings 3:

**LeetCode 2325. Decode the Message[problem](https://leetcode.com/problems/decode-the-message/)**

<i>Question :</i>

You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
Align the substitution table with the regular English alphabet.
Each letter in message is then substituted using the table.
Spaces ' ' are transformed to themselves.
For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').

Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
Output: "this is a secret"

<i>Intuition :</i>

1. We need to create a table mapping for each character of key.
2. Then just need to retrieve the mapped character for each message character.
3. Store them in string and return it.

<i>Approach (two pointer) :</i>

1. First handle the space issue. If there is a space in message or key, then it should put or get a space in return. So , mapping[space] = space.
2. Get an index(for key) and start char with 'a'. Traverse the key til start<='z' and key.length()>index.
   1. If key char is already exist in map then just increase the index. (find() return mapping.end() if it doesn't find the char as key in map. Use it.)
   2. If not then increase start and index, also store the start in map.
3. Start a for loop and get each character of message. find the value for that in map and store it in a decodeMsg.
4. Return the decode message.

<i>TC and SC</i>

1. Two loop. One for message and other for key so TC : O(n) -> n = max(message_length, key_length)
2. SC : O(decodeMsg)

**LeetCode 2391. Minimum Amount of Time to Collect Garbage[problem](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/)**

<i>Question :</i>

You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.

You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.

There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.

Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.

Return the minimum number of minutes needed to pick up all the garbage.

Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21

<i>Intuition :</i>

1. Target each house and get the garbage.
2. Target each garbage and check the type.
3. Increase the th picking time and track the house index with each type.
4. Traverse the travel array with lastHouseIndex tracker for each type and count all travel time.
5. Add all the travel time and picking time of each type together and return it.

<i>TC and SC</i>

1. TC : O(garbage\*currHouseGarbage length).
2. SC : O(1)

**LeetCode 791. Custom Sort String[problem](https://leetcode.com/problems/custom-sort-string/)**

Read the problem and answer it. Simple sorting custom comparator can solve it.

**LeetCode 890. Find and Replace Pattern[problem](https://leetcode.com/problems/find-and-replace-pattern/)**

<i>Question :</i>

return the matched pattern words from given words array.

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]

<i>Intuition :</i>

1. First of all, all words and pattern should be normalized. Take them in 'abc' format. Like for 'qwwe' -> 'abbc'.
2. While normalizing the words from words array, check if the normalized version matched with pattern or not.
3. If so them, store them in a vector of string and return it at last.

<i>TC and SC</i>

1. TC : O(n\*m). -> n = word_size, m = string_size
2. SC : O(n)

# Week 5 (assignment):

**LeetCode 242. Valid Anagram[problem](https://leetcode.com/problems/valid-anagram/)**

<i>Question :</i>

Input: s = "anagram", t = "nagaram"
Output: true

<i>Intuition :</i>

1. Get a frequencyTable array for 256 size as there are 256 ASCII value for character. Init all index with 0.
2. Now run two loop, one for the s and another for t string.
   1. For s, increase count each time encountering a character on it's ASCII equal index.
   2. For t, decrease count each time encountering a character on it's ASCII equal index.
3. Now if s and t are anagram them there will be all zero in the frequencyTable or there will be at least one value more than 0 in an index.
4. Now run a loop and find that out.

<i>TC and SC</i>

1. TC : O(n)
2. SC : O(1)

**LeetCode 917. Reverse Only Letters [problem](https://leetcode.com/problems/reverse-only-letters/)**

<i>Question :</i>

Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

<i>Intuition (two pointer approach):</i>

1. Get the simple two pointer that we take while reversing a string. But check some edge case.
2. If both of the pointer identifying alphabet, than swap character and do low++ , high-- .
3. If low pointer character is not alphabet than do low++ only.
4. vice versa high--.
5. Return the string s, as we reverse in built.

<i>TC and SC</i>

1. TC : O(n)
2. SC : O(1)

**LeetCode 14. Longest Common Prefix [problem](https://leetcode.com/problems/longest-common-prefix/)**

<i>Question :</i>

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Input: strs = ["flower","flow","flight"]
Output: "fl"

<i>Intuition (two pointer approach):</i>

1. First we need an outer loop , which will store the character in ans string and increasing the traverse count of each string. (traverse count should be a global index for that)
2. Now we need an inner loop where we'll get char(from left) of the first string in strs and match with others same index. If matched than we do nothing.
3. Now we need to break the inner and outer loop.
   1. We break the inner loop if any same index character don't match with initial character.
   2. We break the outer loop if we can't retrieve any char from inner loop.
4. At last we need to check an edge case in inner loop that, if the index get out of bound of string length than we break the loop.

<i>TC and SC</i>

1. TC : O(n\*m)
2. SC : O(1)

**LeetCode 345. Reverse Vowels of a String [problem](https://leetcode.com/problems/reverse-vowels-of-a-string/)**

<i>Question :</i>

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Input: s = "hello"
Output: "holle"

<i>Intuition (two pointer approach):</i>

1. Get high and low pointers.
2. Check both sides character.
   1. If both vowel than swap and move the pointer.
   2. If one of them now vowel then move the non-vowel pointer to next.
3. For vowel checking function:
   1. First make the character to lower.
   2. Then check a,e,i,o,u with them and return the bool.

<i>TC and SC</i>

1. TC : O(n)
2. SC : O(1)

**LeetCode 205. Isomorphic Strings [problem](https://leetcode.com/problems/isomorphic-strings/)**

<i>Question :</i>

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Input: s = "egg", t = "add"
Output: true

<i>Intuition (two pointer approach):</i>

Read the code and practice. (Just copied the code. Didn't understand)

<i>TC and SC</i>

1. TC : O(n)
2. SC : O(1)

**LeetCode 767. Reorganize String [problem](https://leetcode.com/problems/reorganize-string/)**

<i>Question :</i>

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Input: s = "aab"
Output: "aba"

<i>Intuition :</i>

1. Get all the occurrence for each character.
2. Find which character is most frequent out there.
3. Place the most freq with gap. This character should be placed on the first go as starting again from first can force it to place within the gap. So check if there occurrence are zero after placing them.
4. Then place all other character's in the gap.

<i>Approach :</i>

1. For getting all occurrence :
   1. Make a hash for 26 letter occurrence. 0 represents a and 25 represents z.
   2. Typecase each character into 0-25 by - 'a' and increase there occurrence.
2. For getting the most frequent :
   1. Maintain two variable, one for the max_freq(with INT_MIN) and another for the most_freq_char.
   2. Check if the occurrence is more than max-freq, if so then store it in max_freq and store it + 'a' (type cast into string) to most_freq-char.
3. Place the most freq char and check in one go :
   1. Take an index variable.
   2. Place the most_freq_char in index of s until we cover it's total occ (which is max_freq that will be decrease by one each time) and the index is not crossing the bound of s (index will be increase by two each time).
   3. If there are still value in max_freq than it's not placed in one go. So we will return empty string.
4. Place other character :
   1. Take a loop for 26 letter and traverse all there occurrence until they are 0.
   2. first check it the index is already larger than the size of s.
      1. If so than start from 1, as the most_freq_char covered the whole even index.
      2. If not than let the value be index.
   3. Place the char with type casting the hash index in char.
   4. decrease the occ and increase the index by two.
5. Return the s.

<i>TC and SC</i>

1. TC : O(n)
2. SC : O(1)

**LeetCode 49. Group Anagrams [problem](https://leetcode.com/problems/group-anagrams/)**

<i>Question :</i>

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

<i> Method 1 -> Intuition :</i>

1. Sort the string values and map the real value with sort as key.
2. Iterate the map return the value of map which are values with same key. Return them.

<i> Approach :</i>

<i>TC and SC</i>

1. TC : O(nklogk)
2. SC : O(nk)

**LeetCode 5. Longest Palindromic Substring [problem](https://leetcode.com/problems/longest-palindromic-substring/)**

**LeetCode 28. Find the Index of the First Occurrence in a String [problem](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)**

**LeetCode 8. String to Integer (atoi)[problem](https://leetcode.com/problems/string-to-integer-atoi/)** -> **Do it again**

**LeetCode 12. Integer to Roman[problem](https://leetcode.com/problems/integer-to-roman/)**

**LeetCode 6. Zigzag Conversion[problem](https://leetcode.com/problems/zigzag-conversion/)**

**LeetCode 179. Largest Number[problem](https://leetcode.com/problems/largest-number/)**

**LeetCode 539. Minimum Time Difference[problem](https://leetcode.com/problems/minimum-time-difference/)**

**LeetCode 2125. Number of Laser Beams in a Bank[problem](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/)**

**LeetCode 1209. Remove All Adjacent Duplicates in String II[problem](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)**

# Week 5 (Mega):

**LeetCode 1781. Sum of Beauty of All Substrings[problem](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)**
