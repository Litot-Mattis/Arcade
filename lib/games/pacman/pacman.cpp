#include "pacman.hpp"
#include "field.hpp"
#include <cmath>
#include <ncurses.h>
#include <chrono>
#include <ctime>
#include <cmath>
#include <unistd.h>
#include <iostream>

extern "C" void Pacman::init()
{

}

extern "C" void Pacman::stop()
{

}

extern "C" void Pacman::increase_size()
{
    //size++;
}

extern "C" void Pacman::eat_fruit(std::size_t y, std::size_t x)
{
    updateMap[y][x] = 0;
    y=0, x=0;

    while (updateMap[y][x] != 0) {
        y = dist_y(engine);
        x = dist_x(engine);
    }

    updateMap[y][x] = static_cast<char>(Color::red);
}


extern "C" int Pacman::make_move()
{
    auto coord = coordinates.front();
    clock_t time = clock() - mainTime;
    float sec = (float)time/CLOCKS_PER_SEC;
    if (sec > 0.01) {
        mainTime= clock();
    switch(next_dir) {
        case Directions::Right:
            coord.second++;
            break;
        case Directions::Left:
            coord.second--;
            break;
        case Directions::Up:
            coord.first--;
            break;
        case Directions::Down:
            coord.first++;
            break;
    }
    }
    if (updateMap[coord.first][coord.second] == static_cast<char>(Color::red)) {
        eat_fruit(coord.first, coord.second);
        return 2;
    }
    else if (updateMap[coord.first][coord.second] != 0) {
       return 9;
    }
    updateMap[coord.first][coord.second] = static_cast<char>(Color::green);
    coordinates.push_front(std::move(coord));
    if (coordinates.size() > size) {
        auto last = coordinates.back();
        updateMap[last.first][last.second] = 0;
        coordinates.pop_back();
    }
    return 1;
}

extern "C" void Pacman::set_direction(Directions dir)
{
    auto coord = coordinates.front();
    if (std::abs(static_cast<int>(dir)) || updateMap[coord.first][coord.second] == static_cast<char>(Color::green)){
        next_dir = dir;
    }
}

extern "C" Directions Pacman::getDir()
{
    return next_dir;
}

extern "C" std::vector<std::vector<char>> Pacman::getField()
{
    return updateMap;
}

extern "C" std::deque<std::pair<std::size_t, std::size_t>> Pacman::getSnakeCoord()
{
    return coordinates;
}

extern "C" std::size_t Pacman::getSizeSnake()
{
    return size;
}

extern "C" void Pacman::add_random_fruit()
{
    // std::size_t y=0, x=0;
    for (int i = 0; i <= 29; i++)
        for (int j = 0; j <= 29; j++)
            if(updateMap[i][j] == 0){
                updateMap[i][j] = static_cast<char>(Color::red);
                numfruits++;
            }
}

extern "C" std::vector<std::vector<char>> Pacman::play()
{
    using namespace std::chrono;
    Field fielder;
    Field* f = &fielder;
    field = f;
    size = 1;
    // coordinates;
    next_dir = Directions::Down;
    auto y = field->height() / 2 + 1;
    auto x = field->height() / 2 - 1;
    coordinates.emplace_back(y, x);
    dist_x = std::uniform_int_distribution<std::size_t>(0, x-1);
    dist_y = std::uniform_int_distribution<std::size_t>(0, y-1);
    fielder.init_field();

    for (std::size_t i = 1; i < size; ++i)
        if ((*field)[y][--x] == 0) {
            coordinates.emplace_back(y, x);
            (*field)[y][x] = static_cast<char>(Color::green);
        }
        else {break;}

    // auto t1 = steady_clock::now();
    updateMap = fielder.field;
    // updateMap[16][15] = ' ';
    return updateMap;
}


extern "C" IGame &entryPoint()
{
    static Pacman all_functions;
    return all_functions;
}