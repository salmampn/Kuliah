$("#btnClickEv").click(function(){
    $("#clickMsg").text("Button above me is clicked!");
    });

    $("#btnHide").click(function(){
      $("#hideShowMsg").fadeOut();
    });
    $("#btnShow").click(function(){
      $("#hideShowMsg").fadeIn();
    });

    $("#btnGetVal").click(function(){
      val = $("#inputVal").val();
      $("#showVal").text(val);
    });

    $("#btnMelahirkan").click(function(){
      $("#ortu").append("<div style='background: deeppink; margin: 2px;'>Anak</div>");
    });