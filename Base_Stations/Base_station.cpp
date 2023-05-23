#include "Base_station.h"
#include <iostream>
#include <unistd.h>

Base_station::Base_station(int _id): id{_id}
{
    std::cout << "Base station constructor" << std::endl;
}

Base_station::~Base_station()
{
    std::cout << "Base station destrcutor" << std::endl;
}

void Base_station::Add_DT(int ps_id, Digital_Twin DT)
{
    if (DTs.find(ps_id) == DTs.end()) {
        DTs[ps_id] = DT;
    }
    else
    {
        DTs[ps_id].Set_Parameters((rand() % (15 - 5 + 1)) + 5, 10,10);
    }
}
void Base_station::display_dts(std::atomic<bool>& finished)
{

        std::cout << "The DTs for base station "<< id << " is as follow: " << std::endl;

        for (auto  x : DTs)
        {
            std::cout << "DT with id " << x.first << " has location of " << x.second.get_location() << "  ";

        }
        std::cout << std::endl;
    

}
std::map<int, Digital_Twin> Base_station::get_Dts()
{
    return DTs;
}

