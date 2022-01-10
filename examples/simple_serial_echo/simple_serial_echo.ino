#include "simpleSerial.h"
#include "ctype.h"

simple_serial_msg msg;

void setup()
{
  Serial.begin( 115200 );
}

void loop()
{
  simpleSerial :: screen_bytes();

  if( simpleSerial :: simple_serial_available() )
  {
    simpleSerial :: get_simple_serial_message( &msg );

    Serial.print( "Title : " );
    Serial.println( msg.title, HEX );
    for( uint8_t i=0; i<msg.len; i++)
    {
      if( isalnum( msg.message[i] ) ) Serial.print( (char )msg.message[i] );
      else Serial.print( msg.message[i], HEX );
      Serial.print( " " );
    }
    Serial.println();
    
    simpleSerial :: simple_serial_delete( msg );
  }

  if( simpleSerial :: byte_available() )
  {
    uint8_t byt = simpleSerial :: byte_read();
    if( isalnum(byt) ) Serial.println( (char)byt );
    else Serial.println( byt, HEX );
  }
}
