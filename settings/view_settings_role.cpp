#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Helper function to create a JSON string
string createTellrawJson(const string& text, const string& color, const string& hoverEvent = "", const string& clickEvent = "") {
    stringstream ss;
    ss << "{\\\"text\\\":\\\"" << text << "\\\",\\\"color\\\":\\\"" << color << "\\\"";
    if (!hoverEvent.empty()) {
        ss << ",\\\"hoverEvent\\\":\" << hoverEvent << "\\\"";
    }
    if (!clickEvent.empty()) {
        ss << ",\\\"clickEvent\\\":\" << clickEvent << "\\\"";
    }
    ss << "}";
    return ss.str();
}

// Helper function to create a hover event JSON
string createHoverEventJson(const string& text) {
    return "{\\\"action\\\":\\\"show_text\\\",\\\"contents\\\":[{\\\"text\\\":\\\"" + text + "\\\"}]}";
}

// Helper function to create a click event JSON
string createClickEventJson(const string& command) {
    return "{\\\"action\\\":\\\"run_command\\\",\\\"value\\\":\\\"" + command + "\\\"}";
}

// Function to display the role settings
void displayRoleSettings(const string& roleName, const string& faction, const string& color, const string& skillDescription, int roleCount, const string& addCommand, const string& removeCommand, int minCount, int maxCount) {
    bool canAdd = roleCount < maxCount;
    bool canRemove = roleCount > minCount;

    string hoverText = "陣営: " + faction + "\\nスキル: \\n" + skillDescription;

    string roleText = createTellrawJson("  " + roleName + "   ", color, createHoverEventJson(hoverText));

    string removeText = createTellrawJson(" <", canRemove ? "white" : "dark_red", createHoverEventJson(canRemove ? "人数を減らす" : "これ以上人数は減らせません"), canRemove ? createClickEventJson(removeCommand) : "");

    string countText = createTellrawJson("  " + to_string(roleCount) + "  ", "white");

    string addText = createTellrawJson(">", canAdd ? "white" : "dark_red", createHoverEventJson(canAdd ? "人数を増やす" : "これ以上人数は増やせません"), canAdd ? createClickEventJson(addCommand) : "");

    cout << "tellraw @s [" << roleText << "," << removeText << "," << countText << "," << addText << "]" << endl;
}

