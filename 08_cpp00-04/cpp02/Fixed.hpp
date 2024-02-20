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
	bool operator<(Fixed const& other) const;
	bool operator>(Fixed const& other) const;
	bool operator<=(Fixed const& other) const;
	bool operator>=(Fixed const& other) const;
	bool operator==(Fixed const& other) const;
	bool operator!=(Fixed const& other) const;
	Fixed operator+(Fixed const& other) const;
	Fixed operator-(Fixed const& other) const;
	Fixed operator*(Fixed const& other) const;
	Fixed operator/(Fixed const& other) const;
	Fixed& operator++(void); // pre-increment
	Fixed operator++(int dummy); // post-increment
	Fixed& operator--(void); // pre-decrement
	Fixed operator--(int dummy); // post-decrement
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed& min(Fixed& f1, Fixed& f2);
	static Fixed& min(Fixed const& f1, Fixed const& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static Fixed& max(Fixed const& f1, Fixed const& f2);
};

// function overloading from ostream
std::ostream& operator<<(std::ostream& os, Fixed const& fixedNum);

#endif
