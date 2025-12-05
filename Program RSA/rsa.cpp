#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Cek bilangan prima (sederhana, untuk contoh kecil)
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// gcd (Euclidean algorithm)
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// perpangkatan modular: (base^exp) mod mod
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// cari d dari e*d ≡ 1 (mod phi)
// implementasi sederhana: brute force
long long findPrivateKey(long long e, long long phi) {
    for (long long d = 1; d < phi; ++d) {
        if ((e * d) % phi == 1) return d;
    }
    return -1; // gagal
}

// konversi char ke integer (0–255)
long long charToInt(char ch) {
    return static_cast<unsigned char>(ch);
}

// konversi integer (0–255) ke char
char intToChar(long long x) {
    return static_cast<char>(x);
}

int main() {
    // ==== 1. Input p dan q (bilangan prima) ====
    long long p, q;
    cout << "Masukkan bilangan prima p: ";
    cin >> p;
    cout << "Masukkan bilangan prima q: ";
    cin >> q;

    if (!isPrime(p) || !isPrime(q)) {
        cout << "p atau q bukan bilangan prima. Program berhenti.\n";
        return 0;
    }

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    cout << "\nModulus n = p * q = " << n << endl;
    cout << "phi(n) = (p-1)*(q-1) = " << phi << endl;

    // ==== 2. Pilih e yang relatif prima dengan phi ====
    long long e;
    cout << "\nMasukkan nilai e (1 < e < phi) dan gcd(e, phi) = 1: ";
    cin >> e;

    if (e <= 1 || e >= phi || gcd(e, phi) != 1) {
        cout << "e tidak valid (harus 1 < e < phi dan gcd(e, phi)=1).\n";
        return 0;
    }

    // ==== 3. Hitung d (kunci privat) ====
    long long d = findPrivateKey(e, phi);
    if (d == -1) {
        cout << "Gagal menemukan d.\n";
        return 0;
    }

    cout << "\nKunci publik  : (e = " << e << ", n = " << n << ")\n";
    cout << "Kunci privat  : (d = " << d << ", n = " << n << ")\n\n";

    // Buang newline sebelum baca string
    cin.ignore();

    // ==== 4. Input pesan plaintext ====
    string plaintext;
    cout << "Masukkan plaintext (tanpa newline): ";
    getline(cin, plaintext);

    // ==== 5. Enkripsi karakter per karakter ====
    vector<long long> ciphertext;
    for (char ch : plaintext) {
        long long m = charToInt(ch);
        long long c = modPow(m, e, n);  // c = m^e mod n
        ciphertext.push_back(c);
    }

    cout << "\nCiphertext (sebagai deretan integer):\n";
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        cout << ciphertext[i];
        if (i + 1 < ciphertext.size()) cout << " ";
    }
    cout << "\n";

    // ==== 6. Dekripsi kembali ke plaintext ====
    string decrypted;
    for (long long c : ciphertext) {
        long long m = modPow(c, d, n);  // m = c^d mod n
        decrypted.push_back(intToChar(m));
    }

    cout << "\nHasil dekripsi: " << decrypted << "\n";

    return 0;
}
