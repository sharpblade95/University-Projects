/**
 * Created by foozhan on 7/4/2015.
 */
function squaref(){
    mltool = mtool ;
    mtool = 9 ;
    if(mltool != mtool)
        addevents();

}



function square(){

    tmp_canvas.addEventListener('mousemove', function(e) {
        mouse.x = typeof e.offsetX !== 'undefined' ? e.offsetX : e.layerX;
        mouse.y = typeof e.offsetY !== 'undefined' ? e.offsetY : e.layerY;
    }, false);


    tmp_ctx.lineWidth = getmsize();
    tmp_ctx.lineJoin = 'round';
    tmp_ctx.lineCap = 'round';
    tmp_ctx.strokeStyle = color;
    tmp_ctx.fillStyle = color;

    tmp_canvas.addEventListener('mousedown', square_event1, false);
    tmp_canvas.addEventListener('mouseup', square_event2, false);

}
var square_event1 = function mousedown(e){
    tmp_canvas.addEventListener('mousemove', onCanvas_square, false);

    tmp_ctx.strokeStyle = color;
    tmp_ctx.fillStyle = color;
    tmp_ctx.lineWidth = getmsize();

    mouse.x = typeof e.offsetX !== 'undefined' ? e.offsetX : e.layerX;
    mouse.y = typeof e.offsetY !== 'undefined' ? e.offsetY : e.layerY;

    start_mouse.x = mouse.x;
    start_mouse.y = mouse.y;

    onCanvas_square();
};
var square_event2 = function mouseup(){
    tmp_canvas.removeEventListener('mousemove', onCanvas_square, false);

    ctx.drawImage(tmp_canvas, 0, 0);
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

};
var onCanvas_square = function() {

    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

    var x = Math.min(mouse.x, start_mouse.x);
    var y = Math.min(mouse.y, start_mouse.y);
    var width = Math.abs(mouse.x - start_mouse.x);
    var height = Math.abs(mouse.y - start_mouse.y);
    var length = Math.min(height, width);

    if(width > height && mouse.x < start_mouse.x){
        tmp_ctx.strokeRect(x+(width - height), y, length, length);
    }
    else if(height > width && mouse.y < start_mouse.y){
        tmp_ctx.strokeRect(x, y + (height - width), length, length);
    }
    else{
        tmp_ctx.strokeRect(x, y, length, length);
    }
};
