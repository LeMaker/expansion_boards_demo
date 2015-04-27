#include <stdio.h>
#include <wiringPi.h>
#include <mcp23017.h>

int main (void)
{
  int i, bit ;

  wiringPiSetup () ;
  mcp23017Setup (100, 0x20) ;
  mcp23017Setup (200, 0x21) ;

  printf ("MCP23017 USB_HUB Test\n") ;

  for (i = 0 ; i < 16 ; ++i)
  {
    pinMode (100 + i, OUTPUT) ;
    pinMode (200 + i, OUTPUT) ;
  }

  for (i = 0 ; i < 2 ; i++)
  {
    for (bit = 0 ; bit < 16 ; ++bit)
    {
      digitalWrite (100 + bit, 1) ;
      digitalWrite (200 + bit, 1) ;
    }
    delay (500) ;
    for (bit = 0 ; bit < 16 ; ++bit)
    {
      digitalWrite (100 + bit, 0) ;
      digitalWrite (200 + bit, 0) ;
    }
    delay (500) ;
  }
  return 0 ;
}
