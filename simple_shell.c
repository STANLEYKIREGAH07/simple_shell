#include "main.h"

/**
 * main - the simple shell.
 * @ac: argument count.
 * @av: vector argument.
 * Return: 1 if something wrong and 0 if success.
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int i;

	i = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (i)
		: "r" (i));

	if (ac == 2)
	{
		i = open(av[1], O_RDONLY);
		if (i == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				print_str(av[0]);
				print_str(": 0: Can't open ");
				print_str(av[1]);
				print_char('\n');
				print_char(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = i;
	}
	populate_env_list(info);
	main_sh(info, av);
	return (EXIT_SUCCESS);
}
