#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	: mIndex(0)
{
	for (size_t index = 0; index < 4; index++)
	{
		this->mMateria[index] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const& org)
{
	*this = org;
}

MateriaSource::~MateriaSource()
{
	for (size_t index = 0; index < this->mIndex; index++)
	{
		delete this->mMateria[index];
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->mIndex = org.getIndex();
	for (size_t index = 0; index < 4; index++)
	{
		AMateria* tmp = org.getMateria(index);
		if (this->mMateria[index])
		{
			delete this->mMateria[index];
		}
		this->mMateria[index] = tmp ? tmp : NULL;
	}
	return *this;
}

AMateria* MateriaSource::getMateria(size_t index) const
{
	return this->mMateria[index];
}

size_t MateriaSource::getIndex(void) const
{
	return this->mIndex;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (this->mIndex < 4)
	{
		this->mMateria[this->mIndex] = materia;
		this->mIndex++;
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	AMateria* newMateria = NULL;
	AMateria* tmp = this->mMateria[0];
	size_t index = 0;

	while (tmp)
	{
		if (tmp->getType() == type)
		{
			newMateria = tmp->clone();
			break;
		}
		index++;
		tmp = this->mMateria[index];
	}
	return newMateria;
}