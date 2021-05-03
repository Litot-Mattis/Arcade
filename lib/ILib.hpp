/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot
** File description:
** ILib
*/

#pragma once

#include <iostream>
#include "Direction.hpp"
#include <vector>
#include <random>
#include <deque>

class ILib {
    public:
        virtual ~ILib() = default;

        virtual void init() = 0;
        virtual void stop() = 0;

        virtual void printAtCoord(int x, int y) = 0;
        virtual void createWinMenu() = 0;
        virtual int menuLoop() = 0;

        virtual void setAsciiGameName(const std::string nameGame) = 0;

        virtual const std::string &getName() const = 0;
        virtual int getLibChoice() const = 0;
        virtual int getGameChoice() const = 0;

        virtual void initGame(std::vector<std::vector<char>> field) = 0;
        virtual void closeGame() = 0;
        virtual void show(std::vector<std::vector<char>> field) = 0;
        virtual void showSnake(std::deque<std::pair<std::size_t, std::size_t>> coordinate, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap) = 0;
        virtual void showPacman(std::deque<std::pair<std::size_t, std::size_t>> coordinates, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap) = 0;
        virtual void endgame(std::size_t score) = 0;

        virtual void initPac(std::vector<std::vector<char>> field) = 0;
        virtual void showMapPac(std::vector<std::vector<char>> field) = 0;
        virtual Direction getKey() = 0;
    protected:
    private:
};
