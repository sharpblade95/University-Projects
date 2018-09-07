/**
 * Created by foozhan on 6/5/2015.
 */


function savef() {

    var dataURL = canvas.toDataURL();
    var link = document.getElementById('dl-but');
    link.href = dataURL;
}