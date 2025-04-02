#include <iostream>

int main() {
    std::cout << "scoreboard players remove #GameManager set_meeting_time 1200" << std::endl;
    std::cout << "scoreboard players operation #GameManager set_meeting_time_minutes = #GameManager set_meeting_time" << std::endl;
    std::cout << "scoreboard players operation #GameManager set_meeting_time_minutes /= #GameManager tick_minute" << std::endl;
    std::cout << "function werewolf:.settings/view_settings_others" << std::endl;
    return 0;
}
