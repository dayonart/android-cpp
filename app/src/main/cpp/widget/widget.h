//
// Created by dayona on 1/4/24.
//

#ifndef DNE_WIDGET_H
#define DNE_WIDGET_H

jobject RelativeLayout(JNIEnv *env, jobject t) {
    jclass clz = env->FindClass("android/widget/RelativeLayout");
    jmethodID jMethodId = env->GetMethodID(clz, "<init>",
                                           "(Landroid/content/Context;)V"
    );
    return env->NewObject(clz, jMethodId, t);
}

jobject LinearLayout(JNIEnv *env, jobject t) {
    jclass clz = env->FindClass("android/widget/LinearLayout");
    jmethodID jMethodId = env->GetMethodID(clz, "<init>",
                                           "(Landroid/content/Context;)V"
    );
    return env->NewObject(clz, jMethodId, t);
}


jobject TextView(JNIEnv *env, jobject t) {
    jclass clz = env->FindClass("android/widget/TextView");
    jmethodID jMethodId = env->GetMethodID(clz, "<init>", "(Landroid/content/Context;)V");
    return env->NewObject(clz, jMethodId, t);
}

#endif //DNE_WIDGET_H
