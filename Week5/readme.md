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
