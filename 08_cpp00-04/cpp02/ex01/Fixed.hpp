#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <ostream>

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
	inline bool isNanOrInf(Float const num);
	inline bool isZero(unsigned int const bit) const;
	inline int removeMSB(unsigned int const bit) const;
	int getExp(void) const;
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

std::ostream& operator<<(std::ostream& os, Fixed const& num);

#endif
