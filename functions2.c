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

char *verifica(const list_token *lista, char *comando)
{
struct stat buf;
char *path = NULL;
while (lista != NULL)
{
	if (!lista)
		return (NULL);
	if (!lista->next)
	{	
		path = _strcat(lista->token, comando);		
		if (stat(path, &buf) == 0)
		{
			return (path);
		}
		break;
	}
		
		path = _strcat(lista->token, comando);
		if (stat(path, &buf) == 0)
		{
			return (path);
		}

	lista = lista->next;
}
	printf("%s",path);
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
	char *cadena2 = _strdup(cadena);
	char *exit = "exit";

	cadena2 = strtok(cadena2, "\n");
	return (_strcmp(exit, cadena2));
}
