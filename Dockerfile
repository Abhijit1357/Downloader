FROM ubuntu:latest

#Set working directory
WORKDIR /app

Copy files
COPY . /app

#Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    libcurl4-openssl-dev \
    libjsoncpp-dev

#Build application
RUN g++ -o main main.cpp curl.cpp json.cpp download.cpp -lcurl -ljsoncpp

Expose port
EXPOSE 8080

Run command
CMD ["./main"]
