#ifndef FT_LS_H
#define FT_LS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

int		isDir(const char* fileName);
void	print_listed_files(DIR *dr);

#endif