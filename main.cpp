#include <iostream>
#include <cstdlib>
#include <memory>
#include <utility>
#include <thread>
#include<unistd.h>               // for linux 
#include "Edge_Nodes/PhysicalSystem.h"
#include "Edge_Nodes/Mobile_Device.h"
#include "Edge_Nodes/Smart_Vehicle.h"
#include "Base_Stations/Base_station.h"
#include "Digital_Twins/Digital_Twin.h"
#include "Application/Business/PS_BS_Connection.h"
#include <atomic>

using namespace std::rel_ops;
std::atomic<bool> finished{false};

void Show_BS_DTs(Base_station b);

int main()
{
    PS_BS_Connection ps_bs{finished.load()};
    PhysicalSystem* p1 = new Mobile_Device{3 , 20, 80};
    PhysicalSystem* p2 = new Mobile_Device{2 , 20, 80};
    p1->fill_velocities();
    p2->fill_velocities();
    Base_station b1{1};
    ps_bs.Add_BS(b1);
    // std::thread th1(ps_bs.Send_PS, 10, p1, 0);
    std::thread th1(&PS_BS_Connection::Send_PS, std::ref(ps_bs), 10, p1, 0, std::ref(finished));
    std::thread th2(&PhysicalSystem::display_information, p1, std::ref(finished));
    // std::thread th3(&PS_BS_Connection::Send_PS, std::ref(ps_bs), 10, p2, 0);
    // std::thread th4(&PhysicalSystem::display_information, p2);
    // std::thread th5(Show_BS_DTs, std::ref(ps_bs.get_BaseStations()[0]));
    // std::thread th2(Add_DT, std::ref(b1), Digital_Twin{15});
    // std::thread th3(Add_DT, std::ref(b1), Digital_Twin{13});
    th1.join();
    th2.join();
    std::cout << finished << std::endl;
    // th3.join();
    // th4.join();
    // Show_BS_DTs(ps_bs.get_BaseStations()[0]);

    // th5.join();
    delete p1;
    delete p2;
    return 0;
}

void Show_BS_DTs(Base_station b)
{
    while (true)
    {
        b.display_dts();
    }
    
}

