#pragma once

#include "GLFramework/Log/Log.h"

#ifdef GLFR_DEBUG
	#define GLFR_ENABLE_ASSERTS 1
#else
	#define GLFR_ENABLE_ASSERTS 0
#endif

#if GLFR_ENABLE_ASSERTS 1
	#define GLFR_ASSERT(x, ...) if (!(x)) { LOG_FATAL("Assertion Failed:"); LOG_ERROR("File: {0}", __FILE__); LOG_ERROR("Line: {0}", __LINE__); LOG_ERROR("Message: {0}", __VA_ARGS__); __debugbreak(); }
	#define GLFR_CORE_ASSERT(x, ...) if (!(x)) { CORE_FATAL("Assertion Failed:"); CORE_ERROR("File: {0}", __FILE__); CORE_ERROR("Line: {0}", __LINE__); CORE_ERROR("Message: {0}", __VA_ARGS__); __debugbreak(); }
#else GLFR_ENABLE_ASSERTS 0
	#define GLFR_ASSERT(x, ...)
	#define GLFR_CORE_ASSERT(x, ...)
#endif
#define ASSERT(x, ...) GLFR_ASSERT(x, __VA_ARGS__)

struct GlfrVec2
{
	float x, y;
};

struct GlfrVec2u
{
	unsigned int x, y;
};

struct GlfrVec2i
{
	int x, y;
};

struct GlfrVec2d
{
	double x, y;
};

using Vec2 = GlfrVec2;
using Vec2i = GlfrVec2i;
using Vec2u = GlfrVec2u;
using Vec2d = GlfrVec2d;