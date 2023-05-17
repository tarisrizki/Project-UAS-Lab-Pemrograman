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
