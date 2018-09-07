/**
 * Created by foozhan on 6/5/2015.
 */

function textf(){
    mltool = mtool ;
    mtool = 7 ;
    if(mltool != mtool)
        addevents();

}

var textarea = document.createElement('textarea');
textarea.id = 'text_tool';
sketch.appendChild(textarea);

var tmp_txt_ctn = document.createElement('div');

tmp_txt_ctn.style.display = 'none';
sketch.appendChild(tmp_txt_ctn);

//

var width = tmp_txt_ctn.offsetWidth;
var height = tmp_txt_ctn.offsetHeight;


function text () {

    (function () {




// Text tool's text container for calculating
// lines/chars







        /* Drawing on Paint App */
        tmp_ctx.lineWidth = getmsize();
        tmp_ctx.lineJoin = 'round';
        tmp_ctx.lineCap = 'round';
        tmp_ctx.strokeStyle = color;
        tmp_ctx.fillStyle = color;

        tmp_canvas.addEventListener('mousedown', tevent1, false);

        textarea.addEventListener('mouseup',mtevents, false);



    }());
}
var tpaint = function () {

    // Tmp canvas is always cleared up before drawing.
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

    var x = Math.min(mouse.x, start_mouse.x);
    var y = Math.min(mouse.y, start_mouse.y);
    var width = Math.abs(mouse.x - start_mouse.x);
    var height = Math.abs(mouse.y - start_mouse.y);
    var ta_comp_style = getComputedStyle(tmp_canvas);

    textarea.style.left = x +parseInt(ta_comp_style.getPropertyValue('left'))+ 'px' ;
    textarea.style.top = y +parseInt(ta_comp_style.getPropertyValue('left'))+ 'px' ;
    textarea.style.width = width + 'px';
    textarea.style.height = height + 'px';

    textarea.style.display = 'block';
};
var tevent1 = function (e) {
    tmp_canvas.addEventListener('mousemove', tpaint, false);

    mouse.x = typeof e.offsetX !== 'undefined' ? e.offsetX : e.layerX;
    mouse.y = typeof e.offsetY !== 'undefined' ? e.offsetY : e.layerY;

    start_mouse.x = mouse.x;
    start_mouse.y = mouse.y;

    tpaint();

    // sprayIntervalID = setInterval(onPaint, 50);
};
var tevent2 = function () {

    tmp_canvas.removeEventListener('mousemove', tpaint, false);

    var lines = textarea.value.split('\n');
    var processed_lines = [];

    for (var i = 0; i < lines.length; i++) {
        var chars = lines[i].length;

        for (var j = 0; j < chars; j++) {
            var text_node = document.createTextNode(lines[i][j]);
            tmp_txt_ctn.appendChild(text_node);

            // Since tmp_txt_ctn is not taking any space
            // in layout due to display: none, we gotta
            // make it take some space, while keeping it
            // hidden/invisible and then get dimensions
            tmp_txt_ctn.style.position = 'absolute';
            tmp_txt_ctn.style.visibility = 'hidden';
            tmp_txt_ctn.style.display = 'block';


            tmp_txt_ctn.style.position = '';
            tmp_txt_ctn.style.visibility = '';
            tmp_txt_ctn.style.display = 'none';

            // Logix
            // console.log(width, parseInt(textarea.style.width));
            if (width > parseInt(textarea.style.width)) {
                break;
            }
        }

        processed_lines.push(tmp_txt_ctn.textContent);
        tmp_txt_ctn.innerHTML = '';
    }

    var ta_comp_style = getComputedStyle(textarea);
   var fs = getmsize();
    var ff = ta_comp_style.getPropertyValue('font-family');

    tmp_ctx.color = color;
    tmp_ctx.font = fs + ' ' + ff;
    tmp_ctx.textBaseline = 'top';

    for (var n = 0; n < processed_lines.length; n++) {
        var processed_line = processed_lines[n];

        tmp_ctx.fillText(
            processed_line,
            parseInt(textarea.style.left),
            parseInt(textarea.style.top) + n * parseInt(fs)
        );
    }
    //tmp_txt_ctn.style.border = 'none';
    // Writing down to real canvas now

    ctx.drawImage(tmp_canvas, 0, 0);


    // Clearing tmp canvas
    tmp_ctx.clearRect(0, 0, tmp_canvas.width, tmp_canvas.height);

    // clearInterval(sprayIntervalID);
    textarea.style.display = 'none';
    textarea.value = '';
    textarea.removeEventListener('mousedown',tevent2 , false);
    tmp_canvas.addEventListener('mousedown', tevent1, false);
};

var mtevents =function() {
    tmp_canvas.removeEventListener('mousedown', tevent1, false);
    tmp_canvas.removeEventListener('mousemove', tpaint, false);
    tmp_canvas.addEventListener('mousedown', tevent2, false);
}