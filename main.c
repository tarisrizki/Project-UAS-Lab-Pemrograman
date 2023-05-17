#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// struct untuk data pemain
typedef struct 
{
    char username[50];
    char password[50];
}pemain;

// fungsi untuk registrasi
void registrasi(char *filename){
    pemain player;

    printf("REGISTRASI PEMAIN\n");
    printf("=========================================================\n\n");
    printf("Username : ");
    scanf("%s", player.username);
    printf("Password : ");
    scanf("%s", player.password);
    exit(1);
}
int main(int argc, char *argv[]){
    char *filename = "database/login.bin";
    if (argc == 1)
    {
        // Menampilkan petunjuk cara penggunaan program
        printf("\nCara Penggunaan: \n");
        printf("Untuk Registrasi: ./Program registrasi\n");
        printf("Untuk Login: ./Program username password\n\n");
        return EXIT_SUCCESS;
    }
    return 0;
}
