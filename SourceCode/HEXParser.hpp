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
 * Description       : A simple Intel HEX file format reader/writer.
 *
 * 
 ****************************************************************************/
#ifndef HEXPARSER_HPP
#define HEXPARSER_HPP

#include "ErrorMsg.hpp"
#include "Utility.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct HEXRecord; // Preliminary definition.

class HEXFile
{
	protected:
		unsigned char * data; // Holds the data bytes.
		long start, end; // Used data range.
		long size; // Size of databuffer.

		void writeRecord( ofstream & f, HEXRecord * recp );
		void parseRecord( const string & hexLine, HEXRecord * recp );

	public:
		/* Constructor */
		HEXFile( long buffersize, long value = 0xff );

		/* Destructor */
		~HEXFile();

		/* Methods */
		void readFile( const string & _filename ); // Read data from HEX file.
		void writeFile( const string & _filename ); // Write data to HEX file.

		void setUsedRange( long _start, long _end ); // Sets the used range.
		void clearAll( long value = 0xff ); // Set databuffer to this value.

		long getRangeStart() { return start; }
		long getRangeEnd() { return end; }
		long getData( long address );
		void setData( long address, long value );
		long getSize() { return size; }
};


#endif

