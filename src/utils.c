#include "../include/ft_ls.h"

void	print_listed_files(DIR *dr)
{
	struct dirent *en;

	if (dr)
	{
		while ((en = readdir(dr)) != NULL)
		{
			if (((strcmp(en->d_name, ".") == 0)
			|| (strcmp(en->d_name, "..") == 0)) == 0)
				printf("%s ", en->d_name);
		}
		closedir(dr);
	}
	printf("\n");
}