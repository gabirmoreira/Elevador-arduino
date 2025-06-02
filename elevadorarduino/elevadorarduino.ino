const int sensor_proximidade_1 = 6;
const int sensor_proximidade_2 = 7;
const int fim_de_curso_t = 8;
const int fim_de_curso_3 = 11;
const int motorPin1 = 9; // pra frente (subir)
const int motorPin2 = 10; // pra tras (descer)
const int botao_t = 2;
const int botao_1 = 3;
const int botao_2 = 4;
const int botao_3 = 5;

void setup() {
  pinMode(botao_t, INPUT);
  pinMode(botao_1, INPUT);
  pinMode(botao_2, INPUT);
  pinMode(botao_3, INPUT);

  pinMode(sensor_proximidade_1, INPUT);
  pinMode(sensor_proximidade_2, INPUT);

  pinMode(fim_de_curso_t, INPUT_PULLUP);
  pinMode(fim_de_curso_3, INPUT_PULLUP);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.begin(9600);

}

void subirElevador(){
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void descerElevador(){
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}

void pararElevador()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void loop() {
  // botao um
  if (digitalRead(botao_1) == LOW)

  { 
    Serial.print("apertou botao 1\n");
    // Se ainda não chegou no teto
    if (digitalRead(fim_de_curso_3) == HIGH){

    
      subirElevador();
      Serial.print("subindo\n");
    }
    else
      pararElevador();
  }
  // botao dois
  else if (digitalRead(botao_2) == LOW)
  { 
    Serial.print("apertou botao 2\n");

    // Se ainda não chegou no terreo
    if (digitalRead(fim_de_curso_t) == HIGH){

    
      descerElevador();
      Serial.print("descendo\n");

    }

    else
      pararElevador();
  }
}
