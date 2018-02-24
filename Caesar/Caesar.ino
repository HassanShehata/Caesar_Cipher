#include <Arduino.h>

const char* A[]={"A", "B", "C", "D", "E", "F", "G", "H",
"I", "J","K", "L", "M", "N", "O", "P", "Q", "R", "S", "T","U",
"V", "W", "X", "Y", "Z", "a", "b", "c", "d","e", "f", "g", "h",
"i", "j", "k", "l", "m", "n","o", "p", "q", "r", "s", "t", "u",
"v", "w", "x","y", "z", "0", "1", "2", "3", "4", "5", "6", "7",
"8", "9", ":", ".", ",", " "};
const int A_len=sizeof(A)/4;
String B[A_len];

void shift(int key)
{
  int k=key;
  //const char* A[]={"a","b","c","e","f"};
  const char* temp[A_len];
  int inc=0;
  for(int n=A_len-k-1;n<A_len;n++)
  {
    temp[inc]=A[n];
    inc++;
    //Serial.println("Debugger for temp: " + String(temp[inc]));
  }
  for(int y=1;y<k+1;y++)
  {
    B[y]=String(temp[y]);
    //Serial.println("Debugger for B-first: " + String(B[y]));
  }
  for(int i=0;i<A_len-k;i++)
  {
    B[i+k]=String(A[i]);
    //Serial.println("Debugger for B-second: " + String(B[i+k]));
  }
  /*delay(1000);
  for(int b=0;b<A_len;b++)
  {
    Serial.print(String(B[b])+", ");
  }*/
}

String caesar(String txt,int shared_key)
{
  int private_key=1;
  int key=shared_key+private_key;
  shift(key); 
  String cipher_txt="";
  for(int n=1;n<txt.length()+1;n++)
  {
    for(int i=0;i<A_len;i++)
    {
      if(String(txt.substring(n-1,n)) == String(A[i]))
      {
        cipher_txt=cipher_txt+String(B[i+1]);
      }
    }
  }
  return cipher_txt;
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  String txt="HELLO";
  String cipher;
  int shared_key=6;
  cipher= caesar(txt,shared_key); 
  Serial.println("Plain: "+ txt + " cipher: "+ cipher);
  delay(1000);
}
