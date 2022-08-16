#include <iostream>
#include <complex>
#include <emscripten/emscripten.h>

int main(int, char **) {
  return 0;
}

#ifdef __cplusplus
extern "C" {
#endif

int
EMSCRIPTEN_KEEPALIVE
julia(double rec, double imc, double x, double y) { 
  std::complex<double> c{rec,imc};
  std::size_t niter = 1000;
  std::size_t count = 0;

  std::complex<double> z{x,y};

  while ( std::abs(z) < 100 && count < niter ) {
    z = z*z + c;
    ++count;
  }

  return std::abs(z);
}

#ifdef __cplusplus
}
#endif
