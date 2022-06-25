#include "Scoreboard.h"
#include "colorsprint.h"
#include <algorithm>


void Scoreboard::print_scoreboard(std::map<std::string, unsigned int> &game_scoreboard)
{
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
    if (game_scoreboard.empty())
    {
        print_no_scores_yet_colored();
    }
    else
    {
        print_scoreboard_colored(names, scores, game_scoreboard);
    }
    print_press_enter();
    clear_screen();
}





