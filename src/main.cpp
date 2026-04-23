#include <jni.h>
#include <android/log.h>
#include <GLES3/gl3.h>
#include "imgui.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"

#define LOG_TAG "LeviViewModel"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// Variabel posisi tangan
float handX = 0.0f, handY = 0.0f, handZ = 0.0f;
bool showMenu = true;

// Fungsi untuk merender menu
void RenderMyMenu() {
    if (!showMenu) return;
    
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Levi Hand Position", &showMenu);
    ImGui::Text("Ubah Posisi Tangan (Real-time)");
    ImGui::SliderFloat("Posisi X", &handX, -2.0f, 2.0f);
    ImGui::SliderFloat("Posisi Y", &handY, -2.0f, 2.0f);
    ImGui::SliderFloat("Posisi Z", &handZ, -2.0f, 2.0f);
    
    if (ImGui::Button("Reset")) {
        handX = handY = handZ = 0.0f;
    }
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOGI("Plugin dengan GUI berhasil dimuat!");
    return JNI_VERSION_1_6;
}
