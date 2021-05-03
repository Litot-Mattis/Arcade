/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot
** File description:
** ncurse
*/

#include "ncurse.hpp"
#include <unistd.h>
#include <cstring>

extern "C" void ncurse::displayAscii(WINDOW *win, const char *Ascii[], int size, int pos_y)
{
    for (int i = 0; strcmp(Ascii[i], "\0") != 0; i++)
        mvwprintw(win, i + pos_y, size, Ascii[i]);
}

extern "C" void ncurse::clearMenu()
{
    wclear(stdscr);
    wclear(field_left);
    wclear(middle);
    wclear(field_right);
    wclear(score);
}

extern "C" void ncurse::refreshMenu()
{
    wrefresh(field_left);
    wrefresh(field_right);
    wrefresh(middle);
    wrefresh(score);
}

extern "C" void ncurse::resizeMenu()
{
    wresize(field_left, new_y - score_size, new_x);
    wresize(middle, new_y - score_size, new_x * 2);
    wresize(field_right, new_y - score_size, new_x);
    wresize(score, score_size, new_x * 4);
}

extern "C" int ncurse::keyInput()
{
    int ch = getch();

    if (ch != ERR)
    {
        ungetch(ch);
        return 1;
    }
    else
    {
        return 0;
    }
}

extern "C" void ncurse::selector()
{

    int c = wgetch(stdscr);
    // mvwprintw(middle, 20, 20, "%d", c);
    // if (c == 119)
    // {
    //     mvwprintw(middle, 19, 20, "CLicked on b");
    // } 31 52  31 65
    switch (c)
    {
        case 'q':
        case 'k':
        case KEY_EXIT:
        case 27:
            clearMenu();
            exit(0);
    }
    if (nameMode == 1)
    {
        if (c != -1)
        {
            if ((c >= 97 && c <= 127) || (c >= 65 && c <= 90))
            {
                std::stringstream ss;
                std::string s;
                char str[12];
                sprintf(str, "%c", c);
                ss << str;
                ss >> s;
                playerName += s;
                mvwprintw(score, 1, 58, playerName.c_str());
            }
        }
        if (c == KEY_UP)
        {
            playerName.clear();
            wclear(score);
        }
        // mvwprintw(middle, 25, new_x / 2 + 2, "%d", c);
        if (c == KEY_DOWN)
        {
            nameMode = 0;
            clearMenu();
        }
        wattron(score, COLOR_PAIR(3));
        mvwprintw(score, 1, 52, "Name:");
        wattroff(score, COLOR_PAIR(3));
    }
    if (nameMode == 0)
    {
        if (c == 117)
        {
            chooseLib = 3;
        }
        if (c == 105)
            chooseLib = 4;
        switch (c)
        {
        case KEY_MOUSE:
            if (getmouse(&event) == OK)
            {
                mvwprintw(middle, 20, 20, "mouse %d %d", event.y, event.x);
                // mvwprintw(middle, 21, 20, "%d %d", (new_x * 4) - 21, (new_x * 4) - 11);
                mvwprintw(middle, 21, 20, "%d %d", (new_x * 4) / 2 - 8, (new_x * 4) / 2 + 8);
                if (event.y == 31 && event.x > (new_x * 4) / 2 - 8 && event.x < (new_x * 4) / 2 + 8)
                {
                    event.x = 0, event.y = 0;
                    nameMode = 1;
                    wattron(score, COLOR_PAIR(3));
                    mvwprintw(score, 1, 52, "Name:");
                    wattroff(score, COLOR_PAIR(3));
                    mvwprintw(middle, 29, new_x / 2 + 3, "Type your Name");
                }
                else
                    nameMode = 0;
                if (event.y == 12 && event.x >= 59 && event.x <= 62)
                {
                    play = 1, exitg = 0;
                    wattron(middle, COLOR_PAIR(3));
                    mvwprintw(middle, 12, 28, "Play");
                    wattroff(middle, COLOR_PAIR(3));
                    chooseLib = 10;
                    if (pacman == 1)
                        chooseLib = 11;
                }
                else if (event.y == 16 && event.x >= 59 && event.x <= 62)
                {
                    exitg = 1, play = 0;
                    wattron(middle, COLOR_PAIR(3));
                    mvwprintw(middle, 16, 28, "Exit");
                    wattroff(middle, COLOR_PAIR(3));
                    stop();
                    exit(0);
                }
                else
                    play = 0, exitg = 0;
                if (event.y == 10 && event.x > (new_x * 4) - 21 && event.x < (new_x * 4) - 11)
                {
                    nibbler = 1, pacman = 0, chooseGame = 1;
                    wattron(field_right, COLOR_PAIR(3));
                    mvwprintw(field_right, 10, new_x / 2 - 5, "[1] Nibbler");
                    wattroff(field_right, COLOR_PAIR(3));
                }
                else if (event.y == 12 && event.x > (new_x * 4) - 21 && event.x < (new_x * 4) - 11)
                {
                    pacman = 1, nibbler = 0, chooseGame = 2;
                    wattron(field_right, COLOR_PAIR(3));
                    mvwprintw(field_right, 12, new_x / 2 - 5, "[2] Pacman");
                    wattroff(field_right, COLOR_PAIR(3));
                }
                if (event.y == 21 && event.x > (new_x * 4) - 21 && event.x < (new_x * 4) - 11)
                {
                    cu = 1, sf = 0, sd = 0;
                    wattron(field_right, COLOR_PAIR(3));
                    mvwprintw(field_right, 21, new_x / 2 - 5, "[Y] Ncurse");
                    wattroff(field_right, COLOR_PAIR(3));
                    chooseLib = 1;
                }
                else if (event.y == 23 && event.x > (new_x * 4) - 21 && event.x < (new_x * 4) - 11)
                {
                    cu = 0, sf = 1, sd = 0;
                    wattron(field_right, COLOR_PAIR(3));
                    mvwprintw(field_right, 23, new_x / 2 - 5, "[U] Sfml");
                    wattroff(field_right, COLOR_PAIR(3));
                    chooseLib = 3;
                }
                else if (event.y == 25 && event.x > (new_x * 4) - 21 && event.x < (new_x * 4) - 11)
                {
                    cu = 0, sf = 0, sd = 1;
                    wattron(field_right, COLOR_PAIR(3));
                    mvwprintw(field_right, 25, new_x / 2 - 5, "[I] Sdl");
                    wattroff(field_right, COLOR_PAIR(3));
                    chooseLib = 4;
                }
                else
                    cu = 0, sf = 0, sd = 0;
            }
        }
    }
    if (play == 0)
        mvwprintw(middle, 12, 28, "Play");
    if (exitg == 0)
        mvwprintw(middle, 16, 28, "Exit");
    if (cu == 0)
        mvwprintw(field_right, 21, new_x / 2 - 5, "[Y] Ncurse");
    if (sf == 0)
        mvwprintw(field_right, 23, new_x / 2 - 5, "[U] Sfml");
    if (sd == 0)
        mvwprintw(field_right, 25, new_x / 2 - 5, "[I] Sdl");
    if (nibbler == 0)
        mvwprintw(field_right, 10, new_x / 2 - 5, "[1] Nibbler");
    if (pacman == 0)
        mvwprintw(field_right, 12, new_x / 2 - 5, "[2] Pacman");
    if (nameMode == 0)
        mvwprintw(score, 1, 52, "Name:");
    mvwprintw(score, 1, 58, playerName.c_str());
    //clearMenu();
}

