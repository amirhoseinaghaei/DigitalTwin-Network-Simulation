
#if !defined(SMART_VEHICLE_H)
#define SMART_VEHICLE_H

#include "PhysicalSystem.h"


class Smart_Vehicle : public PhysicalSystem
{
private:
    double computation_speed; 
public:
    Smart_Vehicle(int _N, double _Velocity , double _computation_speed);
    virtual ~Smart_Vehicle() ;
    virtual void display_information();
    double get_computation_Speed();
};





#endif