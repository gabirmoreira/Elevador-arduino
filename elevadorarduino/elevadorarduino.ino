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
enum Estado {PARADO, ANDANDO} ;
Estado estado_atual = PARADO;
int andar_atual = 0;
int andar_desejado = 0;

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
  switch(estado_atual)
  {
    case PARADO:
      if (digitalRead(botao_t) == LOW)
      {
        andar_desejado = 0;
        if (andar_desejado > andar_atual)
        {
          subirElevador();
          estado_atual = ANDANDO;

        }
        else if (andar_desejado < andar_atual)
        {
          descerElevador();
          estado_atual = ANDANDO;

        }  
      }

      else if (digitalRead(botao_1) == LOW)
      {
        andar_desejado = 1;
        if (andar_desejado > andar_atual)
        {
          subirElevador();
          estado_atual = ANDANDO;

        }
        else if (andar_desejado < andar_atual)
        {
          descerElevador();
          estado_atual = ANDANDO;

        }
      }

      else if (digitalRead(botao_2) == LOW)
      {
        andar_desejado = 2;
        if (andar_desejado > andar_atual)
        {
          subirElevador();
          estado_atual = ANDANDO;

        }
        else if (andar_desejado < andar_atual)
        {
          descerElevador();
          estado_atual = ANDANDO;

        }
      }

      else if (digitalRead(botao_3) == LOW)
      {
        andar_desejado = 3;
        if (andar_desejado > andar_atual)
        {
          subirElevador();
          estado_atual = ANDANDO;

        }
        else if (andar_desejado < andar_atual)
        {
          descerElevador();
          estado_atual = ANDANDO;

        }        
      }

      break;
    case ANDANDO:
      if (andar_desejado == 0)
      {
        if (digitalRead (fim_de_curso_t) == LOW)
        {
          pararElevador();
          estado_atual = PARADO;
          andar_atual = 0;

        }
      }

      else if (andar_desejado == 1)
      {
        if (digitalRead (sensor_proximidade_1) == LOW)
        {
          pararElevador();
          estado_atual = PARADO;
          andar_atual = 1;

        }
      }

      else if (andar_desejado == 2)
      {
        if (digitalRead (sensor_proximidade_2) == LOW)
        {
          pararElevador();
          estado_atual = PARADO;
          andar_atual = 2;
        }
      }

      else if (andar_desejado == 3)
      {
        if (digitalRead (fim_de_curso_3) == LOW)
        {
          pararElevador();
          estado_atual = PARADO;
          andar_atual = 3;
        }
      }

      break;
    default:
      break;
  }
}