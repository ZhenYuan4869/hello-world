#include<iostream>  
#include<algorithm>  
#include<vector>
#include<string>
using namespace std; 
string find_max_substring(string s1,string s2)
{
    string ans;
    ans = "";
    vector< vector<int> > num(s1.size());
    vector<int> temp(s2.size(),0);
    int len = 0;
    for(int i=0;i<num.size();i++)
    {
        num[i].resize(s2.size());
        num[i]=temp;
    }
    ans = "";
    for(int i=0;i<s1.size();i++)
    {
        for(int j = 0;j<s2.size();j++)
        {
            if(s1[i]==s2[j])
            {
                if(i>0&&j>0)
                {
                    num[i][j]=num[i-1][j-1]+1;
                    if(num[i][j]>=len)
                    {
                        len = num[i][j];
                        ans = "";
                        for(int k=0;k<len;k++)
                        {
                            ans = s1[i-k]+ans;
                        }
                    }
                }
                else
                {
                    num[i][j]=1;
                    if(num[i][j]>=len)
                    {
                        ans=ans+s1[i];
                        len = num[i][j];
                    }
                }
                
            }
        }
    }
    return ans;
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<find_max_substring(s1,s2)<<endl;
    return 0;
}