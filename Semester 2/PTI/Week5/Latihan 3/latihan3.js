var jam = prompt("Jam Sekarang: ");
var salam;

    if (jam >= 6 && jam <= 10) {
        salam = "Selamat Pagi";
    } else if (jam >= 11 && jam <= 14) {
        salam = "Selamat Siang";
    } else if (jam >= 15 && jam <= 17) {
        salam = "Selamat Sore";
    } else if (jam >= 18 && jam <= 22) {
        salam = "Selamat Malam";
    } else {
        salam = "Selamat Tidur";
    }

document.write(salam);