int i,level,state = 0;
int bump[] = {0,0,-1,1};

void main() {
     TRISB = 1;
     PORTB = 0;
     TRISC = 0x00;
     ADCON0 = 0;

     INTCON.GIE = 1; // Global Interrupt Enable
     INTCON.INTE = 1; // RB0/INT External Interrupt Enable bit
}

void interrupt()       //Interrupt Handler
{
     INTCON.GIE = 0;   //Disable Global Interupt
     if(INTCON.INTF)  //RB0/INT External Interrupt Flag bit is set
     {
      state = 0;
      state = state + PORTB.RB0;
      state = state << 1;
      state = state + PORTB.RB1;
      level = level + bump[state];
     }
     INTCON.INTF = 0; //Clear RB0/INT External Interrupt Flag bit
     INTCON.GIE = 1;  //Enable Global Interrupt
}

