#ifndef DIGITAL_TWIN_h
#define DIGITAL_TWIN_h

class Digital_Twin
{
private:
    double Location; 
    double Max_Transpower;
    double Computation_Resource;
public:
    Digital_Twin() = default;
    Digital_Twin(double location, double max_transPower, double computation_resource);
    ~Digital_Twin();
    double get_location();
    void Set_Parameters(double location, double max_transPower, double computation_resource);
};



#endif