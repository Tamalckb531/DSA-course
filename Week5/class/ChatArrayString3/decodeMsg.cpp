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

string decodeMessage(string key, string message)
{
    //! FLOW : Map the key -> decode the message

    unordered_map<char, char> mapping;

    //? space edge case handle
    char space = ' ';
    mapping[space] = space;

    //? Map the key
    int index = 0;    //? traverse index of key -> in case of already inserted char traverse the index
    char start = 'a'; //? a to z traverse serially
    while (start <= 'z' && index < key.length())
    {
        char currKeyChar = key[index];
        if (mapping.find(currKeyChar) != mapping.end())
        {
            // key char already exist so move on
            index++;
        }
        else
        {
            mapping[currKeyChar] = start;
            start++;
            index++;
        }
    }

    //? Decode the msg
    string decodeMsg = "";
    for (int i = 0; i < message.length(); i++)
    {
        char msgChar = message[i];
        char decode = mapping[msgChar];
        decodeMsg.push_back(decode);
    }

    return decodeMsg;
}

int main()
{
    return 0;
}