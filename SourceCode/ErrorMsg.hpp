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
#ifndef ERRORMSG_HPP
#define ERRORMSG_HPP

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class ErrorMsg
{
	protected:
		string message; // Contains the error message.

	public:
		// Constructors taking the string as parameter.
		ErrorMsg( const string & _message );

		// Destructor
		~ErrorMsg();

		// Function returning the error msg.
		virtual const string & What();
};

#endif

