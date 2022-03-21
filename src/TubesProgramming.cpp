// TUBES PROGRAMMING
// ROBOT VS MECHA-KURAMA

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// INISIALISASI ATRIBUT
int x=0, y=0; //koordinat Robot
int jarakMax=8; //jarak euclidean maksimum antara Robot dengan bunshin dimana mereka dapat saling menyerang
int damageRobot=300; //damage Robot
int damageBunshin=200; //damage Bunshin
int healthRobot=5000; //health Robot
int healthBunshin=1000; //health bunhsin

// FUNGSI UNTUK MENAMPILKAN POSISI ROBOT DAN BUNSHIN MECHA-KURAMA
void show(int a, int b, double jarak){
    printf("\n      ---PETA DESA URO---\n");
    for (int i=15; i>=0; i--){
        for (int j=0; j<=15; j++){
            if (j==x && i==y){ //koordinat Robot
                printf("R "); //menampilkan robot
            }
            else if (i==b && j==a){ //Koordinat Bunshin Mecha-kurama
                printf("x ");//menampilkan bunshin Mecha-Kurama
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\nHealth Robot : %d", healthRobot);
    printf("\nHealth Bunshin : %d", healthBunshin);
    printf("\nJarak : %.2lf", jarak);
}
        
//FUNGSI SERANGAN BUNSHIN MECHA-KURAMA
void attackBunshin(double jarak){
    if (jarak <= jarakMax){ //bunshin hanya dapat menyerang jika jaraknya dengan Robot kurang dari jarak maksimal yang telah ditetapkan
        healthRobot -= damageBunshin;
    }
}

//FUNGSI SERANGAN ROBOT
void attackRobot(double jarak){
    if (jarak <= jarakMax){
        healthBunshin -= damageRobot;
    }
    else{
        printf("\n -- Bunshin diluar jangkauan! --\n");
    }
}

//FUNGSI UNTUK MENGECEK VALIDITAS INPUT YANG DIMASUKKAN USER
bool isValid(string input){
    if (input== "atas" || input=="bawah" || input=="kanan" || input=="kiri" || input=="stop" || input=="tembak"){ //program hanya menerima 6 jenis input
        return true;
    }
    else{
        return false;
    }
}

//FUNGSI PERGERAKAN ROBOT
void move(string input, int a, int b){
    if (input=="atas"){
        if (0<=y+1 && y+1<=15 ){ //jika Robot masih di dalam koordinat yang diperbolehkan (15x15)
            if (y+1==b && x==a){ //jika koordinat Robot sama dengan koordinat bunshin
                printf("\n-- Robot menabrak Bunshin! saatnya menyerang! --\n");
            }
            else{//jika koordinat Robot tidak sama dengan koordinat bunshin
                y+=1;
            }
        }
        else{//jika Robot keluar dari batas koordinat yang diperbolehkan (15x15)
            printf("\n-- Robot mencapai batas luar Desa URO! --\n");
        }
    }
    else if (input=="bawah"){
        if (0<=y-1 && y-1<=15 ){ //jika Robot masih di dalam koordinat yang diperbolehkan (15x15)
            if (y-1==b && x==a){ //jika koordinat Robot sama dengan koordinat bunshin
                printf("\n-- Robot menabrak Bunshin! saatnya menyerang! --\n");
            }
            else{//jika koordinat Robot tidak sama dengan koordinat bunshin
                y-=1;
            }
        }
        else{//jika Robot keluar dari batas koordinat yang diperbolehkan (15x15)
            printf("\n-- Robot mencapai batas luar Desa URO! --\n");
        }
    }
    else if (input=="kanan"){
        if (0<=x+1 && x+1<=15 ){ //jika Robot masih di dalam koordinat yang diperbolehkan (15x15)
            if (y==b && x+1==a){ //jika koordinat Robot sama dengan koordinat bunshin
                printf("\n-- Robot menabrak Bunshin! saatnya menyerang! --\n");
            }
            else{//jika koordinat Robot tidak sama dengan koordinat bunshin
                x+=1;
            }
        }
        else{//jika Robot keluar dari batas koordinat yang diperbolehkan (15x15)
            printf("\n-- Robot mencapai batas luar Desa URO! --\n");
        }
    }
    else if (input=="kiri"){
        if (0<=x-1 && x-1<=15 ){ //jika Robot masih di dalam koordinat yang diperbolehkan (15x15)
            if (y==b && x-1==a){ //jika koordinat Robot sama dengan koordinat bunshin
                printf("\n-- Robot menabrak Bunshin! saatnya menyerang! saatnya menyerang! --\n");
            }
            else{//jika koordinat Robot tidak sama dengan koordinat bunshin
                x-=1;
            }
        }
        else{//jika Robot keluar dari batas koordinat yang diperbolehkan (15x15)
            printf("\n-- Robot mencapai batas luar Desa URO! --\n");
        }
    }

}

//FUNGSI UTAMA
int main(){
    string input;

    //Inisialisasi koordinat bunshin
    srand(time(0));
    int a = rand() %16;
    int b = rand() %16;
    while (a==x && b==y){
        a = rand() %16;
        b = rand() %16;
    } 

    //Inisialisasi jumlah bunshin
    int N =0;

    //
    while (healthRobot > 0){
        //respawn bunshin jika bunshin mati
        if (healthBunshin<=0){ 
            healthBunshin = 1000; 
            N +=1;//increament jumlah bunshin yang mati
            srand(time(0));
            a = rand() %16;
            b = rand() %16;
            while (a==x && b==y){
                a = rand() %16;
                b = rand() %16;
            }
        }

        //jarak euclidean Robot dengan bunshin
        double jarak = sqrt(pow((a-x),2) + pow((b-y),2));

        //meminta masukan dari user
        show(a,b,jarak);
        printf("\n\nMasukan perintah : ");
        cin >> input;

        if (isValid(input)){ //jika masukan valid
            if (input=="tembak"){
                attackRobot(jarak);
            }
            else if(input=="stop"){
                break;
            }
            else{
                move(input,a,b);
            }
            attackBunshin(jarak);//bunshin menyerang setiap perintah masukan valid (juga jika syarat jarak max terpenuhi)
        } 
        else{ //jika masukan tidak valid
            printf("\n-- Perintah tidak dikenali! --\n");
        }
    }

    //menampilkan jumlah bunhsin mecha-kurama yang mati    
    printf("Jumlah Bunshin Mecha-Kurama yang berhasil dikalahkan : %d", N);
    
    return 0;

}
