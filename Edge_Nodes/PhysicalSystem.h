
#ifndef PHYSICALSYSTEM_H
#define PHYSICALSYSTEM_H

class PhysicalSystem
{
private:
    double Velocity; 
    double * task_size; 
public:
    int N;
    PhysicalSystem(int _N, double _Velocity);
    virtual ~PhysicalSystem();
    virtual void display_information(); 
    void fill_velocities();
    double* get_tasksize();
    double get_velocity();
};



#endif 


