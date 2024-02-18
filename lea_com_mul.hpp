//lea_com_mul.hpp
//lea_com_mul's meaning: Least common multiple

#pragma once
#include<cmath>
#include"max_com_fact.hpp"

unsigned int lea_com_mul(unsigned int a, unsigned int b)
{
    //a = abs(a);
    //b = abs(b);
    unsigned int mcf = max_com_fact(a, b);
    unsigned int lcm = a / mcf * b;
    return lcm;
}
