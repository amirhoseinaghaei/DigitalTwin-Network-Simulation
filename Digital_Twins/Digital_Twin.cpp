#include "Digital_Twin.h"
#include <iostream>

Digital_Twin::Digital_Twin(double location, double max_transPower, double computation_resource): Location{location}, Max_Transpower{max_transPower}, 
Computation_Resource{computation_resource}
{
    std::cout << "Digital Twin constructor" << std::endl;
}

Digital_Twin::~Digital_Twin()
{
    std::cout << "Digital Twin destrcutor" << std::endl;
}
double Digital_Twin::get_location()
{
    return Location;
}
void Digital_Twin::Set_Parameters(double location, double max_transPower, double computation_resource)
{
    Location = location; 
    Max_Transpower = max_transPower; 
    Computation_Resource = computation_resource; 
}
