#include "PhysicalSystem.h"
#include <iostream>
#include<unistd.h> 

PhysicalSystem::PhysicalSystem(int _N, int Id, double transmissionpower) : N{_N} , Id{Id}, TransmissionPower{transmissionpower}
{
    task_size = new double[N];
    std::cout << "Constructor" << std::endl;
}

PhysicalSystem::~PhysicalSystem()
{
    delete[] task_size;
    std::cout << "Destructor" << std::endl;
}

void PhysicalSystem::display_information(std::atomic<bool>& finished)
{
    while (true)
    {
        std::cout<< "TransmissionPower is equal to:" << TransmissionPower << std::endl; 
        for (size_t i{}; i < N; i++)
        {
            std::cout << i << "th task size is: " << task_size[i] << " -- " ;  
            /* code */
        }
        std::cout << std::endl ; 
        sleep(1);
    }
    

}

void PhysicalSystem::fill_tasks()
{
    while (true)
    {
        for (size_t i{0}; i < N; i++)
        {
            task_size[i] = 10 ; 
            /* code */
        }  
        sleep(7);
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
