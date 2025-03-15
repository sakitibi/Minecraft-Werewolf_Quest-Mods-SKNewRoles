#include <iostream>
#include <string>

void executeCommand(const std::string& command) {
    std::cout << command << std::endl;
}

void loversJudge() {
    // 判定処理
    executeCommand("execute if entity @a[tag=player,tag=lovers_1] if entity @a[tag=player,tag=lovers_2] run scoreboard players set #GameManager lovers_full 1");
}

int main() {
    loversJudge();
    return 0;
}
