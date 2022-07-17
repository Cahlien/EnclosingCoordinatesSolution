FROM conanio/gcc11:latest AS base
SHELL ["/bin/bash", "-c"]
RUN sudo apt-get update && sudo apt-get upgrade -y
RUN pip install conan --upgrade
RUN conan profile new default --detect
RUN conan profile update settings.compiler.libcxx=libstdc++11 default

FROM base AS builder
COPY ./ /app
COPY ./conanfile.txt /home/conan/
RUN sudo chown -R $UID /app
RUN conan install . --build=missing
RUN sudo chown -R $UID /home/conan
RUN sudo cp /home/conan/conanbuildinfo.cmake /app/conanbuildinfo.cmake
WORKDIR /app
ENV ENVIRONMENT_DOCKER=ON
RUN cmake .
RUN make EnclosingCoordinatesSolution.exe

FROM fedora:latest AS runtime
COPY --from=builder /app/data/points.txt /app/data/points.txt
COPY --from=builder /app/bin/EnclosingCoordinatesSolution.exe /app/EnclosingCoordinatesSolution.exe
CMD ["/app/EnclosingCoordinatesSolution.exe", "--file", "/app/data/points.txt", "--shape", "circle"]
