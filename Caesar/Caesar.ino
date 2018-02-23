#include <Arduino.h>

String values[]={"A", "B", "C", "D", "E", "F", "G", "H",
"I", "J","K", "L", "M", "N", "O", "P", "Q", "R", "S", "T","U",
"V", "W", "X", "Y", "Z", "a", "b", "c", "d","e", "f", "g", "h",
"i", "j", "k", "l", "m", "n","o", "p", "q", "r", "s", "t", "u",
"v", "w", "x","y", "z", "0", "1", "2", "3", "4", "5", "6", "7",
"8", "9", ":", ".", ",", " "};

void shift(int key)
{
  Serial.print("HELLO");
  int k=key;
  String A[]={"a","b","c","e","f"};
  int A_len=sizeof(A)/4;
  String B[]={"0","0","0","0","0"};
  for(int i=0;i<A_len-1-k;i++)
  {
    B[i+k]=A[i];
    Serial.println("For debugger 1:"+String(A[i]));
  }
  delay(1000);
  int back=0;
  for(int n=A_len;n>A_len-k;n--)
  {
    B[back]=A[n];
    Serial.println("For debugger 2:"+String(A[n]));
    back++;
  }
  delay(1000);
  for(int x=0;x<A_len-1;x++)
  {
    Serial.println(String(B[x]));
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
  int shared_key=1;
  //Serial.println("Plain Text: "+txt);
  //Serial.println("Cipher Text: "+caesar(txt,shared_key));
  shift(shared_key);
  delay(60000);
}
