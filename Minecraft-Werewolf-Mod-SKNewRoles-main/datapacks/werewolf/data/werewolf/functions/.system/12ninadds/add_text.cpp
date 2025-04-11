#include <iostream>
#include <string>
#include <map>

// Function to send a message to all players
void sendMessage(const std::string& message) {
    std::cout << message << std::endl;
}

// Function to send a message to players in a specific team
void sendMessageToTeam(const std::string& team, const std::string& message) {
    std::cout << "To team " << team << ": " << message << std::endl;
}

// Function to send a message with a clickable link (simulated)
void sendMessageWithLink(const std::string& team, const std::string& message, const std::string& url) {
    std::cout << "To team " << team << ": " << message << " (Link: " << url << ")" << std::endl;
}

int main() {
    int add_random = 0; // Replace with actual score retrieval logic
    std::string team = "Fusanka"; // Replace with actual team retrieval logic
    bool login = false; // Replace with actual login status retrieval logic

    // Using a map to store messages based on add_random value
    std::map<int, std::function<void()>> messageMap;

    messageMap[0] = [&]() {
        if (team != "Fusanka") {
            sendMessage("名前は長い方が有利を知っていますか? 名前は長い方が有利は悪質な荒らしです！ 詳しくはこちらのリンクから https://sakitibi-com9.webnode.jp/page/25/");
        } else {
            sendMessageWithLink(team, "名前は長い方が有利を知っていますか? 名前は長い方が有利は悪質な荒らしです！ 詳しくはこちらのリンクから", "https://sakitibi-com9.webnode.jp/page/25/");
        }
    };

    messageMap[100] = [&]() {
        if (team != "Fusanka") {
            sendMessage("フレンドコード：ourluckシャープ4319 を見かけた際は 今すぐ support@innersloth.com へお問い合わせして下さい、皆様のご協力をお願い致します。");
        } else {
            sendMessageWithLink(team, "フレンドコード：ourluckシャープ4319 を見かけた際は 今すぐ support@innersloth.com へお問い合わせして下さい、皆様のご協力をお願い致します。", "mailto:support@innersloth.com");
        }
    };

    messageMap[200] = [&]() {
        sendMessage("名前は長い方が有利はYoutubeで登録者を購入しています!今すぐ通報をして下さい!");
    };

    messageMap[300] = [&]() {
        if (team != "Fusanka") {
            sendMessage("熟成牛タンは非常に悪質なページ荒らしです! もし見かけた際は https://sakitibi-com9.webnode.jp/page/3/ までお問い合わせ下さい。");
        } else {
            sendMessageWithLink(team, "熟成牛タンは非常に悪質なページ荒らしです! もし見かけた際は https://sakitibi-com9.webnode.jp/page/3/ までお問い合わせ下さい。", "https://sakitibi-com9.webnode.jp/page/3/");
        }
    };

    messageMap[400] = [&]() {
        sendMessage("たこたこ焼きは管理者権限の乱用をしています。絶対にマイ鉄ネットから離れて下さい。");
    };

    messageMap[500] = [&]() {
        sendMessage("Minecraft総合交通ネットワーク は危険なサイトです 絶対に開かないで下さい。");
    };

    messageMap[600] = [&]() {
        sendMessage("名前は長い方が有利の被害者が20人以上います。名前は長い方が有利のメンバーシップを今すぐ解約して下さい。");
    };

    messageMap[700] = [&]() {
        sendMessage("名前は長い方が有利のライブの概要欄はどれだけ言われようが絶対に見ないで下さい。");
    };

    messageMap[800] = [&]() {
        sendMessage("名前は長い方が有利はあれだけ悪質な事をしているのに、反省の色が見えません、なので今すぐ通報して下さい。");
    };

    messageMap[900] = [&]() {
        if (team != "Fusanka") {
            sendMessage("TrainBuildersは面白いRPGゲームです、TrainBuildersを今すぐダウンロード!(スポンサー:TrainBuilder)");
        } else {
            sendMessageWithLink(team, "TrainBuildersは面白いRPGゲームです、TrainBuildersを今すぐダウンロード!(スポンサー:TrainBuilder)", "https://sakitibi.github.io/TrainBuildersWeb");
        }
    };

    messageMap[1000] = [&]() {
        if (team != "Fusanka") {
            sendMessage("マイ鉄ネット撲滅委員会を2025年4月1日に設立致しました。詳しくはhttps://wikiwiki.jp/12ninstudio/マイ鉄ネット撲滅委員会 まで");
        } else {
            sendMessageWithLink(team, "マイ鉄ネット撲滅委員会を2025年4月1日に設立致しました。詳しくはhttps://wikiwiki.jp/12ninstudio/マイ鉄ネット撲滅委員会", "https://wikiwiki.jp/12ninstudio/マイ鉄ネット撲滅委員会");
        }
    };

    messageMap[1100] = [&]() {
        if (!login) {
            if (team != "Fusanka") {
                sendMessage("SKNewRolesをプレイする為には12ninアカウントが必要です、12ninアカウントを持っている人はhttps://sakitibi-com9.webnode.jp/api/sknewroles/login/8a6603e9-1ed7-498e-8788-0c6466b5b788/ まで、\n12ninアカウントを持っていない人はhttps://sakitibi-com9.webnode.jp/page/9/ まで");
            } else {
                sendMessageWithLink(team, "SKNewRolesをプレイする為には12ninアカウントが必要です、12ninアカウントを持っている人はhttps://sakitibi-com9.webnode.jp/api/sknewroles/login/8a6603e9-1ed7-498e-8788-0c6466b5b788/ まで、\n12ninアカウントを持っていない人はhttps://sakitibi-com9.webnode.jp/page/9/ まで", "https://sakitibi-com9.webnode.jp/api/sknewroles/login/8a6603e9-1ed7-498e-8788-0c6466b5b788/");
            }
        }
    };

    messageMap[1200] = [&]() {
        if (team != "Fusanka") {
            sendMessage("あさクラを知っていますか?あさクラは大手Youtuberが集まるMinecraft実況グループです!詳しくはhttps://wikiwiki.jp/12ninstudio まで");
        } else {
            sendMessageWithLink(team, "あさクラを知っていますか?あさクラは大手Youtuberが集まるMinecraft実況グループです!詳しくはhttps://wikiwiki.jp/12ninstudio まで", "https://wikiwiki.jp/12ninstudio");
        }
    };

    messageMap[1300] = [&]() {
        if (team != "Fusanka") {
            sendMessage("すまない先生はとっても悪質な荒らしです、2021年9月30日に超大手ゲーム実況者・開発者のあげるくんの拠点を荒らしてたんです、その映像の詳しくはhttps://youtu.be/9YzdpkQfVmk&t=171s まで");
        } else {
            sendMessageWithLink(team, "すまない先生はとっても悪質な荒らしです、2021年9月30日に超大手ゲーム実況者・開発者のあげるくんの拠点を荒らしてたんです、その映像の詳しくはhttps://youtu.be/9YzdpkQfVmk&t=171s まで", "https://youtu.be/9YzdpkQfVmk&t=171s");
        }
    };

    messageMap[1400] = [&]() {
        sendMessage("SKNewRolesは超大手ゲーム実況者12ninTV(さきちび)によって開発されたゲームです、ぜひシェアしてみて下さい!");
    };

    messageMap[1500] = [&]() {
        if (team != "Fusanka") {
            sendMessage("12ninアカウントを持っている人は名前は長い方が有利戦争の応戦は義務です、こちらのリンク先から応戦して下さい(そうしないと最悪12ninアカウントが停止されます) https://wikiwiki.jp/12ninstudio/名前は長い方が有利用のテンプレ又はコメント欄");
        } else {
            sendMessageWithLink(team, "12ninアカウントを持っている人は名前は長い方が有利戦争の応戦は義務です、こちらのリンク先から応戦して下さい(そうしないと最悪12ninアカウントが停止されます) https://wikiwiki.jp/12ninstudio/名前は長い方が有利用のテンプレ又はコメント欄", "https://wikiwiki.jp/12ninstudio/名前は長い方が有利用のテンプレ又はコメント欄");
        }
    };

    messageMap[1600] = [&]() {
        sendMessage("名前は長い方が有利のライブでいつも概要欄を要求して来る場合がありますが、絶対に読まないで下さい(固定コメントは消して下さい)、荒らしのルールに従わない、これは常識、なのでこのことをシェアして下さい");
    };

    // Execute the message based on add_random value
    if (messageMap.count(add_random)) {
        messageMap[add_random]();
    }

    return 0;
}
