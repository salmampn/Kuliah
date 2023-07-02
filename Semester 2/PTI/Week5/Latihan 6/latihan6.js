var batas = window.prompt("Masukkan batas akhir: ");

  for(var i = 2; i <= batas; i++){
    var prima = 1;
    for(var j = 2; j < i; j++){
      if (i%j === 0) {
        prima = 0;
      } 
    }
    if (i > 1 && prima == 1){
      document.write(i + "<br>");
    }
  }