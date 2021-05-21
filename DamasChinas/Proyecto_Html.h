#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);
String s = "";
String pagina = "";
int inicial[4][6] = {{0,1,2,8,9,16},{5,6,7,14,15,23},{47,54,55,61,62,63},{40,48,49,56,57,58}};
char colorido [4][10] = {{"Rojo"}, {"Azul"}, {"Verde"}, {"Amarillo"}};
void string1(){
  s = "";
  s += "<style>@import url('https://fonts.googleapis.com/css?family=Montserrat:400,600&display=swap');* {box-sizing: border-box;margin: 0;padding: 0;}body {align-items: center;background: #D8AA96;";
s += " color: rgba(0, 0, 0, 0.8);display: grid;font-family: 'Montserrat', sans-serif;font-size: 14px;font-weight: 400;height: 100vh;justify-items: center;";
s +=" weight: 100vw;}.signup-container {display: grid;grid-template-areas: 'left right';max-width: 900px;}.left-container {background: #807182;overflow: hidden;padding: 40px 0 0 0;";
 s +=" position: relative;text-align: center;width: 300px;}.left-container h1 {color: rgba(0, 0, 0, 0.8);display: inline-block;font-size: 24px;}.left-container h1 i {background: #F7B1AB;";
 s +=" border-radius: 50%;color: #807182;font-size: 24px;margin-right: 5px;padding: 10px;transform: rotate(-45deg);}.left-container .puppy {bottom: -5px;position: absolute;text-align: center;}";
s +=".left-container .puppy:before {background: #807182;content: '';height: 100%;left: 0;opacity: 0.4;position: absolute;width: 100%;z-index: 1;}.left-container img {filter: sepia(100%);";
s += "  width: 70%;}.right-container {background: #f9c7c2;display: grid;grid-template-areas: '.' '.';width: 500px;}.right-container h1:nth-of-type(1) {color: rgba(0, 0, 0, 0.8);font-size: 28px;";
s += "  font-weight: 600;}.right-container .set {display: flex;justify-content: space-between;margin: 10px 0;}.right-container input {border: 1px solid rgba(0, 0, 0, 0.1);border-radius: 4px;height: 38px;";
s += "  line-height: 38px;padding-left: 5px;}.right-container input, .right-container label {color: rgba(0, 0, 0, 0.8);}.right-container header {padding: 40px;}";
s += ".right-container label, .right-container input, .right-container .pets-photo {width: 176px;}.right-container .pets-photo {align-items: center;display: grid;grid-template-areas: '. .';}";
s += " .right-container .pets-photo button {border: none;border-radius: 50%;height: 38px;margin-right: 10px;outline: none;width: 38px;}.right-container .pets-photo button i {";
s += "  color: rgba(0, 0, 0, 0.8);font-size: 16px;}.right-container .pets-weight .radio-container {display: flex;justify-content: space-between;width: 100%;}.right-container footer {align-items: center;";
s += "  background: #fff;display: grid;padding: 5px 40px;}.right-container footer button {border: 1px solid rgba(0, 0, 0, 0.2);height: 38px;line-height: 38px;width: 100px;border-radius: 19px;";
s += "  font-family: 'Montserrat', sans-serif;}.right-container footer #back {background: #fff;transition: 0.2s all ease-in-out;}.right-container footer #back:hover {background: #171A2B;color: white;}";
s += " .right-container footer #next {background: #807182;border: 1px solid transparent;color: #fff;}.right-container footer #next:hover {background: #171A2B;}";
s += " .pets-name label, .pets-breed label, .pets-birthday label, .pets-gender label, .pets-spayed-neutered label, .pets-weight label {display: block;margin-bottom: 5px;}.radio-container {";
s += "  background: #fff;border: 1px solid rgba(0, 0, 0, 0.1);border-radius: 4px;display: inline-block;padding: 5px;}.radio-container label {background: transparent; ";
s += "  border: 1px solid transparent;border-radius: 2px;display: inline-block;height: 26px;line-height: 26px;margin: 0;padding: 0;text-align: center;transition: 0.2s all ease-in-out;width: 80px;}";
s += ".radio-container input[type=radio] {display: none;}.radio-container input[type=radio]:checked + label {background: #F7B1AB;border: 1px solid rgba(0, 0, 0, 0.1);}</style><div class='signup-container'>";
s += " <img src='https://images-na.ssl-images-amazon.com/images/I/61hZYkvsVPL.__AC_SY300_QL70_ML2_.jpg'><div class='right-container'><header><h1>Bienvenidos a Damas chinas!</h1><div class='set'>";
s += "<div class='pets-weight'><label for='pet-weight-0-25'>Cantidad de jugadores</label><div class='radio-container'><form action='/inicio'>";
s += "<input checked='' id='pet-weight-0-25' name='jugadors' type='radio' value='1'><label for='pet-weight-0-25'>1</label><input id='pet-weight-25-50' name='jugadors' type='radio' value='2'>";
s += "<label for='pet-weight-25-50'>2</label><input id='pet-weight-50-100' name='jugadors' type='radio' value='3'><label for='pet-weight-50-100'>3</label>";
 s += "<input id='pet-weight-100-plus' name='jugadors' type='radio' value='4'><label for='pet-weight-100-plus'>4</label></div></div></header><footer><div class='set'>";
 s += "<button type='submit' id='next'>Next</button></div></form></footer></div></div>";
 delay(10);
 server.send(200, "text/html", s);}

