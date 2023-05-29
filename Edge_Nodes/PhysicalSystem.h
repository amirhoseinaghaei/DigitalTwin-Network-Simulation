
#ifndef PHYSICALSYSTEM_H
#define PHYSICALSYSTEM_H

#include <atomic>
#include <vector>
#include "System_Type.h"

class PhysicalSystem
{
public:
    int N;
    int Id;
private:
    double TransmissionPower; 
    double * task_size; 
    std::vector<double> Task_Size; 
public:
    PS_Type type;
    PhysicalSystem(int _N, int Id, double transmissionpower);
    virtual ~PhysicalSystem();
    virtual void display_information(std::atomic<bool>& finished); 
    void fill_tasks();
    double* get_tasksize();
    double get_transmissionpower();
};



#endif 


