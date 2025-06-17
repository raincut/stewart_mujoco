//
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 16-May-2025 11:15:52
//

// Include Files
#include "mldivide.h"
#include <algorithm>
#include <cmath>

// Function Definitions
//
// Arguments    : const double A[576]
//                double B[72]
// Return Type  : void
//
namespace coder {
void mldivide(const double A[576], double B[72])
{
  double b_A[576];
  double smax;
  int i;
  int jA;
  int jBcol;
  int jp1j;
  int kAcol;
  signed char ipiv[24];
  std::copy(&A[0], &A[576], &b_A[0]);
  for (i = 0; i < 24; i++) {
    ipiv[i] = static_cast<signed char>(i + 1);
  }
  for (int j{0}; j < 23; j++) {
    int b_tmp;
    int mmj_tmp;
    signed char i1;
    mmj_tmp = 22 - j;
    b_tmp = j * 25;
    jp1j = b_tmp + 2;
    jA = 24 - j;
    jBcol = 0;
    smax = std::abs(b_A[b_tmp]);
    for (int k{2}; k <= jA; k++) {
      double s;
      s = std::abs(b_A[(b_tmp + k) - 1]);
      if (s > smax) {
        jBcol = k - 1;
        smax = s;
      }
    }
    if (b_A[b_tmp + jBcol] != 0.0) {
      if (jBcol != 0) {
        jA = j + jBcol;
        ipiv[j] = static_cast<signed char>(jA + 1);
        for (int k{0}; k < 24; k++) {
          jBcol = j + k * 24;
          smax = b_A[jBcol];
          kAcol = jA + k * 24;
          b_A[jBcol] = b_A[kAcol];
          b_A[kAcol] = smax;
        }
      }
      i = (b_tmp - j) + 24;
      for (int b_i{jp1j}; b_i <= i; b_i++) {
        b_A[b_i - 1] /= b_A[b_tmp];
      }
    }
    jA = b_tmp;
    for (jBcol = 0; jBcol <= mmj_tmp; jBcol++) {
      smax = b_A[(b_tmp + jBcol * 24) + 24];
      if (smax != 0.0) {
        i = jA + 26;
        jp1j = (jA - j) + 48;
        for (kAcol = i; kAcol <= jp1j; kAcol++) {
          b_A[kAcol - 1] += b_A[((b_tmp + kAcol) - jA) - 25] * -smax;
        }
      }
      jA += 24;
    }
    i1 = ipiv[j];
    if (i1 != j + 1) {
      smax = B[j];
      B[j] = B[i1 - 1];
      B[i1 - 1] = smax;
      smax = B[j + 24];
      B[j + 24] = B[i1 + 23];
      B[i1 + 23] = smax;
      smax = B[j + 48];
      B[j + 48] = B[i1 + 47];
      B[i1 + 47] = smax;
    }
  }
  for (int j{0}; j < 3; j++) {
    jBcol = 24 * j;
    for (int k{0}; k < 24; k++) {
      kAcol = 24 * k;
      i = k + jBcol;
      if (B[i] != 0.0) {
        jp1j = k + 2;
        for (int b_i{jp1j}; b_i < 25; b_i++) {
          jA = (b_i + jBcol) - 1;
          B[jA] -= B[i] * b_A[(b_i + kAcol) - 1];
        }
      }
    }
  }
  for (int j{0}; j < 3; j++) {
    jBcol = 24 * j;
    for (int k{23}; k >= 0; k--) {
      kAcol = 24 * k;
      i = k + jBcol;
      smax = B[i];
      if (smax != 0.0) {
        B[i] = smax / b_A[k + kAcol];
        for (int b_i{0}; b_i < k; b_i++) {
          jp1j = b_i + jBcol;
          B[jp1j] -= B[i] * b_A[b_i + kAcol];
        }
      }
    }
  }
}

} // namespace coder

//
// File trailer for mldivide.cpp
//
// [EOF]
//
