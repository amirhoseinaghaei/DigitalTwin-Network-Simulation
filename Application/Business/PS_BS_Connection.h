#ifndef PS_BS_CONNECTION_H
#define PS_BS_CONNECTION_H


#include "../../Edge_Nodes/PhysicalSystem.h"
#include "../../Base_Stations/Base_station.h"

#include <vector>
class PS_BS_Connection
{
private:
    std::vector<Base_station> BSs; 
public:
    PS_BS_Connection();
    ~PS_BS_Connection();
    void Send_PS(int period, PhysicalSystem* ps, int Bs_Id);
    std::vector<Base_station> get_BaseStations();
    void Add_BS(Base_station bs);


};

#endif