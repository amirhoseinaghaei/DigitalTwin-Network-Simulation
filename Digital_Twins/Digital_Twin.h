#ifndef DIGITAL_TWIN_h
#define DIGITAL_TWIN_h

class Digital_Twin
{
private:
    double data; 
public:
    Digital_Twin(double _data);
    ~Digital_Twin();
    double get_data();
};



#endif