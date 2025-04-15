#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);
    Fixed e;
    e = a;
    std::cout << "a: " << a.getRawBits() << std::endl;
    std::cout << "b: " << b.getRawBits() << std::endl;
    std::cout << "c: " << c.getRawBits() << std::endl;
    std::cout << "d: " << d.getRawBits() << std::endl;
    std::cout << "e: " << e.getRawBits() << std::endl;
    return 0;
}