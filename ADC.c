#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, STVREN, NOLVP, NODEBUG,
#device ADC  = 10
#use delay(clock=16000000)
#use fast_io(A)
#use fast_io(B)
#use fast_io(C)
#use fast_io(D)
#use fast_io(E)
int contador, banderaUno;

#INT_AD
VOID AD_ISR(VOID){
   
   
}

char Leer_ADC(char canal){
   char dato;
   set_ADC_channel(canal);
   delay_ms(20);
   dato = read_ADC();
   delay_ms(10);
   return dato;
}

void main() {
   set_tris_a(0xFF);
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_d(0x00);
   set_tris_e(0x08);
   output_b(0x00);
   output_c(0x00);
   output_d(0x00);
   output_e(0x00);
   enable_interrupts(INT_AD);
   enable_interrupts(GLOBAL);
   Setup_ADC(ADC_CLOCK_INTERNAL);   
   Setup_ADC_PORTS(AN0_to_AN1);
   int16 valor_1, valor_2;
   while(true){
      valor_1= leer_ADC(0);
      valor_2= leer_ADC(1);
         
   } 
}

