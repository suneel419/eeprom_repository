#include<EEPROM.h>
int address=0; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
EEPROM.begin(100);
EEPROM.writeByte(address, 123); 
address=address+sizeof(byte);

EEPROM.writeChar(address,'A');
address=address+sizeof(char);

EEPROM.writeUChar(address,255);
address=address+sizeof(unsigned char);

EEPROM.writeInt(address,65);
address=address+sizeof(int);

EEPROM.writeShort(address,-32768);
address=address+sizeof(short);

EEPROM.writeUShort(address,65535);
address=address+sizeof(unsigned short);

EEPROM.writeUInt(address, 4294967295);            // 2^32 - 1
address += sizeof(unsigned int);

EEPROM.writeLong(address,-2147483648);
address+=sizeof(long);

EEPROM.writeULong(address,4294967295);
address+=sizeof(unsigned long);

int64_t value=-1223372036854775808LL;
EEPROM.writeLong64(address,value);
address+=sizeof(int64_t);

uint64_t Value=18446744073709551615ULL;
EEPROM.writeULong64(address,Value);
address+=sizeof(uint64_t);

EEPROM.writeFloat(address,123.16);
address+=sizeof(float);

EEPROM.writeDouble(address,123456789.123456789);
address+=sizeof(double);

EEPROM.writeBool(address,true);
address+=sizeof(bool);

String sentence="I LOVE MY INDIA";
EEPROM.writeString(address,sentence);
address+=sentence.length()+1;

char abc[20]="I LOVE MY FAMILY";
EEPROM.writeString(address,abc);
address+=20;


  

EEPROM.commit();
address=0;

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readByte(address));
address += sizeof(byte);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readChar(address));
address +=sizeof(char);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readUChar(address));
address+=sizeof(unsigned char);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readInt(address));
address +=sizeof(int);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readShort(address));
address+=sizeof(short);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readUShort(address));
address+=sizeof(unsigned short);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readUInt(address));
address+=sizeof(unsigned int);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readLong(address));
address+=sizeof(long);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readULong(address));
address+=sizeof(unsigned long);

value=0;
value=EEPROM.readLong64(value);
Serial.print(address);Serial.print(":");
Serial.printf("0x%08X",(uint32_t)(value >> 32));
Serial.printf("%08X\n",(uint32_t)value);
address+=sizeof(int64_t);

value=0;
value=EEPROM.readULong64(value);
Serial.print(address);Serial.print(":");
Serial.printf("0x%08X",(uint32_t)(Value >> 32));
Serial.printf("%08X\n",(uint32_t)Value);
address+=sizeof(uint64_t);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readFloat(address));
address+=sizeof(float);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readDouble(address));
address+=sizeof(double);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readBool(address));
address+=sizeof(bool);

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readString(address));
address+=sentence.length()+1;

Serial.print(address);Serial.print(":");
Serial.println(EEPROM.readString(address));
address+=20;


for(int i=0;i<90;i++)
{
  
  Serial.print("The location of ");Serial.print(i);Serial.print(" value is in HEX");Serial.print(":");Serial.println(EEPROM.read(i),HEX);
  Serial.print("The location of ");Serial.print(i);Serial.print(" value is in BIN");Serial.print(":");Serial.println(EEPROM.read(i),BIN);
  Serial.print("The location of ");Serial.print(i);Serial.print(" value is in DEC");Serial.print(":");Serial.println(EEPROM.read(i),DEC);
  Serial.print("The location of ");Serial.print(i);Serial.print(" value is in CHAR");Serial.print(":");Serial.println(char(EEPROM.read(i)));
  Serial.print("The location of ");Serial.print(i);Serial.print(" value is in int");Serial.print(":");Serial.println(int(EEPROM.read(i)));
}

}

void loop() {
  // put your main code here, to run repeatedly:

}
