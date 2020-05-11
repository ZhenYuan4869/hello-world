#include <string.h>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * 值的阶乘转换成对应的十六进制表示
     * @param num int整型 一个整数
     * @return string字符串
     */
    string toHexValue(int num) {
        // write code here
        string hexTable = "0123456789ABCDEF";
        long long sum=1;
        for(int i=1;i<=num;i++)
        {
            sum = sum*i;
        }
        string ans = "";
        while(sum)
        {
            ans = hexTable[sum%16]+ans;
            sum = sum/16;
        }
        return ans;
    }
};

int main(){
    Solution problem;
    string ans;
    ans = problem.Solution::toHexValue(2);
    cout<<ans<<endl;
    return 0;
}
