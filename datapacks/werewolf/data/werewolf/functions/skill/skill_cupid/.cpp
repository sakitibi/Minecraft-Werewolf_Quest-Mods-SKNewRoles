#include <cooltime/setup.hpp>
#include <cooltime/set_cooltime.hpp>
#include <iostream>
#include <vector>
#include <string>

void executeCommand(const std::string& command) {
    std::cout << command << std::endl;
}

void processCupidArrow() {
    // キューピットの矢処理
    // チャージ
    executeCommand("execute as @a[scores={charge_cupid_arrow=0..}] run function werewolf:skill/skill_cupid/charge");

    // 当たり判定処理
    executeCommand("execute if entity @e[type=item,tag=cupid_arrow] at @e[type=item,tag=cupid_arrow] as @a[tag=!cupid_arrow,tag=!team_cupid,distance=..2,limit=1] unless score @s charge_cupid_arrow matches 0.. run tag @s add hit_cupid_arrow");
    executeCommand("execute if entity @e[type=item,tag=cupid_arrow] as @e[tag=hit_cupid_arrow] at @s run kill @e[type=item,tag=cupid_arrow,sort=nearest,limit=1]");
    executeCommand("execute as @e[tag=hit_cupid_arrow] at @s run function werewolf:skill/skill_cupid/damage");

    // 壁や床に当たったら消滅
    executeCommand("execute as @e[type=item,tag=cupid_arrow] run function werewolf:skill/skill_cupid/bounce");

    // パーティクルの表示
    executeCommand("execute at @a[team=Cupid] if entity @e[type=item,tag=cupid_arrow,distance=1.5..] at @e[type=item,tag=cupid_arrow] run particle heart ~ ~ ~ 0.2 0.2 0.2 0 3 force @a[team=Cupid]");
    executeCommand("execute at @a[team=Cupid] if entity @e[type=item,tag=cupid_arrow,distance=1.5..] at @e[type=item,tag=cupid_arrow] run particle heart ~ ~ ~ 0.2 0.2 0.2 0 3 force @a[tag=!player]");
}

int main() {
    processCupidArrow();
    return 0;
}
