#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Helper function to create a JSON string
string createTellrawJson(const string& text, const string& color, const string& hoverEvent = "", const string& clickEvent = "") {
    stringstream ss;
    ss << "{\\\"text\\\":\\\"" << text << "\\\",\\\"color\\\":\\\"" << color << "\\\"";
    if (!hoverEvent.empty()) {
        ss << ",\\\"hoverEvent\\\":" << hoverEvent;
    }
    if (!clickEvent.empty()) {
        ss << ",\\\"clickEvent\\\":" << clickEvent;
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

// Function to display skill settings with limit and frequency
void displaySkillSettings(const string& skillName, const string& limitObjective, int limitValue, const string& addLimitCommand, const string& removeLimitCommand, const string& frequencyObjective, int frequencyValue, const string& addFrequencyCommand, const string& removeFrequencyCommand) {
    // Skill Limit
    string limitText;
    if (limitValue == 0) {
        limitText = "無制限";
    } else {
        limitText = to_string(limitValue) + " 回";
    }

    string limitTellraw;
    if (limitValue == 0) {
        limitTellraw = createTellrawJson("  スキル[" + skillName + "]の最大回数", "gold", createHoverEventJson("これ以上減らせません"), createClickEventJson(addLimitCommand));
    } else if (limitValue >= 1 && limitValue < 5) {
        limitTellraw = createTellrawJson("  スキル[" + skillName + "]の最大回数", "gold", createHoverEventJson("最大回数を減らす"), createClickEventJson(removeLimitCommand));
    } else {
        limitTellraw = createTellrawJson("  スキル[" + skillName + "]の最大回数", "gold", createHoverEventJson("これ以上増やせません"));
    }

    string limitMiddleText = createTellrawJson(limitText, "white");
    string limitEndText;

    if (limitValue == 0) {
        limitEndText = createTellrawJson("  >", "white", createHoverEventJson("最大回数を増やす"), createClickEventJson(addLimitCommand));
    } else if (limitValue >= 1 && limitValue < 5) {
        limitEndText = createTellrawJson("  >", "white", createHoverEventJson("最大回数を増やす"), createClickEventJson(addLimitCommand));
    } else {
        limitEndText = createTellrawJson("  >", "dark_red", createHoverEventJson("これ以上増やせません"));
    }

    cout << "tellraw @s [" << limitTellraw << "," << createTellrawJson(" <  ", (limitValue == 0) ? "dark_red" : "white", createHoverEventJson((limitValue == 0) ? "これ以上減らせません" : "最大回数を減らす"), (limitValue == 0) ? "" : createClickEventJson(removeLimitCommand)) << "," << limitMiddleText << "," << limitEndText << "]" << endl;

    // Skill Frequency
    string frequencyText = to_string(frequencyValue) + " 日";
    string frequencyTellraw;

    if (frequencyValue == 1) {
        frequencyTellraw = createTellrawJson("  スキル[" + skillName + "]の回復日数", "gold", createHoverEventJson("これ以上減らせません"), createClickEventJson(addFrequencyCommand));
    } else if (frequencyValue == 2) {
        frequencyTellraw = createTellrawJson("  スキル[" + skillName + "]の回復日数", "gold", createHoverEventJson("回復日数を減らす"), createClickEventJson(removeFrequencyCommand));
    } else {
        frequencyTellraw = createTellrawJson("  スキル[" + skillName + "]の回復日数", "gold", createHoverEventJson("これ以上増やせません"));
    }

    string frequencyMiddleText = createTellrawJson(frequencyText, "white");
    string frequencyEndText;

    if (frequencyValue == 1) {
        frequencyEndText = createTellrawJson("  >", "white", createHoverEventJson("回復日数を増やす"), createClickEventJson(addFrequencyCommand));
    } else if (frequencyValue == 2) {
        frequencyEndText = createTellrawJson("  >", "white", createHoverEventJson("回復日数を増やす"), createClickEventJson(addFrequencyCommand));
    } else {
        frequencyEndText = createTellrawJson("  >", "dark_red", createHoverEventJson("これ以上増やせません"));
    }

    cout << "tellraw @s [" << frequencyTellraw << "," << createTellrawJson(" <  ", (frequencyValue == 1) ? "dark_red" : "white", createHoverEventJson((frequencyValue == 1) ? "これ以上減らせません" : "回復日数を減らす"), (frequencyValue == 1) ? "" : createClickEventJson(removeFrequencyCommand)) << "," << frequencyMiddleText << "," << frequencyEndText << "]" << endl;
}

int main() {
    // Output header
    cout << "tellraw @s {\\\"text\\\":\\\"\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n[Settings]\\\"}" << endl;
    cout << "tellraw @s {\\\"text\\\":\\\" [スキル/特殊能力の詳細設定]\\\"}" << endl;

    // 人狼/アサシン
    cout << "tellraw @s {\\\"text\\\":\\\" [人狼/アサシン]\\\"}" << endl;
    displaySkillSettings("切り裂く", "#GameManager skill_jinrou_slash_limit", 0, "/function werewolf:.settings/role/skill/jinrou/slash/add_limit", "/function werewolf:.settings/role/skill/jinrou/slash/remove_limit", "#GameManager skill_jinrou_slash_frequency", 1, "/function werewolf:.settings/role/skill/jinrou/slash/add_frequency", "/function werewolf:.settings/role/skill/jinrou/slash/remove_frequency");

    // Witch
    cout << "tellraw @s {\\\"text\\\":\\\" [Witch]\\\"}" << endl;
    displaySkillSettings("切り裂く", "#GameManager skill_witch_slash_limit", 0, "/function werewolf:.settings/role/skill/witch/slash/add_limit", "/function werewolf:.settings/role/skill/witch/slash/remove_limit", "#GameManager skill_witch_slash_frequency", 1, "/function werewolf:.settings/role/skill/witch/slash/add_frequency", "/function werewolf:.settings/role/skill/witch/slash/remove_frequency");

    // リモコン
    cout << "tellraw @s {\\\"text\\\":\\\" [リモコン]\\\"}" << endl;
    displaySkillSettings("切り裂く", "#GameManager skill_rimokon_slash_limit", 0, "/function werewolf:.settings/role/skill/rimokon/slash/add_limit", "/function werewolf:.settings/role/skill/rimokon/slash/remove_limit", "#GameManager skill_rimokon_slash_frequency", 1, "/function werewolf:.settings/role/skill/rimokon/slash/add_frequency", "/function werewolf:.settings/role/skill/rimokon/slash/remove_frequency");
    displaySkillSettings("マーキング", "#GameManager skill_rimokon_marking_limit", 0, "/function werewolf:.settings/role/skill/rimokon/marking/add_limit", "/function werewolf:.settings/role/skill/rimokon/marking/remove_limit", "#GameManager skill_rimokon_marking_frequency", 1, "/function werewolf:.settings/role/skill/rimokon/marking/add_frequency", "/function werewolf:.settings/role/skill/rimokon/marking/remove_frequency");
    displaySkillSettings("操作", "#GameManager skill_rimokon_operation_limit", 0, "/function werewolf:.settings/role/skill/rimokon/operation/add_limit", "/function werewolf:.settings/role/skill/rimokon/operation/remove_limit", "#GameManager skill_rimokon_operation_frequency", 1, "/function werewolf:.settings/role/skill/rimokon/operation/add_frequency", "/function werewolf:.settings/role/skill/rimokon/operation/remove_frequency");

    // ダブルキラー
    cout << "tellraw @s {\\\"text\\\":\\\" [ダブルキラー]\\\"}" << endl;
    displaySkillSettings("切り裂く", "#GameManager skill_doublekiller_mainslash_limit", 0, "/function werewolf:.settings/role/skill/doublekiller/mainslash/add_limit", "/function werewolf:.settings/role/skill/doublekiller/mainslash/remove_limit", "#GameManager skill_doublekiller_mainslash_frequency", 1, "/function werewolf:.settings/role/skill/doublekiller/mainslash/add_frequency", "/function werewolf:.settings/role/skill/doublekiller/mainslash/remove_frequency");
    displaySkillSettings("切り裂く", "#GameManager skill_doublekiller_subslash_limit", 0, "/function werewolf:.settings/role/skill/doublekiller/subslash/add_limit", "/function werewolf:.settings/role/skill/doublekiller/subslash/remove_limit", "#GameManager skill_doublekiller_subslash_frequency", 1, "/function werewolf:.settings/role/skill/doublekiller/subslash/add_frequency", "/function werewolf:.settings/role/skill/doublekiller/subslash/remove_frequency");

    // 罠師
    cout << "tellraw @s {\\\"text\\\":\\\" [罠師]\\\"}" << endl;
    // You'll need to adapt displaySkillSettings or create a new function for pitfall_max_count, as it doesn't have frequency.
    // For example:
    cout << "tellraw @s {\\\"text\\\":\\\"  スキル[落とし穴]の同時設置数\\\"}" << endl;

    // 占い師
    cout << "tellraw @s {\\\"text\\\":\\\" [占い師]\\\"}" << endl;
    displaySkillSettings("占い", "#GameManager skill_uranai_limit", 0, "/function werewolf:.settings/role/skill/uranai/add_limit", "/function werewolf:.settings/role/skill/uranai/remove_limit", "#GameManager skill_uranai_frequency", 1, "/function werewolf:.settings/role/skill/uranai/add_frequency", "/function werewolf:.settings/role/skill/uranai/remove_frequency");

    // 霊能者
    cout << "tellraw @s {\\\"text\\\":\\\" [霊能者]\\\"}" << endl;
    displaySkillSettings("霊能", "#GameManager skill_reinou_limit", 0, "/function werewolf:.settings/role/skill/reinou/add_limit", "/function werewolf:.settings/role/skill/reinou/remove_limit", "#GameManager skill_reinou_frequency", 1, "/function werewolf:.settings/role/skill/reinou/add_frequency", "/function werewolf:.settings/role/skill/reinou/remove_frequency");

    // 騎士
    cout << "tellraw @s {\\\"text\\\":\\\" [騎士]\\\"}" << endl;
    displaySkillSettings("守護", "#GameManager skill_kishi_limit", 0, "/function werewolf:.settings/role/skill/kishi/add_limit", "/function werewolf:.settings/role/skill/kishi/remove_limit", "#GameManager skill_kishi_frequency", 1, "/function werewolf:.settings/role/skill/kishi/add_frequency", "/function werewolf:.settings/role/skill/kishi/remove_frequency");

    // 保安官
    cout << "tellraw @s {\\\"text\\\":\\\" [シェリフ]\\\"}" << endl;
    displaySkillSettings("正義執行", "#GameManager skill_hoankan_limit", 0, "/function werewolf:.settings/role/skill/hoankan/add_limit", "/function werewolf:.settings/role/skill/hoankan/remove_limit", "#GameManager skill_hoankan_frequency", 1, "/function werewolf:.settings/role/skill/hoankan/add_frequency", "/function werewolf:.settings/role/skill/hoankan/remove_frequency");

    // ナイステレポーター
    cout << "tellraw @s {\\\"text\\\":\\\" [ナイステレポーター]\\\"}" << endl;
    displaySkillSettings("テレポート", "#GameManager skill_niceteleporter_limit", 0, "/function werewolf:.settings/role/skill/niceteleporter/add_limit", "/function werewolf:.settings/role/skill/niceteleporter/remove_limit", "#GameManager skill_niceteleporter_frequency", 1, "/function werewolf:.settings/role/skill/niceteleporter/add_frequency", "/function werewolf:.settings/role/skill/niceteleporter/remove_frequency");

    // ポンコツ
    cout << "tellraw @s {\\\"text\\\":\\\" [ポンコツ]\\\"}" << endl;
    cout << "tellraw @s [{\\\"text\\\":\\\"  ダミー役職\\\",\\\"color\\\":\\\"gold\\\"},{\\\"text\\\":\\\" <  狼陣営入り  > \\\",\\\"color\\\":\\\"red\\\",\\\"clickEvent\\\":{\\\"action\\\":\\\"run_command\\\",\\\"value\\\":\\\"/function werewolf:.settings/role/skill/ponkotsu/switch_1\\\"}}]" << endl;
    cout << "tellraw @s [{\\\"text\\\":\\\"  ダミー役職\\\",\\\"color\\\":\\\"gold\\\"},{\\\"text\\\":\\\" <  狼陣営抜き  > \\\",\\\"color\\\":\\\"green\\\",\\\"clickEvent\\\":{\\\"action\\\":\\\"run_command\\\",\\\"value\\\":\\\"/function werewolf:.settings/role/skill/ponkotsu/switch_0\\\"}}]" << endl;

    // Return button
    cout << "tellraw @s [{\\\"text\\\":\\\"← 戻る\\\",\\\"color\\\":\\\"green\\\",\\\"clickEvent\\\":{\\\"action\\\":\\\"run_command\\\",\\\"value\\\":\\\"/function werewolf:.settings/view_settings\\\"}}]" << endl;

    // Settings reload command
    cout << "function werewolf:.settings/reload_settings" << endl;

    return 0;
}