void string2(){
  s = "";
s += "<!DOCTYPE html><html><style>body, html {height: 100%;margin: 0;}.bgimg {";
s+=  "background-image: url('https://media.istockphoto.com/photos/dark-scary-night-forest-shot-with-mysterious-light-picture-id458804617?k=6&m=458804617&s=612x612&w=0&h=rz0PsGUhTI3TAoQj5rSurKNRhE3ykIp_BOIVXFqb9B4=');";
s += "height: 100%;background-position: center;background-size: cover;position: relative;color: white;font-family: 'Courier New', Courier, monospace;font-size: 25px;}.topleft {position: absolute;top: 0;";
s += "left: 16px;}.bottomleft {position: absolute;bottom: 0;left: 16px;}.middle {position: absolute;top: 50%;left: 50%;transform: translate(-50%, -50%);text-align: center;}hr {margin: auto;width: 40%;";
s += "}.button {background-color: #4CAF50;border: none;color: white;padding: 15px 32px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;margin: 4px 2px;cursor: pointer;}";
s += ".button4 {background-color: #FFFFFF; color: black;}</style><body><div class='bgimg'><div class='topleft'></div><div class='middle'><h1>Listo?</h1><hr><form action='/partida'>";
s += "<button type='submit' class='button button4'>Comenzar</button></div><div class='bottomleft'></div></div></form></body></html>";
delay(10);
server.send(200, "text/html", s);}

