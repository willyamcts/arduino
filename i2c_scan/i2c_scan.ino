// Abra o monitor serial para ver os enderecos I2C conectados

#include <Wire.h> // biblioteca I2C

void setup() {
  Wire.begin(); // inicializa a biblioteca

  Serial.begin(9600); // inicializa a serial
  while (!Serial); // necessário para o Arduino Leonardo
}

void loop() {
  byte detecta; // guarda o codigo de estado da conexão

  Serial.println("");
  Serial.println("Procura I2C:");
  Serial.println("");

  Serial.println("    0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F");
  Serial.print  ("00  _");

  for (byte endereco = 1; endereco < 127; endereco = endereco + 1 )
  {
    // a cada 16 enderecos, muda de linha
    if (endereco % 16 == 0) {
      Serial.println();
      Serial.print  (endereco, HEX);
    }
    Serial.print(" ");
    Wire.beginTransmission(endereco);
    detecta = Wire.endTransmission();
    if (detecta == 0) {
      // periferico respondeu
      if (endereco < 16) Serial.print("0");
      Serial.print(endereco, HEX);
    }
    else {
      // nada respondeu
      Serial.print(" .");
    }
  } // fim do for
  Serial.println("  _");

  delay(3000);
}

/*******************************************************************************
  DESCRIÇÃO:
  Use este programa para descobrir os enderecos I2C conectados ao Arduino
  Veja o resultado na porta serial

  POR:
  PandoraLab
  www.pandoralab.com.br

  COLABORADORES:
  Mau Jabur: mau (at) pandoralab (dot) com (dot) br

  HARDWARE:
  Arduino Uno:
      https://pandoralab.com.br/loja/arduino-uno-r3-smd/
  Qualquer periférico I2C

  TOOLCHAIN:
  Arduino IDE 1.6.9

  BIBLIOTECAS UTILIZADAS:
  Wire - vem com o Arduino

  LICENÇA:
  Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
  http://creativecommons.org/licenses/by-sa/4.0/

 *****************************************************************************/
