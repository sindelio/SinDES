# SinDES - Sindélio's Data Encryption Standard

A simple simmetric cryptography algorithm for general purposes.

### Algorithm explanation

The SinDES is a symmetric algorithm, which means that it uses the same key for encryption and decryption. It is also a block algorithm, meaning that it processes data in blocks and not in a stream. The SinDES uses substitution, transposition and OR-EXCLUSIVE operations to encrypt the data present in a file. These operations are common in standard algorithms such as DES, 3DES and AES.

### Cryptographic key function

The function of the cryptographic key is to introduce an influence in the algorithm known only to the parties involved in the communication. That's accomplished through the OR-EXCLUSIVE bitwise operation of the data to be encrypted and the cryptographic key. In turn, that means the cryptographic key must have the same size of the block being processed by the SinDES algorithm.

### Algorithm restrictions

The SinDES algorithm is a block algorithm, and can't be used to process a stream of data. Also, the objective of this algorithm is to illustrate how cryptographic algorithms work in general, and not become a standard or next gen crypto algorithm. That being said, the SinDES algorithm has a relatively low complexity, specially due to 2 factors:

- Simple substitution operation.
- Unique iteration of the substitution, transposition and OR-EXCLUSIVE operations.

If an algorithm robust against brute force attacks is needed, I suggest work on these 2 factors.

### Key exchange strategy

The usual strategy to exchange a symmetric key consists in the following steps:

1. Choosing an asymmetric cryptography algorithm.
2. Encrypting the symmetric key with the public asymmetric key of the addressee.
3. Sending the encrypted symmetric key to the addressee.
4. The addressee decrypts the symmetric key with his private asymmetric key.

Then messages can be sent or received with the SinDES algorithm, without third parties knowing the symmetric key applied in the encryption or decryption of these messages.

### Compiling instructions

The SinDES algorithm is written in C and was compiled on a Ubuntu operating system, which is a Debian based Linux distribution. The compiler used was:
```
GCC version 5.4.0
```
The C libraries used in the project were:

- stdlib.h
- stdio.h
- string.h
- stdbool.h

Which are all standard C libraries. 
To compile the code, run:
```
$ gcc algorithm.c -o algorithm -Wall
```
The -Wall flag doesn't allow compilation if there is any warning in the code.

### Running instructions

To run the compiled program:
```
$ ./algorithm argument1 argument 2 argument3
```
Whereas:
argument1 - Name of the file to be encrypted.
argument2 - Action required of the program. Can be "enc" for encryption or "dec" for decryption.
argument3 - Name of the file containing the symmetric key.

The project already has a sample file (sample_file.txt) and a sample symmetric key (sample_key.txt) that you can use straight away to test the program. 

Encryption command example:
```
$ ./algorithm sample_file.txt enc sample_key.txt
```
Note: The encryption process always creates an encrypted file (encrypted_file.txt) as a result. 
Decryption command example:
```
$ ./algorithm encrypted_file.txt dec sample_key.txt
```
### Contributions

ANY CONTRIBUTIONS AND COMMENTS ARE MUCH WELCOME!

### Copyright and license
This code is distributed under [the MIT license](https://github.com/sindelio/SinDES/blob/master/LICENSE).

### That's all folks _o/
