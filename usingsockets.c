// Normal libs
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
// socket handling libs
#include <arpa/inet.h>
#include <sys/socket.h>
// net data sructures
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>


int main(void) {
	// socket descriptor
	int network_socket = socket(AF_INET, SOCK_STREAM, 0);
	// struct for storing server address
	struct sockaddr_in serv_addr;
	// use AF_INET address (IPv4)
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(9999);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	// connecting to the server
	int conn_status = connect(network_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if(conn_status == -1) {
		perror("[ERR] => ");
		return EXIT_FAILURE;
	}
	char *send_data = "Mr robot 10000001\r\n";
	send(network_socket, send_data, strlen(send_data), 0);
	char data[1024];
	int got_bytes = read(network_socket, &data, 1024);
	data[got_bytes + 1] = '\0';
	printf("%s", data);
	close(network_socket);
	return EXIT_SUCCESS;
}
