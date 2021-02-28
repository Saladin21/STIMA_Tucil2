Penyusunan Rencana Kuliah dengan Topological Sort 
(Penerapan Decrease and Conquer)
Program ini akan menyusun rencana kuliah berdasarkan data mata kuliah
dan prerequisitenya. Penyusunan dilakukan dengan topological sort yang
merupakan salah satu penerapan dari pendekatan decrease and conquer.
Algoritma program ini akan mengubah data yang ada ke dalam bentuk Directed
Acyclic Graf. Kemudian topological sort dilakukan dengan mengambil lalu menghapus
semua node yang memiliki derajat masuk 0. Hal ini terus dilakukan sampai graf menjadi kosong
atau terjadi 8 iterasi yang menandakan batas maksimal semester.

Program ini dibuild untuk dijalankan pada operating system windows.

Cara menggunakan program:
1. simpan file yang akan ditest dalam folder test. isi file harus dalam format:
    C1, C3.
    C2, C1, C4.
    C3.
    C4, C1, C3.
    C5, C2, C4.
2. Jalankan program 13519187 yang terdapat dalam folder bin.
3. Ketikkan nama file yang telah disimpan dalam folder test.

Program ini dibuat oleh:
Ahmad Saladin - 13519187 - K04