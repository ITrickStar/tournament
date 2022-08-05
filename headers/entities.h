#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

class Unit
{
protected:
    string m_name;
    int m_hp;
    int curr_hp;
    int m_dmg;

    int calcDmg() const
    {
        return m_dmg * (1 + (rand() % 40 - 20) / 100.0f);
    }

public:
    Unit(int hp = 80, int dmg = 15)
    {
        setHP(hp);
        setDmg(dmg);
    }

    string getName() const { return m_name; }
    void setName(string set) { m_name = set + (string)(char *)this; }
    int getHP() const { return curr_hp; }
    void setHP(const int set) { curr_hp = set; }
    void resetHP()
    {
        curr_hp = m_hp;
        cout << m_name << " wins" << endl;
    }
    void setDmg(const int set) { m_dmg = set; }
    virtual void hit(Unit *target)
    {
        if (this == target)
            return;
        target->receiveDmg(calcDmg());
    }
    virtual void receiveDmg(int dmg)
    {
        curr_hp -= dmg;
    }
};

class Archer : public Unit
{
private:
    int evasion = 10;

public:
    Archer() : Unit(60, 15)
    {
        setName("archer");
    }
    virtual void receiveDmg(int dmg) override
    {
        if ((rand() % 100 + 1) / evasion)
            curr_hp -= dmg;
    }
};
class Warrior : public Unit
{
private:
    int resist = 15;

public:
    Warrior() : Unit()
    {
        setName("warrior");
    }

    virtual void receiveDmg(int dmg) override
    {
        curr_hp -= dmg * (100. - resist) / 100;
    }
};

class Rogue : public Unit
{
private:
    int crit = 20;

public:
    Rogue() : Unit(60, 15)
    {
        setName("rogue");
    }

    virtual void hit(Unit *target) override
    {
        if ((rand() % 100 + 1) / crit)
            target->receiveDmg(calcDmg());
        else
            target->receiveDmg(calcDmg() * 2);
    }
};

class Peasant : public Unit
{
public:
    Peasant() : Unit()
    {
        setName("peasant");
    }
};

struct Entities
{
    size_t plcount = 4;
    vector<Unit *> competitors;

    Entities()
    {
        competitors.push_back(new Warrior());
        competitors.push_back(new Archer());
        competitors.push_back(new Rogue());
        competitors.push_back(new Peasant());
    }

    void erase(int num)
    {
        competitors.erase(competitors.begin() + num);
        plcount--;
    }
};
