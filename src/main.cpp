#include <jni.h>
#include <string>
#include <vector>
#include <android/log.h>
#include <dlfcn.h>
#include "imgui.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"
#include "dobby.h"

#define LOG_TAG "LeviViewModel"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// Global variables for Hand Position
struct HandOffset {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
} g_handOffset;

bool g_showMenu = true;

// Original function pointer for hooking
void (*orig_ItemInHandRenderer_renderItemInHand)(void* self, void* player, float partialTicks, float pitch, void* hand, float swingProgress, void* itemStack, float equippedProgress);

// Hooked function
void hook_ItemInHandRenderer_renderItemInHand(void* self, void* player, float partialTicks, float pitch, void* hand, float swingProgress, void* itemStack, float equippedProgress) {
    // Logic to apply offsets before calling original
    // This is a simplified example, real implementation would involve matrix manipulation
    orig_ItemInHandRenderer_renderItemInHand(self, player, partialTicks, pitch, hand, swingProgress, itemStack, equippedProgress);
}

// GUI Rendering
void DrawMenu() {
    if (!g_showMenu) return;

    ImGui::Begin("Levi Hand ViewModel", &g_showMenu);
    ImGui::Text("Adjust Hand Position (Real-time)");
    
    ImGui::SliderFloat("Offset X", &g_handOffset.x, -2.0f, 2.0f);
    ImGui::SliderFloat("Offset Y", &g_handOffset.y, -2.0f, 2.0f);
    ImGui::SliderFloat("Offset Z", &g_handOffset.z, -2.0f, 2.0f);

    if (ImGui::Button("Reset")) {
        g_handOffset = {0.0f, 0.0f, 0.0f};
    }
    
    ImGui::End();
}

// JNI Initialization
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOGI("Plugin Loaded via LeviLauncher!");
    
    // In a real scenario, we would search for symbols in libminecraftpe.so
    void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
    if (handle) {
        // Example symbol (this changes per version, user needs to update this)
        void* target = dlsym(handle, "_ZN18ItemInHandRenderer16renderItemInHandEP6PlayerffffRK9ItemStackf");
        if (target) {
            DobbyHook(target, (void*)hook_ItemInHandRenderer_renderItemInHand, (void**)&orig_ItemInHandRenderer_renderItemInHand);
            LOGI("Hooked renderItemInHand successfully!");
        }
    }

    return JNI_VERSION_1_6;
}
