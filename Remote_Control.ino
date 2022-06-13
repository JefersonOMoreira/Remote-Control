//  Biblioteca para acesso ao sensor IR
#include <IRremote.h>

#define pinoIR    2 // Pino digital para receber sinal do sensor IR

IRrecv receptor(pinoIR);   //  Cria um receptor que decodifica o sinal do sensor IR - codigos do controle remoto
decode_results resultados; //  Variavel que aramzenara os resultados recebidos

void setup() 
{
  Serial.begin(9600); // Inicial o Monitor Serial.
  pinMode(3,OUTPUT); // LED BRANCO.
  pinMode(4,OUTPUT); // LED AZUL.
  pinMode(5,OUTPUT); // LED VERDE.
  pinMode(6,OUTPUT); // LED AMARELO.
  pinMode(7,OUTPUT); // LED LARANJA.
  pinMode(8,OUTPUT); // LED VERMELHO
  receptor.enableIRIn();    //  Habilita o receptor para inicio de processamento dos codigos recebidos do emissor IR
}

void loop() {
  if(receptor.decode(&resultados))
  {
    Serial.println(resultados.value, HEX);//  Decodifica o codigo da informacao enviada pelo emissor IR        
     receptor.resume();
  }//  Continua a aguardar o envio de informacoes peso emissor IR
  
  else if (resultados.value == 0xFD08F7) // Se for pressionado o botão "1", acende o LED BRANCO
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);    
  }
  else if (resultados.value == 0xFD8877) // Se for pressionado o botão "2", acende o LED BRANCO
  {
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);    
  }
  else if (resultados.value == 0xFD48B7) // Se for pressionado o botão "3", acende o LED BRANCO
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);    
  }
  else if (resultados.value == 0xFD28D7) // Se for pressionado o botão "4", acende o LED BRANCO
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);    
  }
  else if (resultados.value == 0xFDA857) // Se for pressionado o botão "5", acende o LED BRANCO
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);    
  }
  else if (resultados.value == 0xFD6897) // Se for pressionado o botão "6", acende o LED BRANCO
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);    
  }
}
