#include "hookSample.h"
#include "loadJNI.h"

typedef void (*func_printJNI)(JNIEnv *env, jobject obj);

static void* dl_handle;
static func_printJNI p_printJNI;

JNIEXPORT void JNICALL Java_jp_ac_nitech_hook_HookLoadJNIActivity_printJNI(JNIEnv *env, jobject obj)
{
	__android_log_print(ANDROID_LOG_DEBUG,"HookSample","function : plat!\n");

	dlerror();
	dl_handle = dlopen("/data/data/jp.ac.nitech.hook/lib/libLoadJNI.so", RTLD_LAZY | RTLD_LOCAL);
	if(dl_handle) {
		__android_log_print(ANDROID_LOG_DEBUG,"HookSample","dlerror : %s\n",dlerror());
		__android_log_print(ANDROID_LOG_DEBUG,"HookSample","dlopen %s\n","Load:libLoadJNI.so");
		dlerror();
		p_printJNI = (func_printJNI)dlsym(dl_handle, "Java_jp_ac_nitech_hook_HookLoadJNIActivity_printJNI");
		__android_log_print(ANDROID_LOG_DEBUG,"HookSample","dlerrror : %s\n",dlerror());
		if(dlerror() == NULL) {
			p_printJNI(env,obj);
		}

		dlclose(dl_handle);
	} else {
		__android_log_print(ANDROID_LOG_DEBUG,"HookSample","dlerror : %s\n",dlerror());
	}
}
