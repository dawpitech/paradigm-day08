/*
** EPITECH PROJECT, 2025
** ex00
** File description:
** main.cpp
*/

#include <iostream>

#include "DroidMemory.hpp"

int main()
{
    DroidMemory mem1;
    mem1 += 42;
    DroidMemory mem2 = mem1;
    std::cout << mem1 << std::endl;
    DroidMemory mem3;
    mem3 << mem1;
    mem3 >> mem1;
    mem3 << mem1;
    std::cout << mem3 << std::endl;
    std::cout << mem1 << std::endl;
}
