#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string minRemove(string s) {
        int flag = 0;
        int len = s.size();
        int i = 0;
        while(i<s.size())
        {
            if (s[i]=='(')
            {
                flag += 1;
            }
            if (s[i]==')')
            {
                if (flag==0)
                {
                    s.erase(i,1);
                    continue;
                }
                else
                {
                    flag -= 1;
                }
            }
            i = i+1;
        }
    
        while(flag)
        {
            if(flag<0)
            {
                for(int i=0;i<s.size();i++)
                {
                    if (s[i]==')')
                    {
                        s.erase(i,1);
                        flag =flag+1;
                        break;
                    }
                }
            }
            else if(flag>0)
            {
                for(int i=0;i<s.size();i++)
                {
                    if (s[i]=='(')
                    {
                        s.erase(i,1);
                        flag =flag-1;
                        break;
                    }
                }
            }
        }
        
        return s;
        
    }
};
int main(){
    string src2 = "mi)ho(y)o";
    Solution problem;
    cout<<1<<endl;
    cout<<problem.Solution::minRemove(src2)<<endl;
    cout<<2<<endl;
}