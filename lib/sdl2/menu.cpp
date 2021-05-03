/*
** EPITECH PROJECT, 2021
** SDL2
** File description:
** menu
*/

#include "menu.hpp"

extern "C" void sdl::init()
{
    window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    pTexture = IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/ok.bmp");
    playTexture = IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/play.bmp");
    exitTexture = IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/exit.bmp");
    arcadeTexture = IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/arcade.bmp");
    playPos = {500, 300, 600, 160};
    exitPos = {500, 600, 600, 160};
    arcadePos = {500, 10, 600, 160};
    playRect = {600, 0, 600, 160};
    exitRect = {600, 0, 600, 160};
    arcadeRect = {0, 0, 600, 160};
	font = TTF_OpenFont("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/font.ttf", 60);
    White = {255, 255, 255};
    Purple = {113, 52, 235};
    gameRect = {0, 0, 210, 50};
    gameRect2 = {0, 0, 210, 50};
    motorRect = {0, 0, 165, 50};
    motorRect2 = {0, 0, 165, 50};
    motorRect3 = {0, 0, 165, 50};
    game1 = "PAC-MAN";
    game1Surface = TTF_RenderText_Blended(font, game1.c_str(), White);
    game1Texture = IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/nibbler.bmp");
    game1Pos = {1275, 220, 210, 50};
    game2 = "NIBBLER";
    game2Surface = TTF_RenderText_Blended(font, game2.c_str(), White);
    game2Texture = IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/pacman.bmp");
    game2Pos = {1275, 320, 210, 50};
    motor1 = "NCURSE";
    motor1Surface = TTF_RenderText_Blended(font, motor1.c_str(), White);
    motor1Texture = IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/ncurse.bmp");
    motor1Pos = {1310, 520, 165, 50};
    motor2 = "SFML";
    motor2Surface = TTF_RenderText_Blended(font, motor2.c_str(), White);
    motor2Texture = IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/sfml.bmp");
    motor2Pos = {1310, 600, 165, 50};
    motor3 = "SDL2";
    motor3Surface = TTF_RenderText_Blended(font, motor3.c_str(), White);
    motor3Texture = IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/SDL2.bmp");
    motor3Pos = {1310, 680, 165, 50};
    chooseLib = 4;
    SDL_StartTextInput();
    SDL_RenderPresent(renderer);
    if (TTF_Init() != 0) {
		std::cerr << "SDL_ttf initialization failed" << std::endl;
		exit(0);
	}
    SDL_LoadWAV("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/music_menu.wav", &wavSpec, &wavBuffer, &wavLength);
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    // int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
    srand(time(0));

    randArcade = (rand() % 10) * 100 + 300;
    if (randArcade == 0)
        randArcade = 300;
}

extern "C" void sdl::stop()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

extern "C" void sdl::createWinMenu()
{
}

extern "C" int sdl::menuLoop()
{
    while (chooseLib == 4)
    {
        SDL_UpdateWindowSurface(window);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, pTexture, NULL, NULL);
        SDL_RenderCopy(renderer, playTexture, &playRect, &playPos);
        SDL_RenderCopy(renderer, exitTexture, &exitRect, &exitPos);
        SDL_RenderCopy(renderer, arcadeTexture, &arcadeRect, &arcadePos);
        SDL_RenderCopy(renderer, game1Texture, &gameRect, &game1Pos);
        SDL_RenderCopy(renderer, game2Texture, &gameRect2, &game2Pos);
        SDL_RenderCopy(renderer, motor1Texture, &motorRect, &motor1Pos);
        SDL_RenderCopy(renderer, motor2Texture, &motorRect2, &motor2Pos);
        SDL_RenderCopy(renderer, motor3Texture, &motorRect3, &motor3Pos);
        loopArcade += 1;
        if (loopArcade == randArcade)
        {
            loopArcade = 0;
            randArcade = (rand() % 10) * 100 + 300;
            if (randArcade == 0)
                randArcade = 500;
            arcadeRect.x += 600;
            if (arcadeRect.x == 3000)
            {
                arcadeRect.x = 0;
                arcadeRect.y += 160;
                if (arcadeRect.y == 1760)
                    arcadeRect.y = 0;
            }
        }
        if (SDL_PollEvent(&event) != 0)
        {
            eventMenu();
        }
        SDL_RenderPresent(renderer);
    }
    return (getLibChoice());
}

