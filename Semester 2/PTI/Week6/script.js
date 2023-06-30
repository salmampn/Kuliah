function getJumlah() {
	var jumlah = document.getElementById("jumlah-anggota").value;
	var addTeam = document.getElementById("addTeam");
	while (addTeam.hasChildNodes()) {
		addTeam.removeChild(addTeam.firstChild);
	}

	var judul = document.createElement("h3");
	judul.setAttribute("id", "anggota");
	var textJudul = document.createTextNode("Anggota Kelompok:");
	judul.appendChild(textJudul);
	addTeam.appendChild(judul);

	for (let i = 0; i < jumlah; i++) {
		// Form Element
		var form = document.createElement("div");
		form.setAttribute("class", "form-floating mb-3");
		form.setAttribute("id", "form-kelompok");

		// Node form : Input structure
		var input = document.createElement("input");
		input.setAttribute("type", "text");
		input.setAttribute("class", "form-control");
		input.setAttribute("id", "nama-anggota");
		input.setAttribute("placeholder", "Nama Anggota");

		// Node form: Label 
		var label = document.createElement("label");
		var textLabel = document.createTextNode("Nama Anggota " + (i + 1));
		label.setAttribute("for", "nama-anggota");
		label.appendChild(textLabel);

		// Form structure
		form.appendChild(input);
		form.appendChild(label);

		addTeam.appendChild(form);
	}

	// Button
	var button = document.createElement("button");
	var textButton = document.createTextNode("Daftar Kelompok");
	button.appendChild(textButton);
	button.setAttribute("type", "button");
	button.setAttribute("class", "btn btn-primary");
	addTeam.appendChild(button);
}
