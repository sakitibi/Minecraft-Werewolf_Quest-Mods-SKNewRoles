#include <iostream>
#include <string>
#include <unordered_map>

// Simulate the Minecraft data modify, execute, and clear commands
void dataModifyStorage(const std::string& storage, const std::string& action) {
    std::cout << "Data modify storage " << storage << " " << action << std::endl;
}

void executeFunction(const std::string& functionName) {
    std::cout << "Executing function " << functionName << std::endl;
}

void clearItem(const std::string& item) {
    std::cout << "Clearing item " << item << std::endl;
}

void replaceSkillItem(const std::string& team, int skillMode, const std::string& skill) {
    std::cout << "Replacing skill item for team " << team << " with skill mode " << skillMode << " to " << skill << std::endl;
}

void replaceSkillItem(const std::string& team, const std::string& skill) {
    std::cout << "Replacing skill item for team " << team << " to " << skill << std::endl;
}

void replaceItemWithNoSkill() {
    std::cout << "Replacing item with no skill" << std::endl;
}

int main() {
    // スロット情報記録
    dataModifyStorage("sys: return_item", "set from entity @s Inventory[{Slot:8b}]");

    // アイテム返却
    executeFunction("werewolf:.system/inventory_menu/return_item");

    // 念のためのストレージリセット
    dataModifyStorage("sys: return_item", "remove");

    // スキルアイテムクリア
    clearItem("carrot_on_a_stick{Tags:[\"role_skill\",\"no_drop\"]}");

    // 役職スキルをセット
    std::unordered_map<std::string, std::unordered_map<int, std::string>> skillMap = {
        {"Jinrou", {{0, "werewolf:skill/jinrou_slash_skill/"}, {1, "werewolf:skill/jinrou_roar_skill/"}}},
        {"Asasine", {{0, "werewolf:skill/asasine_skill/"}}},
        {"Witch", {{0, "werewolf:skill/witch_slash_skill/"}, {1, "werewolf:skill/witch_roar_skill/"}}},
        {"Rimokon", {{0, "werewolf:skill/rimokon_slash_skill/"}, {1, "werewolf:skill/rimokon_marking_skill/"}, {2, "werewolf:skill/rimokon_operation_skill/"}}},
        {"Doublekiller", {{0, "werewolf:skill/doublekiller_mainslash_skill/"}, {1, "werewolf:skill/doublekiller_subslash_skill/"}}},
        {"Wanashi", {{0, "werewolf:skill/wanashi_skill/"}}},
        {"Uranai", {{0, "werewolf:skill/uranai_skill/"}}},
        {"Reinou", {{0, "werewolf:skill/reinou_skill/"}}},
        {"Kishi", {{0, "werewolf:skill/kishi_skill/"}}},
        {"Hoankan", {{0, "werewolf:skill/hoankan_skill/"}}},
        {"Ojousama", {{0, "werewolf:skill/ojousama_skill/"}}},
        {"Saibankan", {{0, "werewolf:skill/saibankan_skill/"}}},
        {"Youko", {{0, "werewolf:skill/youko_skill/"}}},
        {"Shinigami", {{0, "werewolf:skill/shinigami_skill/"}}},
        {"Cupid", {{0, "werewolf:skill/cupid_skill/"}}}
    };

    for (const auto& team : skillMap) {
        for (const auto& skill : team.second) {
            replaceSkillItem(team.first, skill.first, skill.second);
        }
    }

    // ポンコツ用
    std::unordered_map<std::string, std::string> ponkotsuSkillMap = {
        {"jinrou_dummy", "werewolf:skill/jinrou_slash_skill/"},
        {"wanashi_dummy", "werewolf:skill/wanashi_skill/"},
        {"uranai_dummy", "werewolf:skill/uranai_skill/"},
        {"reinou_dummy", "werewolf:skill/reinou_skill/"},
        {"kishi_dummy", "werewolf:skill/kishi_skill/"},
        {"hoankan_dummy", "werewolf:skill/hoankan_skill/"},
        {"ojousama_dummy", "werewolf:skill/ojousama_skill/"},
        {"saibankan_dummy", "werewolf:skill/saibankan_skill/"},
        {"ex_shinigami", "minecraft:carrot_on_a_stick{Tags:[\"role_skill\",\"no_drop\"],display:{Name:'{\"text\":\"スキル無し\",\"italic\":false,\"color\":\"white\"}'},Enchantments:[{id:\"minecraft:vanishing_curse\",lvl:1s}],CustomModelData:9999,HideFlags:63}"}
    };

    for (const auto& skill : ponkotsuSkillMap) {
        replaceSkillItem("Ponkotsu", skill.second);
    }

    // Replace item with no skill for players not in specific teams
    replaceItemWithNoSkill();

    return 0;
}
