#include "main.h"
/**
* main - our simple shell
*@argc: int
*@argv:string
*@env: enviroment
*Return: 1
**/
int main(int __attribute__((unused)) argc, char  __attribute__((unused)) *argv[], char **env)
{
	pid_t hijo;
	char *path = find_PATH(env);
	char *path2 = NULL;
	list_token *lista = NULL;
	ssize_t bytes_leidos = 0;
	size_t numero_bytes = 0;
	char **array = NULL, *cadena = NULL;
	
	while (1)
	{
		lista = NULL;
		printf(VERDE_T "$cisfun " BLANCO_T);
		bytes_leidos = getline(&cadena, &numero_bytes, stdin);
		if (cadena[0] == '\n')
		{
			free(cadena);
			cadena = NULL;
			continue;
		}
		else if (bytes_leidos == -1 || cadena[0] == EOF)
		{
			break;
		}
		else
		{
			lista = llenar_lista(path, lista);
			array = cargar(cadena, array);
			path2 = verifica(lista,array[0]);
		if (path2 == NULL)
		{
			perror(" ERROR");
			continue;
		}
		else
		{
			array[0] = path2;
			hijo = fork();
			if (hijo == 0) /*Dentro del hijo*/
			{
				if (execve(array[0], array, NULL) == -1) /*Tratamos de ejecutar el coman*/
				{
					free(cadena);
					free(array);
					perror(" ERROR");
					return (0);
				}
			}
			else /*Estoy en el padre*/
			{
				wait(NULL);
			}
			free(cadena);
		}
		}
		free(array);
		bytes_leidos = 0;
		cadena = NULL;
	}
	free(cadena);
	free(lista);
	return (0);
}
