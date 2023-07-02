var jumlahMhs = window.prompt("Jumlah");

  for (var i = 1; i <= jumlahMhs; i++){
    var nama = window.prompt('Nama');
    var uts = window.prompt('UTS');
    var uas = window.prompt('UAS');
    var tugas = window.prompt('Tugas');
    computeNilai(uts, uas, tugas);

    document.write("<br><br>" + i + "." + nama + "<br>");
    document.write("Tugas: " + tugas);
    document.write("<br>UTS: " + uts);
    document.write("<br>UAS: " + uas);
    document.write("<br>Nilai Akhir: " + nilaiAkhir);
    document.write("<br>Grade: " + cekNilai(nilaiAkhir));
  }
    
  function computeNilai(uts, uas, tugas) {
    nilaiAkhir = uts * 0.3 + uas * 0.4 + tugas * 0.3;
  }

  function cekNilai(nilai){
      if (nilai >= 85){
        return "A";
      } else if (nilai >= 80){
        return "A-";
      } else if (nilai >= 75) {
        return "B+";
      } else if (nilai >= 70){
        return "B";
      } else if (nilai >= 65) {
        return "B-";
      } else if (nilai >= 60){
        return "C+";
      } else if (nilai >= 55){
        return "C";
      } else if (nilai >= 45) {
        return "D";
      }else if(nilai < 45){
        return "You failed";
      }
  }