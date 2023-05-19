#include "PhysicalSystem.h"
#include <iostream>
#include<unistd.h> 

PhysicalSystem::PhysicalSystem(int _N, double _Velocity) : N{_N} , Velocity{_Velocity}
{
    task_size = new double[N];
    std::cout << "Constructor" << std::endl;
}

PhysicalSystem::~PhysicalSystem()
{
    delete[] task_size;
    std::cout << "destructor" << std::endl;
}

void PhysicalSystem::display_information(std::atomic<bool>& finished)
{
    while (true)
    {
        std::cout<< "Velocity is equal to:" << Velocity << std::endl; 
        for (size_t i{}; i < N; i++)
        {
            std::cout << i << "th task size is: " << task_size[i] << " -- " ;  
            /* code */
        }
        std::cout << std::endl ; 
        sleep(1);
        if (finished)
        {
            break;
        }
    }
    

}

void PhysicalSystem::fill_velocities()
{
    for (size_t i{0}; i < N; i++)
    {
        task_size[i] = 10 ; 
        /* code */
    }    
}
double* PhysicalSystem::get_tasksize()
{
    return task_size; 

}

double PhysicalSystem::get_velocity()
{
    return Velocity;
}
