// # Given a string, find the length of the longest substring without repeating characters.
// # Example 1:
// # Input: "abcabcbb"
// # Output: 3 
// # Explanation: The answer is "abc", with the length of 3. 
// # Example 2:
// # Input: "bbbbb"
// # Output: 1
// # Explanation: The answer is "b", with the length of 1.
// # Example 3:
// # Input: "pwwkew"
// # Output: 3
// # Explanation: The answer is "wke", with the length of 3. 
// #              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int counter = 0;
        string::size_type pos;

    //string::size_type string::find(string &);
    //功能为在string对象中，查找参数string类型的字符串是否存在，如果存在，返回起始位置。不存在则返回 string::npos。

        for (int i=0; i<s.size(); i++){
            counter = 0;
            for (int j=i;j<s.size();j++){
                pos = s.substr(i,j-i).find(s[j]);
                //cout << pos <<" "<<i<<","<<j<<s.substr(i,j)<<endl;
                if (pos == string::npos){
                    counter++;
                }
                else
                {   
                    if (counter > max){
                        max = counter;
                    }
                    //cout << s.substr(i,j) << endl;
                    break;
                }
            }
        if (counter > max){
                max = counter;
             }
        }
    return max; 
    }
};

int main(){
    Solution problem;
    cout<<problem.lengthOfLongestSubstring(" ")<<endl;

}