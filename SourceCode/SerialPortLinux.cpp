#include "SerialPortLinux.hpp"
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include "ErrorMsg.hpp"
#include <termios.h>
#include <unistd.h>

//////////////////////////////////////////////////////////////
SerialPortLinux::SerialPortLinux(const char* portName) :
    _portHandle(-1),
    _portName(portName),
    _portOpened(false)
{
}

//////////////////////////////////////////////////////////////
SerialPortLinux::~SerialPortLinux()
{
    closeChannel();
}

//////////////////////////////////////////////////////////////
void SerialPortLinux::openChannel()
{
    /* Check if channel already open */
	if(_portOpened)
		throw new ErrorMsg("Channel already open! Cannot open port twice.");

	/* Generate COM filename and attempt open */
	//comName[3] = '0' + portNumber;
	//serialHandle = CreateFile( comName, GENERIC_READ | GENERIC_WRITE, 0, NULL,
	//		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );

    // Try to open port.
    _portHandle = open(_portName.c_str(), O_RDWR | O_NOCTTY | O_SYNC);

	/* Print error and return if failed opening port */
	//if( serialHandle == INVALID_HANDLE_VALUE )
    if (_portHandle < 0)
		throw new ErrorMsg("Error opening serial port!");

	struct termios oldtio = {0}, newtio  ={0};

	tcgetattr(_portHandle, &oldtio); /* save current serial port settings */

	cfsetospeed (&oldtio, B115200);
    cfsetispeed (&oldtio, B115200);

	oldtio.c_cflag = (oldtio.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
        // disable IGNBRK for mismatched speed tests; otherwise receive break
        // as \000 chars
        oldtio.c_iflag &= ~IGNBRK;         // disable break processing
        oldtio.c_lflag = 0;                // no signaling chars, no echo,
                                        // no canonical processing
        oldtio.c_oflag = 0;                // no remapping, no delays
        oldtio.c_cc[VMIN]  = 0;            // read doesn't block
        oldtio.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        oldtio.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

        oldtio.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
        oldtio.c_cflag &= ~(PARENB | PARODD);      // shut off parity
        //oldtio.c_cflag |= parity;
        oldtio.c_cflag &= ~CSTOPB;
        oldtio.c_cflag &= ~CRTSCTS;

	tcsetattr(_portHandle, TCSANOW, &oldtio);


	//channelOpen = true;
    _portOpened = true;

	/* Store old COM port settings */
	// if( !GetCommTimeouts( serialHandle, &oldComTimeouts ) )
	// 	throw new ErrorMsg( "Error reading COM port settings!" );

	// /* Get another copy of the COM settings, and change them */
	// if( !GetCommTimeouts( serialHandle, &comTimeouts ) )
	// 	throw new ErrorMsg( "Error reading COM port settings!" );

	// comTimeouts.ReadIntervalTimeout = MAXDWORD;
	// comTimeouts.ReadTotalTimeoutConstant = 0;
	// comTimeouts.ReadTotalTimeoutMultiplier = 0;

	// /* Apply new settings */
	// if( !SetCommTimeouts( serialHandle, &comTimeouts ) )
	// 	throw new ErrorMsg( "Error changing COM port settings!" );
}

//////////////////////////////////////////////////////////////
void SerialPortLinux::closeChannel()
{
    if (_portOpened)
    {
        /* Release port */
        //if( serialHandle != INVALID_HANDLE_VALUE )
        //if( !CloseHandle( serialHandle ) )
        if (close(_portHandle) < 0)
            throw new ErrorMsg( "Error closing COM port!" );

        _portHandle = -1;
        _portOpened = false;
    }
}

//////////////////////////////////////////////////////////////
void SerialPortLinux::sendByte(long data)
{
    /* Check if channel is open */
	if(!_portOpened)
		throw new ErrorMsg( "Channel not open! Cannot send to unopened channel." );

	/* Attempt writing */
	// Works only for little-endian platforms. Crap.
	//if( !WriteFile( serialHandle, &data, 1, &written, NULL ) )
    if (!write(_portHandle, &data, 1))
		throw new ErrorMsg( "Error writing byte to COM port!" );
}

//////////////////////////////////////////////////////////////
long SerialPortLinux::getByte()
{
    /* Check if channel is open */
	if( !_portOpened )
		throw new ErrorMsg( "Channel not open! Cannot read from unopened channel." );

    unsigned char data = 0;
    if (!read(_portHandle, &data, 1))
        throw new ErrorMsg( "Error reading byte from COM port!" );

    return (long)data;
}

//////////////////////////////////////////////////////////////
void SerialPortLinux::flushTX()
{
    /* Check if channel is open */
	if( !_portOpened )
		throw new ErrorMsg( "Channel not open! Cannot flush an unopened channel." );

    sleep(2); //required to make flush work, for some reason
    
    /* Purge data from write buffer */
	//if( tcflush(_portHandle,TCOFLUSH) < 0)
	//	throw new ErrorMsg( "Error flushing COM port TX buffer!" );

}

//////////////////////////////////////////////////////////////
void SerialPortLinux::flushRX()
{
    /* Check if channel is open */
	if( !_portOpened )
		throw new ErrorMsg( "Channel not open! Cannot flush an unopened channel." );

    sleep(2); //required to make flush work, for some reason
    
    /* Purge data from write buffer */
	//if( !tcflush(_portHandle,TCIFLUSH) < 0 )
//		throw new ErrorMsg( "Error flushing COM port TX buffer!" );
}

//////////////////////////////////////////////////////////////
void SerialPortLinux::sendMultiple( unsigned char * data, long bufsize )
{
    /* Check if channel is open */
	if( !_portOpened )
		throw new ErrorMsg( "Channel not open! Cannot write to unopened channel." );

	/* Attempt writing */
	if( !write( _portHandle, data, bufsize ) )
		throw new ErrorMsg( "Error writing multiple bytes to COM port!" );
}
