/*
** EPITECH PROJECT, 2025
** ex00
** File description:
** Droid.hpp
*/

#ifndef DROID_HPP
    #define DROID_HPP

    #include <string>

class Droid
{
public:
    explicit Droid(std::string serial = "");
    ~Droid();
    Droid(const Droid& droid);

    bool operator==(const Droid& other) const;
    bool operator!=(const Droid& other) const;
    size_t& operator<<(size_t& given);
    Droid& operator=(const Droid& droid);

    std::string getId() const { return this->_id; }
    size_t getEnergy() const { return this->_energy; }
    size_t getAttack() const { return this->_attack; }
    size_t getToughness() const { return this->_toughness; }
    std::string* getStatus() const { return this->_status; }

    void setId(std::string id) { this->_id = id; }
    void setEnergy(size_t energy);
    void setStatus(std::string* status) { this->_status = status; }

    protected:
        std::string _id;
        size_t _energy = 50;
        const size_t _attack = 25;
        const size_t _toughness = 15;
        std::string* _status;
};

std::ostream& operator<<(std::ostream& lhs, const Droid& rhs);
#endif //DROID_HPP
