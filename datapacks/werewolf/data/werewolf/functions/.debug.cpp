#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <string>
#include <unordered_map>
#include <functional>
#include <iostream>

// プレイヤークラス
class Player {
public:
    std::string role;
    void changeRole(const std::string& newRole) {
        role = newRole;
        std::cout << "[INFO] 役職が " << newRole << " に変更されました。\n";
    }
};

void renderDebugMenu(Player& player) {
    ImGui::Begin("[Debug_Settings]");

    ImGui::Text("役職変更");

    const std::pair<const char*, ImVec4> roles[] = {
        {"人狼",          ImVec4(1.0f, 0.0f, 0.0f, 1.0f)},
        {"Witch",         ImVec4(1.0f, 0.0f, 0.0f, 1.0f)},
        {"リモコン",      ImVec4(1.0f, 0.0f, 0.0f, 1.0f)},
        {"ダブルキラー",  ImVec4(1.0f, 0.0f, 0.0f, 1.0f)},
        {"狂人",          ImVec4(1.0f, 0.0f, 0.0f, 1.0f)},
        {"狂信者",        ImVec4(1.0f, 0.0f, 0.0f, 1.0f)},
        {"村人",          ImVec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {"占い師",        ImVec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {"霊能者",        ImVec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {"騎士",          ImVec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {"共有者",        ImVec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {"シェリフ",      ImVec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {"パン屋",        ImVec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {"ナイステレポーター", ImVec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {"妖狐",          ImVec4(0.0f, 1.0f, 1.0f, 1.0f)},
        {"背徳者",        ImVec4(0.0f, 1.0f, 1.0f, 1.0f)},
        {"死神",          ImVec4(0.0f, 1.0f, 1.0f, 1.0f)},
        {"キューピット",  ImVec4(0.0f, 1.0f, 1.0f, 1.0f)},
    };

    for (const auto& [name, color] : roles) {
        ImGui::Text("  %s", name);
        ImGui::SameLine();
        ImGui::PushStyleColor(ImGuiCol_Button, color);
        if (ImGui::Button(("変更##" + std::string(name)).c_str())) {
            player.changeRole(name);
        }
        ImGui::PopStyleColor();
    }

    ImGui::Separator();
    ImGui::Text("その他");

    if (ImGui::Button("ゲームを強制終了")) {
        std::cout << "[INFO] ゲームがリセットされました。\n";
    }

    if (ImGui::Button("コマンドログを表示")) {
        std::cout << "[DEBUG] コマンドログON\n";
    }

    if (ImGui::Button("コマンドログを非表示")) {
        std::cout << "[DEBUG] コマンドログOFF\n";
    }

    ImGui::End();
}

int main() {
    if (!glfwInit()) return 1;
    GLFWwindow* window = glfwCreateWindow(800, 600, "Werewolf Role Debug", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    Player player;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        renderDebugMenu(player);

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // クリーンアップ
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
