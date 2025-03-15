#include <iostream>
#include <string>
#include <cooltime/setup.hpp>
#include <cooltime/set_cooltime.hpp>

void executeCommand(const std::string& command) {
    std::cout << command << std::endl;
}

void chargeCupidArrow() {
    // チャージ時間管理
    executeCommand("execute as @a[scores={charge_cupid_arrow=0..}] run scoreboard players add @s charge_cupid_arrow 1");

    // スキル発動
    executeCommand("execute as @a[scores={charge_cupid_arrow=1}] at @s run function werewolf:skill/skill_cupid/main");

    // チャージ用のスコアボードをリセット
    executeCommand("execute as @a[scores={charge_cupid_arrow=10..}] run scoreboard players reset @s charge_cupid_arrow");

    // 再帰
    executeCommand("execute if entity @a[scores={charge_cupid_arrow=0..}] run schedule function werewolf:skill/skill_cupid/charge 1t");
}

int main() {
    chargeCupidArrow();
    return 0;
}
