#include "sfml.hpp"

extern "C" int sfml::menuLoop()
{
    while (window.isOpen() && chooseLib == 3)
    {
        sf::Event event;
        mousePos = sf::Mouse::getPosition(window);
        // printf("%d + %d\n", mousePos.x, mousePos.y);
        window.draw(pSprite);
        window.draw(playSprite);
        window.draw(exitSprite);
        window.draw(arcadeSprite);
        window.draw(game1);
        window.draw(game2);
        window.draw(motor1);
        window.draw(motor2);
        window.draw(motor3);
        loopArcade += 1;
        if (loopArcade == randArcade) {
            loopArcade = 0;
            randArcade = (rand() % 10) * 100 + 300;
            if (randArcade == 0)
                randArcade = 500;
            arcadeRect.left += 600;
            if (arcadeRect.left == 3000) {
                arcadeRect.left = 0;
                arcadeRect.top += 160;
                if (arcadeRect.top == 1760)
                    arcadeRect.top = 0;
            }
            arcadeSprite.setTextureRect(arcadeRect);
        }
        eventMenu(event);
        window.display();
    }
    return (getLibChoice());
}

extern "C" void sfml::init()
{
    chooseLib = 3;
    font.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/font.ttf");
    game1.setFont(font);
    game1.setString("nibbler");
    game1.setCharacterSize(60);
    game1.setFillColor(sf::Color::White);
    game1.setPosition(sf::Vector2f(1295, 225));
    game2.setFont(font);
    game2.setString("PAC-MAN");
    game2.setCharacterSize(60);
    game2.setFillColor(sf::Color::White);
    game2.setPosition(sf::Vector2f(1295, 325));
    motor1.setFont(font);
    motor1.setString("NCURSE");
    motor1.setCharacterSize(60);
    motor1.setFillColor(sf::Color::White);
    motor1.setPosition(sf::Vector2f(1310, 525));
    motor2.setFont(font);
    motor2.setString("SFML");
    motor2.setCharacterSize(60);
    motor2.setFillColor(sf::Color::White);
    motor2.setPosition(sf::Vector2f(1335, 605));
    motor3.setFont(font);
    motor3.setString("SDL2");
    motor3.setCharacterSize(60);
    motor3.setFillColor(sf::Color::White);
    motor3.setPosition(sf::Vector2f(1335, 690));
    pTexture.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/menu.png");
    playTexture.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/play.png");
    exitTexture.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/exit.png");
    arcadeTexture.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/arcade.png");
    pTexture.setSmooth(true);
    playTexture.setSmooth(true);
    exitTexture.setSmooth(true);
    arcadeTexture.setSmooth(true);
    pSprite.setTexture(pTexture);
    playSprite.setTexture(playTexture);
    exitSprite.setTexture(exitTexture);
    arcadeSprite.setTexture(arcadeTexture);
    playSprite.setTextureRect(sf::IntRect(600, 0, 600, 160));
    exitSprite.setTextureRect(sf::IntRect(600, 0, 600, 160));
    arcadeRect = {0, 0, 600, 160};
    arcadeSprite.setTextureRect(arcadeRect);
    playSprite.setPosition(sf::Vector2f(500, 300));
    exitSprite.setPosition(sf::Vector2f(500, 600));
    arcadeSprite.setPosition(sf::Vector2f(500, 10));
    randArcade = (rand() % 10) * 100  + 300;
    if (randArcade == 0)
        randArcade = 300;
}

extern "C" void sfml::createWinMenu()
{
    window.create(sf::VideoMode(1600, 900), "Arcade");
}

