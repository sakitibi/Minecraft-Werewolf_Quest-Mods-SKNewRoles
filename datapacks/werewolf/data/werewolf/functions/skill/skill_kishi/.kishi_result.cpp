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
};

void execute(Player& player, const std::string& condition, const std::function<void()>& action) {
    if (condition == "unless_score_skill_kishi_cooltime_0" && player.scores["skill_kishi_cooltime"] != 0) {
        action();
    } else if (condition == "if_score_skill_kishi_cooltime_0" && player.scores["skill_kishi_cooltime"] == 0) {
        action();
    }
}

void kishi_result(Player& player) {
    execute(player, "unless_score_skill_kishi_cooltime_0", [&]() {
        player.tellraw("今はまだ使えない。");
    });

    execute(player, "if_score_skill_kishi_cooltime_0", [&]() {
        if (player.scores["skill_kishi_protected"] == 1) {
            player.tellraw("あなたは今も誰かを護っている。");
        }
    });

    // 使用回数を減らす
    execute(player, "if_score_skill_kishi_cooltime_0", [&]() {
        if (player.scores["skill_kishi_protected"] == 0) {
            player.scores["skill_kishi_limit"] -= 1;
        }
    });

    // 回復タイミングのカウントを開始
    execute(player, "if_score_skill_kishi_cooltime_0", [&]() {
        if (player.scores["skill_kishi_protected"] == 0) {
            player.scores["skill_kishi_frequency"] = player.scores["#GameManager_skill_kishi_frequency"];
        }
    });

    // 騎士
    for (int i = 1; i <= 12; ++i) {
        execute(player, "unless_score_skill_kishi_cooltime_0", [&]() {
            if (player.team == "Kishi" && player.scores["skill_kishi_protected"] != 1 && player.predicate) {
                player.runFunction("werewolf:skill/skill_kishi/particular/kishi" + std::to_string(i));
            }
        });
    }

    // ポンコツ
    for (int i = 1; i <= 12; ++i) {
        execute(player, "if_score_skill_kishi_cooltime_0", [&]() {
            if (player.team == "Ponkotsu" && player.predicate) {
                player.runFunction("werewolf:skill/skill_kishi/particular/kishi" + std::to_string(i));
            }
        });
    }
}

int main() {
    Player player;
    player.team = "Kishi";
    player.scores["skill_kishi_cooltime"] = 0;
    player.scores["skill_kishi_protected"] = 0;
    player.scores["#GameManager_skill_kishi_frequency"] = 10;
    player.predicate = true;

    kishi_result(player);

    return 0;
}
