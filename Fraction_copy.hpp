//Fraction.hpp
//Create Score Object(Fraction)

#pragma once
#include<iostream>
#include"lea_com_mul.hpp"
typedef unsigned int uint;
//using namespace std;

class Fraction
{
private:
    uint deno;//denominator
    uint num;//numeractor
    bool pos;
    double value;
public:
    Fraction(uint d, uint m, bool pos);
    ~Fraction();
    void univ_sc(uint x);
    void app_sc();
    void reciprocal();//reciprocal
    uint ret_deno();//return denominator
    uint ret_num();//return numeractor
    const uint const_ret_deno() const;
    const uint const_ret_num() const;
    bool ret_pos();//return positive or negative fraction
    const bool const_ret_pos() const;
    double ref_value();//refresh and return value
    const double const_ref_value() const;//const object return value
    //overload operators;
    friend bool operator<(const Fraction &lhs, const Fraction &rhs);
    friend bool operator<=(const Fraction &lhs, const Fraction &rhs);
    friend bool operator>(const Fraction &lhs, const Fraction &rhs);
    friend bool operator>=(const Fraction &lhs, const Fraction &rhs);
    friend bool operator==(const Fraction &lhs, const Fraction &rhs);
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);
    friend Fraction operator+(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator-(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator*(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator/(const Fraction &lhs, const Fraction &rhs);
    friend std::ostream & operator<<(std::ostream &out, const Fraction &A);
    Fraction operator-();
    //Global functions;
    friend void redu_frac_com_deno(Fraction *lpr, Fraction *rpr);
};

Fraction::Fraction(uint m, uint d, bool p = true): num(m), deno(d), pos( (m == 0) ? true : p), value( ( ((m == 0) ? true : p) == true) ? (double)m / d : -( (double)m / d ) )
{
}

Fraction::~Fraction()
{
}
/*
std::ostream & operator<<(std::ostream &out, Fraction &A)
{
    Fraction B = A;
    B.app_sc();
    out << B.num << "/" << B.deno;
    return out;
}
*/

std::ostream & operator<<(std::ostream &out, const Fraction &A)
{
    uint de = A.deno;
    uint nm = A.num;
    bool po = A.pos;
    Fraction B(nm, de, po);
    B.app_sc();
    out << (B.pos ? "" : "-") << B.num << "/" << B.deno;
    return out;
}

void Fraction::univ_sc(uint x)//Universal score
{
    this->deno *= x;
    this->num *= x;
}

void Fraction::app_sc()//Approximate score
{
    uint mcf = max_com_fact(this->deno, this->num);
    this->deno /= mcf;
    this->num /= mcf;
}

void Fraction::reciprocal()//
{
    uint temp = deno;
    if (temp == 0)
    {
        throw 0;
    }
    
    this->deno = num;
    this->num = temp;
}

double Fraction::ref_value()
{
    this->value = (double)this->num / this->deno;
    return this->value;
}

const double Fraction::const_ref_value() const
{
    return this->value;
}

uint Fraction::ret_deno()
{
    uint d = this->deno;
    return d;
}

uint Fraction::ret_num()
{
    uint n = this->num;
    return n;
}

const uint Fraction::const_ret_deno() const
{
    uint d = this->deno;
    return d;
}

const uint Fraction::const_ret_num() const
{
    uint n = this->num;
    return n;
}

bool Fraction::ret_pos()
{
    return this->pos;
}

const bool Fraction::const_ret_pos() const
{
    return this->pos;
}

//****************overload operators;

Fraction Fraction::operator-()
{
    bool opos;
    if (this->pos)
    {
        opos = false;
    }
    else
    {
        opos = true;
    }
    
    return Fraction(this->num, this->deno, opos );
    
}





Fraction operator+(const Fraction &lhs, const Fraction &rhs)
{
    uint lde = lhs.deno;
    uint rde = rhs.deno;
    uint mcf = max_com_fact(lde, rde);
    uint lnm = lhs.num * (rde / mcf);
    uint rnm = rhs.num * (lde / mcf);
    uint lcm = lea_com_mul(lde, rde);
    uint sum;
    bool lpo = lhs.pos;
    bool rpo = rhs.pos;
    if (rpo == true)
    {
        sum = lnm + rnm;
    }
    else
    {
        if (lnm >= rnm)
        {
            sum = lnm - rnm;
        }
        else
        {
            lpo = -lpo;
            sum = rnm - lnm;
            
        }
        
    }
    
    Fraction res(sum, lcm, lpo);
    return res;
    //
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs)
{
    uint lde = lhs.deno;
    uint rde = rhs.deno;
    uint mcf = max_com_fact(lde, rde);
    uint lnm = lhs.num * (rde / mcf);
    uint rnm = rhs.num * (lde / mcf);
    uint lcm = lea_com_mul(lde, rde);
    uint sum;
    bool lpo = lhs.pos;
    bool rpo = rhs.pos;
    if (rhs.pos == false)
    {
        sum = lnm + rnm;
    }
    else
    {
        if (lnm >= rnm)
        {
            sum = lnm - rnm;
        }
        else
        {
            lpo = -lpo;
            sum = rnm - lnm;
            
        }
        
    }
    Fraction res(lnm - rnm, lcm);
    return res;
    //
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs)
{
    uint lde = lhs.deno;
    uint rde = rhs.deno;
    uint lnm = lhs.num;
    uint rnm = rhs.num;
    bool lpo = lhs.pos;
    bool rpo = rhs.pos;
    bool opos;
    if ( (lpo == true && rpo == false) || (lpo == false && rpo == true) )
    {
        opos = false;
    }
    else
    {
        opos = true;
    }
    
    Fraction res(lnm * rnm, lde * rde, opos);
    return res;
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs)
{
    Fraction rhsr = rhs;
    rhsr.reciprocal();
    Fraction res = lhs * rhsr;
    bool lpo = lhs.pos;
    bool rpo = rhs.pos;
    if ( (lpo == true && rpo == false) || (lpo == false && rpo == true) )
    {
        -res;
    }
    return res;
}


//++--
Fraction Fraction::operator++()
{
    Fraction add(1, this->deno);
    *this = *this + add;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction add(1, this->deno);
    Fraction res = *this;
    *this = *this + add;
    return res;
}

Fraction Fraction::operator--()
{
    Fraction sub(1, this->deno);
    *this = *this - sub;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction sub(1, this->deno);
    Fraction res = *this;
    *this = *this - sub;
    return res;
}


bool operator<(const Fraction &lhs, const Fraction &rhs)
{
    Fraction la = lhs;
    Fraction ra = rhs;
    redu_frac_com_deno(&la, &ra);
    if (la.pos == false && ra.pos == true)
    {
        return true;
    }
    if (la.pos == true && ra.pos == false)
    {
        return false;
    }
    
    if (lhs.pos == false && rhs.pos == false)
    {
        if (la.num <= ra.num)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if (la.num >= ra.num)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    return false;
    
}
bool operator<=(const Fraction &lhs, const Fraction &rhs)
{
    Fraction la = lhs;
    Fraction ra = rhs;
    redu_frac_com_deno(&la, &ra);
    if (la.pos == false && ra.pos == true)
    {
        return true;
    }
    if (la.pos == true && ra.pos == false)
    {
        return false;
    }
    
    if (lhs.pos == false && rhs.pos == false)
    {
        if (la.num < ra.num)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if (la.num > ra.num)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    return false;
    
}

bool operator>(const Fraction &lhs, const Fraction &rhs)
{
    Fraction la = lhs;
    Fraction ra = rhs;
    redu_frac_com_deno(&la, &ra);
    if (la.pos == false && ra.pos == true)
    {
        return false;
    }
    if (la.pos == true && ra.pos == false)
    {
        return true;
    }

    if (lhs.pos == false && rhs.pos == false)
    {
        if (la.num >= ra.num)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if (la.num <= ra.num)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    
    return false;
    
}

bool operator>=(const Fraction &lhs, const Fraction &rhs)
{
    Fraction la = lhs;
    Fraction ra = rhs;
    redu_frac_com_deno(&la, &ra);
    if (la.pos == false && ra.pos == true)
    {
        return false;
    }
    if (la.pos == true && ra.pos == false)
    {
        return true;
    }

    if (lhs.pos == false && rhs.pos == false)
    {
        if (la.num > ra.num)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if (la.num < ra.num)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    
    return false;
    
}

bool operator==(const Fraction &lhs, const Fraction &rhs)
{
    Fraction la = lhs;
    Fraction ra = rhs;
    if ((la.pos == false && ra.pos == true) || (la.pos == true && ra.pos == false) )
    {
        return false;
    }

    redu_frac_com_deno(&la, &ra);
    if (la.num == ra.num)
    {
        return true;
    }
    return false;
    
}




//*************Global functions;
void redu_frac_com_deno(Fraction *lpr, Fraction *rpr)
{
    lpr->app_sc();
    rpr->app_sc();
    uint lcm = lea_com_mul( lpr->deno, rpr->deno);
    uint lnm = lpr->num * (lcm / lpr->deno);
    uint rnm = rpr->num * (lcm / rpr->deno);
    lpr->num = lnm;
    rpr->num = rnm;
    lpr->deno = lcm;
    rpr->deno = lcm;
    

}
