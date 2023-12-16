# Use a base image with your desired Linux distribution
FROM ubuntu:latest

# Set the working directory
WORKDIR /MatheusPeixoto


RUN apt-get update && \
    apt-get install -y gcc vim curl make unzip g++ && \
    rm -rf /var/lib/apt/lists/*

