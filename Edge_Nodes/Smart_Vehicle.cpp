#include "Smart_Vehicle.h"
#include <iostream>
#include <cstdlib>
#include <memory>

Smart_Vehicle::Smart_Vehicle(int _N, int id, double _TransmissionPower , double _computation_speed) : PhysicalSystem{_N, id, _TransmissionPower} , computation_speed{_computation_speed}
{
    std:: cout << "MobileDevice consatructor" << std::endl; 
}

Smart_Vehicle::~Smart_Vehicle()
{
    std::cout << "MobileDevice Destructor" << std::endl ;
}
void Smart_Vehicle::display_information(std::atomic<bool>& finished)
{
    PhysicalSystem::display_information(finished); 
    std::cout << "Computation speed: " << get_computation_Speed() << std::endl;

}


double Smart_Vehicle::get_computation_Speed()
{
    return computation_speed ; 
}
