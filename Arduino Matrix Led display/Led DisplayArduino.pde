#include <NewSoftSerial.h>
#include <Sprite.h>  // Sprite before Matrix
#include <Matrix.h>

// DIN, CLK, LOAD, #chips
Matrix myLeds = Matrix(12, 11, 10, 3);

byte byteArray[200];
int tmpByte =0;

int i=23; // max vrednost koju kolona moze da ima
byte proc;
int maxValue=0;
int diff = 0; // da se odredi koliko ce dugo da ide tekst
int hasRead = 0; // za 0 ce da se cita, za 1 ce smeti da se ispisuje
int endPosition = 23; // odakle ce da krene da se ispisuje string,t.j. maxValueimalna vrednost kolone

int helpTmp = 0;
int prev = 0;

int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3
NewSoftSerial bluetooth(bluetoothTx, bluetoothRx);

Sprite letter_A = Sprite(5, 7,
  B01110,
  B10001,
  B10001,
  B11111,
  B10001,
  B10001,
  B10001
);

Sprite letter_B = Sprite(5, 7,
  B11110,
  B10001,
  B10001,
  B11110,
  B10001,
  B10001,
  B11110
);

Sprite letter_C = Sprite(5, 7,
  B01110,
  B10001,
  B10000,
  B10000,
  B10000,
  B10001,
  B01110
);

Sprite letter_D = Sprite(5, 7,
  B11110,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11110
);

Sprite letter_E = Sprite(5, 7,
  B11111,
  B10000,
  B10000,
  B11110,
  B10000,
  B10000,
  B11111
);

Sprite letter_F = Sprite(5, 7,
  B11111,
  B10000,
  B10000,
  B11110,
  B10000,
  B10000,
  B10000
);

Sprite letter_G = Sprite(5, 7,
  B01110,
  B10001,
  B10000,
  B10000,
  B10111,
  B10001,
  B01110
);

Sprite letter_H = Sprite(5, 7,
  B10001,
  B10001,
  B10001,
  B11111,
  B10001,
  B10001,
  B10001
);

Sprite letter_I = Sprite(3, 7,
  B111,
  B010,
  B010,
  B010,
  B010,
  B010,
  B111
);

Sprite letter_J = Sprite(5, 7,
  B00001,
  B00001,
  B00001,
  B00001,
  B10001,
  B10001,
  B01110
);

Sprite letter_K = Sprite(5, 7,
  B10001,
  B10010,
  B10100,
  B11000,
  B10100,
  B10010,
  B10001
);

Sprite letter_L = Sprite(5, 7,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B11111
);

Sprite letter_M = Sprite(5, 7,
  B10001,
  B11011,
  B10101,
  B10001,
  B10001,
  B10001,
  B10001
);

Sprite letter_N = Sprite(5, 7,
  B10001,
  B11001,
  B10101,
  B10011,
  B10001,
  B10001,
  B10001
);

Sprite letter_O = Sprite(5, 7,
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110
);

Sprite letter_P = Sprite(5, 7,
  B01110,
  B10001,
  B10001,
  B11110,
  B10000,
  B10000,
  B10000
);

Sprite letter_Q = Sprite(5, 7,
  B01110,
  B10001,
  B10001,
  B10001,
  B10101,
  B10011,
  B01111
);

Sprite letter_R = Sprite(5, 7,
  B11110,
  B10001,
  B10001,
  B11110,
  B11100,
  B10010,
  B10001
);

Sprite letter_S = Sprite(5, 7,
  B01110,
  B10001,
  B10000,
  B01110,
  B00001,
  B10001,
  B01110
);

Sprite letter_T = Sprite(5, 7,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
);

Sprite letter_U = Sprite(5, 7,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110
);

Sprite letter_W = Sprite(5, 7,
  B10001,
  B10001,
  B10001,
  B10001,
  B10101,
  B11011,
  B10001
);

Sprite letter_V = Sprite(5, 7,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B01010,
  B00100
);

Sprite letter_X = Sprite(5, 7,
  B10001,
  B10001,
  B01010,
  B00100,
  B01010,
  B10001,
  B10001
);

Sprite letter_Y = Sprite(5, 7,
  B10001,
  B10001,
  B10001,
  B01010,
  B00100,
  B00100,
  B00100
);

Sprite letter_Z = Sprite(5, 7,
  B11111,
  B00001,
  B00010,
  B00100,
  B01000,
  B10000,
  B11111
);

Sprite letter_0 = Sprite(5, 7,
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
);

Sprite letter_1 = Sprite(4, 7,
  B0010,
  B0110,
  B1010,
  B0010,
  B0010,
  B0010,
  B0111
);


