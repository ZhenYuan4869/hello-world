//类是通过面向对象（oop：Objective-Oriented programmering）的想法来编写的，数据和操作（function）放在一个类里面
//标准库stl用的是gp：Generic programming 泛式编程来做的, 数据和操作分开来, 因为数据不同所以操作符重载很重要
//类模板
template <typename T>
class complex 
{
public:
    complex (T r = 0, T i = 0)
        :re (r), im (i)
    {}
    complex& operator += (const complex&);
    T real () const {return re;}
    T imag () const {return im;}

private:
    T re, im;
    friend complex&__doapl(complex*, const complex&);
};

//使用方式
{
    complex<double> c1(2.5,1.5);
    complex<int> c2(2,6);
}
