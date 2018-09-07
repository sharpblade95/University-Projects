var size = 1;
var color = "black";
var mtool = 0;
var mltool= 0;
var mouse = {x: 0, y: 0};



var canvas = document.querySelector('#paint');
var ctx = canvas.getContext('2d');

var sketch = document.querySelector('#sketch');
var sketch_style = getComputedStyle(sketch);
canvas.width = parseInt(sketch_style.getPropertyValue('width'));
canvas.height = parseInt(sketch_style.getPropertyValue('height'));



var tmp_canvas = document.createElement('canvas');
var tmp_ctx = tmp_canvas.getContext('2d');
var tmp_ctx_style = getComputedStyle(tmp_canvas);
tmp_canvas.id = 'tmp_canvas';
tmp_canvas.width = canvas.width;
tmp_canvas.height = canvas.height;

sketch.appendChild(tmp_canvas);

tmp_canvas.addEventListener('mousemove', function(e) {
    var m = true;
    mouse.x = typeof e.offsetX !== 'undefined' ? e.offsetX : e.layerX;
    mouse.y = typeof e.offsetY !== 'undefined' ? e.offsetY : e.layerY;

    if ((mouse.x >= 700 || mouse.x <= 10 || mouse.y >= 330 || mouse.y <= 10)){
        ctx.drawImage(tmp_canvas, 0, 0);
        var mlltool = mltool;
        mltool = mtool;
        delevents();
        mltool = mlltool;

        addevents();
    }

}, false);



function getmsize( ){
   var y= document.getElementById("selector");
    return y.value;
}
function setmsize(){
    var y= document.getElementById("selector");
    size= y.value;
}

var eventon = false;


function addevents() {
    eventon = true;
    delevents();
    if (mtool == 1) {
        pen();

    }
   else if (mtool == 2) {
        liner();
        tmp_canvas.style.cursor  = 'crosshair';

    }
   else if (mtool == 3) {
        eraser();
        tmp_canvas.style.cursor = 'cell';

    }
    else if (mtool == 4) {
        spray();
        tmp_canvas.style.cursor  = 'crosshair';
    }
    else if (mtool == 5) {
        circle();
        tmp_canvas.style.cursor  = 'crosshair';

    }
    else if (mtool == 6){


        rec();
        tmp_canvas.style.cursor  = 'crosshair';

    }
    else if (mtool == 7){
        text();
        tmp_canvas.style.cursor  = 'text';
    }
    else if (mtool == 8){
        ellips();
        tmp_canvas.style.cursor  = 'crosshair';
    }
    else if (mtool == 9){
        square();
        tmp_canvas.style.cursor  = 'crosshair';
    }

}



function delevents(){

            if( mltool ==1 ) {
                ctx.drawImage(tmp_canvas, 0, 0);
                tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);
                tmp_canvas.removeEventListener('mousedown',penevent1, false);

                tmp_canvas.removeEventListener('mouseup', penevent2, false);
                tmp_canvas.removeEventListener('mousemove', penpaint, false);
            }
            else if (mltool== 3){
                ctx.drawImage(tmp_canvas, 0, 0);
                tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);
                tmp_canvas.removeEventListener('mousedown',eevent1, false);

                tmp_canvas.removeEventListener('mouseup', eevent2, false);
                tmp_canvas.removeEventListener('mousemove', epaint, false);
            }

          else  if( mltool == 2){
                ctx.drawImage(tmp_canvas, 0, 0);
                tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);
                tmp_canvas.removeEventListener('mousemove', linerpaint, false);

                tmp_canvas.removeEventListener('mousedown',linerevent1 , false);

                tmp_canvas.removeEventListener('mouseup',linerevent2, false);
            }
          else  if(mltool == 4){
                ctx.drawImage(tmp_canvas, 0, 0);
                tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);
                clearInterval(sprayIntervalID);
                tmp_canvas.removeEventListener('mousemove', sPaint, false);
                tmp_canvas.removeEventListener('mousedown',sevent1, false);
                tmp_canvas.removeEventListener('mouseup',sevent2 , false);

            }
           else if (mltool == 5){
                ctx.drawImage(tmp_canvas, 0, 0);
                tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);
                tmp_canvas.removeEventListener('mousemove', cPaint, false);
                tmp_canvas.removeEventListener('mousedown', cevent1, false);

                tmp_canvas.removeEventListener('mouseup', cevent2, false);
            }
    else if(mltool == 6){
                ctx.drawImage(tmp_canvas, 0, 0);
                tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);
                tmp_canvas.removeEventListener('mousemove', recpaint, false);
                tmp_canvas.removeEventListener('mousedown',rece1, false);

                tmp_canvas.removeEventListener('mouseup',rece2, false);
            }
    else if(mltool == 7){
                ctx.drawImage(tmp_canvas, 0, 0);

              //  tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);
                tmp_canvas.removeEventListener('mousedown', tevent1, false);

                tmp_canvas.removeEventListener('mouseup',tevent2 , false);
            }
    else if (mltool== 8){
                tmp_canvas.removeEventListener('mousemove', elPaint, false);
                tmp_canvas.removeEventListener('mousedown',elevent1 , false);

                tmp_canvas.removeEventListener('mouseup', elevent2, false);
            }
            else if (mltool== 9){
                tmp_canvas.removeEventListener('mousemove', onCanvas_square, false);
                tmp_canvas.removeEventListener('mousedown',square_event1 , false);

                tmp_canvas.removeEventListener('mouseup', square_event2, false);
            }
}



function clearf(){
    ctx.clearRect(0,0,canvas.width,canvas.height);
    delevents();
}