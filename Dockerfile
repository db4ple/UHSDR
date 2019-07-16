FROM gitpod/workspace-full

# add your tools here
<<<<<<< HEAD
ARG GCC_BASE=gcc-arm-none-eabi-8-2019-q3-update
ARG GCC_SHORT=8-2019q3
ARG GCC_URL=https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/${GCC_SHORT}/${GCC_BASE}-linux.tar.bz2
RUN mkdir -p /home/gitpod/.local && wget -q ${GCC_URL} -O - | tar xfj - -C /home/gitpod/.local --strip-components=1
=======
ARG GCC_BASE=gcc-arm-none-eabi-8-2018-q4-major
ARG GCC_SHORT=8-2018q4
ARG GCC_URL=https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/${GCC_SHORT}/${GCC_BASE}-linux.tar.bz2
RUN echo ${GCC_URL} && mkdir -p /home/gitpod/arm-gcc && wget -q ${GCC_URL} -O - | tar xfj - -C /home/gitpod/arm-gcc --strip-components=1; fi
>>>>>>> Test gitpod
