
#define TOTAL 4

typedef enum
{
  entebbe = 0,
  gulu,
  lira,
  secret,
}location;

typedef struct
{
  location place;
  String name;
}animals;

animals zoo[TOTAL] = {
                       {entebbe , "cow"},
                       {gulu , "goat"},
                       {lira , "giraffe"},
                       {secret , "hidden"},
                     };

location site(String input);

location site(String input)
{
  int i;
  for(i=0; i<TOTAL; i++)
  {
    if(zoo[i].name == input)
    {
      Serial.print("User input: ");
      Serial.println(zoo[i].name);
      return zoo[i].place;
    }
  }
  return secret;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    String userInput = Serial.readString();
    switch(site(userInput))
    {
      case entebbe:
        Serial.println("Animal is in Entebbe zoo");
      break;

      case gulu:
        Serial.println("Animal is in Gulu zoo");
      break;

      case lira:
        Serial.println("Animal is in Lira zoo");
      break;

      default:
        Serial.println("Animal is in a secret location");
    }

  }
  
}
