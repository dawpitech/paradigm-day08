/*
** EPITECH PROJECT, 2025
** ex01
** File description:
** DroidMemory.hpp
*/

#ifndef DROIDMEMORY_HPP
    #define DROIDMEMORY_HPP
#include <ostream>

class DroidMemory
{
    public:
        explicit DroidMemory();
        DroidMemory(const DroidMemory& other);
        DroidMemory& operator<<(DroidMemory &other);
        DroidMemory& operator>>(DroidMemory &other) const;
        DroidMemory& operator+=(DroidMemory& other);
        DroidMemory& operator+=(size_t exp);
        DroidMemory& operator+(DroidMemory& other);
        DroidMemory& operator+(size_t exp);

        size_t getFingerprint() const { return this->_fingerprint; }
        size_t getExp() const { return this->_exp; }

        void setFingerprint(size_t fingerprint) { this->_fingerprint = fingerprint; }
        void setExp(size_t exp) { this->_exp = exp; }
    protected:
        size_t _fingerprint;
        size_t _exp;
};
std::ostream &operator<<(std::ostream& os, const DroidMemory &droid_memory);
#endif //DROIDMEMORY_HPP
