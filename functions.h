#include "main.h"
/**
 *ContTokens - Function that prints the amount of Tokens
 *@cadena1: Parameter given by the user
 *Return: Cont
 **/

int ContTokens(char *cadena1)
{
	int cont = 0;
	char *token1;

	token1 = strtok(cadena1, " ");
	while (token1 != NULL)
	{
		token1 = strtok(NULL, " ");
		cont++;
	}
	return (cont);
}
