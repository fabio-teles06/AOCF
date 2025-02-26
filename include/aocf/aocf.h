#pragma once

#ifdef _WIN32
#define PLATFORM_WINDOWS
#elif __linux__
#define PLATFORM_LINUX
#endif

#ifdef PLATFORM_WINDOWS
#ifdef AOCF_EXPORTS
#define AOCF_API __declspec(dllexport)
#else
#define AOCF_API __declspec(dllimport)
#endif // AOCF_EXPORTS
#else
#define PLATFORM_API
#endif // PLATFORM_WINDOWS

#include <stdint.h>
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef uint8_t uint8;
typedef unsigned char uchar;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