extern "C" void sdl::eventMenu()
{
    switch (event.type)
    {
    case SDL_QUIT:
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        exit(0);
    case SDL_MOUSEMOTION:
        SDL_GetMouseState(&mouseX, &mouseY);
        if (mouseX >= 695 && mouseX <= 900 && mouseY >= 340 && mouseY <= 420)
            playRect.x = 0;
        else
            playRect.x = 600;
        if (mouseX >= 715 && mouseX <= 880 && mouseY >= 640 && mouseY <= 720)
            exitRect.x = 0;
        else
            exitRect.x = 600;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_1) {
            chooseLib = 10;
        }
        if (event.key.keysym.sym == SDLK_2)
            chooseLib = 11;
        if (event.key.keysym.sym == SDLK_y) {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            TTF_Quit();
            SDL_Quit();
            chooseLib = 1;
        }
        if (event.key.keysym.sym == SDLK_u) {
            chooseLib = 3;
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            TTF_Quit();
            SDL_Quit();
        }
        if (mouseX >= 1295 && mouseX <= 1485 && mouseY >= 225 && mouseY <= 265)
        {
            gameRect.x = 210;
        }
        else if (gameSelected != 1)
        {
            gameRect.x = 0;
        }
        if (mouseX >= 1295 && mouseX <= 1485 && mouseY >= 325 && mouseY <= 370)
        {
            gameRect2.x = 210;
        }
        else if (gameSelected != 2)
        {
            gameRect2.x = 0;
        }
        if (mouseX >= 1310 && mouseX <= 1475 && mouseY >= 525 && mouseY <= 565)
        {
            motorRect.x = 165;
        }
        else if (motorSelected != 1)
        {
            motorRect.x = 0;
        }
        if (mouseX >= 1335 && mouseX <= 1445 && mouseY >= 605 && mouseY <= 645)
        {
            motorRect2.x = 165;
        }
        else if (motorSelected != 2)
        {
            motorRect2.x = 0;
        }
        if (mouseX >= 1335 && mouseX <= 1445 && mouseY >= 690 && mouseY <= 725)
        {
            motorRect3.x = 165;
        }
        else if (motorSelected != 3)
        {
            motorRect3.x = 0;
        }
        SDL_RenderCopy(renderer, game1Texture, &gameRect, &game1Pos);
        SDL_RenderCopy(renderer, game2Texture, &gameRect2, &game2Pos);
        SDL_RenderCopy(renderer, motor1Texture, &motorRect, &motor1Pos);
        SDL_RenderCopy(renderer, motor2Texture, &motorRect2, &motor2Pos);
        SDL_RenderCopy(renderer, motor3Texture, &motorRect3, &motor3Pos);
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (mouseX >= 695 && mouseX <= 900 && mouseY >= 340 && mouseY <= 420)
            chooseLib = 11;
        // std::cout << mouseX << " + " << mouseY << std::endl;
        if (mouseX >= 715 && mouseX <= 880 && mouseY >= 640 && mouseY <= 720) {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            TTF_Quit();
            SDL_Quit();
            exit(0);
        }
        if (mouseX >= 1295 && mouseX <= 1485 && mouseY >= 225 && mouseY <= 265)
        {
            gameRect.x = 210;
            gameSelected = 1;
        }
        else if (mouseX >= 1295 && mouseX <= 1485 && mouseY >= 225 && mouseY <= 265 && gameSelected == 1)
        {
            gameRect.x = 0;
            gameSelected = 0;
        }
        if (mouseX >= 1295 && mouseX <= 1485 && mouseY >= 325 && mouseY <= 370)
        {
            gameRect2.x = 210;
            gameSelected = 2;
        }
        else if (mouseX >= 1295 && mouseX <= 1485 && mouseY >= 325 && mouseY <= 370 && gameSelected == 2)
        {
            gameRect2.x = 0;
            gameSelected = 0;
        }
        if (mouseX >= 1310 && mouseX <= 1475 && mouseY >= 525 && mouseY <= 565)
        {
            motorRect.x = 165;
            motorSelected = 1;
        }
        else if (mouseX >= 1310 && mouseX <= 1475 && mouseY >= 525 && mouseY <= 565 && motorSelected != 1)
        {
            motorRect.x = 0;
            motorSelected = 0;
        }
        if (mouseX >= 1335 && mouseX <= 1445 && mouseY >= 605 && mouseY <= 645)
        {
            motorRect2.x = 165;
            motorSelected = 2;
        }
        else if (mouseX >= 1335 && mouseX <= 1445 && mouseY >= 605 && mouseY <= 645 && motorSelected != 2)
        {
            motorRect2.x = 0;
            motorSelected = 0;
        }
        if (mouseX >= 1335 && mouseX <= 1445 && mouseY >= 690 && mouseY <= 725)
        {
            motorRect3.x = 165;
            motorSelected = 3;
        }
        else if (mouseX >= 1335 && mouseX <= 1445 && mouseY >= 690 && mouseY <= 725 && motorSelected != 3)
        {
            motorRect3.x = 0;
            motorSelected = 0;
        }
    }
}

