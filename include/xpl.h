/*
    This file is part of WJElement.

    WJElement is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    WJElement is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with WJElement.  If not, see <http://www.gnu.org/licenses/>.
*/


/****************************************************************************
 * stub replacement for Messaging Architects' internal Xpl library
 ****************************************************************************/
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>


#ifndef XPL_H
#define XPL_H


#ifdef WINDOWS
# define		WIN_CDECL		__cdecl
# define		WIN_STDCALL		__stdcall
# define		EXPORT			__declspec(dllexport)
# define		IMPORT			__declspec(dllimport)
# define		INLINE			__inline
#else
# define		WIN_CDECL
# define		WIN_STDCALL
# define		EXPORT
# define		IMPORT
# define		INLINE			__inline
#endif


/* xpldefs.h */

#ifndef min
#define min(a, b)   (((a) < (b))? (a): (b))
#endif

#ifndef max
#define max(a, b)   (((a) > (b))? (a): (b))
#endif


/* xpltypes.h */

typedef int XplBool;

#ifndef WIN32
typedef unsigned long LONG;
#endif

#ifndef FALSE
# define FALSE (0)
#endif

#ifndef TRUE
# define TRUE (!FALSE)
#endif

#ifndef _UNSIGNED_INT_64
#define _UNSIGNED_INT_64
#ifdef __WATCOMC__
typedef unsigned __int64 uint64;
#elif ULLONG_MAX == 18446744073709551615ULL
typedef unsigned long long uint64;
#elif ULONG_MAX == 18446744073709551615ULL
typedef unsigned long uint64;
#elif UINT_MAX == 18446744073709551615ULL
typedef unsigned int uint64;
#elif USHRT_MAX == 18446744073709551615ULL
typedef unsigned short uint64;
#else
#error "Can't determine the size of uint64"
#endif
#endif

#ifndef _SIGNED_INT_64
#define _SIGNED_INT_64
#ifdef __WATCOMC__
typedef signed __int64 int64;
#elif LLONG_MAX == 9223372036854775807LL
typedef signed long long int64;
#elif LONG_MAX == 9223372036854775807LL
typedef signed long int64;
#elif INT_MAX == 9223372036854775807LL
typedef signed int int64;
#elif SHRT_MAX == 9223372036854775807LL
typedef signed short int64;
#else
#error "Can't determine the size of int64"
#endif
#endif

#ifndef _UNSIGNED_INT_32
#define _UNSIGNED_INT_32
#if ULONG_MAX == 4294967295UL
typedef unsigned long uint32;
#elif UINT_MAX == 4294967295UL
typedef unsigned int uint32;
#elif USHRT_MAX == 4294967295UL
typedef unsigned short uint32;
#else
#error "Can't determine the size of uint32"
#endif
#endif

#ifndef _SIGNED_INT_32
#define _SIGNED_INT_32
#if LONG_MAX == 2147483647L
typedef signed long int32;
#elif INT_MAX == 2147483647L
typedef signed int int32;
#elif SHRT_MAX == 2147483647L
typedef signed short int32;
#else
#error "Can't determine the size of int32"
#endif
#endif

#ifndef _UNSIGNED_INT_16
#define _UNSIGNED_INT_16
#if USHRT_MAX == 65535U
typedef unsigned short uint16;
#elif UCHAR_MAX == 65535U
typedef signed char uint16;
#else
#error "Can't determine the size of uint16"
#endif
#endif

#ifndef _SIGNED_INT_16
#define _SIGNED_INT_16
#if SHRT_MAX == 32767
typedef signed short int16;
#elif SCHAR_MAX == 32767
typedef unsigned char uint16;
#else
#error "Can't determine the size of int16"
#endif
#endif

#ifndef _UNSIGNED_INT_8
#define _UNSIGNED_INT_8
#if UCHAR_MAX == 255U
typedef unsigned char uint8;
#else
#error "Can't determine the size of uint8"
#endif
#endif

#ifndef _SIGNED_INT_8
#define _SIGNED_INT_8
#if SCHAR_MAX == 127
typedef signed char int8;
#else
#error "Can't determine the size of int8"
#endif
#endif


/* xplutil.h */

#if defined __GNUC__
#define XplFormatString(formatStringIndex, firstToCheck)	__attribute__ ((format (printf, formatStringIndex, firstToCheck)))
#else
#define XplFormatString(formatStringIndex, firstToCheck)
#endif

# define DebugAssert( x )

# define XplStrCaseCmp(a,b) strcasecmp(a,b)
# define stricmp(a,b) strcasecmp(a,b)

# define XplStrNCaseCmp(a,b,c) strncasecmp(a,b,c)
# define strnicmp(a,b,c) strncasecmp(a,b,c)

EXPORT char *_skipspace( char *source, const char *breakchars );
#define skipspace(s) _skipspace((s), "\r\n")

EXPORT size_t strprintf( char *buffer, size_t bufferSize, size_t *sizeNeeded, const char *format, ... ) XplFormatString(4, 5);
EXPORT int stripat(char *str, char *pattern);
EXPORT int stripatn(char *str, char *pattern, size_t len);


#endif
