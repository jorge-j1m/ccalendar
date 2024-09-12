#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Log levels
#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO  1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_ERROR 3
#define LOG_LEVEL_NONE  4

// Get log level from environment variable
static inline int get_log_level(void) {
    char *log_level_str = getenv("LOG_LEVEL");
    int level = LOG_LEVEL_INFO; /* Default to INFO */
    if (log_level_str) {
        if (strcmp(log_level_str, "DEBUG") == 0) level = LOG_LEVEL_DEBUG;
        else if (strcmp(log_level_str, "INFO") == 0) level = LOG_LEVEL_INFO;
        else if (strcmp(log_level_str, "WARN") == 0) level = LOG_LEVEL_WARN;
        else if (strcmp(log_level_str, "ERROR") == 0) level = LOG_LEVEL_ERROR;
        else if (strcmp(log_level_str, "NONE") == 0) level = LOG_LEVEL_NONE;
    }
    return level;
}

// Logging macros
#define LOG_DEBUG(fmt, ...) do { \
    if (get_log_level() <= LOG_LEVEL_DEBUG) { \
        fprintf(stderr, "[DEBUG] " fmt "\n", __VA_ARGS__); \
    } \
} while (0)

#define LOG_INFO(fmt, ...) do { \
    if (get_log_level() <= LOG_LEVEL_INFO) { \
        fprintf(stderr, "[INFO] " fmt "\n", __VA_ARGS__); \
    } \
} while (0)

#define LOG_WARN(fmt, ...) do { \
    if (get_log_level() <= LOG_LEVEL_WARN) { \
        fprintf(stderr, "[WARN] " fmt "\n", __VA_ARGS__); \
    } \
} while (0)

#define LOG_ERROR(fmt, ...) do { \
    if (get_log_level() <= LOG_LEVEL_ERROR) { \
        fprintf(stderr, "[ERROR] " fmt "\n", __VA_ARGS__); \
    } \
} while (0)

#endif // LOG_H
