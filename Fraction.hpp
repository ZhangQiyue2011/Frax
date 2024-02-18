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
    //double value;
    bool pos;
public:
    Fraction(uint d, uint m, bool p = true);
    Fraction(uint n);
    Fraction(int n);
    Fraction(uint n, const Fraction a, bool p = true);
    Fraction();
    ~Fraction();
    void univ_sc(uint x);
    void app_sc();
    void reciprocal();//reciprocal
    uint ret_deno() const;//return denominator
    uint ret_num() const;//return numeractor
    bool ret_pos() const;//return positive or negative fraction
    double ret_value() const;//return value
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

//, value( (m == 0) ? 0.0 : (pos == true ? m / d : -(m / d)) )
Fraction::Fraction(uint m, uint d, bool p): num(m), deno(d), pos( (m == 0) ? true : p)
{
    if (d == 0u)
    {
        throw 0;
    }
    
}

//, value(static_cast<double>(n) )
Fraction::Fraction(uint n): num(n), deno(1), pos(true)
{
}

//, value(static_cast<double>(n) )
Fraction::Fraction(int n): num( abs(n) ), deno(1), pos( (0 > n) ? false : true )
{
}

Fraction::Fraction(uint n, const Fraction a, bool p): deno(a.deno), num( n * a.deno + a.num ), pos(p)
{
    if (a.deno == 0u)
    {
        throw 0;
    }
    if (a.pos == false)
    {
        throw false;
    }
    
    
}

Fraction::Fraction(): num(1), deno(2), pos(true)//, value(0.5)
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

double Fraction::ret_value() const
{
    return (this->pos) ? ( (double)this->num / this->deno ) : ( 0.0 - (double)this->num / this->deno );
}

uint Fraction::ret_deno() const
{
    return this->deno;
}

uint Fraction::ret_num() const
{
    return this->num;
}

bool Fraction::ret_pos() const
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
    bool lpo = lhs.pos;
    bool rpo = rhs.pos;
    bool tpo;
    uint tnm;
    if (lpo == rpo)
    {
        tnm = lnm + rnm;
        tpo = lpo;
        
    }
    else
    {
        if (lnm >= rnm)
        {
            tnm = lnm - rnm;
            tpo = lpo;
        }
        else
        {
            tnm = rnm - lnm;
            tpo = rpo;
        }
        
    }
    
    Fraction res(tnm, lcm, tpo);
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
    bool lpo = lhs.pos;
    bool rpo = (rhs.pos) ? false : true;
    bool tpo;
    uint tnm;
    if (lpo == rpo)
    {
        tnm = lnm + rnm;
        tpo = lpo;
        
    }
    else
    {
        if (lnm >= rnm)
        {
            tnm = lnm - rnm;
            tpo = lpo;
        }
        else
        {
            tnm = rnm - lnm;
            tpo = rpo;
        }
        
    }
    
    Fraction res(tnm, lcm, tpo);
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
    if ( lpo == rpo )
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
    if (rhs.num == 0)
    {
        throw 0;
    }
    
    uint lde = lhs.deno;
    uint rde = rhs.num;
    uint lnm = lhs.num;
    uint rnm = rhs.deno;
    bool lpo = lhs.pos;
    bool rpo = rhs.pos;
    bool opos;
    if ( lpo == rpo )
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
