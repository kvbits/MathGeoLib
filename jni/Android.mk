LOCAL_PATH:= $(call my-dir)/../src

include $(CLEAR_VARS)



LOCAL_MODULE    := MathGeoLib

LOCAL_C_INCLUDES := $(LOCAL_PATH)/

LOCAL_CFLAGS := $(LOCAL_C_INCLUDES:%=-I%)

LOCAL_SRC_FILES := \
		Geometry/AABB.cpp \
		Geometry/TriangleMesh.cpp \
		Geometry/Plane.cpp \
		Geometry/Polygon.cpp \
		Geometry/Frustum.cpp \
		Geometry/Ray.cpp \
		Geometry/OBB.cpp \
		Geometry/Line.cpp \
		Geometry/Sphere.cpp \
		Geometry/PBVolume.cpp \
		Geometry/LineSegment.cpp \
		Geometry/Triangle.cpp \
		Geometry/Circle.cpp \
		Geometry/Capsule.cpp \
		Geometry/Polyhedron.cpp \
		Time/Clock.cpp \
		Algorithm/Random/LCG.cpp \
		Algorithm/GJK.cpp \
		Math/MathFunc.cpp \
		Math/float3.cpp \
		Math/Callstack.cpp \
		Math/float2.cpp \
		Math/MathLog.cpp \
		Math/float4x4.cpp \
		Math/float4.cpp \
		Math/Polynomial.cpp \
		Math/float3x3.cpp \
		Math/MathOps.cpp \
		Math/BitOps.cpp \
		Math/SSEMath.cpp \
		Math/float3x4.cpp \
		Math/Quat.cpp \
		Math/TransformOps.cpp


include $(BUILD_STATIC_LIBRARY)
