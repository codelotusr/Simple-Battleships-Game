#include "Scoreboard.h"
#include "colorsprint.h"
#include <algorithm>


void Scoreboard::print_scoreboard(std::map<std::string, unsigned int> &game_scoreboard)
{
    //sort the scoreboard in descending order and print it to the screen
    std::map<std::string, unsigned int>::iterator it;
    std::vector<std::string> names;
    std::vector<unsigned int> scores;
    for (it = game_scoreboard.begin(); it != game_scoreboard.end(); it++)
    {
        names.push_back(it->first);
        scores.push_back(it->second);
    }
    std::sort(scores.begin(), scores.end(), std::greater<unsigned int>());
    clear_screen();
    print_colorful_scoreboard_sign();
    for (unsigned int i = 0; i < scores.size(); i++)
    {
        for (unsigned int j = 0; j < names.size(); j++)
        {
            if (scores[i] == game_scoreboard[names[j]])
            {
                std::cout << names[j] << ": " << scores[i] << std::endl;
            }
        }
    }
    print_press_enter();
    clear_screen();
}





