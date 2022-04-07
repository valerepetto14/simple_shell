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
char *path;
while (lista != NULL)
{
	if (!lista)
		return (NULL);
	if (!lista->next)
	{	
		path = strcat(lista->token, comando);		
		if (stat(path, &buf) == 0)
		{
			return (path);
		}
		break;
	}
		
		path = strcat(lista->token, comando);
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

/**
*_strcmp- asd
*@s1: asd
*@s2: asd
*Return: asd
**/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
/**
 * _strcat - sss
 * @s: 123
 *@*dest: 122
 *@*src: 1223
 *Return: 2
 **/
char *_strcat(char *dest, char *src)
{
	int contdest = _strlen(dest), a = 0, c = 0;
	int contsrc = _strlen(src);

	for (a = contdest; a < contdest + contsrc; a++)
	{
		if (c <= contsrc)
		{
		dest[a] = src[c];
		c++;
		}
	}
	return (dest);
}

/**
 *_strlen - 123
 *@s: 123
 *Return: 12
 **/
int _strlen(char *s)
{
		int cont = 0;
		char *a;

		a = s;

		while (*a != 0)
		{
			a++;
			cont++;
		}
		return (cont);
}

