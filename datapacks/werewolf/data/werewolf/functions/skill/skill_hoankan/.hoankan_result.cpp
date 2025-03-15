#include <iostream>
#include <string>

void addSkillCooldown() {
    std::cout << "Adding skill_hoankan_cooltime" << std::endl;
}

void checkSkillCooldown() {
    std::cout << "Checking if skill_hoankan_cooltime is 0" << std::endl;
}

void tellPlayerNotReady() {
    std::cout << "Telling player: 今はまだ使えない。" << std::endl;
}

void runSkillFunction(int playerTag) {
    std::cout << "Running skill function for player with tag: " << playerTag << std::endl;
}

void replaceItemForHoankan() {
    std::cout << "Replacing item in main hand for Hoankan" << std::endl;
}

void reduceSkillUsage() {
    std::cout << "Reducing skill_hoankan_limit by 1" << std::endl;
}

void startCooldownCount() {
    std::cout << "Starting cooldown count for skill_hoankan_frequency" << std::endl;
}

void incrementSkillCooldown() {
    std::cout << "Incrementing skill_hoankan_cooltime by 1" << std::endl;
}

void processHoankanResult() {
    addSkillCooldown();
    checkSkillCooldown();
    tellPlayerNotReady();

    for (int i = 1; i <= 12; ++i) {
        runSkillFunction(i);
    }

    replaceItemForHoankan();
    reduceSkillUsage();
    startCooldownCount();
    incrementSkillCooldown();
}

int main() {
    processHoankanResult();
    return 0;
}
