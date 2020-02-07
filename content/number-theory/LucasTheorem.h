/**
 * Author: 7 Halim
 * Description: Compute the value of Combin(A, B) mod P with big A and big B but small prime modulo P.
 * Time: O(P \log(P))
 */
#pragma once

// precompute from 1! to P!

int combin(int v, int k) {
  // return the v combin k by using v! * inv(k!) * inv((v-k)!)
}

// mod must be a prime number
int combinLucas(int a, int b) {
    int res = 1;
    while (a > 0 && b > 0){
        res = (1LL * res * combin(a % mod, b % mod)) % mod;
        a /= mod; b /= mod;
    }
    return res;
}
