/**
 * @file main.c
 * @brief Fichier de démarrage du programme.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "socket.h"

/// Quitter le programme proprement en se déconnectant du serveur.
void quit()
{
	socket_disconnect();
	exit(EXIT_SUCCESS);
}

/// Afficher la liste des arguments de lancement disponibles.
void printHelp()
{
	printf("Arguments available:\n");
	printf("\t--ip <ip-address>	\tServer IP address to connect to.\n");
	printf("\t--port <number>	\t\tServer IP port to connect to.\n");
	printf("\t--help			\tPrint this list.\n");
	printf("\n");

	printf("Note: server IP address and port are mandatory in order to run the program.\n");

	exit(EXIT_SUCCESS);
}

/// Parser les arguments de lancement et en définir l'IP et le port du serveur.
void parseArgs(int argc, char* argv[])
{
	// Aucun argument renseigné.
	if (argc == 1)
	{
		printHelp();
	}

	// Parser les arguments.
	char* ip = NULL;
	char* port = NULL;

	for (int i = 1; i < argc - 1; i++)
	{
		char* arg = argv[i];

		// On récupère l'adresse IP.
		if (strcmp(arg, "--ip") == 0)
		{
			if (i + 1 < argc) ip = argv[i + 1];
		}
		// On récupère le port.
		else if (strcmp(arg, "--port") == 0)
		{
			if (i + 1 < argc) port = argv[i + 1];
		}
	}

	// IP et port non renseignés.
	if (!ip || !port)
	{
		printHelp();
	}

	// Définir IP et port du serveur.
	socket_setIp(ip);
	socket_setPort(atoi(port));
}

int main(int argc, char* argv[])
{
	parseArgs(argc, argv);

	srand(getpid());
	signal(SIGINT, &quit);

	socket_connect();

	return EXIT_SUCCESS;
}
