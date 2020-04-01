//输入一个n表示要输入的通话记录个数，接下来输入n行，每行为逗号相隔的两个整数，两个数字分别代表呼入时间和挂断时间的时间戳。
//举例：10,30，表示[10,30)，代表第10秒呼入，第30秒已经挂断，即第30秒可以接入新的来电； 
//每一行都是一条通话记录，通话记录已经按呼入时间由小到大排序；
//输出一个整数；代表最少需要多少客服，可以满足所有旅客来电不用等待。
/*
样例输入
6
0,30
0,50
10,20
15,30
20,50
20,65
样例输出
5
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int calcMinStaff(int time_table[][2],int len) {
    int current_time = 0;
    int count = 0;
    

}
/******************************结束写代码******************************/


int main() {
    int res;
    int len;
    cin>>len;
    if(len == 0)
    {
        res = 0;
        cout << res << endl;
        return 0;
    }
    
    int time_table[res][2];
    string input_timetable;
    int common_position = 0;
    for(int i = 0;i<len;i++)
    {
        cin>>input_timetable;
        common_position = input_timetable.find(',');
        time_table[i][0]= std::stoi(input_timetable.substr(0,common_position));
        time_table[i][1] = std::stoi(input_timetable.substr(common_position+1,2));
    }

    res = calcMinStaff(time_table,len);
    cout << res << endl;
    
    return 0;

}
