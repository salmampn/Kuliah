var nama = window.prompt("Nama");
var nilai = window.prompt("Nilai");
alert(cekNilai(nilai));

  function cekNilai(nilai){
    if(nilai > 100 || nilai < 0){
      var nama = window.prompt("Nama");
      var nilai = window.prompt("Nilai");
    }else{
      if (nilai >= 85){
        return "Your Grade is A";
      } else if (nilai >= 80){
        return "Your Grade is A-";
      } else if (nilai >= 75) {
        return "Your Grade is B+";
      } else if (nilai >= 70){
        return "Your Grade is B";
      } else if (nilai >= 65) {
        return "Your Grade is B-";
      } else if (nilai >= 60){
        return "Your Grade is C+";
      } else if (nilai >= 55){
        return "Your Grade is C";
      } else if (nilai >= 45) {
        return "Your Grade is D";
      }else if(nilai < 45){
        return "You failed";
      }
    }
  }