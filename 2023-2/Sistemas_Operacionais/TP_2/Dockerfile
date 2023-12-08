# Use a base image with your desired Linux distribution
FROM ubuntu:latest

# Set the working directory
WORKDIR /MatheusPeixoto

# Install packages: gcc, vim, grep
RUN apt-get update && \
    apt-get install -y gcc vim grep && \
    rm -rf /var/lib/apt/lists/*

