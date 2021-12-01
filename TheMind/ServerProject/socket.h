#pragma once

#include "messaging/enums.h"

/**
 * @brief D�marrer le serveur.
 * D�marrer le socket, �couter les demandes de connexion, et g�rer la communication avec les clients.
*/
void socket_open();

/**
 * @brief Fermer le serveur.
 * Terminer la connexion des clients et du serveur.
*/
void socket_close();

/**
 * @brief Diffuser un message � tous les clients connect�s au serveur.
 * @param type Type du message.
 * @param msg Message � envoyer. Structure correspondant au type du message envoy�. // TODO : mettre r�f�rence vers fichier o� il y a les structures.
 * @param size Taille du message.
*/
void socket_broadcast(enum SrvMsg type, const void* msg, size_t size);

/**
 * @brief Envoyer un message � un client.
 * @param clientId Identifiant du client.
 * @param type Type du message.
 * @param msg Message � envoyer. Structure correspondant au type du message envoy�. // TODO : mettre r�f�rence vers fichier o� il y a les structures.
 * @param size Taille du message.
*/
void socket_send(unsigned int clientId, enum SrvMsg type, const void* msg, size_t size);