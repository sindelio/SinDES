# SinDES - Sindélio's Data Encryption Standard

A simple simmetric cryptography algorithm for general purposes.

### Algorithm explanation

The SinDES is a symmetric algorithm, which means that it uses the same key for encryption and decryption. It is also a block algorithm, meaning that processes data in blocks and not in a stream. The SinDES uses substitution, transposition and OR-EXCLUSIVE operations to encrypt the data present in a file. These operations are common in standard algorithms such as DES, 3DES and AES.

### Cryptographic key function

The function of the cryptographic key is to introduce an influence in the algorithm known only to the parties involved in the communication. That's accomplished through the OR-EXCLUSIVE bitwise operation of the data to be encrypted and the cryptographic key. In turn, that means the cryptographic key must have the same size of the block being processed by the SinDES algorithm.

### Algorithm restrictions

The SinDES algorithm is a block algorithm, and can't be used to process a stream of data. Also, the objective of this algorithm is to illustrate how cryptographic algorithms work in general, and not become a standard or next gen crypto algorithm. That being said, the SinDES algorithm has a relatively low complexity, specially due to 2 factors:

- Simple substitution operation.
- Unique iteration of the substitution, transposition and OR-EXCLUSIVE operations.

### Key exchange strategy

The usual strategy to exchange a symmetric key consists in the following steps:

1. Choosing and asymmetric algorithm.
2. Encrypting the symmetric key with the public asymmetric key of the addressee.
3. Sending the encrypted symmetric key to the addressee.
4. The addressee decrypts the symmetric key with his private asymmetric key.

Then messages can be sent or received with the SinDES algorithm, without third parties knowing the symmetric key applied in the encryption or decryption of these messages.

### Compiling instructions


