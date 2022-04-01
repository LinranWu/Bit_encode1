# This program is a bit message stream cipher in C.

An elementary level bit stream cipher is an encryption algorithm that encrypts 1 byte of plain text at a time. 

This cipher uses a given 4-bit bit pattern as the key. The size of the encrypted message that we want to be able to send has a maximum length of 200 characters. The 4-bit pattern must be duplicated to an 8-bit value for this to work. (e.g., if we have the 4-bit pattern 0110, then the 8-bit key would be 0110 0110.)

### **Here is an example:**

If we have the ASCII value for the letter **‘t’**, then that equates to the hex value 0x74, which represents the binary value 0111 0100. If we bitwise XOR that value with a key, say 0101 0101, then 

encryption:

0111 0100 -> ‘t’ 

0101 0101 -> XOR with key  

0010 0001 -> encrypted value 0x21 

If we XOR the encrypted value with the key, we get our ASCII value back. 

decryption:

0010 0001 -> encrypted value 0x21 

0101 0101 -> XOR with key  

0111 0100 -> ‘t’

The bit stream encryption cipher that this program implements will do a little more than this. An alternating bit rotation twist is also added to this algorithm. In this alternating bit rotation algorithm, if it is the 1st character of the message we are encrypting, it will be rotated one bit to the left (in our example above that would mean 0b 0010 0001 would become 0b 0100 0010 or 0x42). The encrypted value for the 2nd character of the message would be rotated one bit to the right, 3rd char rotated left, 4th rotated right and so forth. As a further example, if ‘t’ is rotated to the right one position, that would mean 0b 0010 0001 would become 0b 1001 0000 or 0x90. 

---

### Sample Output: 

[commandline@linux] bit_encode1

enter cleartext: two fat dogs

two fat dogs 

hex encoding: 

 74 77 6F 20 66 61 74 20 64 6F 
 67 73 

enter 4-bit key: 0110

hex ciphertext: 

 24 88 12 23 00 83 24 23 04 84 
 02 8A 

[commandline@linux]$ 

---

This program has also been introduced **#ifdef PROMPT and #endif** preprocessor statements to modify the program such that it will read clear text and the 4-bit key input without printing any prompts at all and prints no other output other than the cipher text without concern for columns. Input will 
be coming from a redirected input source on the command line.

### Sample output: 
[jones.5684@cse-fl1 lab2] bit_encode2 < encode.input

8B 61 87 E2 15 EC BD E5 BD E7 15 EF 89 E1 B9 E7 B1 EC 87 6F A7 

encode.input contains these two lines:

 ohio state university 

 1010

---