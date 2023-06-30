senin = prompt("Masukkan Kehadiran Mahasiswa di Hari Senin: ");
selasa = prompt("Masukkan Kehadiran Mahasiswa di Hari Selasa: ");
rabu = prompt("Masukkan Kehadiran Mahasiswa di Hari Rabu: ");
kamis = prompt("Masukkan Kehadiran Mahasiswa di Hari Kamis: ");
jumat = prompt("Masukkan Kehadiran Mahasiswa di Hari Jumat: ");

  function kehadiran(hari, jumlah){
    document.write(hari);
    for(j = 1; j <= jumlah; j++){
      document.write("X");
    }
    document.write("<br>");
  }

document.write("<b>GRAFIK JUMLAH KEHADIRAN MAHASISWA</b><br><br>");
kehadiran("Senin: ", senin);
kehadiran("Selasa: ", selasa);
kehadiran("Rabu: ", rabu);
kehadiran("Kamis: ", kamis);
kehadiran("Jumat: ", jumat);