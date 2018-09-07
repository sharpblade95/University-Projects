/**
 * Created by foozhan on 6/4/2015.
 *
 */
function circlef(){
    mltool = mtool ;
    mtool = 5 ;
    if(mltool != mtool)
        addevents();
}
function circle() {
    (function () {




        /* Drawing on Paint App */
        tmp_ctx.lineWidth = getmsize();
        tmp_ctx.lineJoin = 'round';
        tmp_ctx.lineCap = 'round';
        tmp_ctx.strokeStyle = color;
        tmp_ctx.fillStyle = color;

        tmp_canvas.addEventListener('mousedown', cevent1, false);

        tmp_canvas.addEventListener('mouseup', cevent2, false);


    }());
}
var cPaint = function() {

    // Tmp canvas is always cleared up before drawing.
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);
    tmp_ctx.lineWidth = getmsize();
    tmp_ctx.strokeStyle = color;
    tmp_ctx.fillStyle = color;
    var x = (mouse.x + start_mouse.x) / 2;
    var y = (mouse.y + start_mouse.y) / 2;

    var radius = Math.max(
            Math.abs(mouse.x - start_mouse.x),
            Math.abs(mouse.y - start_mouse.y)
        ) / 2;

    tmp_ctx.beginPath();
    tmp_ctx.arc(x, y, radius, 0, Math.PI*2, false);
    // tmp_ctx.arc(x, y, 5, 0, Math.PI*2, false);
    tmp_ctx.stroke();
    tmp_ctx.closePath();

};
var cevent2 = function() {
    tmp_canvas.removeEventListener('mousemove', cPaint, false);

    // Writing down to real canvas now
    ctx.drawImage(tmp_canvas, 0, 0);
    // Clearing tmp canvas
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

}
var cevent1 = function(e) {
    tmp_canvas.addEventListener('mousemove', cPaint, false);

    mouse.x = typeof e.offsetX !== 'undefined' ? e.offsetX : e.layerX;
    mouse.y = typeof e.offsetY !== 'undefined' ? e.offsetY : e.layerY;

    start_mouse.x = mouse.x;
    start_mouse.y = mouse.y;

    cPaint();
}