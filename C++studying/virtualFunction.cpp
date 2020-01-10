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

        virtual void virtualTest()
        {
            printf("test virtual parent function part\n");
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

        void virtualTest()
        {
            printf("test virtual child function part\n");
        }
};

int main()
{
    Child c;
    parent *p = &c; //父类的指针可以指向子类的对象(*表示p是个指针，而&表示取c的存放地址)
    p->Test();//此时调用的是父类的函数，相当于父类的指针，所以p是个父类，
    //如果是要使用子类的函数，那么可以在父类或者父类和子类的test（）前面加一个virtual，因为virtual是自动继承的,下面演示
    //相当于根据指针的真是类别调用函数
    p->virtualTest();
    //即将被重写的函数添加virtual是个应该遵守的编码习惯
    return 0;
}