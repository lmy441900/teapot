#ifndef TEAPOT_FILE_H
#define TEAPOT_FILE_H

// C99 boolean
#ifndef __cplusplus
#include <stdbool.h>
#endif

#include <stdint.h>

/**
 * Used in `teapot_file_read` to indicate a whole-file read.
 */
#define TEAPOT_FILE_READ_RANGE_FULL 0

/**
 * A data structure representing a file loaded into the memory.
 */
struct TeapotFile {
  char    *filename;     ///< Name of the file
  char    *content_type; ///< MIME type of the file
  size_t   start;        ///< Start byte of the file
  size_t   size;         ///< Size of the file
  uint8_t *content;      ///< Binary content of the file
};

/**
 * Free the memory occupied by `struct TeapotFile`.
 *
 * @param file [in] The `struct TeapotFile` to free.
 */
void teapot_file_free(struct TeapotFile *file);

/**
 * Read file from path.
 *
 * @param path  [in] Path to the file to load.
 * @param start [in] The start byte to read.
 * @param range [in] Size of the file to read. If this is 0, read until EOF.
 * @return A pointer to `struct TeapotFile` representing the file. On failure,
 *         NULL is returned.
 */
struct TeapotFile *teapot_file_read(const char *path, const size_t start, const size_t range);

/**
 * Write file to path.
 *
 * @param content [in] Binary content of the file.
 * @param size    [in] Size of the file.
 * @param path    [in] Path to the file to write.
 * @return true on success, false on failure.
 */
bool teapot_file_write(const uint8_t *content, const size_t size, const char *path);

#endif
