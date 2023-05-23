#include <iostream>
#include <cstdlib>
#include <memory>
#include <utility>
#include <thread>
#include<unistd.h>
#include "Edge_Nodes/PhysicalSystem.h"
#include "Edge_Nodes/Mobile_Device.h"
#include "Edge_Nodes/Smart_Vehicle.h"
#include "Base_Stations/Base_station.h"
#include "Digital_Twins/Digital_Twin.h"
#include "Application/Business/PS_BS_Connection.h"
#include <atomic>

using namespace std::rel_ops;


int main()
{
    PS_BS_Connection ps_bs{};
    PhysicalSystem* p1 = new Mobile_Device{1 , 0, 20, 80};
    // PhysicalSystem* p2 = new Mobile_Device{15 , 20, 80};


    std::atomic<bool> finished_p1{false};
    std::atomic<bool> finished_p2{false};
   
    std::thread th0(&PhysicalSystem::fill_tasks, std::ref(p1));


    Base_station b1{1};
    ps_bs.Add_BS(b1);
    std::thread th1(&PS_BS_Connection::Send_PS, std::ref(ps_bs), 10, p1, 1, std::ref(finished_p1));
    std::thread th2(&PhysicalSystem::display_information, p1, std::ref(finished_p1));
    // std::thread th3(&PS_BS_Connection::Send_PS, std::ref(ps_bs), 10, p2, 1, std::ref(finished_p2));
    // std::thread th4(&PhysicalSystem::display_information, p2, std::ref(finished_p2));
    std::thread th5(&Base_station::display_dts, std::ref(ps_bs.get_BaseStations()[b1.id]), std::ref(finished_p2));
    th0.join();
    th1.join();
    th2.join();
    // th3.join();
    // th4.join();
    th5.join();

    delete p1;
    // delete p2;
    return 0;
}


