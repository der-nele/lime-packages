#ifndef __VALE_H_
#define __VALE_H_
#define VALE_BITS 60
#define VALE_CHARS (VALE_BITS+5)/5
#define VALE_KEY_BITS 128
#define DATE_FORMAT "%Y-%m-%d %H:%M:%S"



unsigned char charset[] = "abcdefghijklmnopqrstuvwxyz234567";

typedef struct vale {
unsigned int id;
unsigned int type;
unsigned int val;
} vale;

typedef struct vale_used {
char valestr[VALE_CHARS];
time_t when;
unsigned char client_id[24];
} vale_used;

typedef struct group {
    int from;
    int to;
    char *key;
} group;

typedef struct client {
    unsigned char id[24];
    time_t expire;
} client;
void genb32table();
void genb16table();

int b32dec(char *in, unsigned char **outp);
int b16dec(char *in, unsigned char **outp);
vale * vale_decode(unsigned char *valebits);
void vale_used_insert(vale_used *used, char * client_id, char *valestr);
void print_vale_used(FILE * out, vale_used * used);
unsigned char * vale_getkey(vale *v, group *groups);
int vale_isauth(unsigned char *data, unsigned char *key);
int save_vale_used(char *path, vale_used *used);
int save_clients(char *path, client * clients);

char *load_file(char *path);
group *load_groups();
client *load_clients();
vale_used *load_vale_used();

void print_clients(FILE *out, client *clients);
client * client_getbyid(client *clients, char *id);
void client_insert(client *clients, client *newclient);
void client_insertvale(char *id, vale * v, client * clients);

#endif /* __VALE_H_ */

