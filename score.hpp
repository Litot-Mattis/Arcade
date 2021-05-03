/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot
** File description:
** score
*/

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

class score{
    public:
        ~score() = default;
        void createfolder();
        int readFile(std::string scoreS);
    private:
};