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
    
    printf("MARI MULAI PERMAINANNYA\n\n");
    quiz pertanyaan[total_soal];
    strcpy(pertanyaan[0].soal, "Apakah ibu kota India?");
    strcpy(pertanyaan[0].pilihanA, "Dubai");
    strcpy(pertanyaan[0].pilihanB, "Mumbai");
    strcpy(pertanyaan[0].pilihanC, "Newdelhi");
    strcpy(pertanyaan[0].pilihanD, "Bangkok");
    pertanyaan[0].jawaban = 'C';
    
    strcpy(pertanyaan[1].soal, "Apakah nama bahasa pemrograman tertua dari pilihan berikut?");
    strcpy(pertanyaan[1].pilihanA, "Python");
    strcpy(pertanyaan[1].pilihanB, "Java");
    strcpy(pertanyaan[1].pilihanC, "C");
    strcpy(pertanyaan[1].pilihanD, "HTML");
    pertanyaan[1].jawaban = 'C';
    
    strcpy(pertanyaan[2].soal, "Bendera negara manakah yang memiliki bintang terbesar dari semua bendera di dunia?");
    strcpy(pertanyaan[2].pilihanA, "Republic Afrika Tengah");
    strcpy(pertanyaan[2].pilihanB, "Yaman");
    strcpy(pertanyaan[2].pilihanC, "Myanmar");
    strcpy(pertanyaan[2].pilihanD, "Suriname");
    pertanyaan[2].jawaban = 'C';
    
    strcpy(pertanyaan[3].soal, "Siapakah pemenang SEA GAMES cabang sepak bola tahun 2023?");
    strcpy(pertanyaan[3].pilihanA, "Kamboja");
    strcpy(pertanyaan[3].pilihanB, "thailand");
    strcpy(pertanyaan[3].pilihanC, "Malaysia");
    strcpy(pertanyaan[3].pilihanD, "Indonesia");
    pertanyaan[3].jawaban = 'D';
    
    strcpy(pertanyaan[4].soal, "Siapakah yang menciptakan bahasa c?");
    strcpy(pertanyaan[4].pilihanA, "Dennis Ritchie");
    strcpy(pertanyaan[4].pilihanB, "James Gosling");
    strcpy(pertanyaan[4].pilihanC, "Guido van Rossum");
    strcpy(pertanyaan[4].pilihanD, "Bjarne Stroustrup");
    pertanyaan[4].jawaban = 'A';
    
    float score = 0;
    char jawaban_user;
    for(int i=0 ; i < total_soal; i++){
        printf("SOAL %d \n%s\n", (i+1), pertanyaan[i].soal);
        printf("A) %s\n", pertanyaan[i].pilihanA);
        printf("B) %s\n", pertanyaan[i].pilihanB);
        printf("C) %s\n", pertanyaan[i].pilihanC);
        printf("D) %s\n\n", pertanyaan[i].pilihanD);
        printf("masukkan jawaban : (dengan A,B,C atau D)\n");

        scanf(" %c", &jawaban_user);
        if(toupper(jawaban_user) == pertanyaan[i].jawaban){
            score++;
            printf("jawaban anda benar!!!\n\n");
        }
        else{
            printf("jawaban anda salah\n\n");
            printf("jawaban yang benar %c\n\n", pertanyaan[i].jawaban);
        }

        printf("=========================================================\n\n");
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
