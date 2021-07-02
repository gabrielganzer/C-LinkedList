#include "../lib/file.h"

int file(void) {

    DIR *directory;
    FILE *fp;
    struct dirent *file;
    struct stat fstat;
    char buffer[512];

    printf("Enter path name: ");
    scanf("%s", buffer);

    directory = opendir(buffer);
    if(directory == NULL) {
        printf("Unable to open current directory!");
        return(1);
    }

    fp = fopen("filelist.txt", "w+");
    if(fp == NULL) {
        printf("Unable to create file!");
        return(1);
    }

    fprintf(fp, "%-5s %-20s %-10s %s\n","Type","Filename","Size","Timestamp");

    while((file=readdir(directory)) != NULL) {
        stat(file->d_name, &fstat);
        if(S_ISDIR(fstat.st_mode)) {
            fprintf(fp, "%-5s", "Dir");
            fprintf(fp, "%20s %-10lld %24s", file->d_name, fstat.st_size, ctime(&fstat.st_mtime));
        } else {
            fprintf(fp, "%-5s", "File");
            fprintf(fp, "%20s %-10lld %24s", file->d_name, fstat.st_size, ctime(&fstat.st_mtime));
        }
    }
    fclose(fp);
    closedir(directory);

    system("clear");
    printf("Done!\n");
    return(0);
}
