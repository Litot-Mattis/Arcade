/*
** EPITECH PROJECT, 2021
** SDL2
** File description:
** sfm
*/

#pragma once

#include "../ILib.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <fstream>
#include <map>
#include <vector>

enum class Color {
    red=1, green, white, cyan
};

class sfml: public ILib
{
    public:
        ~sfml() = default;
        void init();
        void stop();

        void printAtCoord(int x, int y);
        void createWinMenu();
        int menuLoop();

        void setAsciiGameName(const std::string nameGame) { asciiName = nameGame; }

        const std::string &getName() const { return name; }
        int getLibChoice() const { return chooseLib; }
        int getGameChoice() const { return gameSelected; };
        void loopMenu();
        void eventMenu(sf::Event event);

        std::map<int, std::string> parsing(std::string filename);
        int trumpAni(int x, int y);
        void initPac(std::vector<std::vector<char>> field);
        void showMapPac(std::vector<std::vector<char>> field);
        void initMap();

        void initGame(std::vector<std::vector<char>> field);
        void closeGame();
        void show(std::vector<std::vector<char>> field);
        void showSnake(std::deque<std::pair<std::size_t, std::size_t>> coordinate, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap);
        void showPacman(std::deque<std::pair<std::size_t, std::size_t>> coordinates, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap);
        void endgame(std::size_t score);
        Direction getKey();
        Direction save_dir = Direction::Right;
    private:
        std::size_t x, y, numfruits;

        sf::Sprite spriteW;
        sf::Texture textureW;
        std::vector<sf::Sprite> spriteWall;
        sf::Sprite spriteB;
        sf::Texture textureB;
        std::vector<sf::Sprite> spriteBurger;
        sf::Sprite spriteS;
        sf::Texture textureS;
        std::vector<sf::Sprite> spriteSnake;
        sf::Texture tTrump;
        sf::Sprite sTrump;
        sf::Texture tAmerica;
        sf::Sprite sAmerica;
        sf::Texture tHighlight;
        sf::Sprite sHiglight;
        sf::Clock clock;
        sf::Event event;
        int trumpX = 0;
        int trumpY = 0;
        int trumpPos = 0;



        std::string asciiName;
        std::string name;
        int chooseGame = 1;
        int chooseLib = 3;
        sf::RenderWindow window;
        sf::Texture pTexture;
        sf::Texture playTexture;
        sf::Texture exitTexture;
        sf::Texture arcadeTexture;
        sf::Sprite pSprite;
        sf::Sprite playSprite;
        sf::Sprite exitSprite;
        sf::Sprite arcadeSprite;
        sf::Font font;
        sf::Text game1;
        sf::Text game2;
        sf::Text motor1;
        sf::Text motor2;
        sf::Text motor3;
        sf::Mouse mouse;
        sf::Vector2i mousePos;
        int gameSelected = 0;
        int motorSelected = 0;
        int loopArcade = 0;
        int randArcade;
        sf::IntRect arcadeRect;
};