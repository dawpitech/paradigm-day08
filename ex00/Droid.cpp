/*
** EPITECH PROJECT, 2025
** ex00
** File description:
** Droid.cpp
*/

#include <algorithm>
#include <iostream>
#include <ostream>

#include "Droid.hpp"

Droid::Droid(std::string serial)
{
    this->_id = serial;
    this->_status = new std::string("Standing by");
    std::cout << "Droid '" << this->_id << "' Activated\n";
}

Droid::~Droid()
{
    delete this->_status;
    std::cout << "Droid '" << this->_id << "' Destroyed\n";
}

Droid::Droid(const Droid& droid):
    _attack(droid.getAttack()), _toughness(droid.getToughness())
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    this->_status = new std::string(*droid._status);
    std::cout << "Droid '" << this->_id << "' Activated, Memory Dumped\n";
}

bool Droid::operator==(const Droid& other) const
{
    return this->getId() == other.getId()
        && this->getEnergy() == other.getEnergy()
        && this->getAttack() == other.getAttack()
        && this->getToughness() == other.getToughness()
        && *this->getStatus() == *other.getStatus();
}

bool Droid::operator!=(const Droid& other) const
{
    // ReSharper disable once CppRedundantComplexityInComparison
    return !(this == &other);
}

size_t& Droid::operator<<(size_t& given)
{
    if (const auto needed = 100 - this->_energy; given < needed){
        this->_energy += given;
        given = 0;
    } else {
        this->_energy += needed;
        given -= needed;
    }
    return given;
}

std::ostream& operator<<(std::ostream& lhs, const Droid& rhs)
{
    lhs << "Droid '" << rhs.getId() <<"', " << *rhs.getStatus()
        << ", " << rhs.getEnergy();
    return lhs;
}

Droid& Droid::operator=(const Droid& droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    delete this->_status;
    this->_status = droid._status;
    return *this;
}

void Droid::setEnergy(size_t energy)
{
    this->_energy = std::clamp(
        energy,
        static_cast<size_t>(0),
        static_cast<size_t>(100)
    );
}
