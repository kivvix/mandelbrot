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
mandelbrot(double x, double y) { 
  std::complex<double> c{x,y};
  std::size_t niter = 100;
  std::size_t count = 0;

  std::complex<double> z{c};

  while ( std::abs(z) < 100 && count < niter ) {
    z = z*z + c;
    ++count;
  }

  return std::abs(z);
}

#ifdef __cplusplus
}
#endif