extern "C" void ncurse::responsiveMenu()
{
    wattron(field_left, COLOR_PAIR(2));
    displayAscii(field_left, scoreAscii, new_x / 2 - 14, 3);
    wattroff(field_left, COLOR_PAIR(2));
    wattron(middle, COLOR_PAIR(3));
    displayAscii(middle, arcadeAscii, new_x - 20, 1);
    wattroff(middle, COLOR_PAIR(3));
    wattron(field_right, COLOR_PAIR(2));
    displayAscii(field_right, gamesAscii, new_x / 2 - 13, 3);
    wattroff(field_right, COLOR_PAIR(2));
    wattron(field_right, COLOR_PAIR(2));
    displayAscii(field_right, libAscii, new_x / 2 - 9, 15);
    wattroff(field_right, COLOR_PAIR(2));
}

extern "C" void ncurse::choosenLib()
{
    if (keyInput())
    {
        int key = getch();
        if (key == 117)
        {
            chooseLib = 3;
            mvwprintw(field_right, 20, new_x / 2 - 5, "P");
        }
        if (key == 105)
            chooseLib = 4;
    }
    else
    {
        chooseLib = 1;
    }
}

extern "C" int ncurse::menuLoop()
{
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    clearMenu();
    while (chooseLib == 1)
    {
        drawBox();
        selector();

        getmaxyx(stdscr, new_y, new_x);
        int tmp = new_x;
        new_x = new_x / 4;

        if (new_y != parent_y || new_x != parent_x)
        {
            parent_x = new_x;
            parent_y = new_y;

            resizeMenu();

            mvwin(score, new_y - score_size, 0);
            mvwin(middle, 0, tmp / 4);
            mvwin(field_right, 0, (tmp / 4) * 3);

            clearMenu();
        }
        if (tmp >= 115)
            responsiveMenu();
        refreshMenu();
    }
    return (getLibChoice());
}