extern "C" void sfml::eventMenu(sf::Event event)
{
    while (window.pollEvent(event))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
            chooseLib = 3;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
            chooseLib = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
            chooseLib = 4;
        }
        if (event.type == sf::Event::Closed) {
            window.close();
            exit (0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            exit (0);
        }
        if (mousePos.x >= 715 && mousePos.x <= 880 && mousePos.y >= 640 && mousePos.y <= 720 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            exit(0);
        if (mousePos.x >= 695 && mousePos.x <= 900 && mousePos.y >= 340 && mousePos.y <= 420) {
            playSprite.setTextureRect(sf::IntRect(0, 0, 600, 160));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (gameSelected == 1)
                    chooseLib = 10;
                if (gameSelected == 2)
                    chooseLib = 11;
            }
        }
        else {
            playSprite.setTextureRect(sf::IntRect(600, 0, 600, 160));
        }
        if (mousePos.x >= 715 && mousePos.x <= 880 && mousePos.y >= 640 && mousePos.y <= 720)
            exitSprite.setTextureRect(sf::IntRect(0, 0, 600, 160));
        else
            exitSprite.setTextureRect(sf::IntRect(600, 0, 600, 160));
        if (mousePos.x >= 1295 && mousePos.x <= 1475 && mousePos.y >= 245 && mousePos.y <= 285) {
            game1.setFillColor(sf::Color::Yellow);
        }
        else if (gameSelected != 1) {
            game1.setFillColor(sf::Color::White);
        }
        if (mousePos.x >= 1295 && mousePos.x <= 1475 && mousePos.y >= 245 && mousePos.y <= 285 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            game1.setFillColor(sf::Color::Yellow);
            gameSelected = 1;
        }
        if (mousePos.x >= 1295 && mousePos.x <= 1475 && mousePos.y >= 345 && mousePos.y <= 385) {
            game2.setFillColor(sf::Color::Yellow);
        }
        else if (gameSelected != 2) {
            game2.setFillColor(sf::Color::White);
        }
        if (mousePos.x >= 1295 && mousePos.x <= 1475 && mousePos.y >= 345 && mousePos.y <= 385 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            game2.setFillColor(sf::Color::Yellow);
            gameSelected = 2;
        }
        if (mousePos.x >= 1310 && mousePos.x <= 1465 && mousePos.y >= 545 && mousePos.y <= 585) {
            motor1.setFillColor(sf::Color::Yellow);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                chooseLib = 1;
        }
        else if (motorSelected != 1) {
            motor1.setFillColor(sf::Color::White);
        }
        if (mousePos.x >= 1310 && mousePos.x <= 1465 && mousePos.y >= 545 && mousePos.y <= 585 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            motor1.setFillColor(sf::Color::Yellow);
            motorSelected = 1;
        }
        if (mousePos.x >= 1335 && mousePos.x <= 1440 && mousePos.y >= 625 && mousePos.y <= 665) {
            motor2.setFillColor(sf::Color::Yellow);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                chooseLib = 3;
        }
        else if (motorSelected != 2) {
            motor2.setFillColor(sf::Color::White);
        }
        if (mousePos.x >= 1335 && mousePos.x <= 1440 && mousePos.y >= 625 && mousePos.y <= 665 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            motor2.setFillColor(sf::Color::Yellow);
            motorSelected = 2;
        }
        if (mousePos.x >= 1335 && mousePos.x <= 1440 && mousePos.y >= 715 && mousePos.y <= 750) {
            motor3.setFillColor(sf::Color::Yellow);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                chooseLib = 4;
        }
        else if (motorSelected != 3) {
            motor3.setFillColor(sf::Color::White);
        }
        if (mousePos.x >= 1335 && mousePos.x <= 1440 && mousePos.y >= 715 && mousePos.y <= 750 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            motor3.setFillColor(sf::Color::Yellow);
            motorSelected = 3;
        }
    }
}

extern "C" void sfml::stop()
{
    window.close();
}

extern "C" void sfml::printAtCoord(int x, int y)
{

}