extern "C" void sdl::printAtCoord(int x, int y)
{
    std::cout << "DEBUG: 𝕙𝕖𝕝𝕝𝕠 𝕙𝕖𝕝𝕝𝕠 𝕙𝕖𝕝𝕝𝕠 𝕙𝕖𝕝𝕝𝕠" << std::endl;
}

extern "C" void sdl::initGame(std::vector<std::vector<char>> field)
{
}

extern "C" void sdl::closeGame()
{
}

extern "C" void sdl::show(std::vector<std::vector<char>> field)
{
}

extern "C" void sdl::showSnake(std::deque<std::pair<std::size_t, std::size_t>> coordinate, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap)
{
}

extern "C" void sdl::endgame(std::size_t score)
{
}

extern "C" Direction sdl::getKey()
{
    if (SDL_PollEvent(&event) != 0)
    {
        switch (event.type) {
            case SDL_QUIT:
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                TTF_Quit();
                SDL_Quit();
                exit(0);
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_r) {
                    chooseLib = 110;
                }
                if (event.key.keysym.sym == SDLK_p) {
                    chooseLib = 100;
                }
                if (event.key.keysym.sym == SDLK_y) {
                    chooseLib = 1;
                }
                if (event.key.keysym.sym == SDLK_i) {
                    chooseLib = 4;
                }
                if (event.key.keysym.sym == SDLK_k) {
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    TTF_Quit();
                    SDL_Quit();
                    exit (0);
                }
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    TTF_Quit();
                    SDL_Quit();
                    exit (0);
                }
                else if (event.key.keysym.sym == SDLK_DOWN) {
                    trumpY = 0;
                    trumpPos = 1;
                    save_dir =  Direction::Down;
                    return Direction::Down;
                }
                else if (event.key.keysym.sym == SDLK_RIGHT) {
                    trumpY = 50;
                    trumpPos = 2;
                    save_dir =  Direction::Right;
                    return Direction::Right;
                }
                else if (event.key.keysym.sym == SDLK_UP) {
                    trumpY = 100;
                    trumpPos = 3;
                    save_dir =  Direction::Up;
                    return Direction::Up;
                }
                else if (event.key.keysym.sym == SDLK_LEFT) {
                    trumpY = 150;
                    trumpPos = 4;
                    save_dir = Direction::Left;
                    return Direction::Left;
                }
        }
        return save_dir;
    }
    return save_dir;
}

