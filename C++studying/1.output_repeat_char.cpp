#include<iostream>  
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    
    int len=s.size();
    string ans="";
    string no_repeat_input="";
    for(int i=0;i<len;i++)
    {
        //判断去重复之后是否还有这个字符。find（）函数实现
        if(no_repeat_input.find(s[i])== string::npos)
        {
            no_repeat_input=no_repeat_input+s[i];
        }
        else
        {
            if (ans.find(s[i])==string::npos)
            {
                ans = ans+s[i];
            }
        }
    }
    if(ans == "")
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
    return 0;
    
}