extern "C" void ncurse::drawBox()
{
    wattron(field_left, COLOR_PAIR(2));
    box(field_left, 0, 0);
    wattroff(field_left, COLOR_PAIR(2));
    wattron(field_right, COLOR_PAIR(2));
    box(field_right, 0, 0);
    wattroff(field_right, COLOR_PAIR(2));
    wattron(score, COLOR_PAIR(4));
    box(score, 0, 0);
    wattroff(score, COLOR_PAIR(4));
}

extern "C" void ncurse::createWinMenu()
{
    getmaxyx(stdscr, parent_y, parent_x);
    parent_x = parent_x / 4;

    field_left = newwin(parent_y - score_size, parent_x, 0, 0);
    getmaxyx(field_left, sy, sx);

    middle = newwin(parent_y - score_size, parent_x * 2, 0, sx + 1);
    getmaxyx(middle, zy, zx);

    field_right = newwin(parent_y - score_size, parent_x, 0, sx + zx + 1);
    score = newwin(score_size, parent_x * 4, parent_y - score_size, 0);

    drawBox();
}

extern "C" void ncurse::init()
{
    initscr();
    keypad(stdscr, TRUE);
    clear();
    noecho();
    cbreak();
    curs_set(FALSE);
    nonl();
    nodelay(stdscr, TRUE);

    chooseLib = 1;
    cu = 0, sf = 0, sd = 0, pacman = 0, nibbler = 0, nameMode = 0, nameColor = 0
    ,play = 0, exitg = 0;

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
}

extern "C" void ncurse::printAtCoord(int x, int y)
{
    timeout(1000);
    mvwprintw(stdscr, x, y, "Hello World !!!");
    wrefresh(stdscr);
    refresh();
    getch();
}

extern "C" void ncurse::stop()
{
    clearMenu();
    delwin(field_right);
    delwin(field_left);
    delwin(middle);
    delwin(score);
    endwin();
}

extern "C" void ncurse::initPac(std::vector<std::vector<char>> field)
{
    x = 28, y = 30, numfruits = 0;
    initscr();
    if (has_colors() == FALSE)
    {
        endwin();
        std::cout << "Your terminal does not support colors\n";
        exit(1);
    }
    chooseLib = 11;
    noecho();
    cbreak();
    timeout(100);
    keypad(stdscr, TRUE);
    start_color();
    curs_set(0);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
}

extern "C" void ncurse::initGame(std::vector<std::vector<char>> field)
{
    x = 60, y = 30, numfruits = 0;
    initscr();
    if (has_colors() == FALSE)
    {
        endwin();
        std::cout << "Your terminal does not support colors\n";
        exit(1);
    }
    chooseLib = 10;
    noecho();
    cbreak();
    timeout(100);
    keypad(stdscr, TRUE);
    start_color();
    curs_set(0);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_WHITE);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
}

extern "C" void ncurse::closeGame()
{
    endwin();
}

extern "C" void ncurse::show(std::vector<std::vector<char>> field)
{
    move(0, 0);
    printw("Press q to quit\n");
    for (std::size_t i=0; i<y; ++i) {
        for (std::size_t j=0; j<x; ++j) {
            if (field[i][j] == static_cast<char>(Color::white)) {
                attron(COLOR_PAIR(Color::white));
                printw("*");
                attroff(COLOR_PAIR(Color::white));
            }
    else if (field[i][j] == static_cast<char>(Color::red)) {
        attron(COLOR_PAIR(Color::red));
        printw("O");
        attroff(COLOR_PAIR(Color::red));
    }
    else {
        printw(" ");
    }
        }
        printw("\n");
    }
    refresh();
}

