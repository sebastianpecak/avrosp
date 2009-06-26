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
 * Description       : An abstract class containing a framework for a generic
 *                     programmer for AVR parts. Reading and writing Flash, EEPROM
 *                     lock bits and all fuse bits and reading OSCCAL and reading
 *                     signature bytes are supported.
 *
 *
 ****************************************************************************/
#include "AVRProgrammer.hpp"


/* Constructor */
AVRProgrammer::AVRProgrammer( CommChannel * _comm ) :
	pagesize( -1 )
{
	if( _comm == NULL )
		throw new ErrorMsg( "NULL pointer provided for communication channel!" );

	comm = _comm;
}


/* Destructor */
AVRProgrammer::~AVRProgrammer()
{
	/* No code here */
}


string AVRProgrammer::readProgrammerID( CommChannel * _comm )
{
	string id( "1234567" ); // Reserve 7 characters.

	if( _comm == NULL )
		throw new ErrorMsg( "NULL pointer provided for communication channel!" );

	/* Synchonize with programmer */
	for( int i = 0; i < 10; i++ )
		_comm->sendByte( 27 ); // Send ESC

	/* Send 'S' command to programmer */
	_comm->sendByte( 'S' );
	_comm->flushTX();

	/* Read 7 characters */
	for( long i = 0; i < id.size(); i++ )
	{
		id[i] = _comm->getByte();
	}

	return id;
}

/* end of file */

