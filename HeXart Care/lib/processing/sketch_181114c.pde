//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;
void setup() {
udSerial = new Serial(this, Serial.list()[0], 128000);      //prépare à lire des données de 128000 BAUD au port Serial.list)[0]
output = createWriter ("Battements.csv");                   //écris sur le fichier battements.csv
}
void draw() {
if (udSerial.available() > 0) {                             //si le port est disponible :
String SenVal = udSerial.readString();                      //lis la valeur
if (SenVal != null) {                                       //si la valeur n'est pas NULL
output.print(SenVal);                                       //écris la valeur
}
}
}

//si une touche est appuyée
void keyPressed(){
output.flush();      //clean le port
delay(1000);         //attend 1 seconde (sureté)
output.close();      //ferme la liaison
exit();              //et quitte le programme
}
