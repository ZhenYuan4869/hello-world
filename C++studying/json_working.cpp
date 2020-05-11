#include <string.h>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * Json字符串脱敏
     * @param jsonMsg string字符串 Json字符串
     * @return string字符串
     */
    string maskJsonMsg(string jsonMsg) {
        // write code here
        string ans = jsonMsg;
        int count = 0;
        int head,tail;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='}')
            {
                break;
            }
            if(ans[i]==',')
            {
                count += 1;
                if(count==1)
                {
                    ans.replace(i-2,1,"*");
                }
                else if (count==2)
                {
                    head = i+12;
                    ans.replace(head+1,10,"***");
                }
                else if (count==3)
                {
                    head = i+12;
                    ans.replace(head+1,4,"****");
                }
                else if (count==4)
                {
                    head = i+11;
                }
                else if (count==5)
                {
                    tail = i-1;
                    ans.replace(head+1,tail-head-1,"*");
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution problem;
    string ans;
    ans = problem.Solution::maskJsonMsg("{'user':'张三','sex':'m','idNo':'11010119900307299X','phone':'13436704891','address':'北京市东城区赵堂子胡同16号','postCode':'100010'}");
    cout<<ans<<endl;
    return 0;
}