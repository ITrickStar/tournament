#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

class Unit
{
protected:
    string m_name;
    int m_hp;
    int m_dmg;

    int calcDmg() const
    {
        return m_dmg * (1 + (rand() % 40 - 20) / 100.0f);
    }

public:
    void setName(char *set) { m_name = strcat(set, (char *)this); }
    int getHP() const { return m_hp; }
    void setHP(const int set) { m_hp = set; }
    void setDmg(const int set) { m_dmg = set; }
    virtual void hit(Unit *target) { target->receiveDmg(calcDmg()); }
    virtual bool receiveDmg(int dmg)
    {
        m_hp -= dmg;
        if (m_hp <= 0)
            return false;
        return true;
    }
};

class Archer : public Unit
{
private:
    int evasion = 10;

public:
    Archer()
    {
        setName("archer");
        setHP(80);
        setDmg(15);
    }
    virtual bool receiveDmg(int dmg) override
    {
        if ((rand() % 100 + 1) / evasion)
            m_hp -= dmg;
        if (m_hp <= 0)
            return false;
        return true;
    }
};
class Warrior : public Unit
{
private:
    int resist = 15;

public:
    Warrior()
    {
        setName("warrior");
        setHP(80);
        setDmg(15);
    }

    virtual bool receiveDmg(int dmg) override
    {
        m_hp -= dmg * (100. - resist) / 100;
        if (m_hp <= 0)
            return false;
        return true;
    }
};

class Rogue : public Unit
{
private:
    int crit = 20;

public:
    Rogue()
    {
        setName("rogue");
        setHP(80);
        setDmg(15);
    }

    virtual void hit(Unit *target) override
    {
        if ((rand() % 100 + 1) / crit)
            target->receiveDmg(calcDmg());
        else
            target->receiveDmg(calcDmg() * 2);
    }
};

class Wizard : public Unit
{
public:
    Wizard()
    {
        setName("wizard");
        setHP(80);
        setDmg(15);
    }

    virtual void hit(Unit *target) override
    {
        target->receiveDmg(calcDmg());
    }
};

struct Entities
{
    size_t plcount = 4;
    vector<Unit *> *competitors;

    Entities()
    {
        competitors->push_back(new Warrior());
        competitors->push_back(new Archer());
        competitors->push_back(new Rogue());
        competitors->push_back(new Wizard());
    }
};
