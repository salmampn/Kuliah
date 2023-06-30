rumus = window.prompt("Hitung Luas / Keliling?");

  while (rumus !== "luas" && rumus !== "keliling"){
    rumus = window.prompt("Hitung Luas / Keliling");
  }

lebar = window.prompt("Lebar: ");
panjang = window.prompt("Panjang: ");
        
  if (rumus == "luas") {
    luas = panjang*lebar;
    alert("Luas bangun datar: " + luas);
  } 
  else if (rumus == "keliling") {
    keliling = 2*panjang + 2*lebar;
    alert("Keliling bangun datar: " + keliling);
  }