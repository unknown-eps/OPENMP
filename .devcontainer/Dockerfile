FROM ubuntu:24.04

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages for OpenMP and C/C++ development
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    git \
    libomp-dev \
    libgomp1 \
    clang \
    sudo \
    && rm -rf /var/lib/apt/lists/*

# Grant passwordless sudo access to the default ubuntu user
RUN echo "ubuntu ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/ubuntu \
    && chmod 0440 /etc/sudoers.d/ubuntu

# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog


