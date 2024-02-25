# Base image
FROM ubuntu:latest

# Install SSH server
RUN apt-get update && \
    apt-get install -y openssh-server && \
    apt-get clean

# Install Apache 2
RUN apt-get update && \
    apt-get install -y apache2 && \
    apt-get clean
# Mount volume to htdocs directory
VOLUME /var/www/html

# Expose port 22 for SSH
EXPOSE 22

# Expose port 80 for Apache
EXPOSE 80

# Create user "nox" with password "1"
RUN useradd -m nox && \
    echo "nox:1" | chpasswd

# Start SSH server and Apache 2
CMD service ssh start && \
    apache2ctl -D FOREGROUND
# # Path: JS/ubuntuSSH.dockerfile
#ssh nox@<endereço IP do contêiner>
# FROM ubuntu:latest
## Install SSH server
# RUN apt-get update && \   
#     apt-get install -y openssh-server && \
#     apt-get clean
## Install Apache 2
# RUN apt-get update && \
#     apt-get install -y apache2 && \
#     apt-get clean
## Expose port 22 for SSH
# EXPOSE 22
## Expose port 80 for Apache
# EXPOSE 80
## Create user

# "nox" with
# password "1"
# RUN useradd -m nox && \
#     echo "nox:1" | chpasswd
## Start SSH server and Apache 2
# CMD service ssh start && \
#     apache2ctl -D FOREGROUND
# # Path: JS/ubuntuSSH.dockerfile
# # Base image
# FROM ubuntu:latest
## Install SSH server
# RUN apt-get update && \
#     apt-get install -y openssh-server && \
#docker build -t my-ubuntu-image -f /workspaces/Nuke/JS/ubuntu.dockerfile .
#docker run -d -p 22:22 -p 80:80 my-ubuntu-image
#docker exec -it <container_name_or_id> bash



