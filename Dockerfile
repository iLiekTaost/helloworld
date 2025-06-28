# build project into binary
FROM ubuntu:build AS ubuildtu

# build
COPY src/ /src
RUN mkdir /build
WORKDIR /build

RUN cmake -DCMAKE_BUILD_TYPE:STRING=Release ../src && cmake --build . -j 1
# && cmake --install .
# TODO get install to work, and then copy binaries to correct place under
# /usr/local

# copy to slim image
FROM ubuntu:latest
# TODO try FROM scratch
COPY --from=ubuildtu /build/hw /build/hw
COPY --from=ubuildtu /build/mylibs/libmylib.so /build/mylibs/libmylib.so
COPY --from=ubuildtu /lib/x86_64-linux-gnu/libstdc++.so.6 /lib/x86_64-linux-gnu/libstdc++.so.6
COPY --from=ubuildtu /lib/x86_64-linux-gnu/libgcc_s.so.1 /lib/x86_64-linux-gnu/libgcc_s.so.1
COPY --from=ubuildtu /usr/lib/x86_64-linux-gnu/libc.so.6 /usr/libx86_64-linux-gnu/libc.so.6
COPY --from=ubuildtu /lib/x86_64-linux-gnu/libm.so.6 /lib/x86_64-linux-gnu/libm.so.6
ENTRYPOINT ["/build/hw"]
