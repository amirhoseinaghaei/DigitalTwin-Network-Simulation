#ifndef PS_BS_CONNECTION_H
#define PS_BS_CONNECTION_H


#include "../../Edge_Nodes/PhysicalSystem.h"
#include "../../Base_Stations/Base_station.h"
#include "../../Edge_Nodes/Smart_Vehicle.h"
#include "../../Edge_Nodes/Mobile_Device.h"

#include <vector>
#include <atomic>
#include <map>

class PS_BS_Connection
{
private:
    std::map<int, Base_station> BSs;
    // std::vector<Base_station> BSs; 
public:
    PS_BS_Connection();
    ~PS_BS_Connection();
    void Send_PS(int period, PhysicalSystem* ps, int Bs_Id, std::atomic<bool>& finished);
    std::map<int, Base_station> get_BaseStations();
    void Add_BS(Base_station bs);


};

#endif