void string3(int jugador, String lugar){
  s = "";
s += " <style>html {-webkit-font-smoothing: antialiased;}body {background-image: url('https://ak.picdn.net/shutterstock/videos/16521136/thumb/1.jpg');height: 100%;background-position: center;background-size: cover;";
s += "font-family: 'Titillium Web', sans-serif;}@media screen and (min-width: 40em) {body {font-size: 1.25em;}}.form .button, .form .message, .customSelect, .form .select, .form .textarea, .form .text-input, .form .option-input + label, .form .checkbox-input + label, .form .label {";
s += "padding: 0.75em 1em;-webkit-appearance: none;-moz-appearance: none;appearance: none;outline: none;line-height: normal;border-radius: 0;border: none;background: none;display: block;}.form .label {";
s += "font-weight: bold;color: white;padding-top: 0;padding-left: 0;letter-spacing: 0.025em;font-size: 1.125em;line-height: 1.25;position: relative;z-index: 100;}.required .form .label:after, .form .required .label:after {";
s += "content: ' *';color: #E8474C;font-weight: normal;font-size: 0.75em;vertical-align: top;}.customSelect, .form .select, .form .textarea, .form .text-input, .form .option-input + label, .form .checkbox-input + label {";
s += "font: inherit;line-height: normal;width: 100%;box-sizing: border-box;background: #222222;color: white;position: relative;}.customSelect:placeholder, .form .select:placeholder, .form .textarea:placeholder, .form .text-input:placeholder, .form .option-input + label:placeholder, .form .checkbox-input + label:placeholder {";
s += "color: white;}";
s += ".customSelect:-webkit-autofill, .form .select:-webkit-autofill, .form .textarea:-webkit-autofill, .form .text-input:-webkit-autofill, .form .option-input + label:-webkit-autofill, .form .checkbox-input + label:-webkit-autofill {";
s += "  box-shadow: 0 0 0px 1000px #111111 inset;-webkit-text-fill-color: white;border-top-color: #111111;border-left-color: #111111;border-right-color: #111111;}";
s += ".customSelect:not(:focus):not(:active).error, .form .select:not(:focus):not(:active).error, .form .textarea:not(:focus):not(:active).error, .form .text-input:not(:focus):not(:active).error, .form .option-input + label:not(:focus):not(:active).error, .form .checkbox-input + label:not(:focus):not(:active).error, .error .customSelect:not(:focus):not(:active), .error .form .select:not(:focus):not(:active), .form .error .select:not(:focus):not(:active), .error .form .textarea:not(:focus):not(:active), .form .error .textarea:not(:focus):not(:active), .error .form .text-input:not(:focus):not(:active), .form .error .text-input:not(:focus):not(:active), .error .form .option-input + label:not(:focus):not(:active), .form .error .option-input + label:not(:focus):not(:active), .error .form .checkbox-input + label:not(:focus):not(:active), .form .error .checkbox-input + label:not(:focus):not(:active) {";
s += "  background-size: 8px 8px;background-image: linear-gradient(135deg, rgba(232, 71, 76, 0.5), rgba(232, 71, 76, 0.5) 25%, transparent 25%, transparent 50%, rgba(232, 71, 76, 0.5) 50%, rgba(232, 71, 76, 0.5) 75%, transparent 75%, transparent);";
s += "background-repeat: repeat;}";
s += ".form:not(.has-magic-focus) .customSelect.customSelectFocus, .form:not(.has-magic-focus) .customSelect:active, .form:not(.has-magic-focus) .select:active, .form:not(.has-magic-focus) .textarea:active, .form:not(.has-magic-focus) .text-input:active, .form:not(.has-magic-focus) .option-input + label:active, .form:not(.has-magic-focus) .checkbox-input + label:active, .form:not(.has-magic-focus) .customSelect:focus, .form:not(.has-magic-focus) .select:focus, .form:not(.has-magic-focus) .textarea:focus, .form:not(.has-magic-focus) .text-input:focus, .form:not(.has-magic-focus) .option-input + label:focus, .form:not(.has-magic-focus) .checkbox-input + label:focus {";
s += "background: #4E4E4E;}.form .option-input, .form .checkbox-input {border: 0;clip: rect(0 0 0 0);height: 1px;margin: -1px;overflow: hidden;padding: 0;position: absolute;width: 1px;}.form .option-input + label, .form .checkbox-input + label {";
s += "display: inline-block;width: auto;color: #4E4E4E;position: relative;-webkit-user-select: none;-moz-user-select: none;-ms-user-select: none;user-select: none;cursor: pointer;}";
s += ".form .option-input:focus + label, .form .checkbox-input:focus + label, .form .option-input:active + label, .form .checkbox-input:active + label {color: #4E4E4E;}.form .option-input:checked + label, .form .checkbox-input:checked + label {";
s += "color: white;}.form .button {font: inherit;line-height: normal;cursor: pointer;background: #E8474C;color: white;font-weight: bold;width: auto;margin-left: auto;font-weight: bold;padding-left: 2em;";
s += "padding-right: 2em;}.form .button:hover, .form .button:focus, .form .button:active {color: white;border-color: white;}.form .button:active {position: relative;top: 1px;left: 1px;}body {padding: 2em;}";
s += ".form { max-width: 40em;margin: 0 auto;position: relative;display: flex;flex-flow: row wrap;justify-content: space-between;align-items: flex-end;}.form .field {width: 100%;margin: 0 0 1.5em 0;}";
s += "@media screen and (min-width: 40em) {.form .field.half {width: calc(50% - 1px);}}.form .field.last {margin-left: auto;}.form .textarea {max-width: 100%;}.form .select {text-indent: 0.01px;text-overflow: '' !important;";
s += "}.form .select::-ms-expand {display: none;}.form .checkboxes, .form .options {padding: 0;margin: 0;list-style-type: none;overflow: hidden;}.form .checkbox, .form .option {float: left;margin: 1px;}";
s += "</style><font color='White'><center><h1> Turno del color: " + String(colorido[jugador]) + " </h1></center></font><form action='/" + lugar + "' class='form'><div class='field'><label class='label'>Seleccione a donde quiere mover la ficha</label>";
s += "<ul class='options'><li class='option'><input class='checkbox-input' id='choice-0' name='choice' type='checkbox' value='8'><label class='checkbox-label' for='choice-0'>Arriba</label></li><li class='option'>";
s += "<input class='checkbox-input' id='choice-1' name='choice' type='checkbox' value='-8'><label class='checkbox-label' for='choice-1'>Abajo</label></li><li class='option'><input class='checkbox-input' id='choice-2' name='choice' type='checkbox' value='1'>";
s += "<label class='checkbox-label' for='choice-2'>Izquierda</label></li><li class='option'><input class='checkbox-input' id='choice-3' name='choice' type='checkbox' value='-1'><label class='checkbox-label' for='choice-3'>Derecha</label></li>";
if (lugar == "saltar"){s +="<li class='option'><input class='checkbox-input' id='choice-4' name='choice' type='checkbox' value='-2'><label class='checkbox-label' for='choice-4'>Terminar turno</label></li></ul></div>";}
if (lugar == "movimiento"){
 s += "</ul></divl> <div class='field'><label class='label'>Seleccione una ficha</label><ul class='options'><li class='option'><input class='option-input' id='option-0' name='option' type='radio' value='0'>";
  s += "<label class='option-label' for='option-0'>" + String(inicial[jugador][0]) + "</label></li><li class='option'><input class='option-input' id='option-1' name='option' type='radio' value='1'><label class='option-label' for='option-1'>" + String(inicial[jugador][1]) + "</label></li>";
 s += "<li class='option'><input class='option-input' id='option-2' name='option' type='radio' value='2'><label class='option-label' for='option-2'>" + String(inicial[jugador][2]) + "</label></li><li class='option'><input class='option-input' id='option-3' name='option' type='radio' value='3'>";
 s += "<label class='option-label' for='option-3'>" + String(inicial[jugador][3]) + "</label></li><li class='option'><input class='option-input' id='option-4' name='option' type='radio' value='4'><label class='option-label' for='option-4'>" + String(inicial[jugador][4]) + "</label>";
 s += "</li><li class='option'><input class='option-input' id='option-5' name='option' type='radio' value='5'><label class='option-label' for='option-5'>" + String(inicial[jugador][5]) + "</label></li></ul></div>";
 delay(10);}
s += "<p class='field half'><input class='button' type='submit' value='Continuar'></p></form>";
delay(10);
server.send(200, "text/html", s);}

void string4(){
  s = "";
  s += "<h1> GANASTE </h1>";
  server.send(200, "text/html", s);
}
