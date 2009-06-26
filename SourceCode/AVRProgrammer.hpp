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
#ifndef AVRPROGRAMMER_HPP
#define AVRPROGRAMMER_HPP

#include "ErrorMsg.hpp"
#include "HEXParser.hpp"
#include "CommChannel.hpp"

using namespace std;

class AVRProgrammer
{
	protected:
		long pagesize; // Flash page size.
		CommChannel * comm;

	public:
		/* Constructor */
		AVRProgrammer( CommChannel * _comm );

		/* Destructor */
		~AVRProgrammer();

		/* Static member */
		static string readProgrammerID( CommChannel * _comm ); // Reads 7-character ID.

		/* Methods */
		void setPagesize( long _pagesize ) { pagesize = _pagesize; }

		virtual bool enterProgrammingMode() = 0;
		virtual bool leaveProgrammingMode() = 0;

		virtual bool chipErase() = 0;

		virtual bool readOSCCAL( long pos, long * value ) = 0;
		virtual bool readSignature( long * sig0, long * sig1, long * sig2 ) = 0;
		virtual bool checkSignature( long sig0, long sig1, long sig2 ) = 0;

		virtual bool writeFlashByte( long address, long value ) = 0;
		virtual bool writeEEPROMByte( long address, long value ) = 0;

		virtual bool writeFlash( HEXFile * data ) = 0;
		virtual bool readFlash( HEXFile * data ) = 0;

		virtual bool writeEEPROM( HEXFile * data ) = 0;
		virtual bool readEEPROM( HEXFile * data ) = 0;

		virtual bool writeLockBits( long bits ) = 0;
		virtual bool readLockBits( long * bits ) = 0;

		virtual bool writeFuseBits( long bits ) = 0;
		virtual bool readFuseBits( long * bits ) = 0;
		virtual bool writeExtendedFuseBits( long bits ) = 0;
		virtual bool readExtendedFuseBits( long * bits ) = 0;

		virtual bool programmerSoftwareVersion( long * major, long * minor ) = 0;
		virtual bool programmerHardwareVersion( long * major, long * minor ) = 0;
};


#endif

