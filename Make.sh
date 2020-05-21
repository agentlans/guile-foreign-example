gcc `pkg-config --cflags guile-2.2` \
  -shared -o libguile-bessel.so -fPIC bessel.c

# Where Guile can find the libguile-bessel library
export LTDL_LIBRARY_PATH=.

