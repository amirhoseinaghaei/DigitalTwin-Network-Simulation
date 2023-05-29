
#include "Mobile_Device.h"
#include <iostream>
#include <cstdlib>
#include <memory>

Mobile_Device::Mobile_Device(int _N, int id,  double _TransmissionPower , double _computation_speed) : PhysicalSystem{_N,id, _TransmissionPower} , computation_speed{_computation_speed}
{
    std:: cout << "MobileDevice consatructor" << std::endl; 
}

Mobile_Device::~Mobile_Device()
{
    std::cout << "MobileDevice Destructor" << std::endl ;
}
void Mobile_Device::display_information(std::atomic<bool>& finished)
{
    if (static_cast<int>(type) == 0)
        std::cout << "This is a Mobile Device" << std::endl;
    PhysicalSystem::display_information(finished); 
    // std::cout << "Computation speed: " << get_computation_Speed() << std::endl;

}


double Mobile_Device::get_computation_Speed()
{
    return computation_speed ; 
}
