#include <Adafruit_NeoPixel.h>
#include "Graphs.h"
#include "Circular_Linkedlist.h"
#include "Proyecto_Html.h"
#define PIN 13
#define N_LEDS 64

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
const char* ssid = "TIGO-77C8";
const char* password = "4D9697503256";
int colores[4][3] = {{255,0,0},{0,0,255},{0,255,0},{255,255,0}};
struct ficha{
  int posicion[6];
  int color[3];};
int e;
int pruebas = 0;
int fichaactual=0;
int posfutura=0;
int ganar=0;
int ganando = 0;
struct ficha fichas[4];
int jugador = 0;
int turno = 0;
bool testeando;
int testfinal = 0;
struct Graph* graph = createAGraph(64);
void intro(){ long int t1 = millis();string1();long int t2 = millis();Serial.print("Profiling of function intro(): "); Serial.print(t2-t1); Serial.println(" milliseconds");}
void Inicio(){
  long int t1 = millis();
  jugador = server.arg("jugadors").toInt();
  turno += jugador; 
  empezar = create_cll(empezar);
for(int i=0;i<jugador;i++){
  for(int t=0;t<6;t++){
    fichas[i].posicion[t] = inicial[i][t];
    ocupado[inicial[i][t]] = 1;
    strip.setPixelColor(inicial[i][t],colores[i][0],colores[i][1],colores[i][2]);
    delay(10);
    if(t<3){
    fichas[i].color[t] = colores[i][t];}}}
strip.show();
string2();
long int t2 = millis();Serial.print("Profiling of function Inicio(): "); Serial.print(t2-t1); Serial.println(" milliseconds");}
void siguiente(){
  long int t1 = millis();
  if (testeando == false){
  ganando = 0;
  empezar = empezar->next;
  ganar = empezar->val;}
    for(int mv=0;mv<6;mv++){
      for(int t=0;t<6;t++){
        if (testeando == true){testfinal++;}
    delay(10);
    if(testeando == false){
    if(fichas[jugador].posicion[mv] == inicial[ganar][t]){ganando += 1;break;}}}
    if (testeando == false){if((ganando-1) != mv){break;}}}
   delay(10);
   if (testeando == false){
  if (ganando == 6){long int t2 = millis();Serial.print("Profiling of function Siguiente(): "); Serial.print(t2-t1); Serial.println(" milliseconds");string4();}
  else{
  for(int r=0;r<3;r++){empezar = empezar->next;}
  if((jugador+1) == turno){for(int v=0;v<(3-jugador);v++){empezar = empezar->next;}}
  jugador = empezar->val;
  empezar = empezar->next;
  long int t2 = millis();
string3(jugador, "movimiento");Serial.print("Profiling of function Siguiente(): "); Serial.print(t2-t1); Serial.println(" milliseconds");}}}
void mover(){
  long int t1 = millis();
e = server.arg("option").toInt();
int pos = server.arg("choice").toInt();
fichaactual = fichas[jugador].posicion[e];
posfutura = pos+fichaactual;
SearchGraph(graph, fichaactual, posfutura, pos, false, false);
if (cambiar != -1){
inicial[jugador][e] = cambiar;
fichas[jugador].posicion[e] = cambiar;
strip.setPixelColor(fichaactual,0,0,0);
delay(10);
strip.setPixelColor(cambiar,fichas[jugador].color[0],fichas[jugador].color[1],fichas[jugador].color[2]);
delay(10);
strip.show();}
if(saltar == 1){
  saltar = 0;
  string3(jugador, "saltar");
  long int t2 = millis();
  Serial.print("Profiling of function mover(): "); Serial.print(t2-t1); Serial.println(" milliseconds");}
else{long int t2 = millis();Serial.print("Profiling of function mover(): "); Serial.print(t2-t1); Serial.println(" milliseconds");siguiente();}
}
void brinco(){
  long int t1 = millis();
  delay(10);
  int pos = server.arg("choice").toInt();
  int posactual = cambiar;
  if (pos != -2){
  SearchGraph(graph, cambiar, (cambiar+pos), pos, true, false);
  saltar = 0;
  if(cambiar != -1){
    inicial[jugador][e] = cambiar;
    fichas[jugador].posicion[e] = cambiar;
    strip.setPixelColor(posactual,0,0,0);
    delay(10);
    strip.setPixelColor(cambiar,fichas[jugador].color[0],fichas[jugador].color[1],fichas[jugador].color[2]);
    delay(10);
    strip.show();
    string3(jugador,"saltar");
    long int t2 = millis();Serial.print("Profiling of function brinco(): "); Serial.print(t2-t1); Serial.println(" milliseconds");
    }
  else{long int t2 = millis();Serial.print("Profiling of function brinco(): "); Serial.print(t2-t1); Serial.println(" milliseconds");siguiente();}
    }  
  else{long int t2 = millis();Serial.print("Profiling of function brinco(): "); Serial.print(t2-t1); Serial.println(" milliseconds");siguiente();}}
void setup() {
addEdge(graph);
delay(100);
Serial.begin(9600);
unittesting();
WiFi.mode(WIFI_AP_STA);
WiFi.begin(ssid, password);
strip.begin();
strip.setBrightness(9);
strip.show();
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");}
    Serial.println("");
  Serial.print("Connected to ");
  Serial.println("WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  delay(100);
server.on("/", intro);
delay(10);
server.on("/inicio", Inicio);
delay(10);
server.on("/partida", siguiente);
delay(10);
server.on("/movimiento", mover);
delay(10);
server.on("/saltar", brinco);
delay(10);
delay(10);
server.begin();
testeando = false;
Serial.println("HTTP server started");}
void loop() {server.handleClient();}
void unittesting(){
  long int t1 = millis();
  testeando = true;
  siguiente();
    test = create_cll(test);
  for(int b=0;b<4;b++){
    if(test->val == b){
      delay(10);
      pruebas++;
      test = test->next;
    }
  }
  Serial.println("");
  delay(10);
 SearchGraph(graph, 56, 64, 8, false, false);
 delay(10);
 if(tam == 64){pruebas++;}
 if(test2==56){pruebas++;}
 if(cambiar == -1){pruebas++;}
 if(testfinal == 36){pruebas++;}
 delay(10);
 long int t2 = millis();
 Serial.println("---------------------------------------------------------------------");
 Serial.print("Ran ");Serial.print(pruebas);Serial.print(" tests in ");Serial.print(t2-t1);Serial.print(" miliseconds");
 Serial.println("");
 if(pruebas == 8){
 Serial.println("OK");}
 else{
  Serial.println("FAIL");
 }
 Serial.println("");
 Serial.println("");
 delay(10);
}
