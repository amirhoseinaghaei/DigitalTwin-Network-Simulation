
#ifndef PHYSICALSYSTEM_H
#define PHYSICALSYSTEM_H

#include <atomic>
#include <vector>
#include "../Enums/System_Type.h"
#include "../Dtos/DT_DataDto.h"

class PhysicalSystem
{
public:
    int N;
    int Id;
private:
    double TransmissionPower; 
    DT_Data* Data; 
    double* task_size; 

    std::vector<double> Task_Size; 
public:
    PS_Type type;
    PhysicalSystem(int _N, int Id, double transmissionpower);
    virtual ~PhysicalSystem();
    virtual void display_information(std::atomic<bool>& finished); 
    void fill_tasks();
    double* get_tasksize();
    double get_transmissionpower();
    DT_Data* get_Data();
};



#endif 


