#include "main.h"

/**
 * main - creates a simple shell.
 * @argc: count arguments parameter.
 * @argv: an array of a command listed.
 * @env: variables envirement.
 * Return: 0 in success.
 */

int main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;

	shell(env);

	return (0);
}
