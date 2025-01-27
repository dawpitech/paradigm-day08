/*
** EPITECH PROJECT, 2025
** ex01
** File description:
** DroidMemory.cpp
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    this->_exp = 0;
    this->_fingerprint = random();
}

DroidMemory::DroidMemory(const DroidMemory& other)
{
    this->_exp = other.getExp();
    this->_fingerprint = other.getFingerprint();
}

DroidMemory& DroidMemory::operator<<(DroidMemory& other)
{
    this->setExp(this->getExp() + other.getExp());
    this->setFingerprint(other.getFingerprint() ^ this->getFingerprint());
    return *this;
}

const DroidMemory& DroidMemory::operator>>(DroidMemory& other) const
{
    other.setExp(this->getExp() + other.getExp());
    other.setFingerprint(other.getFingerprint() ^ this->getFingerprint());
    return *this;
}

const DroidMemory& DroidMemory::operator+=(DroidMemory& other)
{
    this->setExp(this->getExp() + other.getExp());
    this->setFingerprint(other.getFingerprint() ^ this->getFingerprint());
    return *this;
}

const DroidMemory& DroidMemory::operator+=(size_t exp)
{
    this->setExp(this->getExp() + exp);
    this->setFingerprint(this->getFingerprint() ^ exp);
    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory& other) const
{
    DroidMemory mem(*this);
    mem.setExp(mem.getExp() + other.getExp());
    mem.setFingerprint(mem.getFingerprint() ^ other.getFingerprint());
    return mem;
}

DroidMemory DroidMemory::operator+(const size_t exp) const
{
    DroidMemory mem(*this);
    mem.setExp(mem.getExp() + exp);
    mem.setFingerprint(mem.getFingerprint() + exp);
    return mem;
}

std::ostream &operator<<(std::ostream& os, const DroidMemory &droid_memory)
{
    os << "DroidMemory '" << droid_memory.getFingerprint() << "', "
        << droid_memory.getExp();
    return os;
}
