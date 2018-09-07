/**
 * Created by foozhan on 6/4/2015.
 */
/**
 * Created by foozhan on 6/4/2015.
 */
function erasef(){
    mltool = mtool ;
    mtool = 3;
    if(mltool != mtool)
        addevents();

}


function eraser(){



    (function() {





        /* Drawing on Paint App */
        tmp_ctx.lineWidth = getmsize();
        ctx.lineJoin = 'miter';
        ctx.lineCap = 'butt';
        tmp_ctx.lineJoin = 'miter';
        tmp_ctx.lineCap = 'butt';
        tmp_ctx.strokeStyle = 'white';
        tmp_ctx.fillStyle = 'white';

        tmp_canvas.addEventListener('mousedown',eevent1, false);

        tmp_canvas.addEventListener('mouseup',eevent2 , false);




    }());

}
var eevent1 =  function(e) {
    tmp_canvas.addEventListener('mousemove', epaint, false);

    mouse.x = typeof e.offsetX !== 'undefined' ? e.offsetX : e.layerX;
    mouse.y = typeof e.offsetY !== 'undefined' ? e.offsetY : e.layerY;

    ppts.push({x: mouse.x, y: mouse.y});

    epaint();
}
var eevent2 = function() {
    tmp_canvas.removeEventListener('mousemove', epaint, false);

    ctx.globalCompositeOperation = 'source-over';

    // Writing down to real canvas now
    ctx.drawImage(tmp_canvas, 0, 0);
    // Clearing tmp canvas
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

    // Emptying up Pencil Points
    ppts = [];
}
var epaint = function() {

    // Saving all the points in an array
    ppts.push({x: mouse.x, y: mouse.y});

    if (ppts.length < 3) {
        var b = ppts[0];
        tmp_ctx.beginPath();
        tmp_ctx.lineWidth = getmsize();
        tmp_ctx.strokeStyle = 'white';
        tmp_ctx.fillStyle = 'white';


        //ctx.moveTo(b.x, b.y);
        //ctx.lineTo(b.x+50, b.y+50);
        tmp_ctx.arc(b.x, b.y, tmp_ctx.lineWidth / 2, 0, Math.PI * 2, !0);
        tmp_ctx.fill();
        tmp_ctx.closePath();

        return;
    }

    // Tmp canvas is always cleared up before drawing.
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

    tmp_ctx.beginPath();
    tmp_ctx.moveTo(ppts[0].x, ppts[0].y);

    for (var i = 1; i < ppts.length - 2; i++) {
        var c = (ppts[i].x + ppts[i + 1].x) / 2;
        var d = (ppts[i].y + ppts[i + 1].y) / 2;

        tmp_ctx.quadraticCurveTo(ppts[i].x, ppts[i].y, c, d);
    }

    // For the last 2 points
    tmp_ctx.quadraticCurveTo(
        ppts[i].x,
        ppts[i].y,
        ppts[i + 1].x,
        ppts[i + 1].y
    );
    tmp_ctx.stroke();


};