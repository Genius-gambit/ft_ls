#include "../include/ft_ls.h"

void	execute_R_flag(DIR *dr)
{
	struct dirent *en;

	if (dr)
	{
		while ((en = readdir(dr)) != NULL)
			if ((((strcmp(en->d_name, ".") == 0)
			|| (strcmp(en->d_name, "..") == 0)) == 0)
			&& en->d_name[0] != '.')
				
		closedir(dr);
	}
}

int main(int ac, char **av)
{
	char *flag;
	DIR *dr;

	flag = NULL;
	dr = opendir(".");
	if (ac > 1)
		flag = strdup(av[1]);
	if (ac > 1)
		free(flag);
	if (ac == 1)
		print_listed_files(dr);
	if (ac > 1)
		execute_R_flag(dr);
	return (0);
}