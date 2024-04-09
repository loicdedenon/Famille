#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int start_simulation_temp(int ac, char **av)
{
     char *buffer = NULL;
    size_t buf_size = 2048;

    printf("START_SIMULATION");
    buffer = malloc(sizeof(char) *buf_size);
    if (buffer == NULL) {
        perror("Malloc failure");
        return (0);
    }
    write(1, "$> ", 3);
    while (getline(&buffer, &buf_size, stdin) > 0) {
        printf("%s\n", buffer);
        write(1, "$> ", 3);
    } 
   free(buffer);
}

float min(float f1,float f2){
    if(f1<f2){
        return f1;
    }else{
        return f2;
    }
}

float max(float f1,float f2){
    if(f1>f2){
        return f1;
    }else{
        return f2;
    }
}

float in_range(float value, float lower, float upper){
    return min(upper,max(lower,value));
}

 /// @brief 
 /// @param engine_power percentage of engine power between 0 and 1 inclusive
 /// @return 
 int car_forward(float engine_power)
 {
    char buffer [1024];
    sprintf(buffer,"CAR_FORWARD:%.2f\n",in_range(engine_power,0,1));
    return send_command(buffer);
 }

int send_command(char *command)
{
    fprintf(stderr, "send command %s\n",command);
    write(1, command, strlen(command));
    size_t buf_size=1024;
    char *buffer= malloc(sizeof(char)*buf_size);
    int nbr_read = getline(&buffer,&buf_size,stdin);
    if(nbr_read>0){
        fprintf(stderr, "receive response %s\n",buffer);
        free(buffer);
        return 0;
    } else {
        free(buffer);
        return -1;
    }
}
int start_simulation()
{
    return send_command("START_SIMULATION\n");
}

int stop_simulation()
{
    
    return send_command("STOP_SIMULATION\n");
}

int main(int ac, char **av)
{
    //start_simulation_temp(ac,av);
    start_simulation();
    car_forward(.1);
    sleep(20);
    return stop_simulation();
}