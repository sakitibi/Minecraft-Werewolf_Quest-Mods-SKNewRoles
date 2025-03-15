#include <iostream>
#include <string>

void addSkillCooldown() {
    std::cout << "Adding skill_doublekiller_mainslash_cooltime" << std::endl;
}

void checkSkillCooldown() {
    std::cout << "Checking if skill_doublekiller_mainslash_cooltime is 0" << std::endl;
}

void tellPlayerNotReady() {
    std::cout << "Telling player: 今はまだ使えない。" << std::endl;
}

void runSkillFunction(int playerTag) {
    std::cout << "Running skill function for player with tag: " << playerTag << std::endl;
}

void replaceItemForDoublekiller() {
    std::cout << "Replacing item in main hand for Doublekiller" << std::endl;
}

void reduceSkillUsage() {
    std::cout << "Reducing skill_doublekiller_mainslash_limit by 1" << std::endl;
}

void startCooldownCount() {
    std::cout << "Starting cooldown count for skill_doublekiller_mainslash_frequency" << std::endl;
}

void incrementSkillCooldown() {
    std::cout << "Incrementing skill_doublekiller_mainslash_cooltime by 1" << std::endl;
}

void processDoubleKillerMainSlashResult() {
    addSkillCooldown();
    checkSkillCooldown();
    tellPlayerNotReady();

    for (int i = 1; i <= 12; ++i) {
        runSkillFunction(i);
    }

    replaceItemForDoublekiller();
    reduceSkillUsage();
    startCooldownCount();
    incrementSkillCooldown();
}

int main() {
    processDoubleKillerMainSlashResult();
    return 0;
}
