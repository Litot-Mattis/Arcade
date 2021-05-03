/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-mattis.litot
** File description:
** score
*/

#include "score.hpp"

int writeFile(std::string score, std::map<std::string, int> scoreMap)
{
    std::ofstream myfile("score/score.txt");
    if (myfile.is_open())
    {
        for (std::pair<std::string, int> element : scoreMap)
            myfile << element.first << "\n";
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
        return 1;
    }
    return 0;
}

int readFile(std::map<std::string, int> &scoresMap, std::string b)
{
    std::string line;
    std::ifstream myfile("score/score.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            int bg = std::stoi(line.substr(line.find(':') + 1, line.find(';') - line.find(':') - 1));
            if (line.size() > 0)
            {
                scoresMap.insert(std::pair<std::string, int>(line, bg));
            }
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
        return 1;
    }
    return 0;
}

std::string formatString(std::string playerName, std::string playerScore, std::string name)
{
    std::string formatScore = playerName + ":" + playerScore + ";" + name;
    return formatScore;
}

std::map<std::string, int> scoreParser(std::map<std::string, int> scoreMap, std::string score)
{
    int parseFalse = 0;
    int bg = std::stoi(score.substr(score.find(':') + 1, score.find(';') - score.find(':') - 1));
    for (std::pair<std::string, int> element : scoreMap)
        if (element.first.substr(0, element.first.find(':')) == score.substr(0, score.find(':')))
        {
            scoreMap.erase(element.first);
            scoreMap.insert(std::pair<std::string, int>(score, bg));
            parseFalse = 1;
        }
    if (parseFalse == 0)
        scoreMap.insert(std::pair<std::string, int>(score, bg));
    return scoreMap;
}

int main(int ac, char **av)
{
    std::map<std::string, int> scoreMap;
    std::vector<std::string> vecOfScore;
    std::string a = av[1];
    std::string b = av[2];
    std::string c = av[3];
    std::string score = formatString(a, b, c);
    if (readFile(scoreMap, b) == 0)
        scoreMap = scoreParser(scoreMap, score);
    writeFile(score, scoreMap);
    return 0;
}
