#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#define BLANCO_T   "\x1b[37m"
#define VERDE_T        "\x1b[32m"

int ContTokens(char *cadena1);
char *find_PATH(char **env);
char **cargar(char *cadena, char **array);
list_token llenar_lista(char *path, list_token *lista);

/**
 *struct node - structure definition
 *@token: Each path
 *@next: Pointer to the next node
 **/
typedef struct node
{
	char *token;
	struct node *next;
} list_token;

#endif
