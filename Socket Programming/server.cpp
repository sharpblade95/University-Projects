/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/un.h> 
#include <sys/socket.h>
#include <pthread.h>

using namespace std;
void error(const char *msg)
{
    perror(msg);
    exit(1);
}


pthread_t mythreads[5];
 mutex mutex1;
  
int hal=0,yo=0,fi=0,pi=0;

void *send_res(void * fd){
    long socket_fd= (long)fd;
    string ship;
   int msg_size;
   char buffer[1024];
   memset(buffer,0,sizeof buffer);
   
   while(buffer[0]==0)
     read(socket_fd,buffer,5);
 


    if(buffer[0]=='5'){
       
             hal=1;
             mutex1.unlock();
           mutex1.lock(); 
           cout<<"halvar"<<": "<<endl;


       while(msg_size = read(socket_fd,buffer,1024)>0 ){
                cout<< buffer;  

       }

       
       if (msg_size < 0) error("ERROR reading from socket");
     
        hal--;
         mutex1.unlock();
      



    }
  else  if(buffer[0]=='4'){
                 yo=1;
                if(!hal){
                
                 mutex1.lock();

                 cout<<"yorob"<<": "<<endl;

       while(msg_size = read(socket_fd,buffer,1024)>0 && !hal){
                cout<< buffer;  

       }
       
       if (msg_size < 0) error("ERROR reading from socket");
     
        yo--;
         mutex1.unlock();
    
   }}
   else  if(buffer[0]=='3'){
                 fi=1;
                if(!hal && !yo){
                 
                 mutex1.lock(); 
                 cout<<"fix"<<": "<<endl;

       while(msg_size = read(socket_fd,buffer,1024)>0 && !hal && !yo){
                cout<< buffer;  

       }
       
       if (msg_size < 0) error("ERROR reading from socket");
     
        fi--;
         mutex1.unlock();
    }}
    else if(buffer[0]=='2'){
     
                if(!hal&& !yo && !fi){

                 pi++;
                 mutex1.lock(); 
                 mutex1.unlock();
                 if(pi==1)
                  cout<<"pirate"<<": "<<endl;
       while(msg_size = read(socket_fd,buffer,1024)>0 && !hal && !yo && !fi){
                cout<< buffer;  

       }
       
       if (msg_size < 0) error("ERROR reading from socket");
     
        
            pi--;
            if(pi==0){

                     mutex1.unlock();
               }
           }
    }
    
   
 
    
  
close(socket_fd);

}





int main(int argc, char *argv[])
{
    const char* SOCK_PATH = "/tmp/srv";
    
     int fd, portno;
     long  client_fd;
     string t_name[5];
     
     struct sockaddr_un addr, cli_addr;
     int n;
    
     fd = socket(AF_UNIX, SOCK_STREAM, 0);
     if (fd < 0) 
        error("ERROR opening socket");
     memset(&addr, 0,sizeof addr);
     addr.sun_family = AF_UNIX;
     
     memcpy(addr.sun_path, SOCK_PATH, sizeof (addr.sun_path-1));
     if( access(addr.sun_path,F_OK) == 0)
        unlink (addr.sun_path) ;


     if (bind(fd, (struct sockaddr *) &addr,
              sizeof(struct sockaddr_un)) < 0) 
              error("ERROR on binding");
     if(listen(fd,6) == -1)
        error("listen error");
    


   

    int pid;
       int i=0;
       socklen_t  clilen = sizeof(addr);
     while(1 ){
       

        client_fd = accept(fd,(struct sockaddr *) &addr, &clilen);      
            if (client_fd < 0) 
                error("ERROR on accept");
        

            pthread_create(&mythreads[i], NULL, send_res, (void*)client_fd);
           
           
          i++;
     } 




     close(fd);


     return 0;
     
     
    
}
