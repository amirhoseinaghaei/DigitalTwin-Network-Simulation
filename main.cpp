#include <iostream>
#include <cstdlib>
#include <memory>
#include <utility>
#include <thread>
#include<unistd.h>
#include "Application/Edge_Nodes/PhysicalSystem.h"
#include "Application/Edge_Nodes/Mobile_Device.h"
#include "Application/Edge_Nodes/Smart_Vehicle.h"
#include "Base_Stations/Base_station.h"
#include "Digital_Twins/Digital_Twin.h"
#include "Application/Business/PS_BS_Connection.h"
#include <atomic>
#include <random> 
#include <ctime>
#include <cstdlib> 
#include "Communication_Channels/PS_ES_Channel.h"


using namespace std::rel_ops;


int main()
{



    std::vector<PS_ES_Channel> channels{PS_ES_Channel{1,1},PS_ES_Channel{4,2},PS_ES_Channel{2,3}};
    PS_BS_Connection ps_bs{channels};
    PhysicalSystem* p1 = new Mobile_Device{1 , 0, 2, 80};
    PhysicalSystem* p2 = new Smart_Vehicle{2 , 1, 1, 80};
    std::atomic<bool> finished_p1{false};
    std::atomic<bool> finished_p2{false};
    std::thread th0(&PhysicalSystem::fill_tasks, std::ref(p1));
    std::thread th01(&PhysicalSystem::fill_tasks, std::ref(p2));
    Base_station b1{1};
    ps_bs.Add_BS(b1);
    std::thread th1(&PS_BS_Connection::Send_PS, std::ref(ps_bs), 10, p1, 0, std::ref(finished_p1));
    std::thread th3(&PS_BS_Connection::Send_PS, std::ref(ps_bs), 10, p2, 1, std::ref(finished_p2));
    th0.join();
    th01.join();
    th1.join();
    th3.join();
    delete p1;

    PS_ES_Channel ch1{1,1};
    std::cout << ch1.Calculate_Rate(2) << std::endl;


    return 0;
}


