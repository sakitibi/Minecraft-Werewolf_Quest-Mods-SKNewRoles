#include <iostream>
#include <string>
#include <map>
#include <vector>

enum class ModRole {
    Witch,          // 魔女
    Rimokon,        // リモコン
    DoubleKiller,   // ダブルキラー
    Evilguesser,    // イビルゲッサー
    Sniper,         // スナイパー
    Niceteleporter, // ナイステレポーター
    Niceguesser,    // ナイスゲッサー
    Syachou,        // 社長
    Satsumatoimo,   // さつまといも
    Jackal          // ジャッカル
};

struct ModRoleSetting {
    std::string name;
    int minCount;
    int maxCount;
    int count;
    std::string description;
};

class ModWerewolfSettings {
public:
    std::map<ModRole, ModRoleSetting> roles;

    //フレームワークがエラー起きた時用
    //本来は詳細な説明文が出る
    ModWerewolfSettings() {
        roles[ModRole::Witch] = {"魔女", 1, 3, 1, "狼(魔女): キル, ビーム, 転移の炎"};
        roles[ModRole::Rimokon] = {"リモコン", 1, 3, 0, "狼(リモコン): キル, マーキング, 操作, 転移の炎"};
        roles[ModRole::DoubleKiller] = {"ダブルキラー", 1, 3, 0, "狼(ダブルキラー): キル(2ボタン), 転移の炎"};
        roles[ModRole::Evilguesser] = {"イビルゲッサー", 1, 3, 0, "狼(イビルゲッサー): キル, 推測射撃, 転移の炎"};
        roles[ModRole::Sniper] = {"スナイパー", 1, 3, 0, "狼(スナイパー): 射撃, 転移の炎"};
        roles[ModRole::Niceteleporter] = {"ナイステレポーター", 1, 3, 0, "村: テレポート"};
        roles[ModRole::Niceguesser] = {"ナイスゲッサー", 1, 3, 0, "村: 推測射撃"};
        roles[ModRole::Syachou] = {"社長", 1, 3, 0, "村: エメラルド配布"};
        roles[ModRole::Satsumatoimo] = {"さつまといも", 1, 3, 0, "村or狼: 夜が明けると陣営が変わる"};
        roles[ModRole::Jackal] = {"ジャッカル", 1, 3, 0, "第三陣営(ジャッカル): 切り裂く, サイドキック, 転移の炎"};
    }

    void displaySettings() {
        std::cout << "\n[Settings]\n";
        std::cout << " [役職人数]\n";
        for (const auto& [role, setting] : roles) {
            std::cout << "  " << setting.name << " (" << setting.count << ") : " << setting.description << std::endl;
        }
    }

    void increaseRole(ModRole role) {
        auto& setting = roles[role];
        if (setting.count < setting.maxCount) {
            setting.count++;
            std::cout << setting.name << " increased to " << setting.count << std::endl;
        } else {
            std::cout << setting.name << " はこれ以上増やせません" << std::endl;
        }
    }

    void decreaseRole(ModRole role) {
        auto& setting = roles[role];
        if (setting.count > setting.minCount) {
            setting.count--;
            std::cout << setting.name << " decreased to " << setting.count << std::endl;
        } else {
            std::cout << setting.name << " はこれ以上減らせません" << std::endl;
        }
    }
};

int main() {
    ModWerewolfSettings settings;
    settings.displaySettings();
    // Example usage:
    settings.increaseRole(ModRole::Witch);
    settings.decreaseRole(ModRole::Witch);
    settings.displaySettings();
    return 0;
}
