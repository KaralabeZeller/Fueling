# Fueling

## bvez2

### Compilig

#### Required software:
- MPLAB X IDE: https://www.microchip.com/mplab/mplab-x-ide
- X16C compiler: https://www.microchip.com/mplab/compilers

### Troubleshoot
####  Comilation errors:
- undefined reference to `ClrWdt': Replace ClrWdt() with asm("clrwdt");
- undefined reference to `Nop': Replace Nop()    with asm("nop");
