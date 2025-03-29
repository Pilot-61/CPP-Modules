#include "StoreData.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    StoreData store(av[1], av[2], av[3]);
    store.replaceOcc();
    return 0;
}
