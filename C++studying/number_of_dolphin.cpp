/*
携程海洋馆中有 n 只萌萌的小海豚，初始均为 0 岁，每只小海豚的寿命是 m 岁，

且这些小海豚会在 birthYear[i] 这些年份生产出一位宝宝海豚（1 <= birthYear[i] <= m），每位宝宝海豚刚出生为 0 岁。

问 x 年时，携程海洋馆有多少只小海豚？
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
long countDolphin(int n, int m, vector < int > birthYear, int x) {
    int count = n;
    for(int j=0;j<x;j++)
    {
        for(int i=0;i<birthYear.size();i++)
        {
            birthYear[i]+=1;
        }
    }


}
/******************************结束写代码******************************/


int main() {
    long res;

    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _birthYear_size = 0;
    cin >> _birthYear_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _birthYear;
    int _birthYear_item;
    for(int _birthYear_i=0; _birthYear_i<_birthYear_size; _birthYear_i++) {
        cin >> _birthYear_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _birthYear.push_back(_birthYear_item);
    }


    int _x;
    cin >> _x;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    
    res = countDolphin(_n, _m, _birthYear, _x);
    cout << res;
    
    return 0;

}