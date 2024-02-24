#Dockerfile para criar um servidor web apache
#Imagem base
FROM httpd:2.4 
#Porta exposta
EXPOSE 80 
#Diretório compartilhado
VOLUME "$PWD/:/usr/local/apache2/htdocs" # diretório compartilhado

#docker build -t server .
#run -d -p 8080:80 -v "$PWD":/usr/local/apache2/htdocs servidor_web_apache //errado.
#docker run -d -p 8080:80 -v "$PWD/:/usr/local/apache2/htdocs" server

#Apache funcionando:
#docker run --name "servidor_web_apache" -d -p 8080:80 -v "$PWD/:/usr/local/apache2/htdocs" httpd:2.4

#Nginx funciona melhor atualizando em tempo real.
#docker run --name "servidor_web" -d -p 8080:80 -e NGINX_ENTRYPOINT_QUIET_LOGS=1 -v "$PWD/:/usr/share/nginx/html" nginx:1.19.4-alpine


# FROM ubuntu:latest
# LABEL MAINTAINER name="Junior-Unix" email="sonjunior@live.com"
# RUN apt-get update
# RUN apt-get install -y openssh-server
# RUN mkdir /var/run/sshd

# RUN echo 'root:root' |chpasswd 
# RUN sed -ri 's/^#PermitRootLogin\s+.*/PermitRootLogin yes/' /etc/ssh/sshd_config
# RUN sed -ri 's/UsePAM yes/#UsePAM yes/g' /etc/ssh/sshd_config
# RUN mkdir /root/.ssh
# EXPOSE 22
# EXPOSE 3090

# CMD ["/usr/sbin/sshd", "-D"]
# # Path: JS/ubuntuSSH.dockerfile