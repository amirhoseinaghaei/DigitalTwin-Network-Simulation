#include "PS_BS_Connection.h"
#include <iostream>
#include<unistd.h> 


PS_BS_Connection::PS_BS_Connection(std::atomic<bool> _finished)
{

    finished.store(_finished);
    std::cout << "PS_BS_Connection Constructor" << std::endl;
}

PS_BS_Connection::~PS_BS_Connection()
{
    std::cout << "PS_BS_Connection Destructor" << std::endl;
}


void PS_BS_Connection::Send_PS(int preiod, PhysicalSystem* ps, int Bs_Id, std::atomic<bool>& finished)
{
  
        for (int i = 0; i < ps->N; i++)
        {
            while (true)
            {
                if(ps->get_tasksize()[i] <= 0)
                {
                    BSs[Bs_Id].Add_DT(Digital_Twin{ps->get_velocity()});
                    // BSs[Bs_Id].display_dts();
                    break;
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
        

}

std::vector<Base_station> PS_BS_Connection::get_BaseStations()
{
    return BSs;
}

void PS_BS_Connection::Add_BS(Base_station bs)
{
    BSs.push_back(bs);
}
