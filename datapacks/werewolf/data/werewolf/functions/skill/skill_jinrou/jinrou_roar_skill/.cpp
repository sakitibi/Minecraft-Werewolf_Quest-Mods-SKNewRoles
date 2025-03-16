#include <iostream>
#include <string>
#include <unordered_map>

// Simulate the Minecraft execute and function commands
void executeFunction(const std::string& functionName) {
    std::cout << "Executing function " << functionName << std::endl;
}

void executeParticle(const std::string& particle, const std::string& entity) {
    std::cout << "Executing particle " << particle << " for entity " << entity << std::endl;
}

void killEntity(const std::string& entity) {
    std::cout << "Killing entity " << entity << std::endl;
}

void addTag(const std::string& entity, const std::string& tag) {
    std::cout << "Adding tag " << tag << " to entity " << entity << std::endl;
}

int main() {
    // Example values, replace with actual logic to get scores and entities
    std::unordered_map<std::string, int> scores = {{"charge_roar", 0}};
    std::string team = "Jinrou"; // Example value
    std::string entity = "entity"; // Example value

    // チャージ
    if (team == "Jinrou" && scores["charge_roar"] >= 0) {
        executeFunction("werewolf:skill/skill_jinrou/jinrou_roar_skill/charge");
    }
    if (team == "Witch" && scores["charge_roar"] >= 0) {
        executeFunction("werewolf:skill/skill_jinrou/jinrou_roar_skill/charge");
    }

    // 当たり判定処理
    if (entity == "item" && scores["charge_roar"] < 0) {
        addTag("entity", "hit_roar");
    }
    if (entity == "hit_roar") {
        killEntity("item");
        executeFunction("werewolf:skill/skill_jinrou/jinrou_roar_skill/damage");
    }

    // 壁や床に当たったら消滅
    if (entity == "item") {
        executeFunction("werewolf:skill/skill_jinrou/jinrou_roar_skill/bounce");
    }

    // パーティクルの表示
    if (entity == "item") {
        executeParticle("sonic_boom", "entity");
    }

    // ポンコツ
    if (team == "Ponkotsu" && scores["charge_roar"] >= 0) {
        executeFunction("werewolf:skill/skill_jinrou/jinrou_roar_skill/charge_dummy");
    }

    // 当たり判定処理
    if (entity == "item" && scores["charge_roar"] < 0) {
        killEntity("item");
    }

    // 壁や床に当たったら消滅
    if (entity == "item") {
        executeFunction("werewolf:skill/skill_jinrou/jinrou_roar_skill/bounce_dummy");
    }

    // パーティクルの表示
    if (entity == "item") {
        executeParticle("minecraft:sonic_boom", "entity");
    }

    return 0;
}
