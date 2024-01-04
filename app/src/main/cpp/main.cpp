#include <jni.h>
#include <string>
#include <unistd.h>
#include "android/log.h"
#include "widget/widget.h"
#include "widget/params.h"

#define TAG "DNE"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__))


jstring getString(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF("HELLO");
}

jint getInt(JNIEnv *env, jobject thiz) {
    return JNI_VERSION_1_6;
}

jstring getBool(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF("false");
}


int startVM(JNIEnv *env) {
    static const JNINativeMethod methods[] = {"relativeLayout", "()Landroid/widget/RelativeLayout;",
                                              reinterpret_cast<void *>(RelativeLayout),
                                              "relativeParams",
                                              "()Landroid/widget/RelativeLayout$LayoutParams;",
                                              reinterpret_cast<void *>(RelativeParam),
                                              "getString",
                                              "()Ljava/lang/String;",
                                              reinterpret_cast<void *>(getString),
                                              "getInt", "()I",
                                              reinterpret_cast<void *>(getInt),
                                              "getBool", "()Ljava/lang/String;",
                                              reinterpret_cast<void *>(getBool),
                                              "textView", "()Landroid/widget/TextView;",
                                              reinterpret_cast<void *>(TextView)

    };
    jclass mainClz = env->FindClass("id/org/dne/MainActivity");
    int methodSize = sizeof(methods) / sizeof(methods[0]);
    if (!mainClz)
        return JNI_ERR;
    if (env->RegisterNatives(mainClz, methods, methodSize) != 0)
        return JNI_ERR;
    return JNI_OK;

}

//__attribute__((constructor))
void *threading(void *) {
    int i = 1;
    do {
        sleep(1);
        LOGD("HELLO %i", i);
        i++;
    } while (i < 10);
    return nullptr;
}

void startThread() {
    pthread_t pthread;
    pthread_create(&pthread, nullptr, threading, nullptr);
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (startVM(env) != JNI_OK) {
        LOGD("ERROR JNI ONLOAD");
        return JNI_ERR;
    } else {
        LOGD("JNI ONLOAD %d", JNI_VERSION_1_6);
//        startThread();
        return JNI_VERSION_1_6;
    }
}
