/**
 * Created by foozhan on 6/4/2015.
 */
var sprayIntervalID;
function sprayf(){
    mltool = mtool ;
    mtool = 4;
    if(mltool != mtool)
        addevents();

}

function spray() {
    (function () {





        /* Drawing on Paint App */
        tmp_ctx.lineWidth = getmsize();
        tmp_ctx.lineJoin = 'round';
        tmp_ctx.lineCap = 'round';
        tmp_ctx.strokeStyle = color;
        tmp_ctx.fillStyle = color;

        tmp_canvas.addEventListener('mousedown',sevent1, false);

        tmp_canvas.addEventListener('mouseup',sevent2 , false);




    }());
}


var sevent1 = function(e){

        tmp_canvas.addEventListener('mousemove', sPaint, false);

        mouse.x = typeof e.offsetX !== 'undefined' ? e.offsetX : e.layerX;
        mouse.y = typeof e.offsetY !== 'undefined' ? e.offsetY : e.layerY;

        start_mouse.x = mouse.x;
        start_mouse.y = mouse.y;

    sPaint();
        sprayIntervalID = setInterval(sPaint, 50);
    }
var sevent2 = function (){

        tmp_canvas.removeEventListener('mousemove', sPaint, false);

        // Writing down to real canvas now
        ctx.drawImage(tmp_canvas, 0, 0);
        // Clearing tmp canvas
        tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

        clearInterval(sprayIntervalID);

}
var sPaint = function () {

    // Tmp canvas is always cleared up before drawing.
    // tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

    var x = mouse.x;
    var y = mouse.y;

    generateSprayParticles();
};


var getRandomOffset = function (radius) {

    var random_angle = Math.random() * (2 * Math.PI);
    var random_radius = Math.random() * radius;

    // console.log(random_angle, random_radius, Math.cos(random_angle), Math.sin(random_angle));

    return {
        x: Math.cos(random_angle) * random_radius,
        y: Math.sin(random_angle) * random_radius
    };
};

var generateSprayParticles = function () {
    // Particle count, or, density
    var density = 50;

    for (var i = 0; i < density; i++) {
        var offset = getRandomOffset(getmsize());

        var x = mouse.x + offset.x;
        var y = mouse.y + offset.y;
        tmp_ctx.strokeStyle = color;
        tmp_ctx.fillStyle = color;
        tmp_ctx.fillRect(x, y, 1, 1);
    }
};
