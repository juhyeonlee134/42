#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

class Fixed
{
private:
	int mFixedNum;
	static int const FRAC_SZ = 8;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const& other);
	Fixed& operator=(Fixed const& other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
