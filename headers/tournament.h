#include "entities.h"

class Tournament
{
private:
    size_t player_count;
    vector<Unit *> bracket;

public:
    Tournament(size_t num = 4) : player_count(num)
    {
        Entities array;
        for (int i = 0; i < player_count; i++)
            bracket.push_back(array.competitors[rand() % array.plcount]);
    }
    void clash()
    {
        int i = 0;
        while (bracket.size() > 1)
        {
            while (bracket[i]->getHP() > 0 && bracket[i + 1]->getHP() > 0)
            {
                bracket[i]->hit(bracket[i + 1]);
                bracket[i + 1]->hit(bracket[i]);
            }
            if (bracket[i]->getHP() > bracket[i + 1]->getHP())
            {
                bracket[i]->resetHP();
                bracket.erase(bracket.begin() + i + 1);
            }
            else
            {
                bracket[i + 1]->resetHP();
                bracket.erase(bracket.begin() + i);
            }
            i += 2;
            if (i >= bracket.size() / 2 * 2)
                i = 0;
        }
    }
};
