import java.io.*;
import java.math.*;
import java.util.*;

class Problem_29 {
  public static void main(String args[]) {
    final int N = 100;
    Map<BigInteger, Boolean> used = new HashMap<>();
    int ans = 0;

    for (int a = 2; a <= N; a++) {
      BigInteger p = new BigInteger("" + a);
      for (int b = 2; b <= N; b++) {
        BigInteger q = p.pow(b);
        if (!used.containsKey(q)) {
          used.put(q, true);
          ans++;
        }
      }
    }

    System.out.println(ans);
  }
}