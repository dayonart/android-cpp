//
// Created by dayona on 1/4/24.
//

#ifndef DNE_PARAMS_H
#define DNE_PARAMS_H

jobject RelativeParam(JNIEnv *env, jobject t) {
    jclass rClz = env->FindClass("android/widget/RelativeLayout");
    jclass clz = env->FindClass("android/widget/RelativeLayout$LayoutParams");
    jclass viewGroupClz = env->FindClass("android/view/ViewGroup$LayoutParams");
    jfieldID wrap = env->GetStaticFieldID(viewGroupClz, "WRAP_CONTENT", "I");
    jfieldID match = env->GetStaticFieldID(viewGroupClz, "MATCH_PARENT", "I");
    jfieldID center = env->GetStaticFieldID(rClz, "CENTER_IN_PARENT", "I");
    jint wrapId = env->GetStaticIntField(viewGroupClz, wrap);
    jint matchId = env->GetStaticIntField(viewGroupClz, match);
    jint centerId = env->GetStaticIntField(rClz, center);
    jmethodID init = env->GetMethodID(clz, "<init>", "(II)V");
    jobject rParam = env->NewObject(clz, init, wrapId, wrapId);
    jmethodID addRule = env->GetMethodID(clz, "addRule", "(I)V");
    env->CallVoidMethod(rParam, addRule, centerId);
    return rParam;
}

#endif //DNE_PARAMS_H
