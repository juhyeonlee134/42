#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
    : mMateriaIndex(0)
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
    for (size_t index = 0; index < this->mMateriaIndex; index++)
    {
        delete this->mMateria[index];
    }
}

MateriaSource& MateriaSource::operator = (MateriaSource const& org)
{
    if (this == &org)
    {
        return *this;
    }
    this->mMateriaIndex = org.mMateriaIndex;
    for (size_t index = 0; index < org.mMateriaIndex; index++)
    return *this;
}