#include <iostream>
#include <unordered_map>
using namespace std;

string decodeMessage(string key, string message)
{

    unordered_map<char, char> mapping;

    // space edge case handling

    char space = ' ';
    mapping[space] = space;

    // insertion of key character in map

    int index = 0; // for traversing key
    char start = 'a';

    while (start <= 'z' && index < key.length())
    {
        char keyCurrentChar = key[index];

        if (mapping.find(keyCurrentChar) != mapping.end())
        {
            // key character already exist
            index++;
        }
        else
        {
            mapping[keyCurrentChar] = start;
            start++;
            index++;
        }
    }

    // decoding the hidden message in message perameter

    string decodedMsg;

    for (int i = 0; i < message.length(); i++)
    {
        char msgChar = message[i];
        char decode = mapping[msgChar];
        decodedMsg.push_back(decode);
    }

    return decodedMsg;
}

int main()
{
    return 0;
}