// Sender Message
$("#btnTeman").click(function buttonTeman(){
		nama = $("#namaTeman").val();
		pesan = $("#pesanTeman").val();
		
		//Isi Pesan
		var boxPesan = $("<div/>", {
			id: "boxPesanTeman",
		});
		var isiPesan = $("<div/>", {
			class: "container",
			id : "isiPesanTeman",
		}).appendTo(boxPesan);
		var nameValue = $("<span/>", {
			class: "fw-bold",
		}).text(nama).appendTo(isiPesan);
		var br = $("<br/>").appendTo(isiPesan);
		var pesanValue = $("<p/>", {
			id: "kotakPesan",
		}).text(pesan).appendTo(isiPesan);

		$("#chatBox").append(boxPesan);
		$("#namaTeman").val("");
		$("#pesanTeman").val("");
});

// My message
$("#btnSaya").click(function buttonSaya(){
	var you = "you";
	nama = $("#namaSaya").val();
	pesan = $("#pesanSaya").val();

		// Isi Pesan
		var boxPesan = $("<div/>", {
			id: "boxPesanSaya",
			class: "text-end",
		});
		var isiPesan = $("<div/>", {
			id: "isiPesanSaya",
			class: "container",
		}).appendTo(boxPesan);
		var nameValue = $("<span/>", {
			class: "fw-bold",
		}).text(nama).appendTo(isiPesan);
		var br = $("<br/>").appendTo(isiPesan);
		var pesanValue = $("<p/>", {
			id: "kotakPesan",
		}).text(pesan).appendTo(isiPesan);

		$("#chatBox").append(boxPesan);
		$("#pesanSaya").val("");
});