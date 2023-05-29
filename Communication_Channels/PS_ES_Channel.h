#ifndef PS_ES_CHANNEL_H_
#define PS_ES_CHANNEL_H_

#include <vector>

class PS_ES_Channel
{
private:
    int Id;
    double Bandwidth; 
    std::vector<double> Ch_gains; 
public:
    PS_ES_Channel(double bandwidth, int id);
    ~PS_ES_Channel();
    double Calculate_Rate(double power);
};

#endif