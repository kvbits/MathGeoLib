LOCAL_PATH:= $(call my-dir)/../src

include $(CLEAR_VARS)



LOCAL_MODULE    := MathGeoLib

LOCAL_C_INCLUDES := $(LOCAL_PATH)/

LOCAL_CFLAGS := $(LOCAL_C_INCLUDES:%=-I%)

LOCAL_SRC_FILES := \
		Math/float3.cpp \
		Math/float2.cpp \

include $(BUILD_STATIC_LIBRARY)
