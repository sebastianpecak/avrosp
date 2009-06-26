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
 * Description       : AVROSP main entry function.
 *
 * 
 ****************************************************************************/
#include "JobInfo.hpp"
#include <vector>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
	JobInfo j;

	try
	{
		j.parseCommandline( argc, argv );
		j.doJob();
	}
	catch( ErrorMsg * e )
	{
		cout << endl << "An error occurred:" << endl;
		cout << "  [" << e->What() << "]" << endl;

		delete e;
	}

	return 0;
}

