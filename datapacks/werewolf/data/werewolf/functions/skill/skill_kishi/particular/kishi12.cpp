#include <iostream>
#include <string>
#include <unordered_map>

class Player {
public:
    std::string team;
    std::unordered_map<std::string, int> scores;
    bool predicate;

    void tellraw(const std::string& message) {
        std::cout << message << std::endl;
    }

    void runFunction(const std::string& functionName) {
        std::cout << "Running function: " << functionName << std::endl;
    }

    void replaceWeapon(const std::string& lootTable) {
        std::cout << "Replacing weapon with loot from: " << lootTable << std::endl;
    }
};

void execute(Player& player, const std::string& condition, const std::function<void()>& action) {
    if (condition == "if_entity_team_Kishi" && player.team == "Kishi") {
        action();
    } else if (condition == "if_entity_team_Ponkotsu" && player.team == "Ponkotsu") {
        action();
    }
}

void kishi12(Player& player) {
    // 通常
    execute(player, "if_entity_team_Kishi", [&]() {
        if (player.scores["skill_kishi_protected"] == 0) {
            player.tellraw("を守護した。");
            player.replaceWeapon("werewolf:skill/kishi_skill/cooltime");
            player.scores["skill_kishi_cooltime"] = 1;
            player.scores["skill_kishi_protected"] = 1;
        } else if (player.scores["skill_kishi_protected"] == 2) {
            player.tellraw("連続で護ることはできない。");
        }
    });

    // ポンコツ
    execute(player, "if_entity_team_Ponkotsu", [&]() {
        if (player.scores["skill_kishi_protected_dummy"] == 1) {
            player.tellraw("連続で護ることはできない。");
        } else if (player.scores["skill_kishi_protected_dummy"] > 1) {
            player.tellraw("あなたは今も誰かを護っている。");
        } else if (player.scores["skill_kishi_protected_dummy"] == 0) {
            player.tellraw("を守護した。");
            player.replaceWeapon("werewolf:skill/kishi_skill/cooltime");
            player.scores["skill_kishi_cooltime"] = 1;
            player.scores["skill_kishi_protected_dummy"] = 1;
        }
    });
}

int main() {
    Player player;
    player.team = "Kishi";
    player.scores["skill_kishi_protected"] = 0;
    player.scores["skill_kishi_protected_dummy"] = 0;
    player.predicate = true;

    kishi12(player);

    return 0;
}