Sprite letter_2 = Sprite(5, 7,
  B01110,
  B10001,
  B00010,
  B00100,
  B01000,
  B10001,
  B11111
);

Sprite letter_3 = Sprite(5, 7,
  B01110,
  B10001,
  B00001,
  B01110,
  B00001,
  B10001,
  B01110
);

Sprite letter_4 = Sprite(5, 7,
  B10001,
  B10001,
  B10001,
  B11111,
  B00001,
  B00001,
  B00001
);

Sprite letter_5 = Sprite(5, 7,
  B11111,
  B10000,
  B10000,
  B11111,
  B00001,
  B00001,
  B11111
);

Sprite letter_6 = Sprite(5, 7,
  B11111,
  B10000,
  B10000,
  B11111,
  B10001,
  B10001,
  B11111
);

Sprite letter_7 = Sprite(5, 7,
  B11111,
  B00001,
  B00001,
  B00010,
  B00100,
  B00100,
  B00100
);

Sprite letter_8 = Sprite(5, 7,
  B11111,
  B10001,
  B10001,
  B11111,
  B10001,
  B10001,
  B11111
);

Sprite letter_9 = Sprite(5, 7,
  B11111,
  B10001,
  B10001,
  B11111,
  B00001,
  B00001,
  B11111
);

Sprite letter_blanko = Sprite(1, 7,
  B0,
  B0,
  B0,
  B0,
  B0,
  B0,
  B0
);

Sprite letter_uzvik = Sprite(1, 7,
  B1,
  B1,
  B1,
  B1,
  B1,
  B0,
  B1
);

Sprite letter_zPitanja = Sprite(5, 7,
  B01110,
  B10001,
  B00001,
  B00010,
  B00100,
  B00000,
  B00100
);

Sprite letter_dveTacke = Sprite(1, 7,
  B0,
  B0,
  B1,
  B0,
  B0,
  B1,
  B0
);

Sprite letter_Plus = Sprite(5, 7,
  B00000,
  B00100,
  B00100,
  B11111,
  B00100,
  B00100,
  B00000
);

Sprite letter_Minus = Sprite(5, 7,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000
);

Sprite letter_Puta = Sprite(5, 7,
  B00000,
  B10001,
  B01010,
  B00100,
  B01010,
  B10001,
  B00000
);

Sprite letter_Podeljeno = Sprite(5, 7,
  B00000,
  B00100,
  B00000,
  B11111,
  B00000,
  B00100,
  B00000
);

Sprite letter_Crta = Sprite(4, 7,
  B0000,
  B0000,
  B0000,
  B1111,
  B0000,
  B0000,
  B0000
);

Sprite letter_Jednako = Sprite(4, 7,
  B0000,
  B0000,
  B1111,
  B0000,
  B1111,
  B0000,
  B0000
);

Sprite letter_Tacka = Sprite(1, 7,
  B0,
  B0,
  B0,
  B0,
  B0,
  B0,
  B1
);

Sprite letter_Zapeta = Sprite(2, 8,
  B00,
  B00,
  B00,
  B00,
  B00,
  B00,
  B01,
  B10
);


void setup() 
{
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$$$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Tempora rily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("w");
  delay(1000);
  bluetooth.println("---");  
  //FINISHED CONFIGURATION OF BT MATE
  myLeds.clear();
  myLeds.setBrightness(15);
  Serial.begin(9600);
  
  for( int brojac=0; brojac<200; brojac++ )
    byteArray[brojac] = 0;
    tmpByte = 0;
  
}

void loop() 
{
   myLeds.clear(); // da bi se osvezio displey     
   
    readLetter();
    if( hasRead == 1 )
      drawLetter();
   


}