extern "C" void sdl::showPacman(std::deque<std::pair<std::size_t, std::size_t>> coordinates, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap)
{
    auto coord = coordinates.front();
    showMapPac(updateMap);
    SDL_Rect rectTrump = {0, 0, 50, 50};
    SDL_Rect rect;
    switch(dir) {
        case Direction::Right:
            // sTrump.move(10, 0);
            rect = {(int(coord.second * 25) + 450), int(105 + (coord.first) * 25), 50, 50};
            break;
        case Direction::Left:
            // sTrump.move(-10, 0);
            rect = {(int(coord.second * 25) + 450), int(105 + (coord.first) * 25), 50, 50};
            break;
        case Direction::Up:
            // sTrump.move(0, -10);
            rect = {(int(coord.second * 25) + 450), int(105 + (coord.first) * 25), 50, 50};
            break;
        case Direction::Down:
            // sTrump.move(0, 10);
            rect = {(int(coord.second * 25) + 450), int(105 + (coord.first) * 25), 50, 50};
            break;
    }
    SDL_RenderCopy(renderer, sTrump, &rectTrump, &rect);
    SDL_RenderPresent(renderer);
}

extern "C" void sdl::initPac(std::vector<std::vector<char>> field)
{
    window = SDL_CreateWindow("Pac-Man (SDL)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderPresent(renderer);
    for (int i = 0; i < 30; i += 1)
    {
        for (int j = 0; j < 28; j += 1) {
            SDL_Rect rect = {j * 25 + 450, i * 25 + 105, 50, 50};
            if (field[i][j] == static_cast<char>(Color::red))
                spriteBurger.insert(std::make_pair(IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/burger.png"), rect));
            if (field[i][j] == static_cast<char>(Color::white))
                spriteWall.insert(std::make_pair(IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/brick2.png"), rect));
        }
    }
}

extern "C" void sdl::showMapPac(std::vector<std::vector<char>> field)
{
    SDL_UpdateWindowSurface(window);
    SDL_RenderClear(renderer);
    for (auto w : spriteWall)
        SDL_RenderCopy(renderer, w.first, NULL, &w.second);
    for (auto b : spriteBurger)
        SDL_RenderCopy(renderer, b.first, NULL, &b.second);
    // SDL_Rect rect = {25 + 450, 25 + 105, 25, 25};
    // sTrump = IMG_LoadTexture(renderer, "/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sdl2/trump.bmp");
    // SDL_RenderCopy(renderer, sTrump, NULL, &rect);
    SDL_RenderPresent(renderer);
}

extern "C" ILib &entryPoint()
{
    static sdl all_functions;
    return all_functions;
}

// sdl::sdl()
// {
//     SDL_StartTextInput();
//     SDL_RenderPresent(renderer);
//     SDL_LoadWAV("music_menu.wav", &wavSpec, &wavBuffer, &wavLength);
//     deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
//     int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
//     game1Pos.x = 1390 - (game1Surface->w / 2.0f);
//     game2Pos.x = 1390 - (game2Surface->w / 2.0f);
//     motor1Pos.x = 1390 - (motor1Surface->w / 2.0f);
//     motor2Pos.x = 1390 - (motor2Surface->w / 2.0f);
//     motor3Pos.x = 1390 - (motor3Surface->w / 2.0f);
//     SDL_PauseAudioDevice(deviceId, 0);
//     srand(time(0));

//     randArcade = (rand() % 10) * 100  + 300;
//     if (randArcade == 0)
//         randArcade = 300;

// }

// sdl::~sdl()
// {
//     SDL_DestroyRenderer(renderer);
// 	SDL_DestroyWindow(window);
// 	TTF_Quit();
// 	SDL_Quit();
// }

// int main()
// {
//     SDL_Init(SDL_INIT_EVERYTHING);
//     TTF_Init();
//     sdl menu;
//     while (1)
//     {
//         menu.loopMenu();
//         if (SDL_PollEvent(&menu.event) != 0)
//         {
//             menu.eventMenu();
//         }
//         SDL_RenderPresent(menu.renderer);
//     }
// }