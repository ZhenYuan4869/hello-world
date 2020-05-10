
#include<iostream>  
#include<algorithm>  
#include<vector>
#include<string>
using namespace std; 
class Solution {
public:
    /**
     * 获取最大可同事办公员工数
     * @param pos char字符型vector<vector<>> 工位分布
     * @return int整型
     */
    int GetMaxStaffs(vector<vector<char> >& pos) {
        // write code here
        int return_value = 0;
        int width = pos.size();
        if(width==0)
        {
            return 0;
        }
        int length = pos[0].size();
        int temp[width][length];
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<width;j++)
            {
                temp[i][j] = 0;
            }
        }
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(i == 0&&j>=1)
                {
                    if(pos[i][j] == '.'&&temp[i][j-1]!=1)
                    {
                        temp[i][j]=1;
                        return_value+=1;
                    }
                }
                
            }
        }
    }
};