const int motorA1 = 6;
const int motorA2 = 5;
const int motorB1 = 3;
const int motorB2 = 9;

int onFar = 10;
int stopLamba = 11;
int korna = 12;
int okuma;
int hiz = 255;

//Ayarlar
void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(onFar, OUTPUT);
  pinMode(stopLamba, OUTPUT);
  pinMode(korna, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}

//Programımız
void loop() {
  if (Serial.available() > 0) {
    okuma = Serial.read();
  } else {
    dur();
  }

  if (okuma == '0') {
    hiz = 0;
  } else if (okuma == '1') {
    hiz = 100;
  } else if (okuma == '2') {
    hiz = 180;
  } else if (okuma == '3') {
    hiz = 200;
  } else if (okuma == '4') {
    hiz = 255;
  }

  switch (okuma) {
    case 'F': ileri(); break;
    case 'G': solIleri(); break;
    case 'I': sagIleri(); break;
    case 'B': geri(); break;
    case 'H': sagGeri(); break;
    case 'J': solGeri(); break;
    case 'L': sol(); break;
    case 'R': sag(); break;
    case 'S': dur(); break;
    case 'W': onFarAcik(); break;
    case 'w': onFarKapali(); break;
    case 'U': stopLambaAcik(); break;
    case 'u': stopLambaKapali(); break;
    case 'V': kornaAcik(); break;
    case 'v': kornaKapali(); break;
    default:
      // durum okunmadığında varsayılan hareketi tanımlayabiliriz.
      break;
  }
}


//Fonksiyonlar
void ileri() {
  analogWrite(motorA1, hiz);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, hiz);
  analogWrite(motorB2, 0);
}

void solIleri() {
  analogWrite(motorA1, hiz);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}

void sagIleri() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, hiz);
  analogWrite(motorB2, 0);
}

void geri() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, hiz);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, hiz);
}

void sagGeri() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, hiz);
}

void solGeri() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, hiz);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}

void sol() {
  analogWrite(motorA1, hiz);
  analogWrite(motorA2, hiz);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}

void sag() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, hiz);
  analogWrite(motorB2, hiz);
}

void dur() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}
void onFarAcik() {
  digitalWrite(onFar, HIGH);
}
void onFarKapali() {
  digitalWrite(onFar, LOW);
}
void stopLambaAcik() {
  digitalWrite(stopLamba, HIGH);
}
void stopLambaKapali() {
  digitalWrite(stopLamba, LOW);
}
void kornaAcik() {
  digitalWrite(korna, HIGH);
}
void kornaKapali() {
  digitalWrite(korna, LOW);
}
