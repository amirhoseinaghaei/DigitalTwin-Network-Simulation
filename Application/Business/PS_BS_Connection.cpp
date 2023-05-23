#include "PS_BS_Connection.h"
#include <iostream>
#include<unistd.h> 


PS_BS_Connection::PS_BS_Connection()
{

    std::cout << "PS_BS_Connection Constructor" << std::endl;
}

PS_BS_Connection::~PS_BS_Connection()
{
    std::cout << "PS_BS_Connection Destructor" << std::endl;
}


void PS_BS_Connection::Send_PS(int preiod, PhysicalSystem* ps, int Bs_Id, std::atomic<bool>& finished)
{
  
    while (true)
    {
        for (int i = 0; i < ps->N; i++)
        {
            while (true)
            {
                if(ps->get_tasksize()[i] <= 0)
                {
                    if (BSs.find(Bs_Id) != BSs.end())
                    {
                        BSs[Bs_Id].Add_DT(ps->Id,  Digital_Twin{10, ps->get_transmissionpower(), dynamic_cast<Mobile_Device*>(ps)->get_computation_Speed()});
                        BSs[Bs_Id].display_dts(finished);
                    }
                    break;
                    continue;
                }
                else
                {
                    ps->get_tasksize()[i] = ps->get_tasksize()[i] - 2;
                }
                sleep(1);            
            }
        }
        finished.store(true);
        std::cout << finished << std::endl;
        sleep(10);
    }
    
        

}

std::map<int, Base_station> PS_BS_Connection::get_BaseStations()
{
    return BSs;
}

void PS_BS_Connection::Add_BS(Base_station bs)
{
    BSs.insert({bs.id, bs});

}
