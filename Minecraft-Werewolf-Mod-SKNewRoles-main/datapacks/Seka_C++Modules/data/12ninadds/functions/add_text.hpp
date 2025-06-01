#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Message {
    int trigger;
    std::string text;
    std::string team;
    std::string color;
    std::string url;
    bool clickable = false;
};

class AddTextManager {
public:
    int add_random = 0;
    std::string team = "";
    std::map<std::string, int> tags;
    int satsumatoimo_role = 0;
    bool witch_weakness = false;

    void show_message(const Message& msg) {
        std::cout << "[Trigger: " << msg.trigger << "] ";
        if (!msg.team.empty()) std::cout << "[Team: " << msg.team << "] ";
        if (!msg.color.empty()) std::cout << "[Color: " << msg.color << "] ";
        std::cout << msg.text;
        if (msg.clickable && !msg.url.empty()) std::cout << " (URL: " << msg.url << ")";
        std::cout << std::endl;
    }

    void process() {
        std::vector<Message> messages = {
            {0, "名前は長い方が有利を知っていますか? 名前は長い方が有利は悪質な荒らしです！\n 詳しくはこちらのリンクから https://sakitibi-com9.webnode.jp/page/25/", "!Fusanka", "", "", false},
            {0, "名前は長い方が有利を知っていますか? 名前は長い方が有利は悪質な荒らしです！\n 詳しくはこちらのリンクから", "Fusanka", "", "https://sakitibi-com9.webnode.jp/page/25/", true},
            {100, "フレンドコード：ourluckシャープ4319 を見かけた際は 今すぐ \nsupport@innersloth.com へお問い合わせして下さい、皆様のご協力をお願い致します。", "!Fusanka", "", "", false},
            {100, "フレンドコード：ourluckシャープ4319 を見かけた際は 今すぐ \nsupport@innersloth.com へお問い合わせして下さい、皆様のご協力をお願い致します。", "Fusanka", "", "mailto:support@innersloth.com", true},
            {200, "名前は長い方が有利はYoutubeで登録者を購入しています!今すぐ通報をして下さい!", "", "", "", false},
            {300, "熟成牛タンは非常に悪質なページ荒らしです! もし見かけた際は \nhttps://sakitibi-com9.webnode.jp/page/3/ までお問い合わせ下さい。", "!Fusanka", "", "", false},
            {300, "熟成牛タンは非常に悪質なページ荒らしです! もし見かけた際は \nhttps://sakitibi-com9.webnode.jp/page/3/ までお問い合わせ下さい。", "Fusanka", "", "https://sakitibi-com9.webnode.jp/page/3/", true},
            {400, "たこたこ焼きは管理者権限の乱用をしています。絶対にマイ鉄ネットから離れて下さい。", "", "", "", false},
            {500, "Minecraft総合交通ネットワーク は危険なサイトです 絶対に開かないで下さい。", "", "", "", false},
            {600, "名前は長い方が有利の被害者が50人以上います。名前は長い方が有利のメンバーシップを今すぐ解約して下さい。", "", "", "", false},
            {700, "名前は長い方が有利のライブの概要欄はどれだけ言われようが絶対に見ないで下さい。", "", "", "", false},
            {800, "名前は長い方が有利はあれだけ悪質な事をしているのに、反省の色が見えません、なので今すぐ通報して下さい。", "", "", "", false},
            {1000, "マイ鉄ネット撲滅委員会を2025年4月1日に設立致しました。\n詳しくはhttps://wikiwiki.jp/12ninstudio/マイ鉄ネット撲滅委員会 まで", "!Fusanka", "", "", false},
            {1000, "マイ鉄ネット撲滅委員会を2025年4月1日に設立致しました。\n詳しくはhttps://wikiwiki.jp/12ninstudio/マイ鉄ネット撲滅委員会 まで", "Fusanka", "", "https://wikiwiki.jp/12ninstudio/マイ鉄ネット撲滅委員会", true},
            {1300, "すまない先生はとっても悪質な荒らしです、\n2021年9月30日に超大手ゲーム実況者・開発者のあげるくんの拠点を荒らしてたんです、\nその映像の詳しくはhttps://youtu.be/9YzdpkQfVmk&t=171s まで", "!Fusanka", "", "", false},
            {1300, "すまない先生はとっても悪質な荒らしです、\n2021年9月30日に超大手ゲーム実況者・開発者のあげるくんの拠点を荒らしてたんです、\nその映像の詳しくはhttps://youtu.be/9YzdpkQfVmk&t=171s まで", "Fusanka", "", "https://youtu.be/9YzdpkQfVmk&t=171s", true},
            {1500, "12ninアカウントを持っている人は名前は長い方が有利戦争の応戦は義務です、\nこちらのリンク先から応戦して下さい(そうしないと最悪12ninアカウントが停止されます) \nhttps://wikiwiki.jp/12ninstudio/名前は長い方が有利用のテンプレ又はコメント欄", "!Fusanka", "", "", false},
            {1500, "12ninアカウントを持っている人は名前は長い方が有利戦争の応戦は義務です、\nこちらのリンク先から応戦して下さい(そうしないと最悪12ninアカウントが停止されます)\n https://wikiwiki.jp/12ninstudio/名前は長い方が有利用のテンプレ又はコメント欄", "Fusanka", "", "https://wikiwiki.jp/12ninstudio/名前は長い方が有利用のテンプレ又はコメント欄", true},
            {1600, "名前は長い方が有利のライブでいつも概要欄を要求して来る場合がありますが、\n絶対に読まないで下さい(固定コメントは消して下さい)、\n荒らしのルールに従わない、これは常識、なのでこのことをシェアして下さい", "", "", "", false},
            {1700, "12ninアカウントで使えるメールアドレスは実在するもののみとなっています、ご注意下さい", "", "green", "", false},
            {900, "TrainBuildersは面白いRPGゲームです、TrainBuildersを今すぐダウンロード!(スポンサー:TrainBuilder)", "!Fusanka", "", "", false},
            {900, "TrainBuildersは面白いRPGゲームです、TrainBuildersを今すぐダウンロード!(スポンサー:TrainBuilder)", "Fusanka", "", "https://sakitibi.github.io/TrainBuildersWeb", true},
            {1200, "あさクラを知っていますか?あさクラは大手Youtuberが集まるMinecraft実況グループです!詳しくはhttps://wikiwiki.jp/12ninstudio まで", "!Fusanka", "", "", false},
            {1200, "あさクラを知っていますか?あさクラは大手Youtuberが集まるMinecraft実況グループです!詳しくはhttps://wikiwiki.jp/12ninstudio まで", "Fusanka", "", "https://wikiwiki.jp/12ninstudio", true},
            {1500, "あげるくんの誕生日は5月5日です!、祝ってあげて下さい! byあげるくん", "", "", "", false},
            {1400, "SKNewRolesは超大手ゲーム実況者12ninTV(さきちび)によって開発されたゲームです、ぜひシェアしてみて下さい!", "", "", "", false},
        };
        for (const auto& msg : messages) {
            show_message(msg);
        }
    }
};

int main() {
    AddTextManager manager;
    manager.process();
    return 0;
}
