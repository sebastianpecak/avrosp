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
 * Description       : A class providing a container for general error messages. This
 *                     class can be thrown as an exception.
 *
 * 
 ****************************************************************************/
#include "ErrorMsg.hpp"


ErrorMsg::ErrorMsg( const string & _message ) :
	message( _message )
{
	// No code here.
}


/* Destructor */
ErrorMsg::~ErrorMsg()
{
	// No code here.
}


/* Get message */
const string & ErrorMsg::What()
{
	return message;
}

/* end of file */

