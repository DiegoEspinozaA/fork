#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h> 

int main(){

    pid_t pid1, pid2, pid3, pid4;
    
    printf("Proceso padre: %d\n",getpid());
    pid1 = fork();
    
    printf("Despues del primer fork\n");
    //primer fork, se divive en el proceso hijo y el "padre" resultante del fork ("bajan de nivel los pid del hijo con el padre como 2 procesos")

    //HIJO
    if(pid1 == 0){
        printf("Hijo: [%d] -> Padre: [%d] \n", getpid(),getppid());
        pid2 = fork();
        if(pid2 == 0){ 
            //690.
            printf("Hijo: [%d] -> Padre: [%d] \n", getpid(),getppid());
        }
    
        else{
            //700
            pid4 = fork();
            if(pid4 == 0){ 
                printf("Hijo: [%d] -> Padre: [%d] \n", getpid(),getppid());
            }
        }
    }
    
    //PADRE
    if(pid1 > 0){
    pid3 = fork();
        if(pid3 == 0){ //680
            printf("Hijo: [%d] -> Padre: [%d] \n", getpid(),getppid());
        }
    }

    for(int i=0; i<3; i++) 
        wait(NULL);

    return 0;
}
