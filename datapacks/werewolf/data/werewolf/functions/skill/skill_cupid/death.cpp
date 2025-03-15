#include <iostream>
#include <string>

void executeCommand(const std::string& command) {
    std::cout << command << std::endl;
}

void processDeath() {
    // メッセージを表示
    executeCommand(R"(tellraw @a[tag=player,tag=lovers] [{"text":"亡き思い人の後を追い、あなたは永遠の愛へと旅立った…","color":"light_purple"}])");
    executeCommand(R"(tellraw @a[team=Cupid] [{"text":"亡き思い人達の後を追い、あなたは永遠の愛へと旅立った…","color":"light_purple"}])");

    // プレイヤーをキル
    executeCommand("kill @a[tag=player,tag=lovers]");
    executeCommand("kill @a[team=Cupid]");
}

int main() {
    processDeath();
    return 0;
}