// function for reading characters
void readLetter()
{  
  if ( bluetooth.available() > 0 )
  {
   // set variables as input should start
       i=23;
       maxValue = i;
       hasRead = 0; // for 1 it will do drawLetter u loop()
       tmpByte = 0; // pointer to array where are stored characters
        
     while ( bluetooth.available() > 0 )
     {
        proc = bluetooth.read();  
		byteArray[ tmpByte ] = proc; // smesti u niz
		tmpByte = tmpByte+1; // pokazuje na sledeci karakter koji se cita  
         
         switch (proc)
         {
            case 'a' :
            case 'A' :
             maxValue = maxValue+6; 
            break;
            
            case 'b' :
            case 'B' :
             maxValue = maxValue+6; 
            break;
            
            case 'c' :
            case 'C' :
             maxValue = maxValue+6; 
            break;
            
            case 'd' :
            case 'D' :
             maxValue = maxValue+6; 
            break;
            
            case 'e' :
            case 'E' :
             maxValue = maxValue+6; 
            break;
            
            case 'f' :
            case 'F' :
             maxValue = maxValue+6; 
            break;
            
            case 'g' :
            case 'G' :
             maxValue = maxValue+6; 
            break;
            
            case 'h' :
            case 'H' :
             maxValue = maxValue+6; 
            break;
            
            case 'i' :
            case 'I' :
             maxValue = maxValue+4; 
            break;
            
            case 'j' :
            case 'J' :
             maxValue = maxValue+6; 
            break;
            
            case 'k' :
            case 'K' :
             maxValue = maxValue+6; 
            break;
            
            case 'l' :
            case 'L' :
             maxValue = maxValue+6; 
            break;
            
            case 'm' :
            case 'M' :
             maxValue = maxValue+6; 
            break;
            
            case 'n' :
            case 'N' :
             maxValue = maxValue+6; 
            break;
            
            case 'o' :
            case 'O' :
             maxValue = maxValue+6; 
            break;
            
            case 'p' :
            case 'P' :
             maxValue = maxValue+6; 
            break;
              
            case 'q' :
            case 'Q' :
             maxValue = maxValue+6; 
            break; 
          
            case 'r' :
            case 'R' :
             maxValue = maxValue+6; 
            break; 
           
            case 's' :
            case 'S' :
             maxValue = maxValue+6; 
            break; 
            
            case 't' :
            case 'T' :
             maxValue = maxValue+6; 
            break;
            
            case 'u' :
            case 'U' :
             maxValue = maxValue+6; 
            break;
            
            case 'v' :
            case 'V' :
             maxValue = maxValue+6; 
            break;
            
            case 'w' :
            case 'W' :
             maxValue = maxValue+6; 
            break;
            
            case 'x' :
            case 'X' :
             maxValue = maxValue+6; 
            break;
            
            case 'y' :
            case 'Y' :
             maxValue = maxValue+6; 
            break;
            
            case 'z' :
            case 'Z' :
             maxValue = maxValue+6; 
            break;
            
            case '0' :
             maxValue = maxValue+6; 
            break;
            
            case '1' :
             maxValue = maxValue+5; 
            break;
            
            case '2' :
             maxValue = maxValue+6; 
            break;
            
            case '3' :
             maxValue = maxValue+6; 
            break;
            
            case '4' :
             maxValue = maxValue+6; 
            break;
            
            case '5' :
             maxValue = maxValue+6; 
            break;
            
            case '6' :
             maxValue = maxValue+6; 
            break;
            
            case '7' :
             maxValue = maxValue+6; 
            break;
         
           case '8' :
             maxValue = maxValue+6; 
            break;
            
            case '9' :
             maxValue = maxValue+6; 
            break;
            
            case ' ' :
             maxValue = maxValue+2; 
            break;
           
           case '!' :
             maxValue = maxValue+2; 
            break;
            
            case '?' :
             maxValue = maxValue+6; 
            break;
            
            case ':' :
             maxValue = maxValue+2; 
            break;
           
            case '+' :
             maxValue = maxValue+6; 
            break;
       
            case '-' :
             maxValue = maxValue+6; 
            break;
            
            case '*' :
             maxValue = maxValue+6; 
            break;
            
            case '/' :
             maxValue = maxValue+6; 
            break;
            
            case '=' :
             maxValue = maxValue+5; 
            break;
            
            case '.' :
             maxValue = maxValue+2; 
            break;
            
            case ',' :
             maxValue = maxValue+3; 
            break;  
         }
     }
		delay(300);
		diff = maxValue - 23; 
		hasRead = (hasRead+1)%2 ; // letters can be displayed  
  }
  else 
  {  
     hasRead = 1; // if nothing is on input, then continue with displaying
  }
}

