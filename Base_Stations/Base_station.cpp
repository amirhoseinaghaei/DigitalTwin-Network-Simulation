#include "Base_station.h"
#include <iostream>


Base_station::Base_station(int _id): id{_id}
{
    std::cout << "Base station constructor" << std::endl;
}

Base_station::~Base_station()
{
    std::cout << "Base station destrcutor" << std::endl;
}

void Base_station::Add_DT(Digital_Twin DT)
{
    Dts.push_back(DT);
}
void Base_station::display_dts()
{
    for (size_t i{}; i < Dts.size(); i++)
    {
        std::cout << i << "th DT data is: " << Dts[i].get_data() << std::endl;
    }
}
std::vector<Digital_Twin> Base_station::get_Dts()
{
    return Dts;
}

