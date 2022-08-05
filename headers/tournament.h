#include "entities.h"

class Tournament
{
private:
    size_t player_count;
    vector<Unit *> bracket;

public:
    Tournament() 
    {
        Entities array;
        player_count = array.plcount;
        int key;
        for (int i = 0; i < player_count; i++)
        {
            key = rand() % array.plcount;
            bracket.push_back(array.competitors[key]);
            array.erase(key);
        }
    }

    Tournament(size_t num) : player_count(num)
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
            cout << bracket[i]->getName() << " vs " << bracket[i + 1]->getName() << " -> ";
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

            if (++i >= bracket.size() / 2 * 2)
                i = 0;
        }
    }
};
