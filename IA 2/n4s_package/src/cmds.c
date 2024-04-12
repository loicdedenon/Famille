/*
** EPITECH PROJECT, 2024
** float values
** File description:
** floats
*/

#include "../includes/my.h"

int parse_response_header(char* raw_response,ResponseHeader* result) {
    if(result==NULL){
        return -1;
    }
    char *token, *lasts, *endptr;
    //parse value_id
    token = strtok_r(raw_response, ":", &lasts);
    fprintf(stderr,"-->%s\n",lasts);
    if (token == NULL) {
        fprintf(stderr, "missing value_id in response %s\n", raw_response);
        return -1;
    }
    long value_id = strtol(token, &endptr, 10);
    if(endptr==token){
        fprintf(stderr,"invalid value_id %s in response %s\n",token,raw_response);
        return -1;
    }
    result->value_id = (int) value_id;
    //parse status
    token = strtok_r(NULL, ":", &lasts);
    if (token == NULL) {
        fprintf(stderr, "missing status in response %s\n", raw_response);
        return -1;
    }
    int status=strcmp(token,"OK")==0?0:-1;
    result->status = status;
    //parse code_str
    token = strtok_r(NULL, ":", &lasts);
    if (token == NULL) {
        fprintf(stderr, "missing code_str in response %s\n", raw_response);
        return -1;
    }
    result->code_str=strdup(token);
    //put the rest of the raw response into the result data
    result->data = strdup(lasts);
    return 0;
}

int receive_response(char *buffer, size_t buffer_size)
{
    int nbr_read;

    nbr_read = getline(&buffer, &buffer_size, stdin);
    if (nbr_read > 0) {
        fprintf(stderr, "receive response %s\n", buffer);
        return 0;
    } else {
        return -1;
    }
}
void print_response_header(ResponseHeader* rh)
{
    fprintf(stderr,"ResponseHeader{value_id=%d,status=%d, code_str=%s, data = %s }\n",rh->value_id,rh->status,rh->code_str, rh->data);
}
int send_command(char *command, ResponseHeader *response)
{
    char *buffer;
    size_t buf_size;

    fprintf(stderr, "send command %s\n", command);
    my_putstr(command);
    buf_size = 1024;
    buffer = malloc(sizeof(char)*buf_size);
    int err =receive_response(buffer, buf_size);
    if (err == 0 && response != NULL) {
        err = parse_response_header(buffer,response);
        fprintf(stderr,"after parse response, %s\n",buffer);
        print_response_header(response);
    }
    free(buffer);
    return err;
}

