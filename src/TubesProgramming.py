# TUBES PROGRAMMING
# ROBOT KURAMA vs BUNSHIN

import random
import math

# fungsi random spawn bunshin
def bunshin():
    global a,b
    a = random.randint(1,9)
    b = random.randint(1,9)
    while a==x and b==y : # agar bunshin tidak spawn di tempat kurama
        a = random.randint(1,9)
        b = random.randint(1,9)

    peta[b][a] = "B "

# fungsi untuk menampilkan peta beserta kurama dan bunshinnya
def show():
    global jarak 
    for i in reversed(range(10)):
        for j in range(10):
            print(peta[i][j],end="")
        print("")
    jarak = math.sqrt(((a-x)*2) + ((b-y)*2)) # jarak euclidean antara kurama dan bunshin setiap saat
    print("Health Kurama : ", healthKurama)
    print("Health Bunshin : ", healthBunshin)
    print("Jarak : ",jarak)

# fungsi untuk menembak atau menyerang bunshin
def menembak():
    global healthBunshin
    if jarak<jarakMax :
        healthBunshin -= damageKurama
        peta[b][a]= "B "

# serangan bunshin ke kurama (bunshi)
def seranganBunshin(): 
    global healthKurama
    if jarak<jarakMax :
        healthKurama -=damageBunshin
        peta[y][x]= "K "

# fungsi pergerakan bunshin
def gerak():
    global x,y
    if n=="atas":
        peta[y][x]= ". "
        y += 1
        if 0<=x<=9 and 0<=y<=9 and not(x==a and y==b):
            peta[y][x]= "K "
        else:
            print("Kurama melewati batas arena atau menabrak Bunshin!")
            y-=1
            peta[y][x]= "K "

    elif n=="bawah":
        peta[y][x]= ". "
        y -=1
        if 0<=x<=9 and 0<=y<=9 and not(x==a and y==b) : 
            peta[y][x]= "K "
        else:
            print("Kurama melewati batas arena atau menabrak Bunshin!")
            y+=1
            peta[y][x]= "K "
    elif n=="kanan":
        peta[y][x]= ". "
        x+=1
        if 0<=x<=9 and 0<=y<=9 and not(x==a and y==b) :
            peta[y][x]= "K "
        else:
            print("Kurama melewati batas arena atau menabrak Bunshin!")            
            x-=1
            peta[y][x]= "K "
    elif n=="kiri":
        peta[y][x]= ". "
        x-=1
        if 0<=x<=9 and 0<=y<=9 and not(x==a and y==b):
            peta[y][x]= "K "
        else:
            print("Kurama melewati batas arena atau menabrak Bunshin!")
            x+=1
            peta[y][x]= "K "

# fungsi pengecekan input apakah valid atau tidak
def isValid():
    if n=="tembak" or n=="atas" or n=="bawah" or n=="kanan" or n=="kiri" or n == "stop":
        return True
    else:
        return False



# MAIN PROGRAM

peta = [[". " for j in range(10)] for i in range(10)] # inisialisasi peta 10x10

# ATRIBUT
jarakMax= 5
# jarak maksimum kurama dan bunshin dapat menembak/menyerang satu sama lain,
# jarak ini adalah jarak euclidean yang meruapakan panjang garis lurus yang menghubungkan kurama dengan bunshin

damageKurama = 300
damageBunshin = 200
healthKurama = 5000
healthBunshin =1000


#INISIALISASI
x=0 # koordinat awal kurama di titik 0,0
y=0
peta[y][x]= "K " # meletakkan kurama di peta (yang ditampilkan dengan health kurama)
        
bunshin()
jumlah=1

while healthKurama >0 :
    if healthBunshin <= 0:
        peta[b][a]= ". "
        healthBunshin=1000
        bunshin()
        jumlah += 1
    show()
    n = str(input("\nMasukkan perintah : "))
    if isValid():
        if n=="tembak" :
            menembak()
        elif n == "stop":
            break
        else :
            gerak()
        seranganBunshin()
        
    else:
        print("\n--Perintah tidak diketahui--\n")

print("\n --- Jumlah Mecha Kurama yang berhasil dikalahkan : ", jumlah-1)
