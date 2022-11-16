#include "main.h"

/**
 * main - Entry point of c programs
 * Return: 0 on success
 */

int main(void)
{
	/* main function with while loop of our shell */
	sh_t data;
	int pl;

	_memset(&data, 0, sizeof(data));
	signal(SIGINT, signal_handler);
	while (true)
	{
		index_cmd(&data);
		if (read_line(&data) < 0)
		{
			if (isatty(STDIN_FILENO))
				PRINT("\n");
			break;
		}
		if (split_line(&data) < 0)
		{
			free_data(&data);
			continue;
		}
		pl = parse_line(&data);
		if (pl == 0)
		{
			free_data(&data);
			continue;
		}
		if (pl < 0)
		{
			print_error(&data);
			continue;
		}
		if (execute(&data) < 0)
		{
			print_error(&data);
			break;
		}

	}
	free_data(&data);

	return (0);
}
