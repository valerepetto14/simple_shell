#ifndef MAIN_H
#define MAIN_H
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#define BLANCO_T   "\x1b[37m"
#define VERDE_T        "\x1b[32m"
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

int ContTokens(char *cadena1);
char *find_PATH(char **env);
char **cargar(char *cadena, char **array);
list_token *llenar_lista(char *path, list_token *lista);
list_token *add_node_end(list_token **token,char *str);
size_t print_list(const list_token *token);
char *verifica(const list_token *lista, char *comando);
void free_list(list_token *head);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
#endif