extern "C" void sfml::initGame(std::vector<std::vector<char>> field)
{
    window.create(sf::VideoMode(1600, 900), "Nibbler (SFML)");
    window.setFramerateLimit(60);

    textureS.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/brick.png");
    spriteS.setTexture(textureS);
    spriteS.setScale(sf::Vector2f(0.5, 0.5));
    for (int i = 0; i < 30; i += 1)
    {
        for (int j = 0; j < 60; j += 1) {
            if (field[i][j] == static_cast<char>(Color::green))
                spriteSnake.push_back(spriteS);
        }
    }
    chooseLib = 10;
    int snake = 0;
    for (int x = 0; x < 30; x += 1)
    {
        for (int y = 0; y < 60; y += 1)
        {
            if (field[x][y] == static_cast<char>(Color::green)) {
                spriteSnake.at(snake).setPosition(sf::Vector2f(y * 25, x * 25));
                snake += 1;
            }
        }
    }



    textureW.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/brick2.png");
    spriteW.setTexture(textureW);
    spriteW.setScale(sf::Vector2f(0.5, 0.5));
    textureB.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/burger.png");
    spriteB.setTexture(textureB);
    spriteB.setScale(sf::Vector2f(0.5, 0.5));
    for (int i = 0; i < 30; i += 1)
    {
        for (int j = 0; j < 60; j += 1) {
            if (field[i][j] == static_cast<char>(Color::red))
                spriteBurger.push_back(spriteB);
            if (field[i][j] == static_cast<char>(Color::white))
                spriteWall.push_back(spriteW);
        }
    }

    int wall = 0;
    int burger = 0;
    for (int x = 0; x < 30; x += 1)
    {
        for (int y = 0; y < 60; y += 1)
        {
            if (field[x][y] == static_cast<char>(Color::white)) {
                spriteWall.at(wall).setPosition(sf::Vector2f(y * 25 , x * 25));
                wall += 1;
            }
            if (field[x][y] == static_cast<char>(Color::red)) {
                spriteBurger.at(burger).setPosition(sf::Vector2f(y * 25, x * 25));
                burger += 1;
            }
        }
    }
    x = 60, y = 30, numfruits = 0;

}

extern "C" void sfml::closeGame()
{
    window.close();
}

extern "C" int sfml::trumpAni(int x, int y)
{
    clock.getElapsedTime();
    x += 50;
    if (x >= 250)
        x = 0;
    sTrump.setTextureRect(sf::IntRect(x, y, 50, 50));
    return x;
}

extern "C" void sfml::show(std::vector<std::vector<char>> field)
{
    for (int i = 0; i < 30; i += 1)
    {
        for (int j = 0; j < 60; j += 1) {
            if (field[i][j] == static_cast<char>(Color::red))
                spriteBurger.push_back(spriteB);
        }
    }

    // int wall = 0;
    int burger = 0;
    for (int x = 0; x < 30; x += 1)
    {
        for (int y = 0; y < 60; y += 1)
        {
            if (field[x][y] == static_cast<char>(Color::red)) {
                spriteBurger.at(burger).setPosition(sf::Vector2f(y * 25, x * 25));
                burger += 1;
            }
        }
    }
    window.clear();
    for (auto w : spriteWall)
        window.draw(w);
    for (auto b : spriteBurger)
        window.draw(b);
}

extern "C" void sfml::endgame(std::size_t score)
{

}

extern "C" Direction sfml::getKey()
{
    if (window.pollEvent(event))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            chooseLib = 110;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            chooseLib = 100;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
            chooseLib = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
            chooseLib = 4;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            window.close();
            exit (0);
        }
        if (event.type == sf::Event::Closed) {
            window.close();
            exit (0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            exit (0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            trumpY = 0;
            trumpPos = 1;
            save_dir =  Direction::Down;
            return Direction::Down;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            trumpY = 50;
            trumpPos = 2;
            save_dir =  Direction::Right;
            return Direction::Right;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            trumpY = 100;
            trumpPos = 3;
            save_dir =  Direction::Up;
            return Direction::Up;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            trumpY = 150;
            trumpPos = 4;
            save_dir = Direction::Left;
            return Direction::Left;
        }
        return save_dir;
    }
    if (clock.getElapsedTime() >= sf::milliseconds(85)) {
        trumpX = trumpAni(trumpX, trumpY);
        clock.restart();
    }
    return save_dir;
}

