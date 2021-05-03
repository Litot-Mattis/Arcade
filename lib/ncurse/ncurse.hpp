/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot
** File description:
** ncurse
*/

#pragma once

#include "../ILib.hpp"
#include <iostream>
#include <ncurses.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include <deque>

enum class Color {
    red=1, green, white, cyan
};

class ncurse: public ILib{
    public:
        ~ncurse() = default;

        void init();
        void stop();

        void printAtCoord(int x, int y);
        void createWinMenu();
        int menuLoop();

        void setAsciiGameName(const std::string nameGame) { asciiName = nameGame; }

        const std::string &getName() const { return name; }
        int getLibChoice() const { return chooseLib; }
        int getGameChoice() const { return chooseGame; };

        void clearMenu();
        void refreshMenu();
        void responsiveMenu();
        int keyInput();
        void resizeMenu();
        void choosenLib();
        void selector();
        void drawBox();
        void displayAscii(WINDOW *win, const char *Ascii[], int size, int pos_y);




        void initGame(std::vector<std::vector<char>> field);
        void closeGame();
        void show(std::vector<std::vector<char>> field);
        void showSnake(std::deque<std::pair<std::size_t, std::size_t>> coordinate, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap);
        void showPacman(std::deque<std::pair<std::size_t, std::size_t>> coordinates, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap);
        void endgame(std::size_t score);

        Direction getKey();

        void initPac(std::vector<std::vector<char>> field);
        void showMapPac(std::vector<std::vector<char>> field);
        std::deque<std::pair<std::size_t, std::size_t>> coordinates;
    private:
        std::size_t x, y, numfruits;
        std::vector<std::vector<char>> field;
        std::random_device seeder;
        std::mt19937 engine;
        std::uniform_int_distribution<std::size_t> dist_x, dist_y;
        Direction next_dir;
        Direction save_dir = Direction::Right;






        WINDOW *haut, *bas;
        WINDOW *field_left, *middle, *field_right, *score;
        MEVENT event;
        std::string playerName;
        std::string asciiName;
        std::string name = "ncurse Lib";
        int score_size = 3;
        int zx, zy, sx, sy, parent_x, parent_y, new_x, new_y;
        const char *scoreAscii[7] = {"    ___                 ","   / __| __ ___ _ _ ___ ","   \\__ \\/ _/ _ \\ '_/ -_)","   |___/\\__\\___/_| \\___|", "\0"};
        const char *arcadeAscii[7] = {"                               _      ", "       /\\                     | |     ", "      /  \\   _ __ ___ __ _  __| | ___ ", "     / /\\ \\ | '__/ __/ _` |/ _` |/ _ \\", "    / ____ \\| | | (_| (_| | (_| |  __/", "   /_/    \\_\\_|  \\___\\__,_|\\__,_|\\___|", "\0"};
        const char *gamesAscii[5] = {"     ___                ","    / __|__ _ _ __  ___ ","   | (_ / _` | '  \\/ -_)","    \\___\\__,_|_|_|_\\___|","\0"};
        const char *libAscii[8] = {"    _     _  _    ", "   | |   (_)| |__ ", "   | |__ | || '_ \\", "   |____||_||_.__/", "\0"};
        int chooseLib = 1;
        int cu = 0, sf = 0, sd = 0, pacman = 0, nibbler = 0, nameMode = 0, nameColor = 0, play = 0, exitg = 0;
        int chooseGame = 1;
};