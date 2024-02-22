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
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	unsigned int sign = num & (1 << 31);
	unsigned int intFixed = num * (sign ? (-1) : 1);
	this->mFixedNum = sign | (intFixed << this->FRAC_SZ);
}

Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;

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
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(Fixed const& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return *this;
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
