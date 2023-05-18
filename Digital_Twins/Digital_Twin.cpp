#include "Digital_Twin.h"
#include <iostream>

Digital_Twin::Digital_Twin(double _data): data{_data}
{
    std::cout << "Digital Twin constructor" << std::endl;
}

Digital_Twin::~Digital_Twin()
{
    std::cout << "Digital Twin destrcutor" << std::endl;
}
double Digital_Twin::get_data()
{
    return data;
}