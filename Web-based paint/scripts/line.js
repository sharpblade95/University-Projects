/**
 * Created by foozhan on 6/4/2015.
 */
var ppts = [];
var start_mouse = {x: 0, y: 0};
function linerf(){
    mltool = mtool ;
    mtool = 2 ;
    if(mltool != mtool)
        addevents();

}
function liner() {
    (function () {





        /* Mouse Capturing Work */


        /* Drawing on Paint App */
        tmp_ctx.lineWidth = getmsize();
        tmp_ctx.lineJoin = 'round';
        tmp_ctx.lineCap = 'round';
        tmp_ctx.strokeStyle = color;
        tmp_ctx.fillStyle = color;

        tmp_canvas.addEventListener('mousedown', linerevent1, false);

        tmp_canvas.addEventListener('mouseup', linerevent2, false);




    }());
}

var linerpaint = function () {

    // Tmp canvas is always cleared up before drawing.
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);
    tmp_ctx.lineWidth = getmsize();
    tmp_ctx.strokeStyle = color;
    tmp_ctx.fillStyle = color;
    tmp_ctx.beginPath();
    tmp_ctx.moveTo(start_mouse.x, start_mouse.y);
    tmp_ctx.lineTo(mouse.x, mouse.y);
    tmp_ctx.stroke();
    tmp_ctx.closePath();

};
var linerevent1 = function (e) {
    tmp_canvas.addEventListener('mousemove', linerpaint, false);

    mouse.x = typeof e.offsetX !== 'undefined' ? e.offsetX : e.layerX;
    mouse.y = typeof e.offsetY !== 'undefined' ? e.offsetY : e.layerY;

    start_mouse.x = mouse.x;
    start_mouse.y = mouse.y;
    //if (mouse.x < 80 || mouse.x> 515 || mouse.y<80 || mouse.y>415)
    //    linerevent2();

    linerpaint();
}
var linerevent2 =  function () {
    tmp_canvas.removeEventListener('mousemove', linerpaint, false);

    // Writing down to real canvas now
    ctx.drawImage(tmp_canvas, 0, 0);
    // Clearing tmp canvas
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

}