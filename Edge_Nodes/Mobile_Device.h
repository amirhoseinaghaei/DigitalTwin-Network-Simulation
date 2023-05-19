
#if !defined(MOBILE_DEVICE_H)
#define MOBILE_DEVICE_H
#include "PhysicalSystem.h"
class Mobile_Device : public PhysicalSystem
{
private:
    double computation_speed; 
public:
    Mobile_Device(int _N, double _Velocity , double _computation_speed);
    virtual ~Mobile_Device() ;
    virtual void display_information(std::atomic<bool>& finished);
    double get_computation_Speed();
};



#endif 

