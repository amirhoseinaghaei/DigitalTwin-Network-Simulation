#include "PS_BS_Connection.h"
#include <iostream>
#include<unistd.h> 
#include <thread>

PS_BS_Connection::PS_BS_Connection(std::vector<PS_ES_Channel> channels) : Channels{channels}
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
        std::thread th2;
        finished.store(false);
        if (static_cast<int>(ps->type) == 0)
            th2 = std::thread(&PhysicalSystem::display_information, dynamic_cast<Mobile_Device*>(ps), std::ref(finished));
        else
            th2 = std::thread(&PhysicalSystem::display_information, dynamic_cast<Smart_Vehicle*>(ps), std::ref(finished));

        // std::thread th2(&PhysicalSystem::display_information, ps, std::ref(finished));
        for (int i = 0; i < ps->N; i++)
        {
            srand(time(0));
            int channel_index{std::rand()%Channels.size()}; 
            while (true)
            {

                if(ps->get_Data()[i].Size <= 0)
                {
                    if (BSs.find(Bs_Id) != BSs.end())
                    {
                        if (static_cast<int>(ps->type) == 0)
                            BSs[Bs_Id].Add_DT(ps->Id,  Digital_Twin{10, ps->get_transmissionpower(), dynamic_cast<Mobile_Device*>(ps)->get_computation_Speed() });
                        else
                            BSs[Bs_Id].Add_DT(ps->Id,  Digital_Twin{15, ps->get_transmissionpower(), dynamic_cast<Smart_Vehicle*>(ps)->get_computation_Speed() });

                        BSs[Bs_Id].display_dts(finished);
                    }
                    break;
                    continue;
                }
                else
                {
                    if ((ps->get_Data()[i].Size - Channels[channel_index].Calculate_Rate(ps->get_transmissionpower())) >= 0 )
                        ps->get_Data()[i].Size -= Channels[channel_index].Calculate_Rate(ps->get_transmissionpower());
                    else
                        ps->get_Data()[i].Size = 0;

                }
                sleep(1);            
            }
        }
        finished.store(true);
        th2.join();

        std::cout << finished << std::endl;
        sleep(preiod);
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
