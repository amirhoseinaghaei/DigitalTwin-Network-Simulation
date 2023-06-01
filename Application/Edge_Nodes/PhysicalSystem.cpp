#include "PhysicalSystem.h"
#include <iostream>
#include<unistd.h> 
#include <sstream>
 
PhysicalSystem::PhysicalSystem(int _N, int Id, double transmissionpower) : N{_N} , Id{Id}, TransmissionPower{transmissionpower}
{   if (Id%2 == 0)
        type = PS_Type::Mobile_Device ;
    else
        type = PS_Type::Smart_Vehicle ;

    task_size = new double[N];
    Data = new DT_Data[N];
    std::cout << "Constructor" << std::endl;
}

PhysicalSystem::~PhysicalSystem()
{
    delete[] task_size;
    std::cout << "Destructor" << std::endl;
}

void PhysicalSystem::display_information(std::atomic<bool>& finished)
{

    while (!finished)
    {
        std::cout<< "Transmission Power is equal to:" << TransmissionPower << std::endl; 
        for (size_t i{}; i < N; i++)
        {
            std::cout << i << "th task data size is: " << Data[i].Size << " -- " ;  
        }
        std::cout << std::endl ; 
        sleep(1);
    }
    

}

void PhysicalSystem::fill_tasks()
{
    // Task_Size.empty();
    while (true)
    {
        for (size_t i{0}; i < N; i++)
        {
            Data[i].Size = 100 ; 
            std::ostringstream oss;
            oss << "Data" << i;
            std::string var = oss.str();
            Data[i].Name = var;
            task_size[i] = 100 ;

        }  
        for (size_t i{}; i < N; i++ )
        {
            std::cout << "Name: " << Data[i].Name << "Size: " << Data[i].Size << std::endl; 

        }
        sleep(100);

    }
    
  
}
double* PhysicalSystem::get_tasksize()
{
    return task_size; 

}

double PhysicalSystem::get_transmissionpower()
{
    return TransmissionPower;
}

DT_Data* PhysicalSystem::get_Data()
{
    return Data;
}