// function for displaying letters
void drawLetter()
{    
   if( i < 0-diff+1 )
      i = endPosition; 
	int poz = i;   

  // dislay read letters
  for( int brojac = 0; brojac <tmpByte; brojac++ )
  {
	  switch( byteArray[brojac] )
	  {
		case 'a' :
		case 'A' :
		
		if( poz >= -5 && poz < 24 )
		   myLeds.write( poz , 0 , letter_A );
		
		poz = poz+6; // places for character and for ' ' sign between
		
		break;
		
		case 'b' :
		case 'B' :
		
		  if( poz >= -5 && poz < 24 )
			myLeds.write( poz , 0 , letter_B );
		   
		poz = poz+6; // places for character and for ' ' sign between
		   
		break;
		
		case 'c' :
		case 'C' :
		
		 if( poz  >= -5 && poz < 24 )
			myLeds.write( poz , 0 , letter_C );
		   
		   poz = poz+6; // places for character and for ' ' sign between
		   
		break;
		
		case 'd' :
		case 'D' :
		
		if( poz >=-5 && poz < 24 )
		   myLeds.write( poz , 0 , letter_D );
		
		poz = poz+6; // places for character and for ' ' sign between
		
		
		break;
		
		case 'e' :
		case 'E' :
		 
		 if( poz >= -5 && poz <24 )
		myLeds.write( poz , 0 , letter_E );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'f' :
		case 'F' :
		
		 if( poz >=-5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_F );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'g' :
		case 'G' :
		
		  if( poz >= -5 && poz < 24  )
		   myLeds.write( poz , 0 , letter_G );
		   
		   poz = poz+6; // places for character and for ' ' sign between
		
		break;
		
		case 'h' :
		case 'H' :
		
		  if( poz >= -5 && poz < 24 ) 
		   myLeds.write( poz , 0 , letter_H );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'i' :
		case 'I' :
		
		  if( poz >=-4 && poz < 24 )
		   myLeds.write( poz , 0 , letter_I );
		
		poz = poz+4; // places for character and for ' ' sign between
		break;
		
		case 'j' :
		case 'J' :
		
		if( poz >= -5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_J );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'k' :
		case 'K' :
		  
		  if( poz >= -5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_K );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'l' :
		case 'L' :
		
		 if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_L );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'm' :
		case 'M' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_M );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'n' :
		case 'N' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_N );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'o' :
		case 'O' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_O );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'p' :
		case 'P' :
		
		 if( poz >= -5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_P );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'q' :
		case 'Q' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_Q );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'r' :
		case 'R' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_R );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 's' :
		case 'S' :
		
		if( poz >= -5 && poz < 24 ) 
		 myLeds.write( poz , 0 , letter_S );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 't' :
		case 'T' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_T );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'u' :
		case 'U' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_U );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'v' :
		case 'V' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_V );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'w' :
		case 'W' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_W );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'x' :
		case 'X' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_X );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case 'y' :
		case 'Y' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_Y );
		
		poz = poz+6; // places for character and for ' ' sign between
		break; 
		
		case 'z' :
		case 'Z' :
		
		if( poz >= -5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_Z );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
	
		case '0' :
		
		if( poz >=-5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_0 );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '1' :
		
		
		myLeds.write( poz , 0 , letter_1 );
		
		poz = poz+5; // places for character and for ' ' sign between
		break;
		
		case '2' :
		
		if( poz >=-5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_2 );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '3' :
		
		if( poz >=-5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_3 );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '4' :
		
		if( poz >=-5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_4 );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '5' :
		
		if( poz >=-5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_5 );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '6' :
		
		if( poz >=-5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_6 );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '7' :
		
		if( poz >=-5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_7 );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '8' :
		
		if( poz >=-5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_8 );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '9' :
		
		if( poz >=-5 && poz < 24 )
		 myLeds.write( poz , 0 , letter_9 );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case ' ' :
		
		
		if( poz >=-2 && poz < 24 )
		  myLeds.write( poz , 0 , letter_blanko );
		
		poz = poz+2; // places for character and for ' ' sign between
		break;
		
		case '!' :
		
		 if( poz >=-2 && poz < 24 )
		  myLeds.write( poz , 0 , letter_uzvik );
		
		poz = poz+2; // places for character and for ' ' sign between
		break;
		
		case '?' :
		
		if( poz >=-5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_zPitanja );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case ':' :
		
		if( poz >=-5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_dveTacke );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '+' :
		
		  if( poz >=-5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_Plus );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '-' :
		
		  if( poz >=-5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_Minus );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '*' :
		if( poz >=-5 && poz < 24 ) 
		 myLeds.write( poz , 0 , letter_Puta );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
		case '/' :
		
		 if( poz >=-5 && poz < 24 )
		  myLeds.write( poz , 0 , letter_Podeljeno );
		
		poz = poz+6; // places for character and for ' ' sign between
		break;
		
	   
		case '=' :
		
		 if( poz >=-4 && poz < 24 )
		  myLeds.write( poz , 0 , letter_Jednako );
		
		poz = poz+5; // places for character and for ' ' sign between
		break;
	   
		case '.' :
		 
		if( poz >=-2 && poz < 24 ) 
		 myLeds.write( poz , 0 , letter_Tacka );
		
		poz = poz+2; // places for character and for ' ' sign between
		break; 
		
		case ',' :
		 
		 if( poz >=-3 && poz < 24 )
		  myLeds.write( poz , 0 , letter_Zapeta );
		 
		 poz = poz+3; // places for character and for ' ' sign between
		break; 
	  }          
     }
        i = i-1; // pomeraj se ulevo
        hasRead = 1;     
        delay(300);     
}