extern "C" void ncurse::showMapPac(std::vector<std::vector<char>> field)
{
    move(0, 0);
    attron(COLOR_PAIR(1));
    printw("Press q to quit\n");
    attroff(COLOR_PAIR(1));
    for (std::size_t i = 0; i<y; ++i) {
        for (std::size_t j = 0; j<x; ++j) {
            if (field[i][j] == static_cast<char>(Color::white)) {
                attron(COLOR_PAIR(Color::white));
                printw("*");
                attroff(COLOR_PAIR(Color::white));
            }
    else if (field[i][j] == static_cast<char>(Color::red)) {
        attron(COLOR_PAIR(Color::red));
        printw("*");
        attroff(COLOR_PAIR(Color::red));
    }
    else {
        printw(" ");
    }
        }
        printw("\n");
    }
    refresh();
}

extern "C" void ncurse::showPacman(std::deque<std::pair<std::size_t, std::size_t>> coordinates, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap)
{
    auto coord = coordinates.front();
    showMapPac(updateMap);
    attron(COLOR_PAIR(Color::cyan));
    switch(dir) {
        case Direction::Right:
            move(coord.first + 1, coord.second);
            printw("O");
            break;
        case Direction::Left:
            move(coord.first + 1, coord.second);
            printw("O");
            break;
        case Direction::Up:
            move(coord.first + 1, coord.second);
            printw("O");
            break;
        case Direction::Down:
            move(coord.first + 1, coord.second);
            printw("O");
            break;
    }

    move(30 + 1, 0); //mis en dur field.height
    attron(COLOR_PAIR(1));
    printw("Score: %d", size);
    attroff(COLOR_PAIR(1));
    refresh();
}

extern "C" void ncurse::showSnake(std::deque<std::pair<std::size_t, std::size_t>> coordinates, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap)
{
    auto coord = coordinates.front();
    move(coord.first+1, coord.second);
    show(updateMap);
    attron(COLOR_PAIR(Color::cyan));
    switch(dir) {
        case Direction::Right:
            // coord.second++;
            move(coord.first + 1, coord.second + 1);
            printw(">");
            break;
        case Direction::Left:
            move(coord.first + 1, coord.second - 1);
            printw("<");
            break;
        case Direction::Up:
            move(coord.first, coord.second);
            printw("^");
            break;
        case Direction::Down:
            move(coord.first + 2, coord.second);
            printw("v");
            break;
    }
    attroff(COLOR_PAIR(Color::cyan));
    // updateMap[coord.first][coord.second] = static_cast<char>(Color::green);
    coordinates.push_front(std::move(coord));
    if (coordinates.size() > size) {
        auto last = coordinates.back();
        updateMap[last.first][last.second] = 0;
        move(last.first+1, last.second);
        printw(" ");
        coordinates.pop_back();
    }

    attron(COLOR_PAIR(Color::green));
    for (std::size_t i = 1; i < size; ++i) {
        coord = coordinates[i];
        move(coord.first+1, coord.second);
        printw("=");
    }
    attroff(COLOR_PAIR(Color::green));

    move(30 + 1, 0); //mis en dur field.height
    printw("Score: %d", size);
    refresh();
}

extern "C" void ncurse::endgame(std::size_t score)
{
    move(0, 0);
    clear();
    refresh();
    timeout(-1);
    attron(COLOR_PAIR(Color::cyan));
    printw("Game Over... Score: %d \n", score);
    for (int c = 0; c != 'q' && c != 'Q' && 'k' != c; c = getch())
    {
    }

    attroff(COLOR_PAIR(Color::cyan));
    exit (0);
}

extern "C" Direction ncurse::getKey()
{
    // bool exit_flag = false;
    int ch = getch();
    if (ch == 112)
        chooseLib = 100;
    if (ch == 117)
        chooseLib = 3;
    if (ch == 105)
        chooseLib = 4;
    switch (ch)
    {
    case KEY_UP:
    case 'w':
        save_dir = Direction::Up;
        return Direction::Up;
        break;
    case KEY_DOWN:
    case 's':
        save_dir = Direction::Down;
        return Direction::Down;
        break;
    case KEY_LEFT:
    case 'a':
        save_dir = Direction::Left;
        return Direction::Left;
        break;
    case KEY_RIGHT:
    case 'd':
        save_dir = Direction::Right;
        return Direction::Right;
        break;
    case 'q':
    case 'k':
    case KEY_EXIT:
    case 27:
        // exit_flag = true;
        exit(0);
    default:
        return save_dir;
        break;
    }
    refresh();
}

extern "C" ILib &entryPoint()
{
    static ncurse all_functions;
    return all_functions;
}