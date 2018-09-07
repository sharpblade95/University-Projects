/**
 * Created by foozhan on 6/5/2015.
 */


function load_but(){
    var in_url = document.getElementById('u_in');
    //document.getElementById('tes').innerHTML = in_url.value;
     var button = document.getElementById('u_bt');

        loadImageURL(ctx, in_url.value);
        in_url.value = "";



}

function loadImageURL(cx , url) {
   var image = document.createElement("img");
    image.src = url;
   image.addEventListener("load", function() {
       var color = cx.fillStyle;
       cx.drawImage(image, 0 , 0 ,cx.canvas.width,cx.canvas.height );
       cx.fillStyle = color;
       cx.strokeStyle = color;
       cx.lineWidth = getmsize();

    });



}

function uploadf(){

    var but = document.getElementById('up_but');
    var input = document.getElementById('upload');


        if (input.files.length == 0) return;
        var reader = new FileReader();
        reader.addEventListener("load", function() {
            loadImageURL(ctx, reader.result);
        });
        reader.readAsDataURL(input.files[0]);


}

