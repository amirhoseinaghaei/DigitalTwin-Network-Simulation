
#ifndef PHYSICALSYSTEM_H
#define PHYSICALSYSTEM_H

#include <atomic>
class PhysicalSystem
{
private:
    double Velocity; 
    double * task_size; 
public:
    int N;
    PhysicalSystem(int _N, double _Velocity);
    virtual ~PhysicalSystem();
    virtual void display_information(std::atomic<bool>& finished); 
    void fill_velocities();
    double* get_tasksize();
    double get_velocity();
};



#endif 


