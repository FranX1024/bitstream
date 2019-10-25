# Bit stream library
## Introduction
This library was made to make things like decoding / encoding base64 and accessing binary files easier.
## Creating a bitstream
New bitstream is created by typing
```cpp
bitStream bs;
bs.open(/* desired size in bytes */);
```
The size is in bytes cause the bitstream uses byte arrays to save data.
Bit stream can also be created from an existing byte array.
```cpp
bitStream bs;
bs.openBytes(/* array pointer */, /* array size */);
```
After opening bitstream and working with it can be closed by doing typing
```cpp
bs.close();
```
Closing a bitstream frees memory that was allocated to create it.
If you created the bitstream by opening an array then closing the bitstream will free memory allocated for the array.
## Writing to and reading from bitstream
To read from bitstream you type
```cpp
bs.read(/* index (in bits) */, /* size (in bits) */);
```
and to write to bitstream use
```cpp
bs.write(/* index (int bits) */, /* size (in bits) */, /* an integer (a value) */);
```
size must be smaller than 32 bits and the value is an integer.
If we have the following bitstream
```
0 0 0 1 1 0 1 1
```
and we type
```cpp
bs.write(0, 4, 11); // 11 = binary 1011
```
we will get
```
written value
   |
+--+--+
1 0 1 1 1 0 1 1
```
To turn the bitstream to a byte array type
```cpp
bs.toByteArray(); // returns a char* pointer (when changes are made to the bitstream using bs.write, the returned array will also change)
```
