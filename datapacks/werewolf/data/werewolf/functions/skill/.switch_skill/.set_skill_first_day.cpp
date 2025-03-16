#include <iostream>
#include <string>
#include <unordered_map>

// Simulate the Minecraft execute and loot commands
void replaceSkillItem(const std::string& team, int skillMode, const std::string& skill) {
    std::cout << "Replacing skill item for team " << team << " with skill mode " << skillMode << " to " << skill << std::endl;
}

void replaceSkillItem(const std::string& team, const std::string& skill) {
    std::cout << "Replacing skill item for team " << team << " to " << skill << std::endl;
}

void tellraw(const std::string& message) {
    std::cout << "Tellraw message: " << message << std::endl;
}

void executeFunction(const std::string& functionName) {
    std::cout << "Executing function " << functionName << std::endl;
}

int main() {
    // 役職スキルをセット
    std::unordered_map<std::string, std::unordered_map<int, std::string>> skillMap = {
        {"Jinrou", {{0, "werewolf:skill/jinrou_slash_skill/cooltime"}, {1, "werewolf:skill/jinrou_roar_skill/ban"}}},
        {"Asasine", {{0, "werewolf:skill/asasine_skill/cooltime"}}},
        {"Witch", {{0, "werewolf:skill/witch_slash_skill/cooltime"}, {1, "werewolf:skill/witch_roar_skill/ban"}}},
        {"Rimokon", {{0, "werewolf:skill/rimokon_slash_skill/cooltime"}, {1, "werewolf:skill/rimokon_marking_skill/cooltime"}, {2, "werewolf:skill/rimokon_operation_skill/cooltime"}}},
        {"Doublekiller", {{0, "werewolf:skill/doublekiller_mainslash_skill/cooltime"}, {1, "werewolf:skill/doublekiller_subslash_skill/cooltime"}}},
        {"Wanashi", {{0, "werewolf:skill/wanashi_skill/ban"}}},
        {"Uranai", {{0, "werewolf:skill/uranai_skill/cooltime"}}},
        {"Reinou", {{0, "werewolf:skill/reinou_skill/cooltime"}}},
        {"Kishi", {{0, "werewolf:skill/kishi_skill/cooltime"}}},
        {"Hoankan", {{0, "werewolf:skill/hoankan_skill/cooltime"}}},
        {"Ojousama", {{0, "werewolf:skill/ojousama_skill/cooltime"}}},
        {"Saibankan", {{0, "werewolf:skill/saibankan_skill/cooltime"}}},
        {"Niceteleporter", {{0, "werewolf:skill/niceteleporter_skill/cooltime"}}},
        {"Shinigami", {{0, "werewolf:skill/shinigami_skill/cooltime"}}},
        {"Cupid", {{0, "werewolf:skill/cupid_skill/ban"}}}
    };

    for (const auto& team : skillMap) {
        for (const auto& skill : team.second) {
            replaceSkillItem(team.first, skill.first, skill.second);
        }
    }

    // 役職スキルをセット(ポンコツ用)
    std::unordered_map<std::string, std::string> ponkotsuSkillMap = {
        {"jinrou_dummy_0", "werewolf:skill/jinrou_slash_skill/cooltime"},
        {"jinrou_dummy_1", "werewolf:skill/jinrou_roar_skill/ban"},
        {"wanashi_dummy", "werewolf:skill/wanashi_skill/ban"},
        {"uranai_dummy", "werewolf:skill/uranai_skill/cooltime"},
        {"reinou_dummy", "werewolf:skill/reinou_skill/cooltime"},
        {"kishi_dummy", "werewolf:skill/kishi_skill/cooltime"},
        {"hoankan_dummy", "werewolf:skill/hoankan_skill/cooltime"},
        {"ojousama_dummy", "werewolf:skill/ojousama_skill/cooltime"},
        {"saibankan_dummy", "werewolf:skill/saibankan_skill/cooltime"}
    };

    for (const auto& skill : ponkotsuSkillMap) {
        replaceSkillItem("Ponkotsu", skill.second);
    }

    // 役職スキル処理
    // 人狼
    tellraw("今はまだ使えない。");
    tellraw("初日の昼はスキルが使えない。");

    // Witch
    tellraw("今はまだ使えない。");
    tellraw("初日の昼はスキルが使えない。");

    // リモコン
    tellraw("初日の昼はスキルが使えない。");
    tellraw("初日の昼はスキルが使えない。");
    tellraw("初日の昼はスキルが使えない。");

    // ダブルキラー
    tellraw("初日の昼はスキルが使えない。");
    tellraw("初日の昼はスキルが使えない。");

    // 罠師
    tellraw("初日の昼はスキルが使えない。");

    // 占い師
    tellraw("初日の昼はスキルが使えない。");

    // 霊能者
    tellraw("初日の昼はスキルが使えない。");

    // 騎士
    tellraw("初日の昼はスキルが使えない。");

    // シェリフ
    tellraw("初日の昼はスキルが使えない。");

    // オポチュニスト
    tellraw("初日の昼はスキルが使えない。");

    // 裁判官
    tellraw("初日の昼はスキルが使えない。");

    // 死神
    tellraw("初日の昼はスキルが使えない。");

    // キューピット
    tellraw("初日の昼はスキルが使えない。");

    // 妖狐
    executeFunction("werewolf:skill/skill_youko/.youko_result");
    executeFunction("werewolf:skill/skill_youko/.youko_result");

    // クールタイム設定
    replaceSkillItem("youko_skill", "werewolf:skill/youko_skill/cooltime");
    replaceSkillItem("youko_skill_cooltime", "werewolf:skill/youko_skill/");

    return 0;
}
