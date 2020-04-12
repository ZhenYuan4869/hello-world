#include<iostream>  
#include<algorithm>  
#include<vector>
#include<string>
using namespace std; 
class Solution {
public:
    /**
     * 根据顾客属性计算出顾客排队顺序
     * @param a int整型vector 顾客a属性
     * @param b int整型vector 顾客b属性
     * @return int整型vector
     */
    vector<int> WaitInLine(vector<int>& a, vector<int>& b) {
        // write code here
        vector<int> ans_origin;
        vector<int> ans_sorted;
        vector<int>::iterator position;
        int temp = 0;
        vector<int> return_ans;
        for(int i=0;i<a.size();i++)
        {
            ans_origin.push_back(a[i]-b[i]);
            ans_sorted.push_back(a[i]-b[i]);
        }

        sort(ans_sorted.begin(),ans_sorted.end());

        for(int i=0;i<ans_sorted.size();i++)
        {
            temp = ans_sorted[ans_sorted.size()-1-i];
            position = find(ans_origin.begin(),ans_origin.end(),temp);
            return_ans.push_back(&*position-&ans_origin[0]+1);
        }
        return return_ans;
    }
};

int main(){
    Solution problem;
    vector<int> ans;
    vector<int> a;
    a.push_back(8);
    a.push_back(9);
    a.push_back(7);
    vector<int> b;
    b.push_back(5);
    b.push_back(8);
    b.push_back(3);
    ans = problem.Solution::WaitInLine(a,b);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}
