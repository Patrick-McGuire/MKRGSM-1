#ifndef _GSM_H_INCLUDED
#define _GSM_H_INCLUDED

#include <Arduino.h>

enum GSM3_NetworkStatus_t { ERROR, IDLE, CONNECTING, GSM_READY, GPRS_READY, TRANSPARENT_CONNECTED, OFF};

class GSM {

public:
  /** Constructor
      @param debug    Determines debug mode
    */
  GSM(bool debug = false);

  /** Start the GSM/GPRS modem, attaching to the GSM network
      @param pin         SIM PIN number (4 digits in a string, example: "1234"). If 
                         NULL the SIM has no configured PIN.
      @param restart     Restart the modem. Default is TRUE. The modem receives
                         a signal through the Ctrl/D7 pin. If it is shut down, it will
                         start-up. If it is running, it will restart. Takes up to 10 
                         seconds
      @param synchronous If TRUE the call only returns after the Start is complete 
                         or fails. If FALSE the call will return inmediately. You have
                         to call repeatedly ready() until you get a result. Default is TRUE.
      @return If synchronous, GSM3_NetworkStatus_t. If asynchronous, returns 0.
    */
  GSM3_NetworkStatus_t begin(const char* pin = 0, bool restart = true, bool synchronous = true);

  /** Check network access status
      @return 1 if Alive, 0 if down
   */
  int isAccessAlive();

  /** Shutdown the modem (power off really)
      @return true if successful
    */
  bool shutdown();

  /** Secure shutdown the modem (power off really)
      @return always true
    */
  bool secureShutdown();

  /** Get last command status
      @return returns 0 if last command is still executing, 1 success, >1 error
    */
  int ready();
};

#endif
