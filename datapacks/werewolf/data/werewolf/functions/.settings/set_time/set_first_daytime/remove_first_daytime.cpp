#include <iostream>

int main() {
    std::cout << "scoreboard players remove #GameManager set_first_daytime 1200" << std::endl;
    std::cout << "scoreboard players operation #GameManager set_first_daytime_minutes = #GameManager set_first_daytime" << std::endl;
    std::cout << "scoreboard players operation #GameManager set_first_daytime_minutes /= #GameManager tick_minute" << std::endl;
    std::cout << "function werewolf:.settings/view_settings_others" << std::endl;
    return 0;
}
