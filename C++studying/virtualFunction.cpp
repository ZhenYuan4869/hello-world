#include <iostream>
//test envioroment
// using namespace std;
// int main()
// {
//     cout<<"hello world."<<endl;
//     return 0;
// }
#include <string> 
class parent
{
    public:
        void Test()
        {
            printf("parent function part\n");
        }
};

class Child: public parent
{
    public:
        void Test()
        {
            parent::Test();
            printf("child function part\n"); //原函数增加一行运行,相当于重载test函数
        }
};
 int main()
 {
     Child c;
     c.Test();

     return 0;
 }