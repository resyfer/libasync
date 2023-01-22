/**
 * @file global.h
 * @brief This header file contains macros that are needed globally.
 *
 * @author Saurav Pal (resyfer)
 * @bug No known bugs
 */

#ifndef __LIBASYNC_GLOBAL_H
#define __LIBASYNC_GLOBAL_H 1

#ifndef OS
	#ifdef __unix__
		#ifdef __linux__
			#define OS "Linux"
		#else
			#define OS "Unix"
		#endif
	#elif __APPLE__
		#define OS "Darwin"
	#elif _WIN32
		#define OS "Win32"
	#endif
#endif

#endif