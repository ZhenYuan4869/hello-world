#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

// 查找str1中str2出现的次数
// 比如：str1 = "haabchnjabchnnjabchuioiabc" 中 str2 = "abc"出现的次数

int get_count(const string str1, const string str2)
{
    // 形参pcount的作用是为了计算次数
    while(str1.find(str2) != );

    return 0;
} 

int main(void)
{
    string str1 = "haabchnjabchnnjabchuioiabc";
    string str2 = "abc";

    int count = 0;
    int ret = 0;

    ret = get_count(str1, str2, &count);

    // 异常处理
    if (ret != 0){
        printf("get_count func err:%d\n", ret);
        return 0;
    }
    printf("count=%d\n", count);

    return 0;
}
