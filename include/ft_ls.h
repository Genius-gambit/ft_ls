#ifndef FT_LS_H
#define FT_LS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef	struct s_info
{
	char 	**str;
	int		currentindex;
	void	*next;
}				t_info;

void	free_2d_str(char **str);
void	print_2d_str(char **str);
int		isDir(const char* fileName);
int		get_n_dirs(DIR *dr, char *path);
t_info	get_listed_dirs(DIR *dr, char *path);
void	print_listed_files(DIR *dr);

#endif