#include "main.h"

#undef DELIMITER

/**
 * execute - process command and execute process
 * @data: a pointer to the struct of data
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */

int execute(sh_t *data)
{
	/* Execute the command using execve or execvp function */

	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(data->cmd, data->args, environ) < 0)
			data->error_msg = _strdup("command not found\n");
		return (FAIL);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
	return (0);
}
