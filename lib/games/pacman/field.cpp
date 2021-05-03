#include "field.hpp"
#include "pacman.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <ncurses.h>

//----------------------------coregraphique----------------------------
extern "C" Field::Field(std::size_t y_size, std::size_t x_size)
    : x{x_size}, y{y_size}, numfruits{0}, field{}, seeder{}, engine{seeder()}
{
    int test_x = 122, test_y = 33; // si le jeux ressemble a rien c'est ici qu'il faut voir
    if (x == 1 and y == 1) {
        y = test_y - 2;
        x = test_x - 2;
    }
    else {
        if (x+2 > test_x) x = test_x-2;
        if (y+2 > test_y) y = test_y-2;
    }

    dist_x = std::uniform_int_distribution<std::size_t>(0, x-1);
    dist_y = std::uniform_int_distribution<std::size_t>(0, y-1);

    init_field();
}

extern "C" Field::~Field()
{
}
//----------------------------coregame----------------------------
extern "C" void Field::init_field()
{
    field = std::vector<std::vector<char>> (y, std::vector<char>(x, 0));

    std::fill(field[0].begin(), field[0].end(), static_cast<char>(Color::white));
    std::fill(field.back().begin(), field.back().end(), static_cast<char>(Color::white));

    for (auto& row: field) {
        row.back() = static_cast<char>(Color::white);
        row.front() = static_cast<char>(Color::white);
    }
    add_random_obstacle();
    //add_random_fruit();
}
//----------------------------CoreGraphique----------------------------

//----------------------------Coregame----------------------------
extern "C" std::map<int, std::string> Field::parsing(std::string filename)
{
    std::map<int, std::string> map;
    std::fstream file;
    std::string save;
    int i = 0;

    file.open(filename);
    std::getline(file, save);
    while (save != "")
    {
        map.insert(std::make_pair(i, save));
        std::getline(file, save);
        i += 1;
    }
    return map;
}

extern "C" void Field::add_random_obstacle()
{
    // Pacman *p;
    std::size_t y=0, x=0;
    std::map<int, std::string> map = parsing("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/games/pacman/map.txt");

    for (int i = 0; i <= 27 ; i++){
        for (int j = 0; j <= 28; j++){
            if (map[i][j] == '#') {
                y = i + 1;
                x = j + 1;
                field[y][x] = static_cast<char>(Color::white);
            }
        }
    }
    // field[16][15] = ' ';
}
//----------------------------coregame----------------------------
extern "C" void Field::add_random_fruit()
{
    // std::size_t y=0, x=0;
    for (int i = 0; i <= 29; i++)
        for (int j = 0; j <= 29; j++)
            if(field[i][j] == 0){
                field[i][j] = static_cast<char>(Color::red);
                numfruits++;
            }
}

//----------------------------coregraphique----------------------------

//----------------------------coregame----------------------------
extern "C" void Field::eat_fruit(std::size_t y, std::size_t x)
{
    --numfruits;
    field[y][x] = 0;
}