/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot
** File description:
** core
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
#include "link_library/dlib.hpp"
#include "../lib/games/IGame.hpp"
#include "../lib/ILib.hpp"

class core {
    public:
        IGame &game_call(dlib d, core c, std::string path);
        ILib &graphic_call(dlib d, core c, std::string path);

        void *libhandle_game;
        void *entryPoint_game;
        void *libhandle_graph;
        void *entryPoint_graph;

        std::string nibbler_path = "./lib/arcade_nibbler.so";
        std::string pacman_path = "./lib/arcade_pacman.so";
        std::string ncurse_path = "./lib/arcade_ncurses.so";
        std::string sfml_path = "./lib/arcade_sfml.so";
        std::string sdl_path = "./lib/arcade_sdl2.so";

        int choosenLib = 0;
        int tmp = 0;
    protected:
    private:

};