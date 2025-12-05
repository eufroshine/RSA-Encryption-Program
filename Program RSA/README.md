# RSA Encryption Program

A simple implementation of the RSA (Rivest-Shamir-Adleman) encryption algorithm in C++.

## Description

This program implements the RSA cryptographic algorithm that allows users to:
- Generate public and private keys from two prime numbers
- Encrypt text messages into ciphertext
- Decrypt ciphertext back to the original message

## Features

- ✅ Prime number validation
- ✅ Public key (e, n) and private key (d, n) calculation
- ✅ Character-by-character encryption
- ✅ Decryption for result verification
- ✅ Efficient modular exponentiation

## Compilation

```bash
g++ -o rsa_program rsa.cpp
```

Or with optimization:

```bash
g++ -o rsa_program rsa.cpp -O2
```

## Usage

1. Run the program:
```bash
./rsa_program
```

2. Enter two prime numbers (p and q):
```
Enter prime number p: 61
Enter prime number q: 53
```

3. The program will automatically calculate n and φ(n)

4. Enter the value of e (public exponent):
```
Enter value e (1 < e < phi) and gcd(e, phi) = 1: 17
```

5. The program will automatically calculate d (private exponent)

6. Enter the message you want to encrypt:
```
Enter plaintext (without newline): Hello RSA
```

7. The program will display:
   - Ciphertext (as a sequence of integers)
   - Decryption result (for verification)

## Example Output

```
Modulus n = p * q = 3233
phi(n) = (p-1)*(q-1) = 3120

Public key  : (e = 17, n = 3233)
Private key : (d = 2753, n = 3233)

Enter plaintext (without newline): Hello

Ciphertext (as a sequence of integers):
2881 2516 2790 2790 2200

Decryption result: Hello
```

## Algorithm Components

### Main Functions

- **`isPrime(n)`** - Checks if a number is prime
- **`gcd(a, b)`** - Calculates Greatest Common Divisor using Euclidean algorithm
- **`modPow(base, exp, mod)`** - Performs efficient modular exponentiation
- **`findPrivateKey(e, phi)`** - Finds private key d from equation e·d ≡ 1 (mod φ)

### Encryption Process

For each character in plaintext:
1. Convert character to ASCII value (0-255)
2. Calculate ciphertext: **c = m^e mod n**
3. Store value c

### Decryption Process

For each value in ciphertext:
1. Calculate plaintext: **m = c^d mod n**
2. Convert value m back to character

## Important Notes

⚠️ **Program Limitations:**
- This program is for **educational purposes** and demonstration only
- Uses small prime numbers (not secure for production)
- Private key search uses brute force (slow for large numbers)
- Does not use padding schemes (such as OAEP)
- Vulnerable to various cryptographic attacks

⚠️ **For Real-World Use:**
- Use tested cryptographic libraries (OpenSSL, Crypto++, etc.)
- Use minimum 2048-bit keys
- Implement proper padding schemes
- Add more robust validation and error handling

## Recommended Prime Numbers

For testing, use small prime numbers such as:
- p = 61, q = 53 (n = 3233)
- p = 17, q = 11 (n = 187)
- p = 7, q = 13 (n = 91)

Common values for e: 3, 5, 17, 257, 65537

## Requirements

- C++ Compiler (C++11 or newer)
- Standard Template Library (STL)

## Author

**Abidzar Sabil**

Created as a learning project to understand RSA encryption fundamentals.

## License

MIT License

Copyright (c) 2025 Abidzar Sabil

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## References

- [RSA Algorithm - Wikipedia](https://en.wikipedia.org/wiki/RSA_(cryptosystem))
- Rivest, R., Shamir, A., & Adleman, L. (1978). A Method for Obtaining Digital Signatures and Public-Key Cryptosystems