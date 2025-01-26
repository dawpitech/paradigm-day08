/*
** EPITECH PROJECT, 2025
** ex01
** File description:
** DroidMemory.cpp
*/

#include "DroidMemory.hpp"
#include "Droid.hpp"

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

DroidMemory& DroidMemory::operator=(const DroidMemory& other)
{
    this->setFingerprint(other.getFingerprint());
    this->setExp(other.getExp());
    return *this;
}

DroidMemory& DroidMemory::operator<<(DroidMemory& other)
{
    this->setExp(this->getExp() + other.getExp());
    this->setFingerprint(other.getFingerprint() ^ this->getFingerprint());
    return *this;
}

DroidMemory& DroidMemory::operator>>(DroidMemory& other) const
{
    other.setExp(this->getExp() + other.getExp());
    other.setFingerprint(other.getFingerprint() ^ this->getFingerprint());
    return other;
}

DroidMemory& DroidMemory::operator+=(DroidMemory& other)
{
    return *this << other;
}

DroidMemory& DroidMemory::operator+=(size_t exp)
{
    this->setExp(this->getExp() + exp);
    this->setFingerprint(this->getFingerprint() ^ exp);
    return *this;
}

DroidMemory& DroidMemory::operator+(DroidMemory& other)
{
    return DroidMemory(other) += other;
}

DroidMemory& DroidMemory::operator+(size_t exp)
{
    return DroidMemory(*this) += exp;
}

bool DroidMemory::operator==(const DroidMemory& other) const
{
    return this->getExp() == other.getExp() &&
        this->getFingerprint() == other.getFingerprint();
}

bool DroidMemory::operator!=(const DroidMemory& other) const
{
    // ReSharper disable once CppRedundantComplexityInComparison
    return !(this == &other);
}

bool DroidMemory::operator>(const DroidMemory& other) const
{
    return this->getExp() > other.getExp();
}

bool DroidMemory::operator<(const DroidMemory& other) const
{
    return this->getExp() < other.getExp();
}

bool DroidMemory::operator>=(const DroidMemory& other) const
{
    return this->getExp() >= other.getExp();
}

bool DroidMemory::operator<=(const DroidMemory& other) const
{
    return this->getExp() <= other.getExp();
}

bool DroidMemory::operator>(const size_t other) const
{
    return this->getExp() > other;
}

bool DroidMemory::operator<(const size_t other) const
{
    return this->getExp() < other;
}

bool DroidMemory::operator>=(const size_t other) const
{
    return this->getExp() >= other;
}

bool DroidMemory::operator<=(const size_t other) const
{
    return this->getExp() <= other;
}

std::ostream &operator<<(std::ostream& os, const DroidMemory &droid_memory)
{
    os << "DroidMemory '" << droid_memory.getFingerprint() << "', "
        << droid_memory.getExp();
    return os;
}
