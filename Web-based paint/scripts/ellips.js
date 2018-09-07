/**
 * Created by foozhan on 6/5/2015.
 */

function ellipsf(){
    mltool = mtool ;
    mtool = 8;
    if(mltool != mtool)
        addevents();

}
function ellips() {




    /* Drawing on Paint App */
    tmp_ctx.lineWidth = getmsize();
    tmp_ctx.lineJoin = 'round';
    tmp_ctx.lineCap = 'round';
    tmp_ctx.strokeStyle = getmcolor();
    tmp_ctx.fillStyle = getmcolor();

    tmp_canvas.addEventListener('mousedown',elevent1 , false);

    tmp_canvas.addEventListener('mouseup', elevent2, false);




};

function drawEllipse(ctx, x, y, w, h) {
    var kappa = .5522848,
        ox = (w / 2) * kappa, // control point offset horizontal
        oy = (h / 2) * kappa, // control point offset vertical
        xe = x + w,           // x-end
        ye = y + h,           // y-end
        xm = x + w / 2,       // x-middle
        ym = y + h / 2;       // y-middle
    tmp_ctx.lineWidth = getmsize();
    tmp_ctx.strokeStyle =color;
    tmp_ctx.fillStyle = color;
    ctx.beginPath();
    ctx.moveTo(x, ym);
    ctx.bezierCurveTo(x, ym - oy, xm - ox, y, xm, y);
    ctx.bezierCurveTo(xm + ox, y, xe, ym - oy, xe, ym);
    ctx.bezierCurveTo(xe, ym + oy, xm + ox, ye, xm, ye);
    ctx.bezierCurveTo(xm - ox, ye, x, ym + oy, x, ym);
    ctx.closePath();
    ctx.stroke();
}
var elPaint = function() {

    // Tmp canvas is always cleared up before drawing.
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

    var x = Math.min(mouse.x, start_mouse.x);
    var y = Math.min(mouse.y, start_mouse.y);

    var w = Math.abs(mouse.x - start_mouse.x);
    var h = Math.abs(mouse.y - start_mouse.y);

    drawEllipse(tmp_ctx, x, y, w, h);
};
var mo = {x:0 , y:0};
var elevent1 = function(e) {
    tmp_canvas.addEventListener('mousemove', elPaint, false);

    mouse.x = typeof e.offsetX !== 'undefined' ? e.offsetX : e.layerX;
    mouse.y = typeof e.offsetY !== 'undefined' ? e.offsetY : e.layerY;


    if ((mouse.x >= 435 || mouse.x <= 0 || mouse.y >= 335 || mouse.y <= 0)){
       debugger;
      elevent2();

   }

    start_mouse.x = mouse.x;
    start_mouse.y = mouse.y;

    elPaint();
}
var elevent2 = function() {
    tmp_canvas.removeEventListener('mousemove', elPaint, false);

    // Writing down to real canvas now
    ctx.drawImage(tmp_canvas, 0, 0);
    // Clearing tmp canvas
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

}