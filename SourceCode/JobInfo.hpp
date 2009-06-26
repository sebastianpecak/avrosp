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
 * Description       : A class holding information on what the AVR Open-Source Programmer
 *                     should do. The information is derived from the command-line.
 *
 * 
 ****************************************************************************/
#ifndef JOBINFO_HPP
#define JOBINFO_HPP

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "ErrorMsg.hpp"
#include "AVRProgrammer.hpp"
#include "AVRBootloader.hpp"
#include "AVRInSystemProg.hpp"
#include "AVRDevice.hpp"
#include "SerialPort.hpp"
#include "Utility.hpp"

using namespace std;

#define ADD_TESTMODE

class JobInfo
{
	protected:
		long convertHex( char * txt );
		void help();
		void doDeviceIndependent( AVRProgrammer * prog );
		void doDeviceDependent( AVRProgrammer * prog, AVRDevice * avr );
#ifdef ADD_TESTMODE
		void enterTestMode();
#endif


		bool showHelp; // Show help screen?
		bool silentMode; // No text output?
		bool noProgressIndicator; // Do not show progress indicators?
		bool readSignature; // Output signature bytes to screen?
		bool chipErase; // Erase chip before any programming operations?
		bool getHWrevision; // Get hardware revision of programmer?
		bool getSWrevision; // Get software revision of programmer?
		bool programFlash; // Flash programming desired?
		bool programEEPROM; // E2 programming desired?
		bool readFlash; // Flash readout desired?
		bool readEEPROM; // E2 readout desired?
		bool verifyFlash; // Flash verification desired?
		bool verifyEEPROM; // E2 verification desired?
		bool readLockBits; // Lock bit readout desired?
		bool readFuseBits; // Fuse bit readout desired?
		bool readOSCCAL; // Read or use specified OSCCAL value, if -O is used?
#ifdef ADD_TESTMODE
		bool testMode; // Enter test mode.
#endif

		string deviceName; // Specified device name.
		string inputFileFlash; // Input file for Flash writing and verification.
		string inputFileEEPROM; // Input file for E2 writing and verification.
		string outputFileFlash; // Output file for Flash readout.
		string outputFileEEPROM; // Output file for E2 readout.
#ifdef ADD_TESTMODE
		string testModeName; // Specified test mode name.
#endif

		long OSCCAL_Parameter; // Value of the -O parameter, -1 if unspecified.

		long OSCCAL_FlashAddress; // Where to put OSCCAL value in flash, -1 if not.
		long OSCCAL_EEPROMAddress; // Where to put OSCCAL value in E2, -1 if not.

		long programLockBits; // Change lock bits to this value, -1 if not.
		long verifyLockBits; // Verify lock bits against this value, -1 if not.

		long programFuseBits; // Change fuse bits to this value, -1 if not.
		long programExtendedFuseBits; // Same as above for extended fuse bits.
		long verifyFuseBits; // Verify fuse bits against this value, -1 if not.
		long verifyExtendedFuseBits; // Same as above for extended fuse bits.

		long memoryFillPattern; // Fill unspecified locations, -1 if not.

		long flashStartAddress; // Limit Flash operations, -1 if not.
		long flashEndAddress; // ...to this address, inclusive, -1 if not.

		long eepromStartAddress; // Same as above for E2.
		long eepromEndAddress; // ...

		long comPort; // Desired COM port to use, -1 if unspecified.

		vector<string> searchpath; // Search path for XML-files.

	public:
		JobInfo(); // Constructor

		void parseCommandline( int argc, char *argv[] );
		void doJob();
};

#endif

