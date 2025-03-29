#ifndef STOREDATA_HPP
#define STOREDATA_HPP

#include <fstream>
#include <iostream>
#include <string>

class StoreData
{
private:
    std::string filename;
    std::string s1;
    std::string s2;

public:
    StoreData(std::string filename, std::string s1, std::string s2);
    void replaceOcc();
    std::string getFilename();
};

#endif
