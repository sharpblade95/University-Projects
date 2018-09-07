#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/un.h> 
#include <sys/socket.h>

using namespace std;
void error(const char *msg)
{
    perror(msg);
    exit(1);
}


void send_msg(int socket_fd){


   int msg_size;
   char buffer[1024];
   memset(buffer,0,sizeof buffer);

     if(msg_size = send(socket_fd,"5",5,0)<0)
			error("ERROR writing to socket");
   while(msg_size = read(STDIN_FILENO,buffer,1024)>0)
        if(msg_size = write(socket_fd,buffer,18)<0)
			error("ERROR writing to socket");
}

int main (int argc ,char** argv ){
	 const char* SOCK_PATH = "/tmp/srv";
	struct sockaddr_un  addr;
	int server_fd;

	if((server_fd  =  socket(AF_UNIX,SOCK_STREAM,0))<0)
		error("socket error");
	memset(&addr,0 ,sizeof	(struct sockaddr_un));
	addr.sun_family= AF_UNIX;
	memcpy(addr.sun_path,SOCK_PATH,sizeof (addr.sun_path) -1 );


	if(connect(server_fd,(struct sockaddr*) &addr,sizeof (struct sockaddr_un))< 0)
		error ("connect  error");
	send_msg(server_fd);

	exit(0);
}