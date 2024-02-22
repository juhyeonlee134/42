#include "Fixed.hpp"
#include <iostream>
#include <cmath>

inline bool Fixed::isNanOrInf(Float const num)
{
	unsigned int bit = (num.bit >> 23) & 0xFF;
	return (bit == 0xFF);
}

inline bool Fixed::isZero(unsigned int const bit) const
{
	unsigned int toCheck = removeMSB(bit);
	return (toCheck == 0);
}

inline int Fixed::removeMSB(unsigned int const bit) const
{
	unsigned int sign = bit >> 31;
	unsigned int ret = bit;

	if (sign)
	{
		ret ^= (1 << 31);
	}
	return (ret);
}

int Fixed::getExp(void) const
{
	int exp = 0;
	unsigned int bit = removeMSB(this->mFixedNum);
	unsigned int intFixed = bit >> this->FRAC_SZ;

	if (intFixed == 0)
	{
		size_t cnt = 0;
		intFixed = intFixed << 1;
		while (intFixed != 1)
		{
			exp--;
			cnt++;
			intFixed = bit >> (this->FRAC_SZ - cnt);
		}
	}
	else
	{
		while (intFixed != 1)
		{
			intFixed = intFixed >> 1;
			exp++;
		}
	}
	return exp;
}

Fixed::Fixed()
	: mFixedNum(0)
{}

Fixed::Fixed(int const num)
{
	unsigned int sign = num & (1 << 31);
	unsigned int intFixed = num * (sign ? (-1) : 1);
	this->mFixedNum = sign | (intFixed << this->FRAC_SZ);
}

Fixed::Fixed(float const num)
{
	float roundNum = roundf(static_cast<float>(num * (1 << this->FRAC_SZ))) / (1 << this->FRAC_SZ);
	Float org;

	org.num = roundNum;
	if (isNanOrInf(org) || org.bit == 0)
	{
		this->mFixedNum = 0;
		return;
	}

	unsigned int sign = org.bit & (1 << 31);
	int exp = ((org.bit >> 23) & 0xFF) - 127;
	unsigned int mts = (org.bit & 0x7FFFFF) | 0x800000;

	unsigned int ret = 0;
	if (exp <= 15)
	{
		ret = sign | (mts >> (15 - exp));
	}
	else
	{
		ret = sign | (mts << (exp - 15));
	}
	this->mFixedNum = ret;
}

Fixed::~Fixed()
{}

Fixed::Fixed(Fixed const& other)
{
	*this = other;
}

Fixed& Fixed::operator=(Fixed const& other)
{
	this->setRawBits(other.getRawBits());
	return *this;
}

bool Fixed::operator>(Fixed const& other) const
{
	int n1 = roundf(this->toFloat() * (1 << this->FRAC_SZ));
	int n2 = roundf(other.toFloat() * (1 << this->FRAC_SZ));
	return (n1 > n2);
}

bool Fixed::operator<(Fixed const& other) const
{
	int n1 = roundf(this->toFloat() * (1 << this->FRAC_SZ));
	int n2 = roundf(other.toFloat() * (1 << this->FRAC_SZ));
	return (n1 < n2);
}

bool Fixed::operator>=(Fixed const& other) const
{
	return (*this > other) || (*this == other);
}

bool Fixed::operator<=(Fixed const& other) const
{
	return (*this < other) || (*this == other);
}

bool Fixed::operator==(Fixed const& other) const
{
	return !((*this > other) && (*this < other));
}

bool Fixed::operator!=(Fixed const& other) const
{
	return !(*this == other);
}

Fixed Fixed::operator+(Fixed const& other) const
{
	Fixed ret;
	float f1 = this->toFloat();
	float f2 = other.toFloat();
	ret = Fixed(f1 + f2);
	return ret;
}

Fixed Fixed::operator-(Fixed const& other) const
{
	Fixed ret;
	float f1 = this->toFloat();
	float f2 = other.toFloat();
	ret = Fixed(f1 - f2);
	return ret;
}

Fixed Fixed::operator*(Fixed const& other) const
{
	Fixed ret;
	float f1 = this->toFloat();
	float f2 = other.toFloat();
	ret = Fixed(f1 * f2);
	return ret;
}

Fixed Fixed::operator/(Fixed const& other) const
{
	Fixed ret;
	float f1 = this->toFloat();
	float f2 = other.toFloat();
	ret = Fixed(f1 / f2);
	return ret;
}

Fixed& Fixed::operator++(void)
{
	Fixed eps;

	eps.setRawBits(0x1);
	*this = *this + eps;
	return *this;
}

Fixed Fixed::operator++(int dummy)
{
	Fixed eps(dummy);
	Fixed ret = *this;

	eps.setRawBits(0x1);
	*this = *this + eps;
	return ret;
}

Fixed& Fixed::operator--(void)
{
	Fixed eps;

	eps.setRawBits(0x1);
	*this = *this - eps;
	return *this;
}

Fixed Fixed::operator--(int dummy)
{
	Fixed eps(dummy);
	Fixed ret = *this;

	eps.setRawBits(0x1);
	*this = *this - eps;
	return ret;
}

int Fixed::getRawBits(void) const
{
	return this->mFixedNum;
}

void Fixed::setRawBits(int const raw)
{
	this->mFixedNum = raw;
}

float Fixed::toFloat(void) const
{
	unsigned int bit = this->getRawBits();
	if (isZero(bit))
	{
		return 0.0f;
	}

	unsigned int sign = bit & (1 << 31);
	int exp = getExp();
	unsigned int mts = removeMSB(bit);
	if (exp <= 15)
	{
		mts = mts << (15 - exp);
	}
	else
	{
		mts = mts >> (exp - 15);
	}

	Float ret;
	ret.bit = sign | ((exp + 127) << 23) | (mts ^ (1 << 23));
	return ret.num;
}

int Fixed::toInt(void) const
{
	unsigned int sign = this->getRawBits() & (1 << 31);
	unsigned int intFixed = removeMSB(this->getRawBits()) >> this->FRAC_SZ;
	int ret = intFixed * (sign ? (-1) : 1);

	return ret;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	return f1 < f2 ? f1 : f2;
}

Fixed& Fixed::min(Fixed const& f1, Fixed const& f2)
{
	return const_cast<Fixed&>(f1 < f2 ? f1 : f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	return f1 > f2 ? f1 : f2;
}

Fixed& Fixed::max(Fixed const& f1, Fixed const& f2)
{
	return const_cast<Fixed&>(f1 > f2 ? f1 : f2);
}

std::ostream& operator<<(std::ostream& os, Fixed const& num)
{
	unsigned int bit = num.getRawBits();

	if ((bit & 0xFF) == 0)
	{
		os << num.toInt();
	}
	else
	{
		os << num.toFloat();
	}
	return os;
}
