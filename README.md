# Varmeskap

Utstyr: <br>
Wemos mini32 D1 microkontroller<br>
BMP280<br>
AC Dimmer<br>
Varmelement<br>
Apparatboks<br>

Denne skissen leser tempraturen fra en BMP280, koblet til en Wemos mini32 D1 microkontroller<br> ig styrer en AC Dimmer progressivt opp mot 34 grader. Teperaturer under 34 grader aktivserer varmeelementet, over kobler det ut.
I2C adresse BMP280 :0x76<br>
0-deteksjon kobles til port GPIO35<br>
thyristor-styringen skjer fra port 8c

Sync til IO18
Gate til IO19
SDA til IO21
SCL til IO22

Leser sync trigger fra
<a href="https://skule.sormo.no/bilder/36.jpg">fra AC Dimmer</a>

Opprinnelig var det meningen å vise data på en OLED skjerm og koble til Node-Red. Men tidskonstantene var for tidskritiske. En versjon med fast grenseverdi på 34 grader som aktiverer varmelementet progresivt med pulsbredde på nettfrekvensen ble lagt inn<br>
