/**
 * Created by foozhan on 6/5/2015.
 */
var picker = document.getElementById('inColor');
var comp_p = getComputedStyle(picker);
function getmcolor(){
    return picker.value;
}
picker.addEventListener('change' , function(){
    color = getmcolor();
        } , false)

function cloudf(){
   color = 'azure';

}
function purplef(){
    color = 'purple';
}
function yellowf(){
 color = 'yellow';
}
function bluef(){
    color = 'blue';
}
function greenf(){
    color = 'green';
}
function blackf(){
    color = 'black';
}
function redf(){
    color = 'red';
}