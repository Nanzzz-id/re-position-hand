#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "LeviViewModel"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// Inisialisasi JNI sederhana untuk tes build
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOGI("Plugin LeviViewModel berhasil dimuat!");
    return JNI_VERSION_1_6;
}
