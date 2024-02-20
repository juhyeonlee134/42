#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	: mFixedNum(0)
{}

Fixed::Fixed(int const num)
{
	this->mFixedNum = num << this->FRAC_SZ;
}

Fixed::Fixed(float const num)
{
	float roundNum = roundf(static_cast<float>(num * (1 << this->FRAC_SZ)));
	roundNum /= (1 << this->FRAC_SZ);

	Float orgNum;
	orgNum.num = roundNum;

	unsigned int sign = (orgNum.bit >> (EXP_SZ + MTS_SZ)) & 1;
	unsigned int exp = ((orgNum.bit >> MTS_SZ) & BYT_MSK) - TO_R_EXP;
	unsigned int mts = (orgNum.bit & MTS_MSK) | (1 << MTS_SZ);

	int intFixed = (mts >> (MTS_SZ - exp)) * (sign ? (-1) : 1);
	unsigned char floatFixed = (mts & MTS_MSK) >> (MTS_SZ - EXP_SZ - exp);

	unsigned int retBit = (intFixed << this->FRAC_SZ) | floatFixed;
	this->setRawBits(retBit);
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
	int orgBit = this->getRawBits();

	int intFixed = orgBit >> this->FRAC_SZ;
	unsigned char floatFixed = orgBit & BYT_MSK;

	unsigned int sign = orgBit < 0;
	intFixed *= (sign ? (-1) : 1);
	unsigned int exp = 0;
	{
		unsigned int tmp = intFixed;
		while (tmp != 1)
		{
			tmp = tmp >> 1;
			exp++;
		}
	}
	unsigned int mts = (intFixed << (MTS_SZ - exp)) | (floatFixed << (MTS_SZ - EXP_SZ - exp));
	exp += TO_R_EXP;
	mts ^= (1 << MTS_SZ);

	Float ret;
	ret.bit = (sign << (EXP_SZ + MTS_SZ)) | (exp << MTS_SZ) | mts;
	return ret.num;
}

int Fixed::toInt(void) const
{
	int num = this->getRawBits();
	
	return num >> this->FRAC_SZ;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixedNum)
{
	os << fixedNum.toFloat();
	return os;
}
