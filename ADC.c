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

int16 datoCanal0=0, datoCanal1=0;

int16 rango(int16 dato);

#INT_AD
VOID AD_ISR(VOID){
   
   set_adc_channel(0);
   datoCanal0=read_ADC(adc_start_and_read);
   
   set_adc_channel(1);
   datoCanal1=read_ADC(adc_start_and_read);
   read_adc(adc_start_only);
   
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

   Setup_ADC(adc_clock_internal | ADC_TAD_MUL_4);
   Setup_ADC_PORTS(AN0_to_AN1);
   read_adc(adc_start_only);
   int16 rango1, rango2;
   
   while(true){
      
      rango1 = rango(datoCanal0);
      rango2 = rango(datoCanal1);
      output_b(rango1);
      output_c(rango1>>8);
      output_d(rango2);
      output_e(rango2>>8);
      
   } 
}

int16 rango(int16 dato){
   
   int16 valor=0;
   if(dato==0)
      valor=0;
   if(dato>=1 && dato<=113)
      valor=1;
   if(dato>=114 && dato<=226)
      valor=2;
   if(dato>=227 && dato<=339)
      valor=4;
   if(dato>=340 && dato<=452)
      valor=8;
   if(dato>=453 && dato<=565)
      valor=16;
   if(dato>=566 && dato<=678)
      valor=32;
   if(dato>=679 && dato<=791)
      valor=64;
   if(dato>=792 && dato<=904)
      valor=128;
   if(dato>=905 && dato<=1022)
      valor=256;
   if(dato==1023)
      valor=512;
   
   return valor; 
}