extern "C" void sfml::showSnake(std::deque<std::pair<std::size_t, std::size_t>> coordinate, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap)
{
    auto coord = coordinate.front();
    show(updateMap);
    switch(dir) {
        case Direction::Right:
            spriteW.setPosition((coord.second) * 25, (coord.first) * 25);
            break;
        case Direction::Left:
            spriteW.setPosition((coord.second) * 25, (coord.first) * 25);
            break;
        case Direction::Up:
            spriteW.setPosition(coord.second * 25, (coord.first) * 25);
            break;
        case Direction::Down:
            spriteW.setPosition((coord.second) * 25, (coord.first) * 25);
            break;
    }
    for (std::size_t i = 1; i < size; ++i) {
        coord = coordinate[i];
        spriteS.setPosition(coord.second * 25 ,(coord.first)* 25);
        window.draw(spriteS);
    }
    window.draw(spriteS);
    window.draw(spriteW);
    window.display();
}

extern "C" void sfml::showPacman(std::deque<std::pair<std::size_t, std::size_t>> coordinates, Direction dir, std::size_t size, std::vector<std::vector<char>> updateMap)
{
    auto coord = coordinates.front();
    showMapPac(updateMap);
    switch(dir) {
        case Direction::Right:
            // sTrump.move(10, 0);
            sTrump.setPosition(coord.second * 25 + 450, 105 + (coord.first + 1) * 25);
            break;
        case Direction::Left:
            // sTrump.move(-10, 0);
            sTrump.setPosition(coord.second * 25 + 450, 105 + (coord.first + 1) * 25);
            break;
        case Direction::Up:
            // sTrump.move(0, -10);
            sTrump.setPosition(coord.second * 25 + 450, 105 + (coord.first + 1) * 25);
            break;
        case Direction::Down:
            // sTrump.move(0, 10);
            sTrump.setPosition(coord.second * 25 + 450, 105 + (coord.first + 1) * 25);
            break;
    }
    window.draw(sTrump);
    window.display();
}

extern "C" void sfml::initPac(std::vector<std::vector<char>> field)
{
    window.create(sf::VideoMode(1600, 900), "Pac-Man (SFML)");
    window.setFramerateLimit(60);

    // std::map<int, std::string> map = field;
    textureW.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/brick2.png");
    spriteW.setTexture(textureW);
    spriteW.setScale(sf::Vector2f(0.5, 0.5));
    textureB.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/burger.png");
    spriteB.setTexture(textureB);
    spriteB.setScale(sf::Vector2f(0.5, 0.5));
    for (int i = 0; i < 30; i += 1)
    {
        for (int j = 0; j < 28; j += 1) {
            if (field[i][j] == static_cast<char>(Color::red))
                spriteBurger.push_back(spriteB);
            if (field[i][j] == static_cast<char>(Color::white))
                spriteWall.push_back(spriteW);
        }
    }
    chooseLib = 11;
    int wall = 0;
    int burger = 0;
    for (int x = 0; x < 30; x += 1)
    {
        for (int y = 0; y < 28; y += 1)
        {
            if (field[x][y] == static_cast<char>(Color::white)) {
                spriteWall.at(wall).setPosition(sf::Vector2f(y * 25 + 450, x * 25 + 130));
                wall += 1;
            }
            if (field[x][y] == static_cast<char>(Color::red)) {
                spriteBurger.at(burger).setPosition(sf::Vector2f(y * 25 + 450, x * 25 + 130));
                burger += 1;
            }
        }
    }


    tTrump.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/trump.png");
    sTrump.setTexture(tTrump);
    sTrump.setTextureRect(sf::IntRect(0, 0, 50, 50));
    //sTrump.setOrigin(37, 50);
    sTrump.setScale(sf::Vector2f(0.5, 0.5));

    // sTrump.setPosition(325 + 450, 100 + 150);
    tAmerica.loadFromFile("/home/mattis/TEK2/B-OOP-400-MPL-4-1-arcade-mattis.litot/lib/sfml/america.png");
    sAmerica.setTexture(tAmerica);
    sAmerica.setPosition(623, 10);
}

extern "C" void sfml::showMapPac(std::vector<std::vector<char>> field)
{
    window.clear();
    for (auto w : spriteWall)
        window.draw(w);
    for (auto b : spriteBurger)
        window.draw(b);
    window.draw(sAmerica);
}

extern "C" ILib &entryPoint()
{
    static sfml all_functions;
    return all_functions;
}