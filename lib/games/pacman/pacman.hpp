#pragma once


#include <deque>
#include <utility>
#include "../IGame.hpp"
#include "field.hpp"

class Field;

class Pacman: public IGame{
private:
    std::string pathMap;
    Field* field;
    std::size_t numfruits;
    std::size_t size;
    std::deque<std::pair<std::size_t, std::size_t>> coordinates;

    Directions next_dir;
    std::string name = "Nibbler";
    std::vector<std::vector<char>> updateMap;
    std::random_device seeder;
    std::mt19937 engine;

    clock_t mainTime = clock();
    std::uniform_int_distribution<std::size_t> dist_x, dist_y;
public:
    ~Pacman() = default;
    std::vector<std::vector<char>> play();
    std::vector<std::vector<char>> getField();
    std::deque<std::pair<std::size_t, std::size_t>> getSnakeCoord();
    void eat_fruit(std::size_t y, std::size_t x);
    void add_random_fruit();

    std::size_t getSizeSnake();
    void setPathMap(std::string path) { pathMap = path; } ;
    std::string getPathMap() {  return pathMap; } ;

    void init();
    void stop();

    const std::string &getName() const { return name; }

    void show();
    int make_move();
    void increase_size();
    void set_direction(Directions dir);
    Directions getDir();
    std::pair<std::size_t, std::size_t> get_coordinate() const {return coordinates.front();}
    std::size_t score() const {return size;}
};
