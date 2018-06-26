#ifndef SERIALPORTLINUX_HPP
#define SERIALPORTLINUX_HPP

#include "CommChannel.hpp"
#include <string>

class SerialPortLinux : public CommChannel
{
    int _portHandle;
    std::string _portName;
    bool _portOpened;

public:
    explicit SerialPortLinux(const char* portName);
    virtual ~SerialPortLinux();

    // Open the communication channel.
	virtual void openChannel();

	// Close the communication channel.
	virtual void closeChannel();

	// Transmit a single byte.
	virtual void sendByte(long data);

	// Receive a single byte.
	virtual long getByte();

	// Flush the transmit buffer.
	virtual void flushTX();

	// Flush the receive buffer.
	virtual void flushRX();

	// Transmit multiple bytes.
	virtual void sendMultiple( unsigned char * data, long bufsize ); 
};

#endif  // SERIALPORTLINUX_HPP
