#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

// 查找str1中str2出现的次数
// 比如：str1 = "haabchnjabchnnjabchuioiabc" 中 str2 = "abc"出现的次数

int get_count(const string str1, const string str2)
{
    // 形参pcount的作用是为了计算次数
    if (str1 == "")
    {
        return 0;
    }
    string rest_string = str1;
    int pos = 0;
    int count = 0;
    while(rest_string.find(str2) != string::npos)
    {
        pos = rest_string.find(str2);
        count += 1;
        rest_string.assign(rest_string,(pos+(str2.size())));
    };

    return count;
} 

int main(void)
{
    string str1 = "";
    string str2 = "aaa";

    int count = 0;

    count = get_count(str1, str2);

    
    printf("count=%d\n", count);

    return 0;
}
