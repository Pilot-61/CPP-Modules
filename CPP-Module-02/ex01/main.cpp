#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    a = Fixed(1234.4321f);

    std::cout << "a: " << a.toFloat() << std::endl;
    std::cout << "b: " << b.toFloat() << std::endl;
    std::cout << "c: " << c.toFloat() << std::endl;
    std::cout << "d: " << d.toFloat() << std::endl;

    return 0;
}