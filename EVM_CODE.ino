#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 10, 9, 8, 7, 6);

 byte customChar1[] = {
  B00100,
  B01010,
  B10001,
  B10001,
  B01111,
  B00100,
  B01010,
  B10001

 
};

byte customChar2[] = {
  B10111,
  B10100,
  B10100,
  B10100,
  B11111,
  B00101,
  B00101,
  B11101
};

byte customChar3[] = {
  B10101,
  B10101,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte customChar4[] = {
  B00100,
  B00100,
  B10101,
  B01110,
  B01110,
  B10101,
  B00100,
  B00100
};

#define sw1 A0 // Button 1
#define sw2 A1 // Button 2
#define sw3 A2 // Button 3
#define sw4 A3 // Button 4
#define sw5 A4 // Button 5 for result

int vote1 = 0;
int vote2 = 0;
int vote3 = 0;
int vote4 = 0;

void setup() {
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(sw5, INPUT);
  pinMode(13, OUTPUT); // Red LED
  pinMode(12, OUTPUT); // Green LED

  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("WELCOME TO");
  lcd.setCursor(2, 1);
  lcd.print(" BOOTH NO.1");
  delay(3000);
  lcd.setCursor(3, 0);
  lcd.print("DO VOTE");
  lcd.setCursor(2, 1);
  lcd.print("EVERY VOTE MATTERS");
  delay(3000);
  lcd.setCursor(3, 0);
  lcd.print("PICK YOUR FAV");
  lcd.setCursor(2, 1);
  lcd.print("IPL TEAM");
  delay(3000);
  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);
  digitalWrite(sw3, HIGH);
  digitalWrite(sw4, HIGH);
  digitalWrite(sw5, HIGH);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("CSK");
  lcd.createChar(0, customChar1);
  lcd.setCursor(1,0);
  lcd.write((byte)0);
  lcd.setCursor(4, 1);
  lcd.print("MI");
  lcd.createChar(1, customChar2);
  lcd.setCursor(5,0);
  lcd.write((byte)1);
  lcd.setCursor(8, 1);
  lcd.print("RCB");
  lcd.createChar(2, customChar3);
  lcd.setCursor(9,0);
  lcd.write((byte)2);
  lcd.setCursor(12, 1);
  lcd.print("OTH");
  lcd.createChar(3, customChar4);
  lcd.setCursor(13,0);
  lcd.write((byte)3);
}

void loop() {
  if (digitalRead(sw1) == LOW) {
    lcd.clear();
    lcd.print("VOTE CASTED");
    lcd.setCursor(0, 1);
    delay(200);
    vote1++;
    digitalWrite(12, HIGH);
    delay(500);
    while (digitalRead(sw1) == LOW);
    digitalWrite(12, LOW);
    showPartyOptions();
  }

  if (digitalRead(sw2) == LOW) {
    lcd.clear();
    lcd.print("VOTE CASTED");
    lcd.setCursor(0, 1);
    delay(200);
    vote2++;
    digitalWrite(12, HIGH);
    delay(500);
    while (digitalRead(sw2) == LOW);
    digitalWrite(12, LOW);
    showPartyOptions();
  }

  if (digitalRead(sw3) == LOW) {
    lcd.clear();
    lcd.print("VOTE CASTED");
    lcd.setCursor(0, 1);
    delay(200);
    vote3++;
    digitalWrite(12, HIGH);
    delay(500);
    while (digitalRead(sw3) == LOW);
    digitalWrite(12, LOW);
    showPartyOptions();
  }

  if (digitalRead(sw4) == LOW) {
    lcd.clear();
    lcd.print("VOTE CASTED");
    lcd.setCursor(0, 1);
    delay(200);
    vote4++;
    digitalWrite(12, HIGH);
    delay(500);
    while (digitalRead(sw4) == LOW);
    digitalWrite(12, LOW);
    showPartyOptions();
  }

  if (digitalRead(sw5) == LOW) {
    digitalWrite(13, HIGH);
    lcd.clear();
    determineWinner();
    delay(2500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CSK");
    lcd.setCursor(1, 1);
    lcd.print(vote1);
    lcd.setCursor(3, 0);
    lcd.print("MI");
    lcd.setCursor(5, 1);
    lcd.print(vote2);
    lcd.setCursor(7, 0);
    lcd.print("RCB");
    lcd.setCursor(9,1);
    lcd.print(vote3);
    lcd.setCursor(11, 0);
    lcd.print(" OTH ");
    lcd.setCursor(13, 1);
    lcd.print(vote4);
    delay(2500);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Thanks for");
    lcd.setCursor(5,1);
    lcd.print("Voting!");
    delay(2500);
    resetVotes();
    showPartyOptions();
  }
}

void showPartyOptions() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CSK");
  lcd.setCursor(4, 0);
  lcd.print("MI");
  lcd.setCursor(8, 0);
  lcd.print("RCB");
  lcd.setCursor(12, 0);
  lcd.print("OTH");
}

void determineWinner() {
  int totalVotes = vote1 + vote2 + vote3 + vote4;
  lcd.clear();
  if (totalVotes > 0) {
    if (vote1 > vote2 && vote1 > vote3 && vote1 > vote4) {
      lcd.print("CSK Wins!");
      lcd.setCursor(0, 1);
      lcd.print("VOTE CASTED:");
      lcd.print(totalVotes);
    } else if (vote2 > vote1 && vote2 > vote3 && vote2 >vote4) {
      lcd.print("MI Wins!");
      lcd.setCursor(0, 1);
      lcd.print("VOTE CASTED:");
      lcd.print(totalVotes);
    } else if (vote3 > vote1 && vote3 > vote2 && vote3 > vote4) {
      lcd.print("RCB Wins!");
      lcd.setCursor(0, 1);
      lcd.print("VOTE CASTED:");
      lcd.print(totalVotes);
    } else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3) {
      lcd.print("OTH Wins!");
      lcd.setCursor(0, 1);
      lcd.print("VOTE CASTED:");
      lcd.print(totalVotes);
    }
     else {
        lcd.print("Tie Up Or");
        lcd.setCursor(0, 1);
        lcd.print("No Result");
        lcd.setCursor(0, 1);
      lcd.print("VOTE CASTED:");
      lcd.print(totalVotes);
      }
    }else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("No Voting....");
      lcd.setCursor(0, 1);
      lcd.print("VOTE CASTED:");
      lcd.print(totalVotes);
    }
}

void resetVotes() {
  vote1 = 0;
  vote2 = 0;
  vote3 = 0;
  vote4 = 0;
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}