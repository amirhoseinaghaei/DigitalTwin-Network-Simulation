#include "Smart_Vehicle.h"
#include <iostream>

Smart_Vehicle::Smart_Vehicle(int _N, double _Velocity , double _computation_speed) : PhysicalSystem{_N, _Velocity} , computation_speed{_computation_speed}
{
    std:: cout << "MobileDevice consatructor" << std::endl; 
}

Smart_Vehicle::~Smart_Vehicle()
{
    std::cout << "MobileDevice Destructor" << std::endl ;
}
void Smart_Vehicle::display_information()
{
    PhysicalSystem::display_information(); 
    std::cout << "Computation speed: " << get_computation_Speed() << std::endl;

}


double Smart_Vehicle::get_computation_Speed()
{
    return computation_speed ; 
}
