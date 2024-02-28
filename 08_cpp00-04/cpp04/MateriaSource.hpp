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
    MateriaSource& operator = (MateriaSource const& org);
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
private:
    AMateria* mMateria[4];
    size_t mMateriaIndex;
};

#endif