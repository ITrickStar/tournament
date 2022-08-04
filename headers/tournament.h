#include "entities.h"

class Tournament
{
private:
    size_t player_count;
    vector<Unit *> *bracket;

public:
    Tournament(size_t num = 4) : player_count(num)
    {
        Entities array;
        for (int i = 0; i < player_count; i++)
            bracket[i] = array.competitors[rand() % array.plcount];
    }
    void clash()
    {
        int i = 0;
        while (bracket->size() > 1)
        {
            while (1)
            {
                bracket[i].
            }
            i += 2;
            if (i >= bracket->size() / 2 * 2)
                i = 0;
        }
    }
};
