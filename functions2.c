#include "main.h"
/**
 *print_list - printea
 *@h: puntero
 *Return: size
 **/
size_t print_list(const list_token *token)
{
size_t n = 0;
while (token != NULL)
{
	if (!token)
		return (0);
	if (!token->token)
	{
		printf("[0] (nil)\n");
	}
	else
		printf("%s\n", token->token);
	token = token->next;
	n++;
}
	return (n);
}

char *verifica(list_token *lista, char *comando)
{
struct stat buf;
char *path = NULL;
while (lista != NULL)
{
	if (!lista)
		return (NULL);
	if (!lista->next)
	{	
		path = strcat(lista->token, comando);		
		if (stat(path, &buf) == 0)
		{
			free_list(lista);
			return (path);
		}
		break;
	}
		
		path = strcat(lista->token, comando);
		if (stat(path, &buf) == 0)
		{
			free_list(lista);
			return (path);
		}

	lista = lista->next;
}
return (NULL);
}

/**
 *free_list - printea
 *@head: puntero
 **/
void free_list(list_token *head)
{
		while (head != NULL)
		{
			free(head->token);
			free(head);
			head = head->next;
		}
}

int verifica_exit(char *cadena)
{
	char *cadena2 = strdup(cadena);
	char *exit = "exit";

	cadena2 = strtok(cadena2, "\n");
	return (strcmp(exit, cadena2));
}

int verifica_caracteres(char *cadena)
{
	int iter = 0;
	while (cadena[iter])
	{
		if(cadena[iter] != ' ' || cadena[iter] != '\t' || cadena[iter] != '\n')
		{
			printf("hola");
			return (0);
		}
		iter++;
	}
	return (1);
}
