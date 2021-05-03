/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot [WSL: Ubuntu-18.04]
** File description:
** IGame
*/

#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <deque>

enum class Directions {
    Up=1, Down=2, Left=5, Right=6
};

class IGame {
    public:
        virtual ~IGame() = default;
        virtual std::vector<std::vector<char>> play() = 0;
        virtual std::vector<std::vector<char>> getField() = 0;
        virtual std::deque<std::pair<std::size_t, std::size_t>> getSnakeCoord() = 0;
        virtual std::size_t getSizeSnake() = 0;
        virtual int make_move() = 0;


        virtual void init() = 0;
        virtual void stop() = 0;
        virtual void set_direction(Directions dir) = 0;
        virtual Directions getDir() = 0;
        virtual void add_random_fruit() = 0;
        virtual void setPathMap(std::string path) = 0;
        virtual std::string getPathMap() = 0;

        virtual const std::string &getName() const = 0;
    protected:
    private:
};