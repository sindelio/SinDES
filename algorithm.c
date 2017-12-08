/* University of São Paulo 
** 
** Computer Engineering
** Security Engineering Project
** Professor(a): Kalinka Branco
** Theme: Criptography Algorithm
** Author(a): Sindélio Henrique Lima
** Lots of coffee spent to hone this code!
**
*/
   
#include <stdlib.h> // rand() e etc.
#include <stdio.h> // printf, fread, fwrite, type FILE*.
#include <string.h> // strcmp().
#include <stdbool.h> // tipo bool.

#define BLOCK_SIZE 128 // Processing block size for the algorithm

bool file_end = false;

// Function to write the decryption in a file
void Write_Decrypted_File(FILE *p, char *aux){
	int i = 0;
	for(i = 0; i < BLOCK_SIZE; i++){
		if(aux[i] == 0){
			return;
		}
		fwrite(aux + i, 1, sizeof(char), p);
	}
	return;
}

// Function to write the encryption in a file
void Write_Encrypted_File(FILE *p, char *aux){
	fwrite(aux, BLOCK_SIZE, sizeof(char), p);
	return;
}

// Signature function. Each character being processed goes through an OR-EXCLUSIVE with its corresponding character in the key file
void Sign(char *aux, char *key){
	int i = 0;
	for( ; i < BLOCK_SIZE; i++){
		aux[i] = aux[i] ^ key[i];
	}
}

// Transposition function. Switches the first character with the last, the second with the penultimate, and so forth
void Transposition(char *aux){
	int i = 0;
	char temp = '\0';
	for(; i < BLOCK_SIZE/2; i++){
		temp = aux[i];
		aux[i] = aux[BLOCK_SIZE - 1 - i];
		aux[BLOCK_SIZE - 1 - i] = temp; 
	}
	return;
}

// Inverse susbtitution function. Switches a character for its predecessor in the ASCII table
void Inverse_Substitution(char *aux){
	int i = 0;
	for(; i < BLOCK_SIZE; i++){
		aux[i] -= 1;
	} 
	return;
}

// Substitution function. Switches a character for its successor in the ASCII table
void Substitution(char *aux){
	int i = 0;
	for(; i < BLOCK_SIZE; i++){
		aux[i] += 1;
	}
	return;
}

// File reading function
void File_Read(FILE *p, char *aux){
	int i = 0;
	int n = -1;
	n = fread(aux, 1, sizeof(char), p);
	if(n == 0){
		file_end = true;
		return;
	}
	for(i = 1; i < BLOCK_SIZE; i++){
		n = fread(aux + i, 1, sizeof(char), p);
		if(n == 0){
			for( ; i < BLOCK_SIZE; i++){
				aux[i] = 0;
			}
			return;
		}	
	}
	return;
}

// File opening function
FILE* File_Open(const char name[], const char mode[]){
	FILE *p = fopen(name, mode);
	if(p == NULL){
		printf("Error opening file!!!\n\n");
		exit(1);
	}
	return p;
}

int main(int argc, char *argv[]){
	// Variable declaration
	FILE *file = NULL;
	FILE *encrypted_file = NULL;
	FILE *decrypted_file = NULL; 
	FILE *key_file = NULL;
	int i = 0; // Counter
	char key[BLOCK_SIZE];
	char aux[BLOCK_SIZE]; // Processing auxiliar
	
	for(i = 0; i < BLOCK_SIZE; i++){ 
		aux[i] = 0; // Initializing the processing auxiliar
	}

	key_file = File_Open(argv[3], "rb+"); // Opening the file that contains the cryptographic key.
	fread(key, BLOCK_SIZE, sizeof(char), key_file); // Passing the characters from the key file to a char vector. This facilitates working with the key.

	// Encription
	if(strcmp(argv[2], "enc") == 0){
		file = File_Open(argv[1], "rb+"); // Opening the file that contains the data to be encrypted.
		encrypted_file = File_Open("encrypted_file.txt", "wb+"); // Opening the file that will contain the encrypted data.
		for(i = 0; !file_end; i++){ 
			File_Read(file, aux); // Reads BLOCK_SIZE characters from the file to be encrypted and puts them in the processing auxiliar vector.
			if(file_end){
				break;
			}
			Substitution(aux);
			Transposition(aux);
			Sign(aux, key);
			Write_Encrypted_File(encrypted_file, aux);
		}
		fclose(file);
		fclose(encrypted_file);
	}

	// Decription
	if(strcmp(argv[2], "dec") == 0){
		encrypted_file = File_Open(argv[1], "rb+");
		decrypted_file = File_Open("decrypted_file.txt", "wb+");
		for(i = 0; !file_end; i++){
			File_Read(encrypted_file, aux); // Reads BLOCK_SIZE characters from the file to be decrypted and puts them in the processing auxiliar vector.
			if(file_end){
				break;
			}
			Sign(aux, key);
			Transposition(aux);
			Inverse_Substitution(aux);
			Write_Decrypted_File(decrypted_file, aux);
		}
		fclose(encrypted_file);
		fclose(decrypted_file);
	}
	fclose(key_file);
	return 0;
}