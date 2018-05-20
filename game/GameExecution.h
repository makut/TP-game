# pragma once
# include <iostream>
# include <algorithm>
# include <string>
# include <cctype>
# include "Factory.h"
# include "Command.h"
# include "Army.h"

std::shared_ptr<Army> createHumanArmy();
std::shared_ptr<Army> createOrcArmy();
void executeGame();