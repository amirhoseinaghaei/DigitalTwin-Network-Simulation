#ifndef BASE_STATION_H
#define BASE_STATION_H
#include <vector>
#include "../Digital_Twins/Digital_Twin.h"
#include <atomic>
#include <map>
class Base_station
{
private:
    std::map<int, Digital_Twin> DTs; 
    // std::vector<Digital_Twin> Dts; 
public:
    int id;
    Base_station() = default ;
    Base_station(int id);
    ~Base_station();
    void Add_DT(int ps_id, Digital_Twin DT);
    void display_dts(std::atomic<bool>&);
    std::map<int, Digital_Twin> get_Dts();
};



#endif