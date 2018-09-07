/**
 * Created by foozhan on 6/5/2015.
 */
function recf(){
    mltool = mtool ;
    mtool = 6 ;
    if(mltool != mtool)
        addevents();

}
function rec() {
    (function () {




        /* Drawing on Paint App */
        tmp_ctx.lineWidth = getmsize();
        tmp_ctx.lineJoin = 'round';
        tmp_ctx.lineCap = 'round';
        tmp_ctx.strokeStyle = color;
        tmp_ctx.fillStyle = color;

        tmp_canvas.addEventListener('mousedown',rece1, false);

        tmp_canvas.addEventListener('mouseup',rece2, false);



    }());
}
var recpaint = function () {

    // Tmp canvas is always cleared up before drawing.
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);
    tmp_ctx.lineWidth = getmsize();
    tmp_ctx.strokeStyle = color;
    tmp_ctx.fillStyle = color;

    var x = Math.min(mouse.x, start_mouse.x);
    var y = Math.min(mouse.y, start_mouse.y);
    var width = Math.abs(mouse.x - start_mouse.x);
    var height = Math.abs(mouse.y - start_mouse.y);
    tmp_ctx.strokeRect(x, y, width, height);

};
var rece1 =  function (e) {
    tmp_canvas.addEventListener('mousemove', recpaint, false);

    mouse.x = typeof e.offsetX !== 'undefined' ? e.offsetX : e.layerX;
    mouse.y = typeof e.offsetY !== 'undefined' ? e.offsetY : e.layerY;

    start_mouse.x = mouse.x;
    start_mouse.y = mouse.y;

    recpaint();
}
var rece2 =  function () {
    tmp_canvas.removeEventListener('mousemove', recpaint, false);

    // Writing down to real canvas now
    ctx.drawImage(tmp_canvas, 0, 0);
    // Clearing tmp canvas
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

}