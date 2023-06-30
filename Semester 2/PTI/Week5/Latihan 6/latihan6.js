batas = window.prompt("Masukkan batas akhir: ");

  for(i = 2; i <= batas; i++){
    prima = 1;
    for(j = 2; j < i; j++){
      if (i%j === 0) {
        prima = 0;
      } 
    }
    if (i > 1 && prima == 1){
      document.write(i + "<br>");
    }
  }