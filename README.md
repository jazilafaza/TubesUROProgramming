# TubesUROProgramming
Kelompok 1: Jazila Faza Aliyya Nurfauzi (16521199), Muhammad Rizky Sya'ban (16521383), Adriel Tohonan Simamora (16521391), Muhammad Afief Abdurrahman (16021257)

Cara menjalankan program (python):
1. Pada keadaan awal program akan menampilkan sebuah peta dengan luas 10 x 10 berbentuk matrix yang bertindak
sebagai arena perang. Robot akan ditempatkan pada titik (0,0) dan Mecha-Kurama akan muncul pada koordinat sembarang didalam jangkauan 10x10, tetapi tidak dititik yang tepat dengan robot
2. Robot memiliki atribut health sebesar 5000 poin dengan damage sebesar 300 poin dan Mecha-Kurama memiliki atribut health sebesar 1000 poin dengan damage sebesar 200 poin
3. Program akan menampilkan jarak antara robot dengan Mecha-Kurama
4. Program akan meminta masukan input yang akan menjadi perintah bagi robot dengan fungsi sebagai berikut:
   a. tembak
   b. atas
   c. bawah
   d. kanan
   e. kiri
   f. stop
5. Jika user memilih input tembak maka robot dan Mecha-Kurama akan saling menyerang dan mengurangi health yang dimiliki masing-masing. Robot hanya dapat menyerang Mecha-Kurama dalam jarak yang ditentukan. Jika jarak robot dengan Mecha-Kurama terlalu jauh akan muncul pesan "Kurama melewati batas arena!". Mecha-Kurama tidak dapat berpindah posisi tetapi dapat muncul di koordinat yang berbeda jika healtnya mencapai 0 point.
6. Jika user memilih input atas, bawah, kanan, atau kiri maka robot akan bergerak satu satuan mengikuti perintah yang dimasukkan.
7. Program akan berhenti jika health robot 0 point atau saat user memilih input stop dan program akan menyatakan banyaknya Mecha-Kurama yang terbunuh.

Cara menjalankan program (c++):
1. Pada keadaan awal program akan menampilkan sebuah peta dengan luas 15 x 15 yang bertindak sebagai arena perang. Robot akan ditempatkan pada titik (0,0) dan bunshin Mecha-Kurama akan muncul pada koordinat sembarang didalam jangkauan 15x15, tetapi tidak dititik yang tepat dengan robot
2. Robot memiliki atribut health sebesar 5000 poin dengan damage sebesar 300 poin dan bunshin Mecha-Kurama memiliki atribut health sebesar 1000 poin dengan damage sebesar 200 poin
3. Program akan menampilkan jarak antara robot dengan bunshin Mecha-Kurama
4. Program akan meminta masukan input yang akan menjadi perintah bagi robot dengan fungsi sebagai berikut:
   a. tembak
   b. atas
   c. bawah
   d. kanan
   e. kiri
   f. stop
5. Jika user memilih input tembak maka robot dan bunshin Mecha-Kurama akan saling menyerang dan mengurangi health yang dimiliki masing-masing. Robot hanya dapat menyerang bunshin Mecha-Kurama dalam jarak yang ditentukan (max jarak 8 satuan). Jika jarak robot dengan bunshin Mecha-Kurama terlalu jauh akan muncul pesan "Robot mencapai batas luar Desa URO!". Bunshin Mecha-Kurama tidak dapat berpindah posisi tetapi dapat muncul di koordinat yang berbeda jika healtnya mencapai 0 point.
6. Jika user memilih input atas, bawah, kanan, atau kiri maka robot akan bergerak satu satuan mengikuti perintah yang dimasukkan.Jika robot berada di koordinat yang sama dengan bunshin Mecha-Kurama akan muncul pesan "Robot menabrak Bunshin! saatnya menyerang! saatnya menyerang!".
7. Jika masukan user tidak terdefinisi akan muncul pesan "Perintah tidak dikenali!"
8. Program akan berhenti jika health robot 0 point atau saat user memilih input stop dan program akan menyatakan banyaknya bunshin Mecha-Kurama yang terbunuh.

Link GitHub : https://github.com/jazilafaza/TubesUROProgramming
