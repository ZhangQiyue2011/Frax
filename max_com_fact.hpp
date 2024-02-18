//max_com_fact.hpp
//max_com_fact's meaning: Maximum common factor

#pragma once

//Finding the greatest common factor.
unsigned int max_com_fact(unsigned int a, unsigned int b)
{
    //a = abs(a);
    //b = abs(b);
    unsigned int min = (a < b) ? a : b;
    for (unsigned int i = min; i >= 1; --i)
    {
        if ( (a % i == 0) && (b % i == 0) )
        {
            return i;
        }
        
    }

    return 1;
}
