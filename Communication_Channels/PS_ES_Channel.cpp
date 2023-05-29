#include <iostream>
#include "PS_ES_Channel.h"
#include <cmath>
#include <random>
#include <ctime>


PS_ES_Channel::PS_ES_Channel(double bandwidth, int id): Bandwidth{bandwidth}, Id{id}
{
    std::cout << "PS_ES_Channel constructor with id of" << id << std::endl;
    srand(time(0));  

    for (size_t i{}; i < 5; i++)
    {
        Ch_gains.push_back((rand() % 10) + 10);
    }
    
}

PS_ES_Channel::~PS_ES_Channel()
{
    std::cout << "PS_ES_Channel destructor with id of" << Id << std::endl;
}

double PS_ES_Channel::Calculate_Rate(double power)
{ 

    return Bandwidth* std::log2(1 + ((power*(Ch_gains[std::rand()% Ch_gains.size()]))/Bandwidth));
}

