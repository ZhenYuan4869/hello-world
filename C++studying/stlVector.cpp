//类是通过面向对象（oop：Objective-Oriented programmering）的想法来编写的，数据和操作（function）放在一个类里面
//标准库stl用的是gp：Generic programming 泛式编程来做的, 数据和操作分开来, 因为数据不同所以操作符重载很重要
//1.类模板
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
    complex<double> c1(2.5,1.5); //一定要尖括号
    complex<int> c2(2,6);
}

//2.函数模板
template <class T>
inline
const T& min(const T& a, const T& b)
{
    return b < a ? b : a; 
}

//使用方式：
class stone
{
public:
    stone(int w, int h, int we):
        : _w(w), _h(h), _weight(we)
        {

        }
    bool operator < (const stone& rhs) const
        {
            return _weight < rhs._weight;
        }

private:
    int _w, _h, _weight;
};

stone r1(2,3), r2(3,3), r3;
r3 = min(r1,r2); //有实参推倒，所以不用用尖括号

//3.成员模板 member template
