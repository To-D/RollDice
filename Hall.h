/**
 * @class Hall
 * @author Liu Junwei
 * @brief This class is the abstraction of the game hall
 */
#include <string>
#include "DiceRolling.h"

#ifndef Hall_H
#define Hall_H

using namespace std;

class Hall{
    public:
    Hall();
    ~Hall();
    DiceRolling start(int gameIndex);
};

#endif