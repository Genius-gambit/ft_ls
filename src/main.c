#include "../include/ft_ls.h"

void	execute_R_flag(DIR *dr)
{
	t_info			info;

	if (get_n_dirs(dr, ".") > 0)
	{
		info = get_listed_dirs(dr, ".");
		info.currentindex = 0;
		printf(".:\n");
		dr = opendir(".");
		print_listed_files(dr);
		printf("\n");
		printf("%s:\n", info.str[0]);
		dr = opendir(info.str[0]);
		print_listed_files(dr);
		free_2d_str(info.str);
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