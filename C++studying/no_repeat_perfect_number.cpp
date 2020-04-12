#include<iostream>  
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
class Solution {
public:
    /**
     * 返回无重复幂因子的 N进制完美数之和的所有幂因子
     * @param R int整型 
     * @param N int整型 N进制
     * @return int整型vector
     */
    vector<int> GetPowerFactor(int R, int N) {
        int temp = 0;
        int count = 0;
        vector<int> ans;
        if(R==1)
        {
            ans.push_back(0);
            return ans;
        }
        while(R)
        {
            temp = R%N;
            if(temp==1)
            {
                ans.push_back(count);
            }
            if(temp>1)
            {
                ans.clear();
                return ans;
            }
            count++;
            R = R/N;
        }
        return ans;
    }
};

int main(){
    Solution problem;
    vector<int> ans;
    ans = problem.Solution::GetPowerFactor(39,3);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}