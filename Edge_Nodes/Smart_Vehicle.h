
#if !defined(SMART_VEHICLE_H)
#define SMART_VEHICLE_H

#include "PhysicalSystem.h"


class Smart_Vehicle : public PhysicalSystem
{
private:
    double computation_speed; 
public:
    int a ;
    Smart_Vehicle(int _N, int id, double _TransmissionPower , double _computation_speed);
    virtual ~Smart_Vehicle() ;
    virtual void display_information(std::atomic<bool>& finished);
    virtual double get_computation_Speed();
};





#endif