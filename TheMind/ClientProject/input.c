#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"

/// Fonction de rappel appel�e apr�s une saisie.
void (*ptrCallback)() = NULL;
/// Buffer stockant la derni�re saisie.
char buffer[1024];

void setInputCallback(void (*newPtrCallback)())
{
	ptrCallback = newPtrCallback;
}

char* getUserInput()
{
	return buffer;
}

void beginInputLoop()
{
	while (1)
	{
		fgets(buffer, sizeof buffer, stdin);
		buffer[strcspn(buffer, "\n")] = 0; // Enlever retour ligne.

		if (ptrCallback)
		{
			ptrCallback();
		}
	}
}