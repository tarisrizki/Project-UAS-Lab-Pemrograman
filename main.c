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
    
    FILE *fpw = fopen(filename, "wb");
    if(fpw == NULL){
        printf("Gagal membuka file!");
        exit(1);
    }

    fwrite(&player, sizeof(player), 1, fpw);

    fclose(fpw);

    printf("=========================================================\n\n");
    printf("Registrasi Berhasil!!!\n");
    printf("Data pemain berhasil disimpan dalam database. Gunakan CLA untuk login\n");
    printf("=========================================================\n\n");
    exit(1);
}
void login(char *filename, char *username, char *password){
    FILE *fpr = fopen(filename, "rb");
    if(fpr == NULL){
        printf("Gagal membuka file!");
        exit(1);
    }
    pemain player;
    fread(&player, sizeof(player), 1, fpr);
    fclose(fpr);

    if(strcmp(player.username, username) == 0 && strcmp(player.password, password) == 0){
        printf("LOGIN BERHASIL. SELAMAT DATANG, %s!\n", player.username);
    }
    else{
        printf("GAGAL LOGIN. User atau Password salah.\n");
        printf("Petunjuk penggunaan CLA untuk login :\n");
        printf("Program : ./nama_program\n");
        printf("Argumen 1 : username\n");
        printf("Argumen 2 : password\n");   
    }
}

void permainan(){
    #define kata2_soal 100
    #define kata2_pilihan 100
    #define total_soal 5
    typedef struct 
    {
        char soal[kata2_soal];
        char pilihanA[kata2_pilihan];
        char pilihanB[kata2_pilihan];
        char pilihanC[kata2_pilihan];
        char pilihanD[kata2_pilihan];
        char jawaban;
    } quiz;
    
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
    else if (strcmp(argv[1], "registrasi") == 0){
        registrasi(filename);
    }
    else if (argc == 3){
        char *username = argv[1];
        char *password = argv[2];
        login(filename, username, password);
        permainan();
    }
    return 0;
}
