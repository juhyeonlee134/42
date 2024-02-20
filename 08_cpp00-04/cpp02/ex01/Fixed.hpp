#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <ostream>
#define EXP_SZ 8
#define TO_R_EXP 127
#define MTS_SZ 23
#define MTS_MSK 0x7FFFFF
#define BYT_MSK 0xFF

union Float
{
	float num;
	unsigned int bit;
};

class Fixed
{
private:
	int mFixedNum;
	static int const FRAC_SZ = 8;
public:
	Fixed();
	Fixed(int const num);
	Fixed(float const num);
	~Fixed();
	Fixed(Fixed const& other);
	Fixed& operator=(Fixed const& other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

// function overloading from ostream
std::ostream& operator<<(std::ostream& os, Fixed const& fixedNum);

#endif
