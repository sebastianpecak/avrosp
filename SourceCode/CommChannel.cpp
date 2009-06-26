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
 * Description       : An abstract class for general byte-by-byte communication.
 *                     Serialport, USB, TCP/IP or similar implementations can be derived
 *                     from this class to create a technology-independent
 *                     communication interface.
 *
 *                     This abstract class does not provide any constructor as it is
 *                     too specific for this generalized class. Derived classes should
 *                     implement their own constructors for specific communication devices.
 *
 * 
 ****************************************************************************/
#include "CommChannel.hpp"


/* Destructor */
CommChannel::~CommChannel()
{
	/* no code here */
}

/* end of file */

