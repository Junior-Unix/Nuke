FROM ubuntu:latest
LABEL maintainer="Junior-Unix<sonjunior@live.com>"
RUN apt-get update && apt-get install -y apache2
CMD ["apache2ctl", "-D", "FOREGROUND"]
EXPOSE 80
COPY index.html /var/www/html/index.html
# Path: JS/ubuntu.dockerfile
# Compare this snippet from JS/Dockerfile:
# FROM httpd:2.4
