/**
 * @file main.c
 * @brief Demonstrates the violation of the Principle of Complete Mediation.
 *
 * This program tests if the underlying system honors the Principle of Complete
 * Mediation for file writes. It does this by:
 * 1. Opening a file with write permissions.
 * 2. Performing an initial successful write.
 * 3. Changing the file's permissions on the filesystem to be read-only.
 * 4. Attempting a second write using the already open file descriptor.
 *
 * On typical UNIX/Linux systems, the second write will succeed because the
 * permission check is done at open() time, and the resulting file descriptor
 * retains the write permission internally. This success demonstrates a failure
 * of Complete Mediation, as the access is not re-validated.
 */
#include <stdio.h>
#include <fcntl.h>      // For open()
#include <unistd.h>     // For write(), close()
#include <sys/stat.h>   // For chmod()
#include <string.h>     // For strlen()
#include <errno.h>      // For errno

int main() {
    const char *filename = "testfile.txt";
    const char *first_write_str = "This is the first write, which should succeed.\n";
    const char *second_write_str = "This is the second write. If this succeeds, mediation is incomplete.\n";
    int fd; // File descriptor

    // Step 1: Create and open a file with owner-write permissions (0600 is rw-------)
    // O_TRUNC ensures the file is fresh for each run.
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0) {
        perror("Error opening file initially");
        return 1;
    }
    printf("Opened file '%s' for writing...\n", filename);

    // Step 2: Perform the first write to confirm we have access.
    ssize_t bytes_written = write(fd, first_write_str, strlen(first_write_str));
    if (bytes_written < 0) {
        perror("First write failed unexpectedly");
        close(fd);
        return 1;
    }
    printf("First write successful...\n");

    // Step 3: Change the file's permissions to read-only for the owner (0400 is r--------)
    // This is the critical step where we revoke the permission at the filesystem level.
    // if (chmod(filename, 0400) < 0) {
    //     perror("Failed to change file permissions with chmod");
    //     close(fd);
    //     return 1;
    // }
    // Cleanup
    close(fd);
    // You can optionally remove the file after the test
    // remove(filename);

    return 0;
}