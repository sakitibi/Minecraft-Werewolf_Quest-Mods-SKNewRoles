#include <iostream>
#include <fstream>

void executeCommand(const std::string& command) {
    std::ofstream mcFunction("output.mcfunction", std::ios::app);
    if (mcFunction.is_open()) {
        mcFunction << command << std::endl;
        mcFunction.close();
    }
}

void initializeGameSettings() {
    // バージョンを記録
    executeCommand("function werewolf:version");

    // ゲームフェイズ判定変数作成
    executeCommand("execute unless data storage sys: game_phase run data modify storage sys: game_phase set value 0");

    // ゲームスタート判定変数作成
    executeCommand("execute unless data storage sys: game_start run data modify storage sys: game_start set value 0");

    // スコアボードの設定
    executeCommand("scoreboard objectives add member_count dummy");
    executeCommand("scoreboard objectives add death deathCount");

    // ゲームルール設定
    executeCommand("gamerule announceAdvancements false");
    executeCommand("gamerule showDeathMessages false");
    executeCommand("gamerule sendCommandFeedback false");
    executeCommand("gamerule doDaylightCycle false");
    executeCommand("gamerule doWeatherCycle false");
    executeCommand("gamerule randomTickSpeed 1");
    executeCommand("gamerule doImmediateRespawn false");
    executeCommand("gamerule doMobSpawning false");

    // 難易度設定
    executeCommand("difficulty hard");

    // 初期時間設定
    executeCommand("execute if data storage sys: {game_phase:0} run time set 3000");
}

void setupBossBar() {
    executeCommand("data modify storage sys: bossbar_text set value '[{\"text\":\"\\uF804\\uF804\\uF804\\uF804\\uF804\\uF804\"},"
                   "{\"score\":{\"name\":\"GameManager\",\"objective\":\"day\"},\"font\":\"default_negative\"},"
                   "{\"interpret\":true,\"nbt\":\"time_text\",\"storage\":\"sys:\"},{\"text\":\" [\"},"
                   "{\"score\":{\"name\":\"GameManager\",\"objective\":\"day\"}},{\"text\":\"日目]\"},"
                   "{\"score\":{\"name\":\"GameManager\",\"objective\":\"day\"},\"font\":\"default_negative\"},"
                   "{\"text\":\"\\uF804\\uF804\\uF804\\uF804\\uF804\\uF804\"},{\"interpret\":true,\"nbt\":\"random_event.title\",\"storage\":\"sys:\"},"
                   "{\"interpret\":true,\"nbt\":\"random_event.content.1\",\"storage\":\"sys:\"},"
                   "{\"interpret\":true,\"nbt\":\"random_event.content.2\",\"storage\":\"sys:\"},"
                   "{\"interpret\":true,\"nbt\":\"random_event.content.3\",\"storage\":\"sys:\"},"
                   "{\"interpret\":true,\"nbt\":\"random_event.bar\",\"storage\":\"sys:\"}]'");
}

void setupTimeCycle() {
    executeCommand("scoreboard objectives add day dummy");
    executeCommand("scoreboard objectives add common_timer dummy");

    executeCommand("scoreboard objectives add set_first_daytime dummy");
    executeCommand("execute unless score GameManager set_first_daytime matches 0.. run scoreboard players set GameManager set_first_daytime 1200");
    executeCommand("scoreboard objectives add set_first_daytime_minutes dummy");
    executeCommand("scoreboard players operation GameManager set_first_daytime_minutes = GameManager set_first_daytime");
    executeCommand("scoreboard players operation GameManager set_first_daytime_minutes /= GameManager tick_minute");

    executeCommand("scoreboard objectives add set_daytime dummy");
    executeCommand("execute unless score GameManager set_daytime matches 0.. run scoreboard players set GameManager set_daytime 3600");
    executeCommand("scoreboard objectives add set_daytime_minutes dummy");
    executeCommand("scoreboard players operation GameManager set_daytime_minutes = GameManager set_daytime");
    executeCommand("scoreboard players operation GameManager set_daytime_minutes /= GameManager tick_minute");

    executeCommand("scoreboard objectives add set_nighttime dummy");
    executeCommand("execute unless score GameManager set_nighttime matches 0.. run scoreboard players set GameManager set_nighttime 1200");
    executeCommand("scoreboard objectives add set_nighttime_minutes dummy");
    executeCommand("scoreboard players operation GameManager set_nighttime_minutes = GameManager set_nighttime");
    executeCommand("scoreboard players operation GameManager set_nighttime_minutes /= GameManager tick_minute");
}

void setupMiscellaneous() {
    executeCommand("scoreboard objectives add rng dummy");
    executeCommand("scoreboard objectives add .100 dummy");
    executeCommand("scoreboard players set GameManager .100 100");

    executeCommand("scoreboard objectives add event_timer dummy");
    executeCommand("scoreboard objectives add event_timer_countdown dummy");
    executeCommand("execute unless data storage sys: event_active run data modify storage sys: event_active set value 0");
    executeCommand("function werewolf:random_event/event_data");

    executeCommand("scoreboard objectives add event_timer_divide dummy");
    executeCommand("scoreboard objectives add event_timer_update dummy");
    executeCommand("scoreboard objectives add .36 dummy");
    executeCommand("scoreboard players set GameManager .36 36");

    executeCommand("scoreboard objectives add meeting_button dummy");
    executeCommand("execute unless data storage sys: meeting.active run data modify storage sys: meeting.active set value 1");

    executeCommand("execute unless data storage sys: judge_mode run data modify storage sys: judge_mode set value 0");
    executeCommand("execute unless data storage sys: task_win.active run data modify storage sys: task_win.active set value 1");
    executeCommand("execute unless data storage sys: task_win.count run data modify storage sys: task_win.count set value 100");

    executeCommand("scoreboard objectives add right_click minecraft.used:minecraft.carrot_on_a_stick");
    executeCommand("scoreboard objectives add is_sneaking minecraft.custom:minecraft.sneak_time");
    executeCommand("scoreboard objectives add login minecraft.custom:minecraft.leave_game");

    executeCommand("execute as @e[tag=child] run data modify entity @s Age set value 3000000");

    executeCommand("function werewolf:role/.ini");
    executeCommand("function werewolf:skill/.ini");
    executeCommand("function werewolf:item/.ini");
    executeCommand("function werewolf:task/.ini");
    executeCommand("function werewolf:shop/.ini");
    executeCommand("function werewolf:anim/.ini");
    executeCommand("function werewolf:.system/vote/.ini");

    executeCommand("scoreboard objectives add reserve_1 dummy");
    executeCommand("scoreboard objectives add reserve_2 dummy");
    executeCommand("scoreboard objectives add reserve_3 dummy");
    executeCommand("scoreboard objectives add reserve_4 dummy");
    executeCommand("scoreboard objectives add reserve_5 dummy");
    executeCommand("scoreboard objectives add owner dummy");

    executeCommand("bossbar add settings_bossbar \"\"");
    executeCommand("bossbar set settings_bossbar color pink");
    executeCommand("function werewolf:.settings/reload_settings");
    executeCommand("execute if data storage sys: {game_phase:0} run bossbar set settings_bossbar players @a");

    executeCommand("schedule function werewolf:shop/reset_shop 1s");
}

int main() {
    initializeGameSettings();
    setupBossBar();
    setupTimeCycle();
    setupMiscellaneous();

    std::cout << "全てのゲーム設定が完了しました。" << std::endl;
    return 0;
}
