#include "../include/ft_ls.h"

int isDir(const char* fileName)
{
	struct stat	path;

	stat(fileName, &path);
	return S_ISREG(path.st_mode);
}

void	print_listed_files(DIR *dr)
{
	struct dirent *en;

	if (dr)
	{
		while ((en = readdir(dr)) != NULL)
		{
			if ((((strcmp(en->d_name, ".") == 0)
			|| (strcmp(en->d_name, "..") == 0)) == 0)
			&& en->d_name[0] != '.')
				printf("%s ", en->d_name);
		}
		closedir(dr);
	}
	printf("\n");
}