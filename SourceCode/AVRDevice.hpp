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
 * Description       : A class containing information of device memory sizes etc.
 *                     It also provides funcitons for reading these parameters from
 *                     the PartDescriptionFiles supplied with AVR Studio 4.
 *
 * 
 ****************************************************************************/
#ifndef AVRDEVICE_HPP
#define AVRDEVICE_HPP

#include <string>
#include <vector>
#include "Utility.hpp"
#include "XMLParser.hpp"
#include "ErrorMsg.hpp"

using namespace std;

class AVRDevice
{
	protected:
		string deviceName; // The name of the device, eg. ATmega128.

		long flashSize; // Size of Flash memory in bytes.
		long eepromSize; // Size of EEPROM memory in bytes.
		bool hasFuseBits; // Does this device have fuse bits at all?
		bool hasExtendedFuseBits; // Does this device have extended fuses?
		long signature0;
		long signature1;
		long signature2; // The three signature bytes, read from XML PartDescriptionFiles.
		long pagesize; // Flash page size.

	public:
		/* Constructor */
		AVRDevice( const string & _deviceName );

		/* Destructor */
		~AVRDevice();

		/* Methods */
		void readParametersFromAVRStudio( vector<string> & searchpath );

		long getFlashSize() { return flashSize; }
		long getEEPROMSize() { return eepromSize; }
		long getPageSize() { return pagesize; }
		bool getFuseStatus() { return hasFuseBits; }
		bool getXFuseStatus() { return hasExtendedFuseBits; }

		void getSignature( long * sig0, long * sig1, long * sig2 );
};

#endif

