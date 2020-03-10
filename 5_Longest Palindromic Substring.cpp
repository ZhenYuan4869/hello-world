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
    string longest_palind_including_first(string s)
    {
        int len = s.size();
        string temp;
        for(int i=len;i>0;i--)
        {
            temp.assign(s,0,i);
            if(wether_is_palindrome(temp))
            {
                return temp;
            }
        }
        return s.substr(0,1);
    }

    string longestPalindrome(string s) 
    {
        int len = s.size();
        string temp_palind;//记录子串的最大回文字符串
        string substring = "";

        for(int i=0;i<len;i++)
        {
            temp_palind.assign(longest_palind_including_first(s.substr(i,len-i+1)));
            if(temp_palind.size()>=substring.size())
            {
                substring = temp_palind;
            }
        }
            
        return substring;

    }
};

int main(){
    Solution problem;
    cout<<problem.longestPalindrome("cyyoacmjwjubfkzrrbvquqkwhsxvmytmjvbborrtoiyotobzjmohpadfrvmxuagbdczsjuekjrmcwyaovpiogspbslcppxojgbfxhtsxmecgqjfuvahzpgprscjwwutwoiksegfreortttdotgxbfkisyakejihfjnrdngkwjxeituomuhmeiesctywhryqtjimwjadhhymydlsmcpycfdzrjhstxddvoqprrjufvihjcsoseltpyuaywgiocfodtylluuikkqkbrdxgjhrqiselmwnpdzdmpsvbfimnoulayqgdiavdgeiilayrafxlgxxtoqskmtixhbyjikfmsmxwribfzeffccczwdwukubopsoxliagenzwkbiveiajfirzvngverrbcwqmryvckvhpiioccmaqoxgmbwenyeyhzhliusupmrgmrcvwmdnniipvztmtklihobbekkgeopgwipihadswbqhzyxqsdgekazdtnamwzbitwfwezhhqznipalmomanbyezapgpxtjhudlcsfqondoiojkqadacnhcgwkhaxmttfebqelkjfigglxjfqegxpcawhpihrxydprdgavxjygfhgpcylpvsfcizkfbqzdnmxdgsjcekvrhesykldgptbeasktkasyuevtxrcrxmiylrlclocldmiwhuizhuaiophykxskufgjbmcmzpogpmyerzovzhqusxzrjcwgsdpcienkizutedcwrmowwolekockvyukyvmeidhjvbkoortjbemevrsquwnjoaikhbkycvvcscyamffbjyvkqkyeavtlkxyrrnsmqohyyqxzgtjdavgwpsgpjhqzttukynonbnnkuqfxgaatpilrrxhcqhfyyextrvqzktcrtrsbimuokxqtsbfkrgoiznhiysfhzspkpvrhtewthpbafmzgchqpgfsuiddjkhnwchpleibavgmuivfiorpteflholmnxdwewj")<<endl;
}