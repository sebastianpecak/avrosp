/*****************************************************************************
 *
 * Atmel Corporation
 *
 * File              : ErrorMsg.cpp
 * Compiler          : Microsoft Visual Studio 2005
 * Revision          : $Revision: 8.0.50727.42 $
 * Date              : $Date: 2009-06-12 $
 * Updated by        : $Author: Jerry Wong $
 *
 * Support mail      : jacksoonhtp@163.com
 *
 * Target platform   : Win32
 *
 * AppNote           : AVR911 - AVR Open-source Programmer
 *
 * Description       : A class providing serial communication through the PC COM port.
 *                     This class is derived from the CommChannel abstract class.
 *
 * 
 ****************************************************************************/
#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <time.h>
#include <iostream>
#include "CommChannel.hpp"
#include "ErrorMsg.hpp"

using namespace std;


class SerialPort : public CommChannel
{
	protected:
		long portNumber; // COMx port number.
		long timeout; // Desired timeout limit when receiving data.
		HANDLE serialHandle; // Win32 device handle for the com port.
		COMMTIMEOUTS oldComTimeouts; // Store old serial port timeout parameters.
		bool channelOpen; // Is channel open?

	public:
		// Constructor taking port number, baudrate and
		// timeout limit as parameters.
		SerialPort( long portnumber, long timeout );

		// Destructor.
		~SerialPort();

		// Open the communication channel.
		virtual void openChannel();

		// Close the communication channel.
		virtual void closeChannel();

		// Transmit a single byte.
		virtual void sendByte( long data );

		// Receive a single byte.
		virtual long getByte();

		// Flush the transmit buffer.
		virtual void flushTX();

		// Flush the receive buffer.
		virtual void flushRX();

		// Transmit multiple bytes.
		virtual void sendMultiple( unsigned char * data, long bufsize );
};

#endif

