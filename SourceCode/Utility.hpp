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
 * Description       : A class holding misc. utility methods used in AVROSP.
 *
 * 
 ****************************************************************************/
#ifndef UTILITY_HPP
#define UTILITY_HPP

#ifndef NOREGISTRY
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <vector>
#include <string>
#include "ErrorMsg.hpp"

using namespace std;

class Utility
{
	protected:
		bool noLog;
		bool noProgress;

	public:
		/* Constructor */
		Utility();

		/* Destructor */
		~Utility();

		/* Methods */
		void muteLog() { noLog = true; }
		void muteProgress() { noProgress = true; }

		void log( const string & txt );
		void progress( const string & txt );

		long convertHex( const string & txt );
		string convertLong( long num, long radix = 10 );

		void parsePath( vector<string> & list );
		bool fileExists( string filename );
		void saveString( string txt, string filename );

#ifndef NOREGISTRY	
		string getRegistryValue( const string & path, const string & value );
#endif
};

extern Utility Util;

#endif

