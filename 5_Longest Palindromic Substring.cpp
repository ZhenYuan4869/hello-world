// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
// 示例 1：

// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。
// 示例 2：

// 输入: "cbbd"
// 输出: "bb"
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:

    int wether_is_palindrome(string s)
    {
        int len = s.size();
        for(int i=0;i<=len/2;i++)
        {
            if(s[i]!=s[len-i-1])
            {
                return 0;
            }
        }
        return 1;
    }

    string longestPalindrome(string s) 
    {
        int len = s.size();
        string temp;//记录最大字符串
        string substring = "";

        for(int i=0;i<len;i++)
        {
            for(int j=len-1;j>=i;j--) //判断子序列是否是回文字符串
            {
                temp.assign(s,i,j-i+1);
                if(wether_is_palindrome(temp))
                {
                    if (temp.size()>=substring.size())
                    {
                        substring = temp;
                    }
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        return substring;

    }
};