int main() {
    // Output header
    cout << "tellraw @s {\\\"text\\\":\\\"\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n[Settings]\\\"}" << endl;
    cout << "tellraw @s {\\\"text\\\":\\\" [役職人数]\\\"}" << endl;

    // Display role settings
    displayRoleSettings("人狼", "狼(人狼)", "red", "> 切り裂く - 目の前の相手を一撃でキルすることができる\\n > 咆哮(夜限定) - 直線上の相手を一撃でキルすることができる\\n特殊能力:\\n > 誰が人狼か知ることができる(役職本から確認可能)\\n > 転移の炎(ワープポイント)を使用できる", 1, "/function werewolf:.settings/role/count/jinrou/add", "/function werewolf:.settings/role/count/jinrou/remove", 0, 3);
    displayRoleSettings("Witch", "狼(Witch)", "red", "> キル - 目の前の相手を一撃でキルすることができる\\n > ビーム(夜限定) - 直線上の相手を一撃でキルすることができる\\n特殊能力:\\n > 誰が人狼か知ることができる(役職本から確認可能)\\n > 転移の炎(ワープポイント)を使用できる", 0, "/function werewolf:.settings/role/count/witch/add", "/function werewolf:.settings/role/count/witch/remove", 0, 3);
    displayRoleSettings("リモコン", "狼(リモコン)", "red", "> キル - 目の前の相手を一撃でキルすることができる\\n > マーキング - 目の前の相手をマーキングすることが出来る \\n> 操作 - マーキングした相手を一定時間操作することが出来る\\n特殊能力:\\n > 誰が人狼か知ることができる(役職本から確認可能)\\n > 転移の炎(ワープポイント)を使用できる", 0, "/function werewolf:.settings/role/count/rimokon/add", "/function werewolf:.settings/role/count/rimokon/remove", 0, 3);
    displayRoleSettings("ダブルキラー", "狼(ダブルキラー)", "red", "> キル - 目の前の相手を一撃でキルすることができる スキルボタンが二つある\\n特殊能力:\\n > 誰が人狼か知ることができる(役職本から確認可能)\\n > 転移の炎(ワープポイント)を使用できる", 0, "/function werewolf:.settings/role/count/doublekiller/add", "/function werewolf:.settings/role/count/doublekiller/remove", 0, 3);
    displayRoleSettings("アサシン", "狼(人狼)", "red", "> 切り裂く - 目の前の相手を一撃でキル、10秒間透明化する\\n特殊能力:\\n > 誰が人狼か知ることができる(役職本から確認可能)\\n > 転移の炎(ワープポイント)を使用できる\\n > スキルで相手をキルすると一定時間透明になる", 0, "/function werewolf:.settings/role/count/asasine/add", "/function werewolf:.settings/role/count/asasine/remove", 0, 3);
    displayRoleSettings("狂人", "狼(狂人)", "red", "> なし", 0, "/function werewolf:.settings/role/count/kyoujin/add_kyoujin", "/function werewolf:.settings/role/count/kyoujin/remove_kyoujin", 0, 3);
    displayRoleSettings("狂信者", "狼(狂人)", "red", "> なし\\n特殊能力:\\n > 誰が人狼か知ることができる(役職本から確認可能)", 0, "/function werewolf:.settings/role/count/kyoushin/add_kyoushin", "/function werewolf:.settings/role/count/kyoushin/remove_kyoushin", 0, 3);
    displayRoleSettings("罠師", "狼(狂人)", "red", "> 落とし穴 - 足元に狼陣営のみ視認可能な罠を設置する", 0, "/function werewolf:.settings/role/count/wanashi/add_wanashi", "/function werewolf:.settings/role/count/wanashi/remove_wanashi", 0, 3);
    displayRoleSettings("占い師", "村", "green", "> 占い - 相手が人狼か否かを確認できる", 0, "/function werewolf:.settings/role/count/uranaishi/add_uranaishi", "/function werewolf:.settings/role/count/uranaishi/remove_uranaishi", 0, 3);
    displayRoleSettings("霊能者", "村", "green", "> 霊能 - 墓となったプレイヤーが人狼であったか確認できる", 0, "/function werewolf:.settings/role/count/reinousha/add_reinousha", "/function werewolf:.settings/role/count/reinousha/remove_reinousha", 0, 3);
    displayRoleSettings("騎士", "村", "green", "> 守護 - 相手を人狼のスキルから護ることができる", 0, "/function werewolf:.settings/role/count/kishi/add_kishi", "/function werewolf:.settings/role/count/kishi/remove_kishi", 0, 1);
    displayRoleSettings("共有者", "村", "green", "> なし\\n特殊能力:\\n > もう1人の共有者を知ることができる(役職本から確認可能)", 2, "/function werewolf:.settings/role/count/kyouyuu/add_kyouyuu", "/function werewolf:.settings/role/count/kyouyuu/remove_kyouyuu", 2, 2);
    displayRoleSettings("シェリフ", "村", "green", "> 正義執行 - 相手が狼陣営ならキルできる\\n          その他陣営なら自身が死亡する", 0, "/function werewolf:.settings/role/count/hoankan/add_hoankan", "/function werewolf:.settings/role/count/hoankan/remove_hoankan", 0, 3);
    displayRoleSettings("パン屋", "村", "green", "> なし\\n特殊能力:\\n > 生存している限り夜が明けると全員にパンが配られる", 0, "/function werewolf:.settings/role/count/panya/add_panya", "/function werewolf:.settings/role/count/panya/remove_panya", 0, 3);
    displayRoleSettings("ポンコツ", "村", "green", "> なし\\n特殊能力:\\n > 自分を他の役職と思い込む\\n > ダミー役職: 人狼,占い師,霊能者,騎士,シェリフ", 0, "/function werewolf:.settings/role/count/ponkotsu/add_ponkotsu", "/function werewolf:.settings/role/count/ponkotsu/remove_ponkotsu", 0, 3);
    displayRoleSettings("妖狐", "第三陣営(妖狐)", "aqua", "> サイドキック(初日の昼のみ) - 相手を1人従えることができる\\n特殊能力:\\n > 人狼のスキルによって倒されない\\n > 占われると死亡する\\n勝利条件:\\n > 他陣営が勝利条件を満たす＋妖狐陣営の生存", 0, "/function werewolf:.settings/role/count/youko/add_youko", "/function werewolf:.settings/role/count/youko/remove_youko", 0, 1);
    displayRoleSettings("死神", "第三陣営(死神)", "aqua", "> 憑依 - 相手をキルしてその役職になり替わる\\n勝利条件:\\n > ①スキル不使用時 - 死神陣営のみの生存\\n > ②スキル使用時 - なり替わった役職に従う", 0, "/function werewolf:.settings/role/count/shinigami/add_shinigami", "/function werewolf:.settings/role/count/shinigami/remove_shinigami", 0, 1);
    displayRoleSettings("キューピット", "第三陣営(恋人)", "aqua", "> 縁結び - 放物線上にいる相手を恋人にする\\n            恋人が2人になった時からスキルが封印される\\n特殊能力:\\n > 恋人が2人になって以降、恋人が死亡すると恋人陣営は全滅する\\n勝利条件:\\n > ①村陣営または狼陣営の全滅＋恋人2人の生存\\n > ②恋人(＋キューピット)のみの生存", 0, "/function werewolf:.settings/role/count/cupid/add_cupid", "/function werewolf:.settings/role/count/cupid/remove_cupid", 0, 1);

    // Output return button
    string returnButtonJson = createTellrawJson("← 戻る", "green", "", createClickEventJson("/function werewolf:.settings/view_settings"));
    cout << "tellraw @s [" << returnButtonJson << "]" << endl;

    // Output settings reload command
    cout << "function werewolf:.settings/reload_settings" << endl;

    return 0;
}
