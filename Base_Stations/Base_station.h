#ifndef BASE_STATION_H
#define BASE_STATION_H
#include <vector>
#include "../Digital_Twins/Digital_Twin.h"
class Base_station
{
private:
    std::vector<Digital_Twin> Dts; 
public:
    int id;
    Base_station(int id);
    ~Base_station();
    void Add_DT(Digital_Twin DT);
    void display_dts();
    std::vector<Digital_Twin> get_Dts();
};



#endif