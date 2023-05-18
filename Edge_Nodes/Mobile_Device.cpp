
#include "Mobile_Device.h"
#include <iostream>

Mobile_Device::Mobile_Device(int _N, double _Velocity , double _computation_speed) : PhysicalSystem{_N, _Velocity} , computation_speed{_computation_speed}
{
    std:: cout << "MobileDevice consatructor" << std::endl; 
}

Mobile_Device::~Mobile_Device()
{
    std::cout << "MobileDevice Destructor" << std::endl ;
}
void Mobile_Device::display_information()
{
    PhysicalSystem::display_information(); 
    std::cout << "Computation speed: " << get_computation_Speed() << std::endl;

}


double Mobile_Device::get_computation_Speed()
{
    return computation_speed ; 
}
