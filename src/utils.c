#include "../include/ft_ls.h"

int isDir(const char* fileName)
{
	struct stat	path;

	stat(fileName, &path);
	return S_ISREG(path.st_mode);
}

void	free_2d_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free (str);
}

void	print_2d_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		printf("%d --> %s\n", i, str[i]);
		i++;
	}
}

int	get_n_dirs(DIR *dr, char *path)
{
	struct dirent *en;
	int				count = 0;

	dr = opendir(path);
	if (dr)
	{
		while ((en = readdir(dr)) != NULL)
			if ((((strcmp(en->d_name, ".") == 0)
			|| (strcmp(en->d_name, "..") == 0)) == 0)
			&& en->d_name[0] != '.')
				count += isDir(en->d_name) == 0 ? 1 : 0;
	}
	closedir(dr);
	return (count);
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

t_info	get_listed_dirs(DIR *dr, char *path)
{
	struct dirent	*en;
	t_info			info;
	int				i;

	i = 0;
	info.str = (char **)malloc(sizeof(char *) * (get_n_dirs(dr, path) + 1));
	if (dr)
	{
		while ((en = readdir(dr)) != NULL)
			if ((((strcmp(en->d_name, ".") == 0)
			|| (strcmp(en->d_name, "..") == 0)) == 0)
			&& en->d_name[0] != '.')
				if (isDir(en->d_name) == 0)
					info.str[i++] = strdup(en->d_name);
	}
	info.str[i] = NULL;
	closedir(dr);
	info.next = NULL;
	return (info);
}