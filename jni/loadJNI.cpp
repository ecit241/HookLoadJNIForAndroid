#include "loadJNI.h"

JNIEXPORT void JNICALL Java_jp_ac_nitech_hook_HookLoadJNIActivity_printJNI(JNIEnv *env, jobject obj)
{
    __android_log_print(ANDROID_LOG_DEBUG,"LoadJNI","function: HOOK printJNI!\n");

}
