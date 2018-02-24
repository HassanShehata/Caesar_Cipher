#include <Arduino.h>

const char* values[]={"A", "B", "C", "D", "E", "F", "G", "H",
"I", "J","K", "L", "M", "N", "O", "P", "Q", "R", "S", "T","U",
"V", "W", "X", "Y", "Z", "a", "b", "c", "d","e", "f", "g", "h",
"i", "j", "k", "l", "m", "n","o", "p", "q", "r", "s", "t", "u",
"v", "w", "x","y", "z", "0", "1", "2", "3", "4", "5", "6", "7",
"8", "9", ":", ".", ",", " "};

void shift(int key)
{
  Serial.println("HELLO");
  int k=key;
  const char* A[]={"a","b","c","e","f"};
  int A_len=sizeof(A)/4;
  const char* B[A_len];
  const char* temp[A_len];
  int inc=0;
  for(int n=A_len-k-1;n<A_len;n++)
  {
    temp[inc]=A[n];
    inc++;
    Serial.println("Debugger for temp: " + String(temp[inc]));
  }
  for(int y=1;y<k+1;y++)
  {
    B[y]=temp[y];
    Serial.println("Debugger for B-first: " + String(B[y]));
  }
}

String caesar(String txt,int shared_key)
{
  int private_key=1;
  int key=shared_key+private_key; 
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  //String txt="Hello";
  int shared_key=2;
  //Serial.println("Plain Text: "+txt);
  //Serial.println("Cipher Text: "+caesar(txt,shared_key));
  shift(shared_key);
  delay(1000);
}
