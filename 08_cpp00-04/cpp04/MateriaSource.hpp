#pragma once
#ifndef __MATERIA_SOURCE_H__
#define __MATERIA_SOURCE_H__

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(MateriaSource const& org);
	~MateriaSource();
	MateriaSource& operator=(MateriaSource const& org);

	AMateria* getMateria(size_t index) const;
	size_t getIndex(void) const;

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const& type);
private:
	AMateria* mMateria[4];
	size_t mIndex;
};

#endif