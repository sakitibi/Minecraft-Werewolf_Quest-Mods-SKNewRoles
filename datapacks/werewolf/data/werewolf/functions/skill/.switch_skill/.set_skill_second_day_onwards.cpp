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

void replaceItemWithAir(const std::string& team) {
    std::cout << "Replacing item with air for team " << team << std::endl;
}

void removeScore(const std::string& player, const std::string& score, int value) {
    std::cout << "Removing " << value << " from score " << score << " for player " << player << std::endl;
}

int main() {
    // スキル関連
    // 人狼
    replaceItemWithAir("Jinrou");
    replaceItemWithAir("Ponkotsu");

    // クールタイム設定
    // 咆哮
    removeScore("@a", "skill_jinrou_roar_cooltime", 1);
    replaceSkillItem("Jinrou", "werewolf:skill/jinrou_roar_skill/cooltime");

    // Conditional replacements based on time phase
    std::string time_phase = "day"; // Example value, replace with actual logic to get time phase
    if (time_phase == "day") {
        replaceSkillItem("Jinrou", "werewolf:skill/jinrou_roar_skill/ban");
    } else if (time_phase == "night") {
        replaceSkillItem("Jinrou", "werewolf:skill/jinrou_roar_skill/");
    }

    // 切り裂く
    replaceSkillItem("Jinrou", 0, "werewolf:skill/jinrou_slash_skill/");
    replaceSkillItem("Jinrou", 1, "werewolf:skill/jinrou_slash_skill/cooltime");

    // アサシン
    replaceSkillItem("Asasine", 0, "werewolf:skill/asasine_skill/");
    replaceSkillItem("Asasine", 1, "werewolf:skill/asasine_skill/cooltime");

    // Witch
    replaceItemWithAir("Witch");

    // クールタイム設定
    // ビーム
    removeScore("@a", "skill_jinrou_roar_cooltime", 1);
    replaceSkillItem("Witch", "werewolf:skill/jinrou_roar_skill/cooltime");

    if (time_phase == "day") {
        replaceSkillItem("Witch", "werewolf:skill/jinrou_roar_skill/ban");
    } else if (time_phase == "night") {
        replaceSkillItem("Witch", "werewolf:skill/jinrou_roar_skill/");
    }

    // キル
    replaceSkillItem("Witch", 0, "werewolf:skill/asasine_skill/");
    replaceSkillItem("Witch", 1, "werewolf:skill/asasine_skill/cooltime");

    // 罠師
    replaceSkillItem("Wanashi", "werewolf:skill/wanashi_skill/");
    removeScore("@a", "skill_wanashi_cooltime", 1);
    replaceSkillItem("Wanashi", "werewolf:skill/wanashi_skill/cooltime");

    // 占い師
    replaceSkillItem("Uranai", "werewolf:skill/uranai_skill/cooltime");
    replaceSkillItem("Uranai", "werewolf:skill/uranai_skill/");

    // 霊能者
    replaceSkillItem("Reinou", "werewolf:skill/reinou_skill/cooltime");
    replaceSkillItem("Reinou", "werewolf:skill/reinou_skill/");

    // 騎士
    replaceSkillItem("Kishi", "werewolf:skill/kishi_skill/cooltime");
    replaceSkillItem("Kishi", "werewolf:skill/kishi_skill/");

    // シェリフ
    replaceSkillItem("Hoankan", "werewolf:skill/hoankan_skill/cooltime");
    replaceSkillItem("Hoankan", "werewolf:skill/hoankan_skill/");

    // オポチュニスト
    replaceSkillItem("Ojousama", "werewolf:skill/ojousama_skill/cooltime");
    replaceSkillItem("Ojousama", "werewolf:skill/ojousama_skill/");

    // 裁判官
    replaceSkillItem("Saibankan", "werewolf:skill/saibankan_skill/cooltime");
    replaceSkillItem("Saibankan", "werewolf:skill/saibankan_skill/");

    // 妖狐
    replaceSkillItem("Youko", "werewolf:skill/youko_skill/cooltime");

    // 死神
    replaceSkillItem("Shinigami", "werewolf:skill/shinigami_skill/cooltime");
    replaceSkillItem("Shinigami", "werewolf:skill/shinigami_skill/");

    // キューピット
    replaceSkillItem("Cupid", "werewolf:skill/cupid_skill/");
    removeScore("@a", "skill_cupid_cooltime", 1);
    replaceSkillItem("Cupid", "werewolf:skill/cupid_skill/cooltime");

    // 人狼スキル処理
    executeFunction("werewolf:skill/skill_jinrou/jinrou_roar_skill/");
    tellraw("今はまだ使えない。");
    tellraw("今はまだ使えない。");
    executeFunction("werewolf:skill/skill_jinrou/jinrou_roar_skill/shot");

    // 切り裂き
    executeFunction("werewolf:skill/skill_jinrou/jinrou_slash_skill/.jinrou_slash_result");
    executeFunction("werewolf:skill/skill_jinrou/jinrou_slash_skill/.jinrou_slash_result");

    // スキルチェンジ
    replaceItemWithAir("Jinrou");
    replaceItemWithAir("Ponkotsu");

    // アサシン用
    executeFunction("werewolf:skill/skill_jinrou/jinrou_slash_skill/.jinrou_slash_result");
    executeFunction("werewolf:skill/skill_jinrou/jinrou_slash_skill/.jinrou_slash_result");

    // Witchスキル処理
    executeFunction("werewolf:skill/skill_jinrou/jinrou_roar_skill/");
    tellraw("今はまだ使えない。");
    tellraw("今はまだ使えない。");
    executeFunction("werewolf:skill/skill_witch/witch_roar_skill/shot");

    // スキルチェンジ
    replaceItemWithAir("Witch");

    // キル
    executeFunction("werewolf:skill/skill_witch/witch_slash_skill/.witch_slash_result");
    executeFunction("werewolf:skill/skill_witch/witch_slash_skill/.witch_slash_result");

    // リモコンスキル処理
    executeFunction("werewolf:skill/skill_rimokon/rimokon_marking_skill/");
    tellraw("今はまだ使えない。");
    tellraw("今はまだ使えない。");
    executeFunction("werewolf:skill/skill_rimokon/rimokon_marking_skill/rimokon_marking_skill_result");

    // 操作
    executeFunction("werewolf:skill/skill_rimokon/operation_slash_skill/.rimokon_operation_result");
    executeFunction("werewolf:skill/skill_rimokon/rimokon_operation_skill/.rimokon_operation_result");

    // スキルチェンジ
    replaceItemWithAir("Rimokon");

    // キル
    executeFunction("werewolf:skill/skill_rimokon/rimokon_slash_skill/.rimokon_slash_result");
    executeFunction("werewolf:skill/skill_rimokon/rimokon_slash_skill/.rimokon_slash_result");

    // ダブルキラースキル処理
    executeFunction("werewolf:skill/skill_doublekiller/doublekiller_mainslash_skill/");
    tellraw("今はまだ使えない。");
    tellraw("今はまだ使えない。");
    executeFunction("werewolf:skill/skill_doublekiller/doublekiller_mainslash_skill/doublekiller_mainslash_skill_result");

    // スキルチェンジ
    replaceItemWithAir("Doublekiller");

    // キル
    executeFunction("werewolf:skill/skill_doublekiller/doublekiller_subslash_skill/.doublekiller_subslash_result");
    executeFunction("werewolf:skill/skill_doublekiller/doublekiller_subslash_skill/.doublekiller_subslash_result");

    // 罠設置処理
    executeFunction("werewolf:skill/skill_wanashi/.main");
    executeFunction("werewolf:skill/skill_wanashi/.main");

    // 占い処理
    executeFunction("werewolf:skill/skill_uranai/.uranai_result");
    executeFunction("werewolf:skill/skill_uranai/.uranai_result");

    // 霊能処理
    executeFunction("werewolf:skill/skill_reinou/.reinou_result");
    executeFunction("werewolf:skill/skill_reinou/.reinou_result");

    // 守護処理
    executeFunction("werewolf:skill/skill_kishi/.kishi_result");
    executeFunction("werewolf:skill/skill_kishi/.kishi_result");

    // シェリフ処理
    executeFunction("werewolf:skill/skill_hoankan/.hoankan_result");
    executeFunction("werewolf:skill/skill_hoankan/.hoankan_result");

    // オポチュニスト処理
    executeFunction("werewolf:skill/skill_ojousama/.ojousama_result");
    executeFunction("werewolf:skill/skill_ojousama/.ojousama_result");

    // 裁判官処理
    executeFunction("werewolf:skill/skill_saibankan/.saibankan_result");
    executeFunction("werewolf:skill/skill_saibankan/.saibankan_result");

    // 裁判官補佐処理
    executeFunction("werewolf:skill/skill_saibankan/.successor_result");

    // 死神処理
    executeFunction("werewolf:skill/skill_shinigami/.shinigami_result");
    executeFunction("werewolf:skill/skill_shinigami/.shinigami_result");

    // キューピット処理
    executeFunction("werewolf:skill/skill_cupid/lovers_judge");
    executeFunction("werewolf:skill/skill_cupid/");
    tellraw("今はまだ使えない。");
    tellraw("今はまだ使えない。");
    executeFunction("werewolf:skill/skill_cupid/shot");
    tellraw("このスキルはもう使えない。");

    // クールタイム可視化処理
    if (time_phase == "night") {
        executeFunction("werewolf:skill/skill_jinrou/jinrou_roar_skill/cooltime/set_cooltime");
        executeFunction("werewolf:skill/skill_witch/witch_roar_skill/cooltime/set_cooltime");
    }

    executeFunction("werewolf:skill/skill_wanashi/cooltime/set_cooltime");
    executeFunction("werewolf:skill/skill_cupid/cooltime/set_cooltime");

    return 0;
}
