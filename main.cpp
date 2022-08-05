#include <iostream>
#include <ctime>

#include "./headers/tournament.h"

using namespace std;

auto main() -> int
{
    srand(time(0));

    Tournament tarr;
    tarr.clash();
}
