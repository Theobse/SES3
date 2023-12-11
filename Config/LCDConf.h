#ifndef LCDCONF_H
#define LCDCONF_H

// Define this term if running on LPC4088 OEM module. Comment out if on a LPC1788 OEM module
//#define LPC4088

#ifdef LPC4088
#define LPC_SSP LPC_SSP2
#else
#define LPC_SSP LPC_SSP0
#endif

#endif /* LCDCONF_H */
