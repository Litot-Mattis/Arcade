/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot [WSL: Ubuntu-18.04]
** File description:
** main
*/

#include "core.hpp"
#include <unistd.h>
#include <iostream>

IGame &core::game_call(dlib d, core c, std::string path)
{
    libhandle_game = d.open(path.c_str(), RTLD_LAZY);
    entryPoint_game = d.get_dlsym(libhandle_game, "entryPoint");
    IGame &lib = reinterpret_cast<IGame &(*)()>(entryPoint_game)();
    return (lib);
}

ILib &core::graphic_call(dlib d, core c, std::string path)
{
    libhandle_graph = d.open(path.c_str(), RTLD_LAZY);
    entryPoint_graph = d.get_dlsym(libhandle_graph, "entryPoint");
    ILib &lib = reinterpret_cast<ILib &(*)()>(entryPoint_graph)();
    return (lib);
}

int coreLoop(char **av)
{
    std::string pathGraph(av[1]);
    dlib d;
    core c;
    std::string path = "./lib/arcade_nibbler.so";
    while (1) {
        std::cout << "DEBUG: Lib choosen: " << pathGraph << std::endl;
        if (pathGraph == "./lib/arcade_ncurses.so" || pathGraph == "./lib/arcade_sfml.so" || pathGraph == "./lib/arcade_sdl2.so") {
            if (path == "./lib/arcade_nibbler.so" || path == "./lib/arcade_pacman.so") {
                MENU:
                ILib &graph1 = c.graphic_call(d, c, pathGraph);
                if (c.tmp == 10)
                    c.choosenLib = 10;
                if (c.tmp == 11)
                    c.choosenLib = 11;
                if (c.choosenLib != 10 && c.choosenLib != 11) {
                    graph1.init();
                    // graph1.setAsciiGameName(lib.getName());

                    graph1.createWinMenu();
                    // lib.init();
                    // lib.stop();
                    // std::cout << lib.getName() << std::endl;

                    c.choosenLib = graph1.menuLoop();
                    // graph1.stop();
                }
                bool exitFlag = false;
                if (c.choosenLib == 10) {
                    path = c.nibbler_path;
                }
                if (c.choosenLib == 11) {
                    path = c.pacman_path;
                }
                IGame &lib = c.game_call(d, c, path);
                if (c.choosenLib == 1) {
                    pathGraph = c.ncurse_path;
                    lib.setPathMap("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/games/pacman/map.txt");
                }
                if (c.choosenLib == 3) {
                    pathGraph = c.sfml_path;
                    lib.setPathMap("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/games/pacman/map2.txt");
                }
                if (c.choosenLib == 4) {
                    pathGraph = c.sdl_path;
                }
                while (c.choosenLib == 11) {
                    graph1.stop();
                    graph1.initPac(lib.play());
                    graph1.showMapPac(lib.play());
                    // graph1.showPacman(lib.getSnakeCoord(), static_cast<Direction>(lib.getDir()), lib.getSizeSnake(), lib.getField());
                    while (!exitFlag) {
                        lib.set_direction(static_cast<Directions>(graph1.getKey()));
                        int i = lib.make_move();
                        graph1.showPacman(lib.getSnakeCoord(), static_cast<Direction>(lib.getDir()), lib.getSizeSnake(), lib.getField());
                        if (i == 2) {
                            graph1.showMapPac(lib.getField());
                        } if (i == 1) {
                            graph1.showPacman(lib.getSnakeCoord(), static_cast<Direction>(lib.getDir()), lib.getSizeSnake(), lib.getField());
                        } if (i == 9) {
                            // std::cout << "DEBUG: je passe 3" << std::endl;
                            //exitFlag = false;
                        }
                        c.choosenLib = graph1.getLibChoice();
                        if (c.choosenLib == 1 || c.choosenLib == 3 || c.choosenLib == 4) {
                            graph1.closeGame();
                            if (c.choosenLib == 1)
                                pathGraph = c.ncurse_path;
                            if (c.choosenLib == 3)
                                pathGraph = c.sfml_path;
                            if (c.choosenLib == 4)
                                pathGraph = c.sdl_path;
                            c.tmp = 11;
                            goto MENU;
                        }
                        if (c.choosenLib == 100) {
                            if (pathGraph == c.ncurse_path)
                                c.choosenLib = 1;
                            if (pathGraph == c.sfml_path)
                                c.choosenLib = 3;
                            if (pathGraph == c.sdl_path)
                                c.choosenLib = 4;
                            goto MENU;
                            graph1.closeGame();
                        }
                    }
                }
                while (c.choosenLib == 10) {
                    graph1.stop();
                    restartGame:
                    graph1.initGame(lib.play());
                    graph1.show(lib.play());
                    //lib.add_random_fruit();
                    while (!exitFlag) {
                        lib.set_direction(static_cast<Directions>(graph1.getKey()));
                        int i = lib.make_move();
                        if (i == 2) {
                            graph1.show(lib.getField());
                        }
                        if (i == 1)
                            graph1.showSnake(lib.getSnakeCoord(), static_cast<Direction>(lib.getDir()), lib.getSizeSnake(), lib.getField());
                        if (i == 9 && pathGraph == c.ncurse_path) {
                            exitFlag = true;
                            graph1.endgame(lib.getSizeSnake());
                        }
                        c.choosenLib = graph1.getLibChoice();
                        if (c.choosenLib == 1 || c.choosenLib == 3 || c.choosenLib == 4) {
                            graph1.closeGame();
                            if (c.choosenLib == 1)
                                pathGraph = c.ncurse_path;
                            if (c.choosenLib == 3)
                                pathGraph = c.sfml_path;
                            if (c.choosenLib == 4)
                                pathGraph = c.sdl_path;
                            c.tmp = 10;
                            goto MENU;
                        }
                        if (c.choosenLib == 110) {
                            graph1.closeGame();
                            goto restartGame;
                        }
                        if (c.choosenLib == 100) {
                            if (pathGraph == c.ncurse_path)
                                c.choosenLib = 1;
                            if (pathGraph == c.sfml_path)
                                c.choosenLib = 3;
                            if (pathGraph == c.sdl_path)
                                c.choosenLib = 4;
                            goto MENU;
                            graph1.closeGame();
                        }
                    }
                }
                c.choosenLib = 0;
                graph1.stop();
            } else {
                std::cerr << "ERROR: You must type an existant library game"
                << std::endl;
                exit (84);
            }
        } else {
            std::cerr << "ERROR: You must type an existant graphic library"
            << std::endl;
            exit (84);
        }
    }
    d.close_lib(c.libhandle_game);
    d.close_lib(c.libhandle_graph);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "USAGE: ./arcade <./arcade_'*'>\n\t'*' = ncurse, sfml, sdl."
        << std::endl;
        exit (84);
    }
    coreLoop(av);
}
