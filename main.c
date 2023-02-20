/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : Adriel Tohonan Simamora
 *   Hari dan Tanggal    : Rabu, 17 Februari 2023
 *   Nama (NIM)          : Adriel Tohonan Simamora(13221056)
 *   Nama File           : main.c
 *   Deskripsi           : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

int main()
{   
    char namafile[MAX];
    printf("Masukkan nama file: ");
    scanf("%s", &namafile);
    FILE *fp;
    fp = fopen(namafile,"r");
    if (fp == NULL){
        printf("Error : file tidak ada");
        return 0;
    }
    /*
    while(fp == NULL){
        printf("Error : file kosong");
    }
    */
    char tempString[255];
    while(fgets(tempString,255,fp)){
        // Data pertama didapatkan tempString
        // Kemudian dilakukan penyortiran
        int tempPanjangString;
        tempPanjangString = strlen(tempString);
        /* Membuat suatu array dimana array tersebut 
        / berisi 0,1,atau 2
        / Apabila bernilai 0 berarti lowercase
        / Apabila bernilai 1 berarti uppercase
        / Apabila bernilai 2 berarti 
        */
        int valueKalimat[tempPanjangString];
        for(int i = 0;i<tempPanjangString;i++){
            if ((tempString[i] <= 122)&& (tempString[i]>= 97)){
                valueKalimat[i] = 0;
            }
            else if ((tempString[i] <= 90)&& (tempString[i]>= 65)){
                valueKalimat[i] = 1;
            }
            else if((tempString[i] <= 57)&& (tempString[i]>= 48)){
                valueKalimat[i] = 2;
            }
        }
        

        // Streak yang sama
        int streaklower = 0;
        int streakUpper = 0;
        int streakAngka = 0;
        int maxLower = 0;
        int maxUpper = 0;
        int maxAngka = 0;
        int indexLower = 0;
        int indexUpper = 0;
        int indexAngka = 0;

        // Cari Streak dari LowerCase
        for(int i = 0 ;i < tempPanjangString;i++){
            while(i < tempPanjangString){
                if (valueKalimat[i] == 0){
                    streaklower += 1;
                }
                else{
                    break;
                }
                i +=1;
            }
            if (streaklower > maxLower){
                maxLower = streaklower;
                indexLower = i;
            }
            streaklower = 0;
        }

        // Cari Streak dari Upper Case
        for(int i = 0 ;i < tempPanjangString;i++){
            while(i < tempPanjangString){
                if (valueKalimat[i] == 1){
                    streakUpper += 1;
                }
                else{
                    break;
                }
                i +=1;
            }
            if (streakUpper > maxUpper){
                maxUpper = streakUpper;
                indexUpper = i;
            }
            streakUpper = 0;
        }

        // Cari Streak Angka
        // Cari Streak dari Upper Case
        for(int i = 0 ;i < tempPanjangString;i++){
            while(i < tempPanjangString){
                if (valueKalimat[i] == 2){
                    streakAngka += 1;
                }
                else{
                    break;
                }
                i +=1;
            }
            if (streakAngka > maxAngka){
                maxAngka = streakAngka;
                indexAngka = i;
            }
            streakAngka = 0;
        }
       // Testing Case
       if((maxAngka>=maxLower)&&(maxAngka>=maxUpper)){
        if(maxAngka == maxLower){
            if((indexAngka-maxAngka)<(indexLower-maxLower)){
                for(int i = indexAngka-maxAngka;i < indexAngka;i++){
                    printf("%c",tempString[i]);
            }
            }
            else{
                for(int i = indexLower-maxLower;i < indexLower;i++){
                    printf("%c",tempString[i]);
                }
            }
        }
        else if(maxAngka == maxUpper){
            if((indexAngka-maxAngka)<(indexLower-maxUpper)){
                for(int i = indexAngka-maxAngka;i < indexAngka;i++){
                    printf("%c",tempString[i]);
                }
            }
            else{
                for(int i = indexUpper-maxUpper;i < indexUpper ;i++){
                    printf("%c",tempString[i]);
                }
            }
        }
        else{
            for(int i = indexAngka-maxAngka;i < indexAngka;i++){
                printf("%c",tempString[i]);
            }
        }
       }
       else if((maxLower>=maxUpper)&&(maxLower>=maxAngka)){
        if(maxLower == maxUpper){
            if((indexLower-maxLower)<(indexUpper-maxUpper)){
                for(int i = indexLower-maxLower;i < indexLower;i++){
                    printf("%c",tempString[i]);
            }
            }
            else{
                for(int i = indexUpper-maxUpper;i < indexUpper ;i++){
                    printf("%c",tempString[i]);
                }
            }
        }
        else if(maxLower == maxAngka){
            if((indexLower-maxLower)<(indexAngka-maxAngka)){
                for(int i = indexLower-maxLower;i < indexLower;i++){
                    printf("%c",tempString[i]);
                }
            }
            else{
                for(int i = indexAngka-maxAngka;i < indexAngka;i++){
                    printf("%c",tempString[i]);
            }
            }

        }
        else{
            for(int i = indexLower-maxLower;i < indexLower;i++){
                printf("%c",tempString[i]);
            }
        }
       }
       else if((maxUpper>=maxLower)&&(maxUpper>=maxAngka)){
        if(maxUpper == maxAngka){
            if((indexUpper-maxUpper)<(indexAngka-maxAngka)){
                for(int i = indexUpper-maxUpper;i < indexUpper ;i++){
                    printf("%c",tempString[i]);
                }
            }
            else{
                for(int i = indexAngka-maxAngka;i < indexAngka;i++){
                    printf("%c",tempString[i]);
            }
            }
        }
        else if(maxUpper == maxLower){
            if((indexUpper-maxUpper)<(indexLower-maxLower)){
                for(int i = indexUpper-maxUpper;i < indexUpper ;i++){
                    printf("%c",tempString[i]);
                }
            }
            else{
                for(int i = indexLower-maxLower;i < indexLower;i++){
                    printf("%c",tempString[i]);
            }
            }   
        }
        else{
            for(int i = indexUpper-maxUpper;i < indexUpper ;i++){
                printf("%c",tempString[i]);
            }
        }
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}
