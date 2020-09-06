// #include <wiringPi.h>

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>

// int main (void)
// {
// 	int bright ;

// 	printf ("Raspberry Pi wiringPi PWM test program\n") ;

// 	if (wiringPiSetup () == -1)
// 	exit (1) ;

// 	pinMode (1, PWM_OUTPUT) ;

// 	for (;;)
// 	{
// 	for (bright = 0 ; bright < 1024 ; ++bright)
// 	{
// 		pwmWrite (1, bright) ;
// 		delay (1) ;
// 	}

// 	for (bright = 1023 ; bright >= 0 ; --bright)
// 	{
// 		pwmWrite (1, bright) ;
// 		delay (1) ;
// 	}
// 	}

//     if (wiringPiSetup () == -1) //using wPi pin numbering
//     {
//     exit (1);
//     }

//     pinMode(1, PWM_OUTPUT);
//     pwmSetMode(PWM_MODE_MS); 
//     pwmSetClock(384); //clock at 50kHz (20us tick)
//     pwmSetRange(1000); //range at 1000 ticks (20ms)
//     pwmWrite(1, 75);  //theretically 50 (1ms) to 100 (2ms) on my servo 30-130 works ok
//     return 0 ;
// }

#include <wiringPi.h>
#include <stdio.h>

//eye position (right / left) as if your own eyes

int main (void)
{
   printf ("Raspberry Pi wiringPi test program\n");
   wiringPiSetupGpio();
   
   pinMode (18, PWM_OUTPUT);  	//left eye horizontal movement
   pinMode (24, PWM_OUTPUT);     //left eye vertical movement
   
   pwmSetMode (PWM_MODE_MS);
   pwmSetClock(384); //clock at 50kHz (20us tick)
   pwmSetRange (2000);
   pwmSetClock (192);


   //look left, delay
   printf ("look left, delay\n");
   pwmWrite(18, 540);
   delay(1000);
   
   //look right, delay
   printf ("look right, delay\n");
   pwmWrite(18, 240);
   delay(1000);

   //look middle, delay
   printf ("look middle\n");
   pwmWrite(18, 420);
   delay(1000);

   // //look up, delay
   // printf ("look up\n");
   // pwmWrite(24, 300);
   // delay(1000);

   // //look down, delay
   // printf ("look down\n");
   // pwmWrite(24, 420);
   // delay(1000);

   // //look middle, delay
   // printf("look middle\n");
   // pwmWrite(24, 500);
   // delay(1000);

   printf("end of program.\n");

   return 0;
}