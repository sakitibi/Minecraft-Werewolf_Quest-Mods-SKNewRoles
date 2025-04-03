#include <iostream>

int main() {
    std::cout << "scoreboard players add #GameManager set_daytime 1200" << std::endl;
    std::cout << "scoreboard players operation #GameManager set_daytime_minutes = #GameManager set_daytime" << std::endl;
    std::cout << "scoreboard players operation #GameManager set_daytime_minutes /= #GameManager tick_minute" << std::endl;
    std::cout << "function werewolf:.settings/view_settings_others" << std::endl;
    return 0;
}
