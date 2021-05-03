/*
** EPITECH PROJECT, 2021
** SDL2
** File description:
** menu
*/

#pragma once

#include "../ILib.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <string>
#include <map>

enum class Color {
    red=1, green, white, cyan
};

class sdl: public ILib {
    public:
        ~sdl() = default;
        //sdl();

        void init();
        void stop();

        void printAtCoord(int x, int y);
        void createWinMenu();
        int menuLoop();

        void setAsciiGameName(const std::string nameGame) { asciiName = nameGame; }

        const std::string &getName() const { return name; }
        int getLibChoice() const { return chooseLib; }
        int getGameChoice() const { return chooseGame; };
        void loopMenu();
        void eventMenu();



        void initPac(std::vector<std::vector<char>> field);
        void showMapPac(std::vector<std::vector<char>> field);

        void initGame(std::vector<std::vector<char>> field);
        void closeGame();
        void show(std::vector<std::vector<char>> field);
        void showSnake(std::deque<std::pair<std::size_t, std::size_t>> coordinate, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap);
        void endgame(std::size_t score);
        void showPacman(std::deque<std::pair<std::size_t, std::size_t>> coordinates, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap);
        Direction getKey();


        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Window *windowPac;
        SDL_Renderer *rendererPac;
        SDL_Event event;
    private:
        Direction save_dir = Direction::Right;
        SDL_Texture *pTexture;
        SDL_Texture *sTrump;
        SDL_Texture *playTexture;
        SDL_Texture *exitTexture ;
        SDL_Texture *arcadeTexture;
        SDL_Rect playPos;
        SDL_Rect exitPos;
        SDL_Rect arcadePos;
        SDL_Rect playRect;
        SDL_Rect exitRect;
        SDL_Rect arcadeRect;
	    TTF_Font *font;
        SDL_Color White;
        SDL_Color Purple;
        SDL_Rect gameRect;
        SDL_Rect gameRect2;
        SDL_Rect motorRect;
        SDL_Rect motorRect2;
        SDL_Rect motorRect3;
        std::string game1 = "PAC-MAN";
        SDL_Surface *game1Surface;
        SDL_Texture *game1Texture;
        SDL_Rect game1Pos;
        std::string game2 = "NIBBLER";
        SDL_Surface *game2Surface;
        SDL_Texture *game2Texture;
        SDL_Rect game2Pos;
        std::string motor1 = "NCURSE";
        SDL_Surface *motor1Surface;
        SDL_Texture *motor1Texture;
        SDL_Rect motor1Pos;
        std::string motor2 = "SFML";
        SDL_Surface *motor2Surface;
        SDL_Texture *motor2Texture;
        SDL_Rect motor2Pos;
        std::string motor3 = "SDL2";
        SDL_Surface *motor3Surface;
        SDL_Texture *motor3Texture;
        SDL_Rect motor3Pos;
        SDL_AudioSpec wavSpec;
        Uint32 wavLength;
        Uint8 *wavBuffer;
        SDL_AudioDeviceID deviceId;
        int mouseX = 0;
        int mouseY = 0;
        int loopArcade = 0;
        int randArcade = 0;
        int gameSelected = 0;
        int motorSelected = 0;
        std::map<SDL_Texture *, SDL_Rect> spriteWall;
        std::map<SDL_Texture *, SDL_Rect> spriteBurger;
        SDL_Rect scaleMap = {25/2, 25/2, 25, 25};
        int trumpX = 0;
        int trumpY = 0;
        int trumpPos = 0;

        std::string name = "ncurse Lib";
        std::string asciiName;
        int chooseLib = 4;
        int chooseGame = 1;
};