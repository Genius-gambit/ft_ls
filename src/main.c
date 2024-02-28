#include "../include/ft_ls.h"

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
	print_listed_files(dr);
	return (0);
}