#include "snake.hpp"
#include "field.hpp"
#include <cmath>
#include <ncurses.h>
#include <chrono>

extern "C" void Snake::init()
{

}

extern "C" void Snake::stop()
{

}

extern "C" void Snake::increase_size()
{
    size++;
}

extern "C" void Snake::eat_fruit(std::size_t y, std::size_t x)
{
    updateMap[y][x] = 0;
    y=0, x=0;

    while (updateMap[y][x] != 0) {
        y = dist_y(engine);
        x = dist_x(engine);
    }

    updateMap[y][x] = static_cast<char>(Color::red);
}


extern "C" int Snake::make_move()
{
    auto coord = coordinates.front();
    // clock_t time = clock() - mainTime;
    // float sec = (float)time/CLOCKS_PER_SEC;
    // if (sec > 0.01) {
    //     mainTime= clock();
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
    // }
    }
    if (updateMap[coord.first][coord.second] == static_cast<char>(Color::red)) {
        increase_size();
        eat_fruit(coord.first, coord.second);
        return 2;
    }
    if( updateMap[coord.first][coord.second]!= 0) {
        if ((coord.first >= 4 && coord.second >= 10) || coord.first <= 48){
            return 9;
        }
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

extern "C" void Snake::set_direction(Directions dir)
{
    if (std::abs(static_cast<int>(dir) - static_cast<int>(next_dir)) >= 2) {
        next_dir = dir;
    }
}

extern "C" Directions Snake::getDir()
{
    return next_dir;
}

extern "C" std::vector<std::vector<char>> Snake::getField()
{
    return updateMap;
}

extern "C" std::deque<std::pair<std::size_t, std::size_t>> Snake::getSnakeCoord()
{
    return coordinates;
}

extern "C" std::size_t Snake::getSizeSnake()
{
    return size;
}

extern "C" std::vector<std::vector<char>> Snake::play()
{
    using namespace std::chrono;
    Field fielder;
    Field* f = &fielder;
    field = f;
    size = 4;
    // coordinates;
    next_dir = Directions::Right;
    auto y = field->height() / 2;
    auto x = field->width() / 2;
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
    return updateMap;
}

extern "C" void Snake::add_random_fruit() {

}


extern "C" IGame &entryPoint()
{
    static Snake all_functions;
    return all_functions;
}