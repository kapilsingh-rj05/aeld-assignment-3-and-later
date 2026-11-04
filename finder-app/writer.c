#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: expected 2, got %d", argc - 1);
        fprintf(stderr, "Usage: %s <file> <string>\n", argv[0]);
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Failed to open file %s for writing: %s", writefile, strerror(errno));
        fprintf(stderr, "Error opening file %s: %s\n", writefile, strerror(errno));
        closelog();
        return 1;
    }

    if (fprintf(fp, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Failed to write to file %s: %s", writefile, strerror(errno));
        fprintf(stderr, "Error writing to file %s: %s\n", writefile, strerror(errno));
        fclose(fp);
        closelog();
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    fclose(fp);
    closelog();

    return 0;
}