LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE		:= HookSample
LOCAL_SRC_FILES	:= hookSample.cpp
LOCAL_LDLIBS		:= -llog
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE		:= LoadJNI
LOCAL_SRC_FILES	:= loadJNI.cpp
LOCAL_LDLIBS		:= -llog
include $(BUILD_SHARED_LIBRARY)